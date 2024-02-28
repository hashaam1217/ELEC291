# Microsoft Developer Studio Generated NMAKE File, Based on C51.dsp
!IF "$(CFG)" == ""
CFG=C51 - Win32 Debug
!MESSAGE No configuration specified. Defaulting to C51 - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "C51 - Win32 Debug" && "$(CFG)" != "C51 - Win32 Release"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "C51.mak" CFG="C51 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "C51 - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE "C51 - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "C51 - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "..\..\..\bin\c51.exe" "$(OUTDIR)\C51.bsc"

!ELSE 

ALL : "flex - Win32 Debug" "mcs51 - Win32 Debug" "yacc - Win32 Debug" "..\..\..\bin\c51.exe" "$(OUTDIR)\C51.bsc"

!ENDIF 

!IF "$(RECURSE)" == "1" 
CLEAN :"yacc - Win32 DebugCLEAN" "mcs51 - Win32 DebugCLEAN" "flex - Win32 DebugCLEAN" 
!ELSE 
CLEAN :
!ENDIF 
	-@erase "$(INTDIR)\BuildCmd.obj"
	-@erase "$(INTDIR)\BuildCmd.sbr"
	-@erase "$(INTDIR)\c51.res"
	-@erase "$(INTDIR)\C51asm.obj"
	-@erase "$(INTDIR)\C51asm.sbr"
	-@erase "$(INTDIR)\C51ast.obj"
	-@erase "$(INTDIR)\C51ast.sbr"
	-@erase "$(INTDIR)\C51BBlock.obj"
	-@erase "$(INTDIR)\C51BBlock.sbr"
	-@erase "$(INTDIR)\C51bitv.obj"
	-@erase "$(INTDIR)\C51bitv.sbr"
	-@erase "$(INTDIR)\C51cflow.obj"
	-@erase "$(INTDIR)\C51cflow.sbr"
	-@erase "$(INTDIR)\C51cse.obj"
	-@erase "$(INTDIR)\C51cse.sbr"
	-@erase "$(INTDIR)\C51debug.obj"
	-@erase "$(INTDIR)\C51debug.sbr"
	-@erase "$(INTDIR)\C51dflow.obj"
	-@erase "$(INTDIR)\C51dflow.sbr"
	-@erase "$(INTDIR)\C51dwarf2.obj"
	-@erase "$(INTDIR)\C51dwarf2.sbr"
	-@erase "$(INTDIR)\C51err.obj"
	-@erase "$(INTDIR)\C51err.sbr"
	-@erase "$(INTDIR)\C51glue.obj"
	-@erase "$(INTDIR)\C51glue.sbr"
	-@erase "$(INTDIR)\C51hasht.obj"
	-@erase "$(INTDIR)\C51hasht.sbr"
	-@erase "$(INTDIR)\C51icode.obj"
	-@erase "$(INTDIR)\C51icode.sbr"
	-@erase "$(INTDIR)\C51label.obj"
	-@erase "$(INTDIR)\C51label.sbr"
	-@erase "$(INTDIR)\C51lex.obj"
	-@erase "$(INTDIR)\C51lex.sbr"
	-@erase "$(INTDIR)\C51loop.obj"
	-@erase "$(INTDIR)\C51loop.sbr"
	-@erase "$(INTDIR)\C51lrange.obj"
	-@erase "$(INTDIR)\C51lrange.sbr"
	-@erase "$(INTDIR)\C51macro.obj"
	-@erase "$(INTDIR)\C51macro.sbr"
	-@erase "$(INTDIR)\C51main.obj"
	-@erase "$(INTDIR)\C51main.sbr"
	-@erase "$(INTDIR)\C51mem.obj"
	-@erase "$(INTDIR)\C51mem.sbr"
	-@erase "$(INTDIR)\C51opt.obj"
	-@erase "$(INTDIR)\C51opt.sbr"
	-@erase "$(INTDIR)\C51peeph.obj"
	-@erase "$(INTDIR)\C51peeph.sbr"
	-@erase "$(INTDIR)\C51ptropt.obj"
	-@erase "$(INTDIR)\C51ptropt.sbr"
	-@erase "$(INTDIR)\C51set.obj"
	-@erase "$(INTDIR)\C51set.sbr"
	-@erase "$(INTDIR)\C51symt.obj"
	-@erase "$(INTDIR)\C51symt.sbr"
	-@erase "$(INTDIR)\C51util.obj"
	-@erase "$(INTDIR)\C51util.sbr"
	-@erase "$(INTDIR)\C51val.obj"
	-@erase "$(INTDIR)\C51val.sbr"
	-@erase "$(INTDIR)\c51y.obj"
	-@erase "$(INTDIR)\c51y.sbr"
	-@erase "$(INTDIR)\cdbFile.obj"
	-@erase "$(INTDIR)\cdbFile.sbr"
	-@erase "$(INTDIR)\dbuf.obj"
	-@erase "$(INTDIR)\dbuf.sbr"
	-@erase "$(INTDIR)\dbuf_string.obj"
	-@erase "$(INTDIR)\dbuf_string.sbr"
	-@erase "$(INTDIR)\MySystem.obj"
	-@erase "$(INTDIR)\MySystem.sbr"
	-@erase "$(INTDIR)\NewAlloc.obj"
	-@erase "$(INTDIR)\NewAlloc.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\C51.bsc"
	-@erase "$(OUTDIR)\c51.pdb"
	-@erase "..\..\..\bin\c51.exe"
	-@erase "..\..\..\bin\c51.ilk"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MLd /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "..\support\util" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\c51.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\C51.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\BuildCmd.sbr" \
	"$(INTDIR)\C51asm.sbr" \
	"$(INTDIR)\C51ast.sbr" \
	"$(INTDIR)\C51BBlock.sbr" \
	"$(INTDIR)\C51bitv.sbr" \
	"$(INTDIR)\C51cflow.sbr" \
	"$(INTDIR)\C51cse.sbr" \
	"$(INTDIR)\C51debug.sbr" \
	"$(INTDIR)\C51dflow.sbr" \
	"$(INTDIR)\C51dwarf2.sbr" \
	"$(INTDIR)\C51err.sbr" \
	"$(INTDIR)\C51glue.sbr" \
	"$(INTDIR)\C51hasht.sbr" \
	"$(INTDIR)\C51icode.sbr" \
	"$(INTDIR)\C51label.sbr" \
	"$(INTDIR)\C51lex.sbr" \
	"$(INTDIR)\C51loop.sbr" \
	"$(INTDIR)\C51lrange.sbr" \
	"$(INTDIR)\C51macro.sbr" \
	"$(INTDIR)\C51main.sbr" \
	"$(INTDIR)\C51mem.sbr" \
	"$(INTDIR)\C51opt.sbr" \
	"$(INTDIR)\C51peeph.sbr" \
	"$(INTDIR)\C51ptropt.sbr" \
	"$(INTDIR)\C51set.sbr" \
	"$(INTDIR)\C51symt.sbr" \
	"$(INTDIR)\C51util.sbr" \
	"$(INTDIR)\C51val.sbr" \
	"$(INTDIR)\c51y.sbr" \
	"$(INTDIR)\cdbFile.sbr" \
	"$(INTDIR)\dbuf.sbr" \
	"$(INTDIR)\dbuf_string.sbr" \
	"$(INTDIR)\MySystem.sbr" \
	"$(INTDIR)\NewAlloc.sbr"

