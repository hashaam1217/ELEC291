/*-------------------------------------------------------------------------
  C51asm.c - header file for all types of stuff to support different assemblers.


  Written By - Michael Hope <michaelh@juju.net.nz> 2000

  This program is free software; you can redistribute it and/or modify it
  under the terms of the GNU General Public License as published by the
  Free Software Foundation; either version 2, or (at your option) any
  later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

  In other words, you are welcome to use, share and improve this program.
  You are forbidden to forbid anyone else to use, share and improve
  what you give them.   Help stamp out software-hoarding!
-------------------------------------------------------------------------*/

/*  Provides output functions that modify the output string
    based on the input tokens and the assembler token mapping
    specification loaded.

    Note that the functions below only handle digit format modifiers.
    eg %02X is ok, but %lu and %.4u will fail.
*/

#include <errno.h>

#include "common.h"
#include "dbuf_string.h"

/* A 'token' is like !blah or %24f and is under the programmers
   control. */

static hTab *_h;

char *
FileBaseName (char *fileFullName)
{
    char *p = fileFullName;

    if (!fileFullName)
    {
        return "unknown";
    }

    while (*fileFullName)
    {
        if ((*fileFullName == '/') || (*fileFullName == '\\') || (*fileFullName == ':'))
        {
            p = fileFullName;
            p++;
        }
        fileFullName++;
    }
    return p;
}

void
dbuf_tvprintf (struct dbuf_s *dbuf, const char *format, va_list ap)
{
    // Under Linux PPC va_list is a structure instead of a primitive type,
    // and doesnt like being passed around.  This version turns everything
    // into one function.

    // Supports:
    //  !tokens
    //  %[CIFN] - special formats with no argument (ie list isnt touched)
    //  All of the system formats

    // This is acheived by expanding the tokens and zero arg formats into
    // one big format string, which is passed to the native printf.
    static int count;
    struct dbuf_s tmpDBuf;
    const char *noTokens;
    const char *sz = format;

    dbuf_init (&tmpDBuf, INITIAL_INLINEASM);

    /* First pass: expand all of the macros */
    while (*sz)
    {
        if (*sz == '!')
        {
            /* Start of a token.  Search until the first
               [non alpha, *] and call it a token. */
            const char *t;
            struct dbuf_s token;

            dbuf_init (&token, 64);
            sz++;
            while (isalpha ((unsigned char)*sz) || *sz == '*')
            {
                dbuf_append (&token, sz++, 1);
            }
            /* Now find the token in the token list */
            if ((t = shash_find (_h, dbuf_c_str(&token))))
            {
                dbuf_append_str (&tmpDBuf, t);
            }
            else
            {
                /* Token not recognized as a valid macro: macro is not expanded */
                dbuf_append_char (&tmpDBuf, '!');
                dbuf_append (&tmpDBuf, dbuf_get_buf(&token), dbuf_get_length(&token));
            }
            dbuf_destroy (&token);
        }
        else
        {
            dbuf_append_char (&tmpDBuf, *sz++);
        }
    }

    /* Second pass: Expand any macros that we own */
    dbuf_c_str (&tmpDBuf);
    sz = noTokens = dbuf_detach (&tmpDBuf);

    /* recycle tmpDBuf */
    dbuf_init (&tmpDBuf, INITIAL_INLINEASM);

    while (*sz)
    {
        if (*sz == '%')
        {
            // See if its one that we handle.
            sz++;
            switch (*sz)
            {
            case 'C':
                // Code segment name.
                dbuf_append_str (&tmpDBuf, CODE_NAME);
                sz++;
                break;

            case 'F':
                // Source file name.
                dbuf_append_str (&tmpDBuf, fullSrcFileName);
                sz++;
                break;

            case 'N':
                // Current function name.
                dbuf_append_str (&tmpDBuf, currFunc->rname);
                sz++;
                break;

            case 'I':
                // Unique ID.
                dbuf_printf (&tmpDBuf, "%u", ++count);
                sz++;
                break;

            default:
                // Not one of ours.  Copy until the end.
                dbuf_append_char (&tmpDBuf, '%');
                while (!isalpha ((unsigned char)*sz))
                    dbuf_append_char (&tmpDBuf, *sz++);

                dbuf_append_char (&tmpDBuf, *sz++);
            }
        }
        else
        {
            dbuf_append_char (&tmpDBuf, *sz++);
        }
    }

    dbuf_free (noTokens);

    dbuf_vprintf (dbuf, dbuf_c_str (&tmpDBuf), ap);

    dbuf_destroy (&tmpDBuf);
}

