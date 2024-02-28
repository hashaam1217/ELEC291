#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>


#ifndef COMMON_H
#define COMMON_H

#if defined(__APPLE__) && (__MACH__)
#ifdef _G
#undef _G
#endif
#endif

#include "C51globl.h"
#include "C51mem.h"
#include "C51ast.h"
#include "C51y.h"
#include "C51hasht.h"
#include "C51bitv.h"
#include "C51set.h"
#include "C51icode.h"
#include "C51label.h"
#include "C51BBlock.h"
#include "C51loop.h"
#include "C51cse.h"
#include "C51cflow.h"
#include "C51dflow.h"
#include "C51lrange.h"
#include "C51ptropt.h"
#include "C51opt.h"
#include "C51glue.h"
#include "C51peeph.h"
#include "C51debug.h"
#include "C51util.h"
#include "C51asm.h"

#include "port.h"

#include "newalloc.h"

#endif