"$(OUTDIR)\C51.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=mcs51\Debug\port.lib /nologo /subsystem:console /incremental:yes /pdb:"$(OUTDIR)\c51.pdb" /debug /machine:I386 /out:"..\..\..\bin\c51.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\BuildCmd.obj" \
	"$(INTDIR)\C51asm.obj" \
	"$(INTDIR)\C51ast.obj" \
	"$(INTDIR)\C51BBlock.obj" \
	"$(INTDIR)\C51bitv.obj" \
	"$(INTDIR)\C51cflow.obj" \
	"$(INTDIR)\C51cse.obj" \
	"$(INTDIR)\C51debug.obj" \
	"$(INTDIR)\C51dflow.obj" \
	"$(INTDIR)\C51dwarf2.obj" \
	"$(INTDIR)\C51err.obj" \
	"$(INTDIR)\C51glue.obj" \
	"$(INTDIR)\C51hasht.obj" \
	"$(INTDIR)\C51icode.obj" \
	"$(INTDIR)\C51label.obj" \
	"$(INTDIR)\C51lex.obj" \
	"$(INTDIR)\C51loop.obj" \
	"$(INTDIR)\C51lrange.obj" \
	"$(INTDIR)\C51macro.obj" \
	"$(INTDIR)\C51main.obj" \
	"$(INTDIR)\C51mem.obj" \
	"$(INTDIR)\C51opt.obj" \
	"$(INTDIR)\C51peeph.obj" \
	"$(INTDIR)\C51ptropt.obj" \
	"$(INTDIR)\C51set.obj" \
	"$(INTDIR)\C51symt.obj" \
	"$(INTDIR)\C51util.obj" \
	"$(INTDIR)\C51val.obj" \
	"$(INTDIR)\c51y.obj" \
	"$(INTDIR)\cdbFile.obj" \
	"$(INTDIR)\dbuf.obj" \
	"$(INTDIR)\dbuf_string.obj" \
	"$(INTDIR)\MySystem.obj" \
	"$(INTDIR)\NewAlloc.obj" \
	"$(INTDIR)\c51.res" \
	".\mcs51\Debug\port.lib"

