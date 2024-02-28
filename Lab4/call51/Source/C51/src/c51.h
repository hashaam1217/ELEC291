#ifndef C51_HEADER
#define C51_HEADER

#define C51_VERSION_HI 1
#define C51_VERSION_LO 0
#define C51_VERSION_P 0
#define C51_VERSION_STR "1.0.0"

#ifndef __FUNCTION__
#define __FUNCTION__  __FILE__
#endif

#define __func__      __FUNCTION__

#define DIR_SEPARATOR_STRING "\\"
#define DIR_SEPARATOR_CHAR   '\\'

#define PREFIX                "\\call51"
#define EXEC_PREFIX           "\\call51"
#define BIN_PREFIX            "\\call51\\bin"
#define DATADIR               "\\call51"

#define INCLUDE_DIR_SUFFIX    "\\include"
#define LIB_DIR_SUFFIX        "\\lib"

#define BIN2DATA_DIR          "\\.."
#define PREFIX2BIN_DIR        "\\bin"
#define PREFIX2DATA_DIR       ""
#define BINDIR PREFIX         "\\bin"

/* environment variables */
#define C51_DIR_NAME "C51_HOME"
#define C51_INCLUDE_NAME "C51_INCLUDE"
#define C51_LIB_NAME "C51_LIB"

/* standard libraries */
#define STD_LIB               "libc51"
#define STD_INT_LIB           "libint"
#define STD_LONG_LIB          "liblong"
#define STD_FP_LIB            "libfloat"

#undef HAVE_STRERROR
#define HAVE_VSNPRINTF
#define vsnprintf _vsnprintf
#undef HAVE_SPRINTF
#undef HAVE_VSPRINTF
#undef HAVE_MKSTEMP
#define pclose  _pclose

#define RETSIGTYPE void

#define TYPE_BYTE char
#define TYPE_WORD short
#define TYPE_DWORD int
#define TYPE_UBYTE unsigned TYPE_BYTE
#define TYPE_UWORD unsigned TYPE_WORD
#define TYPE_UDWORD unsigned TYPE_DWORD


/* for flex 2.5.35 and greater */
#define YY_NO_UNISTD_H  1

#undef OPT_DISABLE_MCS51
#define OPT_DISABLE_GBZ80 1
#define OPT_DISABLE_Z80 1
#define OPT_DISABLE_AVR 1
#define OPT_DISABLE_TININative 1
#define OPT_DISABLE_PIC 1
#define OPT_DISABLE_XA51 1
#define OPT_DISABLE_PIC16 1
#define OPT_DISABLE_XA51 1
#define OPT_DISABLE_HC08 1

#if defined(_MSC_VER)
#pragma warning (disable : 4996)
#endif

#if defined(_WIN64)
#pragma warning (disable : 4244)
#pragma warning (disable : 4267)
#endif

#if defined(_WIN64)
#pragma warning (disable : 4244)
#pragma warning (disable : 4267)
#endif
#endif  /* C51_HEADER */

/* End of c51.h */
