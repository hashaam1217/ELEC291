/*-------------------------------------------------------------------------
  C51util.c - Small utility functions.

             Written By -  Sandeep Dutta . sandeep.dutta@usa.net (1999)

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

#ifndef C51UTIL_H
#define C51UTIL_H

#include "C51hasht.h"
#include "dbuf.h"
#include <stdarg.h>

/** Given an array of name, value string pairs creates a new hash
    containing all of the pairs.
*/
hTab *populateStringHash (const char **pin);

/** Prints elements of the set to the file, each element on new line
*/
void fputStrSet (FILE *fp, set *list);

/** Prepend / append given strings to each item of string set. The result is in a
    new string set.
*/
set *appendStrSet (set *list, const char *pre, const char *post);

/** Given a set returns a string containing all of the strings seperated
    by spaces. The returned string is on the heap.
*/
const char *joinStrSet (set *list);

/** Split the path string to the directory and file name (including extension) components.
    The directory component doesn't contain trailing directory separator.
    Returns true if the path contains the directory separator. */
int dbuf_splitPath (const char *path, struct dbuf_s *dir, struct dbuf_s *file);

/** Split the path string to the file name (including directory) and file extension components.
    The file name component doesn't contain trailing extension separator.
    Returns true if the path contains the extension separator. */
int dbuf_splitFile (const char *path, struct dbuf_s *file, struct dbuf_s *ext);

/** Combile directory and the file name to a path string using the DIR_SEPARATOR_CHAR.
 */
void dbuf_makePath (struct dbuf_s *path, const char *dir, const char *file);

/** Given a file with path information in the binary files directory,
    returns the directory component. Used for discovery of bin
    directory of C51 installation. Returns NULL if the path is
    impossible.
*/
const char *getBinPath (const char *prel);

/** Returns true if the given path exists.
 */
bool pathExists (const char *ppath);

void setMainValue (const char *pname, const char *pvalue);

void populateMainValues (const char **ppin);

void buildCmdLine2 (char *pbuffer, size_t len, const char *pcmd, ...);

/** Returns true if sz starts with the string given in key.
 */
bool startsWith (const char *sz, const char *key);

/** Removes any newline characters from the string.  Not strictly the
    same as perl's chomp.
*/
void chomp (char *sz);

hTab *getRuntimeVariables (void);

/* strncpy() with guaranteed NULL termination. */
char *strncpyz (char *dest, const char *src, size_t n);

/* like strncat() with guaranteed NULL termination
 * The passed size should be the size of the dest buffer, not the number of
 * bytes to copy.
 */
char *strncatz (char *dest, const char *src, size_t n);

/* return C51 build number */
const char *getBuildNumber (void);

/* return C51 build date */
const char *getBuildDate (void);

/* return environment used to build C51 */
const char *getBuildEnvironment(void);

/* snprintf, by hook or by crook. */
size_t C51snprintf (char *, size_t, const char *, ...);

# if defined(HAVE_VSNPRINTF)

// best option: we can define our own snprintf which logs errors.
#  define SNPRINTF C51snprintf

# elif defined(HAVE_SPRINTF)

// if we can't build a safe snprintf for lack of vsnprintf but there
// is a native snprintf, use it.
#  define SNPRINTF snprintf

# elif defined(HAVE_VSPRINTF)

// we can at least define our own unsafe version.
#  define SNPRINTF C51snprintf

# else
// We don't have a native snprintf nor the functions we need to write one.
#  error "Need at least one of snprintf, vsnprintf, vsprintf!"
# endif

/** Pragma tokenizer
 */
enum pragma_token_e { TOKEN_UNKNOWN, TOKEN_STR, TOKEN_INT, TOKEN_EOL };

struct pragma_token_s
{
    enum pragma_token_e type;
    struct dbuf_s dbuf;
    union
    {
        int int_val;
    } val;
};

void init_pragma_token (struct pragma_token_s *token);
char *get_pragma_token (const char *s, struct pragma_token_s *token);
const char *get_pragma_string (struct pragma_token_s *token);
void free_pragma_token (struct pragma_token_s *token);

unsigned char hexEscape (const char **src);
unsigned char octalEscape (const char **src);
int copyStr (char *dest, const char *src);

#endif
