# Microsoft Developer Studio Generated NMAKE File, Based on mcs51a.dsp
!IF "$(CFG)" == ""
CFG=mcs51a - Win32 Release
!MESSAGE No configuration specified. Defaulting to mcs51a - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "mcs51a - Win32 Debug" && "$(CFG)" != "mcs51a - Win32 Release"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "mcs51a.mak" CFG="mcs51a - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "mcs51a - Win32 Debug" (based on "Win32 (x86) Generic Project")
!MESSAGE "mcs51a - Win32 Release" (based on "Win32 (x86) Generic Project")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

OUTDIR=.
INTDIR=.

!IF "$(RECURSE)" == "0" 

ALL : ".\peeph.rul" 

!ELSE 

ALL : "gawk - Win32 Debug" ".\peeph.rul" 

!ENDIF 

!IF "$(RECURSE)" == "1" 
CLEAN :"gawk - Win32 DebugCLEAN" 
!ELSE 
CLEAN :
!ENDIF 
	-@erase 
	-@erase "peeph.rul"

!IF  "$(CFG)" == "mcs51a - Win32 Debug"

MTL=midl.exe
MTL_PROJ=

!ELSEIF  "$(CFG)" == "mcs51a - Win32 Release"

MTL=midl.exe
MTL_PROJ=

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("mcs51a.dep")
!INCLUDE "mcs51a.dep"
!ELSE 
!MESSAGE Warning: cannot find "mcs51a.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "mcs51a - Win32 Debug" || "$(CFG)" == "mcs51a - Win32 Release"

!IF  "$(CFG)" == "mcs51a - Win32 Debug"

"gawk - Win32 Debug" : 
   cd "\Source\call51\Source\Tools\gawk"
   $(MAKE) /$(MAKEFLAGS) /F .\gawk.mak CFG="gawk - Win32 Debug" 
   cd "..\..\C51\src\mcs51"

"gawk - Win32 DebugCLEAN" : 
   cd "\Source\call51\Source\Tools\gawk"
   $(MAKE) /$(MAKEFLAGS) /F .\gawk.mak CFG="gawk - Win32 Debug" RECURSE=1 CLEAN 
   cd "..\..\C51\src\mcs51"

!ELSEIF  "$(CFG)" == "mcs51a - Win32 Release"

"gawk - Win32 Release" : 
   cd "\Source\call51\Source\Tools\gawk"
   $(MAKE) /$(MAKEFLAGS) /F .\gawk.mak CFG="gawk - Win32 Release" 
   cd "..\..\C51\src\mcs51"

"gawk - Win32 ReleaseCLEAN" : 
   cd "\Source\call51\Source\Tools\gawk"
   $(MAKE) /$(MAKEFLAGS) /F .\gawk.mak CFG="gawk - Win32 Release" RECURSE=1 CLEAN 
   cd "..\..\C51\src\mcs51"

!ENDIF 

SOURCE=.\peeph.def

!IF  "$(CFG)" == "mcs51a - Win32 Debug"

InputPath=.\peeph.def

"$(INTDIR)\peeph.rul" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	..\..\..\Tools\bin\gawk -f ../C51peeph.awk $(InputPath) >peeph.rul
<< 
	

!ELSEIF  "$(CFG)" == "mcs51a - Win32 Release"

InputPath=.\peeph.def

"$(INTDIR)\peeph.rul" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	..\..\..\Tools\bin\gawk -f ../C51peeph.awk $(InputPath) >peeph.rul
<< 
	

!ENDIF 


!ENDIF 