"..\..\..\bin\c51.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "C51 - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release

!IF "$(RECURSE)" == "0" 

ALL : "..\..\..\bin\c51.exe"

!ELSE 

ALL : "flex - Win32 Release" "mcs51 - Win32 Release" "yacc - Win32 Release" "..\..\..\bin\c51.exe"

!ENDIF 

!IF "$(RECURSE)" == "1" 
CLEAN :"yacc - Win32 ReleaseCLEAN" "mcs51 - Win32 ReleaseCLEAN" "flex - Win32 ReleaseCLEAN" 
!ELSE 
CLEAN :
!ENDIF 
	-@erase "$(INTDIR)\BuildCmd.obj"
	-@erase "$(INTDIR)\c51.res"
	-@erase "$(INTDIR)\C51asm.obj"
	-@erase "$(INTDIR)\C51ast.obj"
	-@erase "$(INTDIR)\C51BBlock.obj"
	-@erase "$(INTDIR)\C51bitv.obj"
	-@erase "$(INTDIR)\C51cflow.obj"
	-@erase "$(INTDIR)\C51cse.obj"
	-@erase "$(INTDIR)\C51debug.obj"
	-@erase "$(INTDIR)\C51dflow.obj"
	-@erase "$(INTDIR)\C51dwarf2.obj"
	-@erase "$(INTDIR)\C51err.obj"
	-@erase "$(INTDIR)\C51glue.obj"
	-@erase "$(INTDIR)\C51hasht.obj"
	-@erase "$(INTDIR)\C51icode.obj"
	-@erase "$(INTDIR)\C51label.obj"
	-@erase "$(INTDIR)\C51lex.obj"
	-@erase "$(INTDIR)\C51loop.obj"
	-@erase "$(INTDIR)\C51lrange.obj"
	-@erase "$(INTDIR)\C51macro.obj"
	-@erase "$(INTDIR)\C51main.obj"
	-@erase "$(INTDIR)\C51mem.obj"
	-@erase "$(INTDIR)\C51opt.obj"
	-@erase "$(INTDIR)\C51peeph.obj"
	-@erase "$(INTDIR)\C51ptropt.obj"
	-@erase "$(INTDIR)\C51set.obj"
	-@erase "$(INTDIR)\C51symt.obj"
	-@erase "$(INTDIR)\C51util.obj"
	-@erase "$(INTDIR)\C51val.obj"
	-@erase "$(INTDIR)\c51y.obj"
	-@erase "$(INTDIR)\cdbFile.obj"
	-@erase "$(INTDIR)\dbuf.obj"
	-@erase "$(INTDIR)\dbuf_string.obj"
	-@erase "$(INTDIR)\MySystem.obj"
	-@erase "$(INTDIR)\NewAlloc.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "..\..\..\bin\c51.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /ML /W3 /GX /O2 /I "." /I ".." /I "..\support\util" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\c51.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\C51.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=mcs51\Release\port.lib /nologo /subsystem:console /pdb:none /machine:I386 /out:"..\..\..\bin\c51.exe" 