void
dbuf_tprintf (struct dbuf_s *dbuf, const char *szFormat, ...)
{
    va_list ap;
    va_start (ap, szFormat);
    dbuf_tvprintf (dbuf, szFormat, ap);
    va_end (ap);
}

void
tsprintf (char *buffer, size_t len, const char *szFormat, ...)
{
    va_list ap;
    struct dbuf_s dbuf;
    size_t copyLen;

    dbuf_init (&dbuf, INITIAL_INLINEASM);

    va_start (ap, szFormat);
    dbuf_tvprintf (&dbuf, szFormat, ap);
    va_end (ap);

    copyLen = min (len - 1, dbuf_get_length (&dbuf));
    memcpy (buffer, dbuf_get_buf (&dbuf), copyLen);
    buffer[copyLen] = '\0';
    dbuf_destroy (&dbuf);
}

void
tfprintf (FILE *fp, const char *szFormat, ...)
{
    va_list ap;
    struct dbuf_s dbuf;
    size_t len;

    dbuf_init (&dbuf, INITIAL_INLINEASM);

    va_start (ap, szFormat);
    dbuf_tvprintf (&dbuf, szFormat, ap);
    va_end (ap);

    len = dbuf_get_length (&dbuf);
    fwrite(dbuf_get_buf (&dbuf), 1, len, fp);
    dbuf_destroy (&dbuf);
}

void
asm_addTree (const ASM_MAPPINGS *pMappings)
{
    const ASM_MAPPING *pMap;

    /* Traverse down first */
    if (pMappings->pParent)
        asm_addTree (pMappings->pParent);
    pMap = pMappings->pMappings;
    while (pMap->szKey && pMap->szValue)
    {
        shash_add (&_h, pMap->szKey, pMap->szValue);
        pMap++;
    }
}

/*-----------------------------------------------------------------*/
/* printILine - return the readable i-code for this ic             */
/*-----------------------------------------------------------------*/
const char *
printILine (iCode *ic)
{
    char *verbalICode;
    struct dbuf_s tmpBuf;
    size_t len;
    iCodeTable *icTab = getTableEntry (ic->op);

    dbuf_init (&tmpBuf, 1024);

    if (INLINEASM == ic->op)
        dbuf_append (&tmpBuf, "inline", (sizeof "inline") - 1);
    else
    {
        /* stuff the temporary file with the readable icode */
        icTab->iCodePrint (&tmpBuf, ic, icTab->printName);
    }

    len = dbuf_get_length (&tmpBuf);

    /* null terminate the buffer */
    dbuf_c_str (&tmpBuf);
    verbalICode = dbuf_detach (&tmpBuf);

    /* kill the trailing NL */
    if (len > 0 && '\n' == verbalICode[len - 1])
        verbalICode[--len] = '\0';

    /* and throw it up */
    return verbalICode;
}


/*-----------------------------------------------------------------*/
/* skipLine - skip the line from file infp                         */
/*-----------------------------------------------------------------*/
static int
skipLine (FILE *infp)
{
    int c;
    static char is_eof = 0;
    size_t len = 0;

    if (is_eof)
        return 0;

    while ((c = getc(infp)) != '\n' && EOF != c)
        ++len;

    if (EOF == c)
    {
        if (len)
        {
            /* EOF in the middle of the line */
            is_eof = 1;
            return 1;
        }
        else
            return 0;
    }
    else
        return 1;
}

