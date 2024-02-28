# Microsoft Developer Studio Generated NMAKE File, Based on mcs51.dsp
!IF "$(CFG)" == ""
CFG=mcs51 - Win32 Release
!MESSAGE No configuration specified. Defaulting to mcs51 - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "mcs51 - Win32 Debug" && "$(CFG)" != "mcs51 - Win32 Release"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "mcs51.mak" CFG="mcs51 - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "mcs51 - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "mcs51 - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "mcs51 - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\port.lib" "$(OUTDIR)\mcs51.bsc"

!ELSE 

ALL : "mcs51a - Win32 Debug" "$(OUTDIR)\port.lib" "$(OUTDIR)\mcs51.bsc"

!ENDIF 

!IF "$(RECURSE)" == "1" 
CLEAN :"mcs51a - Win32 DebugCLEAN" 
!ELSE 
CLEAN :
!ENDIF 
	-@erase "$(INTDIR)\gen.obj"
	-@erase "$(INTDIR)\gen.sbr"
	-@erase "$(INTDIR)\main.obj"
	-@erase "$(INTDIR)\main.sbr"
	-@erase "$(INTDIR)\peep.obj"
	-@erase "$(INTDIR)\peep.sbr"
	-@erase "$(INTDIR)\ralloc.obj"
	-@erase "$(INTDIR)\ralloc.sbr"
	-@erase "$(INTDIR)\rtrack.obj"
	-@erase "$(INTDIR)\rtrack.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\mcs51.bsc"
	-@erase "$(OUTDIR)\port.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MLd /W3 /Gm /GX /ZI /Od /I ".." /I "." /I "..\.." /I "..\..\support\util" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /Zm1500 /c 

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
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\mcs51.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\gen.sbr" \
	"$(INTDIR)\main.sbr" \
	"$(INTDIR)\peep.sbr" \
	"$(INTDIR)\ralloc.sbr" \
	"$(INTDIR)\rtrack.sbr"

"$(OUTDIR)\mcs51.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LIB32=link.exe -lib
LIB32_FLAGS=/nologo /out:"$(OUTDIR)\port.lib" 
LIB32_OBJS= \
	"$(INTDIR)\gen.obj" \
	"$(INTDIR)\main.obj" \
	"$(INTDIR)\peep.obj" \
	"$(INTDIR)\ralloc.obj" \
	"$(INTDIR)\rtrack.obj"

"$(OUTDIR)\port.lib" : "$(OUTDIR)" $(DEF_FILE) $(LIB32_OBJS)
    $(LIB32) @<<
  $(LIB32_FLAGS) $(DEF_FLAGS) $(LIB32_OBJS)
<<

!ELSEIF  "$(CFG)" == "mcs51 - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\port.lib"

!ELSE 

ALL : "mcs51a - Win32 Release" "$(OUTDIR)\port.lib"

!ENDIF 

!IF "$(RECURSE)" == "1" 
CLEAN :"mcs51a - Win32 ReleaseCLEAN" 
!ELSE 
CLEAN :
!ENDIF 
	-@erase "$(INTDIR)\gen.obj"
	-@erase "$(INTDIR)\main.obj"
	-@erase "$(INTDIR)\peep.obj"
	-@erase "$(INTDIR)\ralloc.obj"
	-@erase "$(INTDIR)\rtrack.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\port.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /ML /W3 /GX /O2 /I ".." /I "." /I "..\.." /I "..\..\support\util" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /Zm1500 /c 

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
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\mcs51.bsc" 
BSC32_SBRS= \
	
LIB32=link.exe -lib
LIB32_FLAGS=/nologo /out:"$(OUTDIR)\port.lib" 
LIB32_OBJS= \
	"$(INTDIR)\gen.obj" \
	"$(INTDIR)\main.obj" \
	"$(INTDIR)\peep.obj" \
	"$(INTDIR)\ralloc.obj" \
	"$(INTDIR)\rtrack.obj"

"$(OUTDIR)\port.lib" : "$(OUTDIR)" $(DEF_FILE) $(LIB32_OBJS)
    $(LIB32) @<<
  $(LIB32_FLAGS) $(DEF_FLAGS) $(LIB32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("mcs51.dep")
!INCLUDE "mcs51.dep"
!ELSE 
!MESSAGE Warning: cannot find "mcs51.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "mcs51 - Win32 Debug" || "$(CFG)" == "mcs51 - Win32 Release"
SOURCE=.\gen.c

!IF  "$(CFG)" == "mcs51 - Win32 Debug"


"$(INTDIR)\gen.obj"	"$(INTDIR)\gen.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "mcs51 - Win32 Release"


"$(INTDIR)\gen.obj" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\main.c

!IF  "$(CFG)" == "mcs51 - Win32 Debug"


"$(INTDIR)\main.obj"	"$(INTDIR)\main.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "mcs51 - Win32 Release"


"$(INTDIR)\main.obj" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\peep.c

!IF  "$(CFG)" == "mcs51 - Win32 Debug"


"$(INTDIR)\peep.obj"	"$(INTDIR)\peep.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "mcs51 - Win32 Release"


"$(INTDIR)\peep.obj" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\ralloc.c

!IF  "$(CFG)" == "mcs51 - Win32 Debug"


"$(INTDIR)\ralloc.obj"	"$(INTDIR)\ralloc.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "mcs51 - Win32 Release"


"$(INTDIR)\ralloc.obj" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\rtrack.c

!IF  "$(CFG)" == "mcs51 - Win32 Debug"


"$(INTDIR)\rtrack.obj"	"$(INTDIR)\rtrack.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "mcs51 - Win32 Release"


"$(INTDIR)\rtrack.obj" : $(SOURCE) "$(INTDIR)"


!ENDIF 

!IF  "$(CFG)" == "mcs51 - Win32 Debug"

"mcs51a - Win32 Debug" : 
   cd "."
   $(MAKE) /$(MAKEFLAGS) /F .\mcs51a.mak CFG="mcs51a - Win32 Debug" 
   cd "."

"mcs51a - Win32 DebugCLEAN" : 
   cd "."
   $(MAKE) /$(MAKEFLAGS) /F .\mcs51a.mak CFG="mcs51a - Win32 Debug" RECURSE=1 CLEAN 
   cd "."

!ELSEIF  "$(CFG)" == "mcs51 - Win32 Release"

"mcs51a - Win32 Release" : 
   cd "."
   $(MAKE) /$(MAKEFLAGS) /F .\mcs51a.mak CFG="mcs51a - Win32 Release" 
   cd "."

"mcs51a - Win32 ReleaseCLEAN" : 
   cd "."
   $(MAKE) /$(MAKEFLAGS) /F .\mcs51a.mak CFG="mcs51a - Win32 Release" RECURSE=1 CLEAN 
   cd "."

!ENDIF 


!ENDIF 