LINK32_OBJS= \
	"$(INTDIR)\BuildCmd.obj" \
	"$(INTDIR)\C51asm.obj" \
	"$(INTDIR)\C51ast.obj" \
	"$(INTDIR)\C51BBlock.obj" \
	"$(INTDIR)\C51bitv.obj" \
	"$(INTDIR)\C51cflow.obj" \
	"$(INTDIR)\C51cse.obj" \
	"$(INTDIR)\C51debug.obj" \
	"$(INTDIR)\C51dflow.obj" \
	"$(INTDIR)\C51dwarf2.obj" \
	"$(INTDIR)\C51err.obj" \
	"$(INTDIR)\C51glue.obj" \
	"$(INTDIR)\C51hasht.obj" \
	"$(INTDIR)\C51icode.obj" \
	"$(INTDIR)\C51label.obj" \
	"$(INTDIR)\C51lex.obj" \
	"$(INTDIR)\C51loop.obj" \
	"$(INTDIR)\C51lrange.obj" \
	"$(INTDIR)\C51macro.obj" \
	"$(INTDIR)\C51main.obj" \
	"$(INTDIR)\C51mem.obj" \
	"$(INTDIR)\C51opt.obj" \
	"$(INTDIR)\C51peeph.obj" \
	"$(INTDIR)\C51ptropt.obj" \
	"$(INTDIR)\C51set.obj" \
	"$(INTDIR)\C51symt.obj" \
	"$(INTDIR)\C51util.obj" \
	"$(INTDIR)\C51val.obj" \
	"$(INTDIR)\c51y.obj" \
	"$(INTDIR)\cdbFile.obj" \
	"$(INTDIR)\dbuf.obj" \
	"$(INTDIR)\dbuf_string.obj" \
	"$(INTDIR)\MySystem.obj" \
	"$(INTDIR)\NewAlloc.obj" \
	"$(INTDIR)\c51.res" \
	".\mcs51\Release\port.lib"

"..\..\..\bin\c51.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("C51.dep")
!INCLUDE "C51.dep"
!ELSE 
!MESSAGE Warning: cannot find "C51.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "C51 - Win32 Debug" || "$(CFG)" == "C51 - Win32 Release"
SOURCE=..\support\Util\BuildCmd.c

!IF  "$(CFG)" == "C51 - Win32 Debug"


"$(INTDIR)\BuildCmd.obj"	"$(INTDIR)\BuildCmd.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "C51 - Win32 Release"


"$(INTDIR)\BuildCmd.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\C51.lex

!IF  "$(CFG)" == "C51 - Win32 Debug"

InputPath=.\C51.lex
USERDEP__C51_L="c51y.h"	

".\C51lex.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)" $(USERDEP__C51_L)
	<<tempfile.bat 
	@echo off 
	..\..\tools\bin\flex  -oc51lex.c c51.lex
<< 
	

!ELSEIF  "$(CFG)" == "C51 - Win32 Release"

InputPath=.\C51.lex
USERDEP__C51_L="c51y.h"	

".\C51lex.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)" $(USERDEP__C51_L)
	<<tempfile.bat 
	@echo off 
	..\..\tools\bin\flex  -oc51lex.c c51.lex
<< 
	

!ENDIF 

SOURCE=.\Resource\c51.rc

!IF  "$(CFG)" == "C51 - Win32 Debug"


"$(INTDIR)\c51.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) /l 0x409 /fo"$(INTDIR)\c51.res" /i "Resource" /d "_DEBUG" $(SOURCE)


!ELSEIF  "$(CFG)" == "C51 - Win32 Release"


"$(INTDIR)\c51.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) /l 0x409 /fo"$(INTDIR)\c51.res" /i "Resource" /d "NDEBUG" $(SOURCE)