/*-----------------------------------------------------------------*/
/* printCLine - return the c-code for this lineno                  */
/*-----------------------------------------------------------------*/
/* int rewinds=0; */
const char *
printCLine (const char *srcFile, int lineno)
{
    static FILE *inFile = NULL;
    static struct dbuf_s line;
    static struct dbuf_s lastSrcFile;
    static char dbufInitialized = 0;
    static int inLineNo = 0;
    size_t len;

    if (!dbufInitialized)
    {
        dbuf_init (&line, 1024);
        dbuf_init (&lastSrcFile, PATH_MAX);
        dbufInitialized = 1;
    }
    else
    {
        /* empty the dynamic buffer */
        dbuf_set_length (&line, 0);
    }

    if (inFile)
    {
        if (strcmp (dbuf_c_str (&lastSrcFile), srcFile) != 0)
        {
            fclose (inFile);
            inFile = NULL;
            inLineNo = 0;
            dbuf_set_length (&lastSrcFile, 0);
            dbuf_append_str (&lastSrcFile, srcFile);
        }
    }

    if (!inFile)
    {
        if (!(inFile = fopen(srcFile, "r")))
        {
            /* can't open the file:
               don't panic, just return the error message */
            dbuf_printf(&line, "ERROR: %s", strerror(errno));

            return dbuf_c_str (&line);
        }
        else
        {
            dbuf_set_length (&lastSrcFile, 0);
            dbuf_append_str (&lastSrcFile, srcFile);
        }
    }

    if (inLineNo > lineno)
    {
        /* past the lineno: rewind the file pointer */
        rewind (inFile);
        inLineNo = 0;
        /* rewinds++; */
    }

    /* skip lines until lineno */
    while (inLineNo + 1 < lineno)
    {
        if (!skipLine (inFile))
            goto err_no_line;
        ++inLineNo;
    }

    /* get the line */
    if (0 != (len = dbuf_getline (&line, inFile)))
    {
        const char *inLineString = dbuf_c_str (&line);

        ++inLineNo;

        /* remove the trailing NL */
        if (len > 0 &&'\n' == inLineString[len - 1])
        {
            dbuf_set_length (&line, --len);
            inLineString = dbuf_c_str (&line);
        }

        /* skip leading spaces */
        while (isspace (*inLineString))
            inLineString++;

        return inLineString;
    }

err_no_line:
    dbuf_printf(&line, "ERROR: no line number %d in file %s", lineno, srcFile);

    return dbuf_c_str (&line);
}

static const ASM_MAPPING _a51_mapping[] =
{
    {"labeldef", "%s:"}, // Public label
    {"slabeldef", "%s:"},
    {"tlabeldef", "L%04d$:"},
    {"tlabel", "L%04d$"},
    {"immed", "#"},
    {"zero", "#0x00"},
    {"one", "#0x01"},
    {"area", "rseg %s"},
    {"areacode", "rseg %s"},
    {"areadata", "rseg %s"},
    {"areahome", "rseg %s"},
    {"ascii", "db '%s'"},
    {"ds", "ds %d"},
    {"db", "db"},
    {"dbs", "db '%s'"},
    {"dw", "dw"},
    {"dws", "dw '%s'"},
    {"constbyte", "0x%02X"},
    {"constword", "0x%04X"},
    {"immedword", "#0x%04X"},
    {"immedbyte", "#0x%02X"},
    {"hashedstr", "#%s"},
    {"lsbimmeds", "#<(%s)"},
    {"msbimmeds", "#>(%s)"},
    {"module", "; ;module %s"},
    {"global", "public %s"},
    {"extern", "extrn code (%s)"},
    {
        "fileprelude",
        "R_DSEG    segment data\n"
        "\tR_CSEG    segment code\n"
        "\tR_BSEG    segment bit\n"
        "\tR_XSEG    segment xdata\n"
        "\tR_PSEG    segment xdata\n"
        "\tR_ISEG    segment idata\n"
        "\tR_OSEG    segment data overlay\n"
        "\tBIT_BANK  segment data overlay\n"
        "\tR_HOME    segment code\n"
        "\tR_GSINIT  segment code\n"
        "\tR_IXSEG   segment xdata\n"
        "\tR_CONST   segment code\n"
        "\tR_XINIT   segment code\n"
        "\tR_DINIT   segment code\n"
    },
    {
        "functionheader",
        "; ---------------------------------\n"
        "; Function %s\n"
        "; ---------------------------------"
    },
    {"functionlabeldef", "%s:"},
    {"bankimmeds", "0     ; PENDING: bank support"},
    {"los", "(%s & 0xFF)"},
    {"his", "(%s >> 8)"},
    {"hihis", "(%s >> 16)"},
    {"hihihis", "(%s >> 24)"},
    {"lod", "(%d & 0xFF)"},
    {"hid", "(%d >> 8)"},
    {"hihid", "(%d >> 16)"},
    {"hihihid", "(%d >> 24)"},
    {"lol", "(%L04d$ & 0xFF)"},
    {"hil", "(%L04d$ >> 8)"},
    {"hihil", "(%L04d$ >> 16)"},
    {"hihihil", "(%L04d$ >> 24)"},
    {"equ", "equ"},
    {"org", "org 0x%04X"},
    {NULL, NULL}
};

const ASM_MAPPINGS asm_a51_mapping =
{
    NULL,
    _a51_mapping
};