!ENDIF 

SOURCE=.\C51asm.c

!IF  "$(CFG)" == "C51 - Win32 Debug"


"$(INTDIR)\C51asm.obj"	"$(INTDIR)\C51asm.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "C51 - Win32 Release"


"$(INTDIR)\C51asm.obj" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\C51ast.c

!IF  "$(CFG)" == "C51 - Win32 Debug"


"$(INTDIR)\C51ast.obj"	"$(INTDIR)\C51ast.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "C51 - Win32 Release"


"$(INTDIR)\C51ast.obj" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\C51BBlock.c

!IF  "$(CFG)" == "C51 - Win32 Debug"


"$(INTDIR)\C51BBlock.obj"	"$(INTDIR)\C51BBlock.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "C51 - Win32 Release"


"$(INTDIR)\C51BBlock.obj" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\C51bitv.c

!IF  "$(CFG)" == "C51 - Win32 Debug"


"$(INTDIR)\C51bitv.obj"	"$(INTDIR)\C51bitv.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "C51 - Win32 Release"


"$(INTDIR)\C51bitv.obj" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\C51cflow.c

!IF  "$(CFG)" == "C51 - Win32 Debug"


"$(INTDIR)\C51cflow.obj"	"$(INTDIR)\C51cflow.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "C51 - Win32 Release"


"$(INTDIR)\C51cflow.obj" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\C51cse.c

!IF  "$(CFG)" == "C51 - Win32 Debug"


"$(INTDIR)\C51cse.obj"	"$(INTDIR)\C51cse.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "C51 - Win32 Release"


"$(INTDIR)\C51cse.obj" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\C51debug.c

!IF  "$(CFG)" == "C51 - Win32 Debug"


"$(INTDIR)\C51debug.obj"	"$(INTDIR)\C51debug.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "C51 - Win32 Release"


"$(INTDIR)\C51debug.obj" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\C51dflow.c

!IF  "$(CFG)" == "C51 - Win32 Debug"


"$(INTDIR)\C51dflow.obj"	"$(INTDIR)\C51dflow.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "C51 - Win32 Release"


"$(INTDIR)\C51dflow.obj" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\C51dwarf2.c

!IF  "$(CFG)" == "C51 - Win32 Debug"


"$(INTDIR)\C51dwarf2.obj"	"$(INTDIR)\C51dwarf2.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "C51 - Win32 Release"


"$(INTDIR)\C51dwarf2.obj" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\C51err.c

!IF  "$(CFG)" == "C51 - Win32 Debug"


"$(INTDIR)\C51err.obj"	"$(INTDIR)\C51err.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "C51 - Win32 Release"


"$(INTDIR)\C51err.obj" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\C51glue.c

!IF  "$(CFG)" == "C51 - Win32 Debug"


"$(INTDIR)\C51glue.obj"	"$(INTDIR)\C51glue.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "C51 - Win32 Release"


"$(INTDIR)\C51glue.obj" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\C51hasht.c

!IF  "$(CFG)" == "C51 - Win32 Debug"


"$(INTDIR)\C51hasht.obj"	"$(INTDIR)\C51hasht.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "C51 - Win32 Release"


"$(INTDIR)\C51hasht.obj" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\C51icode.c

!IF  "$(CFG)" == "C51 - Win32 Debug"


"$(INTDIR)\C51icode.obj"	"$(INTDIR)\C51icode.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "C51 - Win32 Release"


"$(INTDIR)\C51icode.obj" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\C51label.c

!IF  "$(CFG)" == "C51 - Win32 Debug"


"$(INTDIR)\C51label.obj"	"$(INTDIR)\C51label.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "C51 - Win32 Release"


"$(INTDIR)\C51label.obj" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\C51lex.c

!IF  "$(CFG)" == "C51 - Win32 Debug"


"$(INTDIR)\C51lex.obj"	"$(INTDIR)\C51lex.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "C51 - Win32 Release"


"$(INTDIR)\C51lex.obj" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\C51loop.c

!IF  "$(CFG)" == "C51 - Win32 Debug"


"$(INTDIR)\C51loop.obj"	"$(INTDIR)\C51loop.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "C51 - Win32 Release"


"$(INTDIR)\C51loop.obj" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\C51lrange.c

!IF  "$(CFG)" == "C51 - Win32 Debug"


"$(INTDIR)\C51lrange.obj"	"$(INTDIR)\C51lrange.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "C51 - Win32 Release"


"$(INTDIR)\C51lrange.obj" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\C51macro.c

!IF  "$(CFG)" == "C51 - Win32 Debug"


"$(INTDIR)\C51macro.obj"	"$(INTDIR)\C51macro.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "C51 - Win32 Release"


"$(INTDIR)\C51macro.obj" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\C51main.c

!IF  "$(CFG)" == "C51 - Win32 Debug"


"$(INTDIR)\C51main.obj"	"$(INTDIR)\C51main.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "C51 - Win32 Release"


"$(INTDIR)\C51main.obj" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\C51mem.c

!IF  "$(CFG)" == "C51 - Win32 Debug"


"$(INTDIR)\C51mem.obj"	"$(INTDIR)\C51mem.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "C51 - Win32 Release"


"$(INTDIR)\C51mem.obj" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\C51opt.c

!IF  "$(CFG)" == "C51 - Win32 Debug"


"$(INTDIR)\C51opt.obj"	"$(INTDIR)\C51opt.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "C51 - Win32 Release"


"$(INTDIR)\C51opt.obj" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\C51peeph.c

!IF  "$(CFG)" == "C51 - Win32 Debug"


"$(INTDIR)\C51peeph.obj"	"$(INTDIR)\C51peeph.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "C51 - Win32 Release"


"$(INTDIR)\C51peeph.obj" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\C51ptropt.c

!IF  "$(CFG)" == "C51 - Win32 Debug"


"$(INTDIR)\C51ptropt.obj"	"$(INTDIR)\C51ptropt.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "C51 - Win32 Release"


"$(INTDIR)\C51ptropt.obj" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\C51set.c

!IF  "$(CFG)" == "C51 - Win32 Debug"


"$(INTDIR)\C51set.obj"	"$(INTDIR)\C51set.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "C51 - Win32 Release"


"$(INTDIR)\C51set.obj" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\C51symt.c

!IF  "$(CFG)" == "C51 - Win32 Debug"


"$(INTDIR)\C51symt.obj"	"$(INTDIR)\C51symt.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "C51 - Win32 Release"


"$(INTDIR)\C51symt.obj" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\C51util.c

!IF  "$(CFG)" == "C51 - Win32 Debug"


"$(INTDIR)\C51util.obj"	"$(INTDIR)\C51util.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "C51 - Win32 Release"


"$(INTDIR)\C51util.obj" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\C51val.c

!IF  "$(CFG)" == "C51 - Win32 Debug"


"$(INTDIR)\C51val.obj"	"$(INTDIR)\C51val.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "C51 - Win32 Release"


"$(INTDIR)\C51val.obj" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\c51y.c

!IF  "$(CFG)" == "C51 - Win32 Debug"


"$(INTDIR)\c51y.obj"	"$(INTDIR)\c51y.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "C51 - Win32 Release"


"$(INTDIR)\c51y.obj" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\cdbFile.c

!IF  "$(CFG)" == "C51 - Win32 Debug"


"$(INTDIR)\cdbFile.obj"	"$(INTDIR)\cdbFile.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "C51 - Win32 Release"


"$(INTDIR)\cdbFile.obj" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=..\support\Util\dbuf.c

!IF  "$(CFG)" == "C51 - Win32 Debug"


"$(INTDIR)\dbuf.obj"	"$(INTDIR)\dbuf.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "C51 - Win32 Release"


"$(INTDIR)\dbuf.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\support\Util\dbuf_string.c

!IF  "$(CFG)" == "C51 - Win32 Debug"


"$(INTDIR)\dbuf_string.obj"	"$(INTDIR)\dbuf_string.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "C51 - Win32 Release"


"$(INTDIR)\dbuf_string.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\support\Util\MySystem.c

!IF  "$(CFG)" == "C51 - Win32 Debug"


"$(INTDIR)\MySystem.obj"	"$(INTDIR)\MySystem.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "C51 - Win32 Release"


"$(INTDIR)\MySystem.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\support\Util\NewAlloc.c

!IF  "$(CFG)" == "C51 - Win32 Debug"


"$(INTDIR)\NewAlloc.obj"	"$(INTDIR)\NewAlloc.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "C51 - Win32 Release"


"$(INTDIR)\NewAlloc.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

!IF  "$(CFG)" == "C51 - Win32 Debug"

"yacc - Win32 Debug" : 
   cd "."
   $(MAKE) /$(MAKEFLAGS) /F .\yacc.mak CFG="yacc - Win32 Debug" 
   cd "."

"yacc - Win32 DebugCLEAN" : 
   cd "."
   $(MAKE) /$(MAKEFLAGS) /F .\yacc.mak CFG="yacc - Win32 Debug" RECURSE=1 CLEAN 
   cd "."

!ELSEIF  "$(CFG)" == "C51 - Win32 Release"

"yacc - Win32 Release" : 
   cd "."
   $(MAKE) /$(MAKEFLAGS) /F .\yacc.mak CFG="yacc - Win32 Release" 
   cd "."

"yacc - Win32 ReleaseCLEAN" : 
   cd "."
   $(MAKE) /$(MAKEFLAGS) /F .\yacc.mak CFG="yacc - Win32 Release" RECURSE=1 CLEAN 
   cd "."

!ENDIF 

!IF  "$(CFG)" == "C51 - Win32 Debug"

!ELSEIF  "$(CFG)" == "C51 - Win32 Release"

!ENDIF 

!IF  "$(CFG)" == "C51 - Win32 Debug"

"mcs51 - Win32 Debug" : 
   cd ".\mcs51"
   $(MAKE) /$(MAKEFLAGS) /F .\mcs51.mak CFG="mcs51 - Win32 Debug" 
   cd ".."

"mcs51 - Win32 DebugCLEAN" : 
   cd ".\mcs51"
   $(MAKE) /$(MAKEFLAGS) /F .\mcs51.mak CFG="mcs51 - Win32 Debug" RECURSE=1 CLEAN 
   cd ".."

!ELSEIF  "$(CFG)" == "C51 - Win32 Release"

"mcs51 - Win32 Release" : 
   cd ".\mcs51"
   $(MAKE) /$(MAKEFLAGS) /F .\mcs51.mak CFG="mcs51 - Win32 Release" 
   cd ".."

"mcs51 - Win32 ReleaseCLEAN" : 
   cd ".\mcs51"
   $(MAKE) /$(MAKEFLAGS) /F .\mcs51.mak CFG="mcs51 - Win32 Release" RECURSE=1 CLEAN 
   cd ".."

!ENDIF 

!IF  "$(CFG)" == "C51 - Win32 Debug"

"flex - Win32 Debug" : 
   cd "\Source\call51\Source\tools\flex"
   $(MAKE) /$(MAKEFLAGS) /F .\flex.mak CFG="flex - Win32 Debug" 
   cd "..\..\C51\src"

"flex - Win32 DebugCLEAN" : 
   cd "\Source\call51\Source\tools\flex"
   $(MAKE) /$(MAKEFLAGS) /F .\flex.mak CFG="flex - Win32 Debug" RECURSE=1 CLEAN 
   cd "..\..\C51\src"

!ELSEIF  "$(CFG)" == "C51 - Win32 Release"

"flex - Win32 Release" : 
   cd "\Source\call51\Source\tools\flex"
   $(MAKE) /$(MAKEFLAGS) /F .\flex.mak CFG="flex - Win32 Release" 
   cd "..\..\C51\src"

"flex - Win32 ReleaseCLEAN" : 
   cd "\Source\call51\Source\tools\flex"
   $(MAKE) /$(MAKEFLAGS) /F .\flex.mak CFG="flex - Win32 Release" RECURSE=1 CLEAN 
   cd "..\..\C51\src"

!ENDIF 


!ENDIF 

