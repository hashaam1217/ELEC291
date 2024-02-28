# Microsoft Developer Studio Project File - Name="C51" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=C51 - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "C51.mak".
!MESSAGE 
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

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "C51 - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /I ".." /I "..\support\util" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FR /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "..\support\util" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FR /FD /GZ /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 mcs51\Debug\port.lib z80\Debug\port.lib avr\Debug\port.lib ds390\Debug\port.lib pic\Debug\port.lib /nologo /subsystem:console /debug /machine:I386 /out:"..\..\..\bin\c51.exe" /pdbtype:sept
# ADD LINK32 mcs51\Debug\port.lib /nologo /subsystem:console /debug /machine:I386 /out:"..\..\..\bin\c51.exe" /pdbtype:sept
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "C51 - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /ML /W3 /GX /O2 /I ".." /I "..\support\util" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /FD /c
# ADD CPP /nologo /ML /W3 /GX /O2 /I "." /I ".." /I "..\support\util" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 mcs51\Release\port.lib z80\Release\port.lib avr\Release\port.lib ds390\Release\port.lib pic\Release\port.lib /nologo /subsystem:console /pdb:none /machine:I386 /out:"..\..\bin\c51.exe"
# ADD LINK32 mcs51\Release\port.lib /nologo /subsystem:console /pdb:none /machine:I386 /out:"..\..\..\bin\c51.exe"

!ENDIF 

# Begin Target

# Name "C51 - Win32 Debug"
# Name "C51 - Win32 Release"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\support\Util\BuildCmd.c
# End Source File
# Begin Source File

SOURCE=.\C51.lex

!IF  "$(CFG)" == "C51 - Win32 Debug"

USERDEP__C51_L="c51y.h"	
# Begin Custom Build
InputPath=.\C51.lex

"C51lex.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	..\..\tools\bin\flex  -oc51lex.c c51.lex

# End Custom Build

!ELSEIF  "$(CFG)" == "C51 - Win32 Release"

USERDEP__C51_L="c51y.h"	
# Begin Custom Build
InputPath=.\C51.lex

"C51lex.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	..\..\tools\bin\flex  -oc51lex.c c51.lex

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Resource\c51.rc
# End Source File
# Begin Source File

SOURCE=.\C51asm.c
# End Source File
# Begin Source File

SOURCE=.\C51ast.c
# End Source File
# Begin Source File

SOURCE=.\C51BBlock.c
# End Source File
# Begin Source File

SOURCE=.\C51bitv.c
# End Source File
# Begin Source File

SOURCE=.\C51cflow.c
# End Source File
# Begin Source File

SOURCE=.\C51cse.c
# End Source File
# Begin Source File

SOURCE=.\C51debug.c
# End Source File
# Begin Source File

SOURCE=.\C51dflow.c
# End Source File
# Begin Source File

SOURCE=.\C51dwarf2.c
# End Source File
# Begin Source File

SOURCE=.\C51err.c
# End Source File
# Begin Source File

SOURCE=.\C51glue.c
# End Source File
# Begin Source File

SOURCE=.\C51hasht.c
# End Source File
# Begin Source File

SOURCE=.\C51icode.c
# End Source File
# Begin Source File

SOURCE=.\C51label.c
# End Source File
# Begin Source File

SOURCE=.\C51lex.c
# End Source File
# Begin Source File

SOURCE=.\C51loop.c
# End Source File
# Begin Source File

SOURCE=.\C51lrange.c
# End Source File
# Begin Source File

SOURCE=.\C51macro.c
# End Source File
# Begin Source File

SOURCE=.\C51main.c
# End Source File
# Begin Source File

SOURCE=.\C51mem.c
# End Source File
# Begin Source File

SOURCE=.\C51opt.c
# End Source File
# Begin Source File

SOURCE=.\C51peeph.c
# End Source File
# Begin Source File

SOURCE=.\C51ptropt.c
# End Source File
# Begin Source File

SOURCE=.\C51set.c
# End Source File
# Begin Source File

SOURCE=.\C51symt.c
# End Source File
# Begin Source File

SOURCE=.\C51util.c
# End Source File
# Begin Source File

SOURCE=.\C51val.c
# End Source File
# Begin Source File

SOURCE=.\c51y.c
# End Source File
# Begin Source File

SOURCE=.\cdbFile.c
# End Source File
# Begin Source File

SOURCE=..\support\Util\dbuf.c
# End Source File
# Begin Source File

SOURCE=..\support\Util\dbuf_string.c
# End Source File
# Begin Source File

SOURCE=..\support\Util\MySystem.c
# End Source File
# Begin Source File

SOURCE=..\support\Util\NewAlloc.c
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\c51.h
# End Source File
# Begin Source File

SOURCE=.\C51asm.h
# End Source File
# Begin Source File

SOURCE=.\C51ast.h
# End Source File
# Begin Source File

SOURCE=.\C51BBlock.h
# End Source File
# Begin Source File

SOURCE=.\C51bitv.h
# End Source File
# Begin Source File

SOURCE=.\C51cflow.h
# End Source File
# Begin Source File

SOURCE=.\C51cse.h
# End Source File
# Begin Source File

SOURCE=.\C51dflow.h
# End Source File
# Begin Source File

SOURCE=.\C51dwarf2.h
# End Source File
# Begin Source File

SOURCE=.\C51err.h
# End Source File
# Begin Source File

SOURCE=.\C51globl.h
# End Source File
# Begin Source File

SOURCE=.\C51glue.h
# End Source File
# Begin Source File

SOURCE=.\C51hasht.h
# End Source File
# Begin Source File

SOURCE=.\C51icode.h
# End Source File
# Begin Source File

SOURCE=.\C51label.h
# End Source File
# Begin Source File

SOURCE=.\C51loop.h
# End Source File
# Begin Source File

SOURCE=.\C51lrange.h
# End Source File
# Begin Source File

SOURCE=.\C51mem.h
# End Source File
# Begin Source File

SOURCE=.\C51opt.h
# End Source File
# Begin Source File

SOURCE=.\C51peeph.h
# End Source File
# Begin Source File

SOURCE=.\C51ptropt.h
# End Source File
# Begin Source File

SOURCE=.\C51set.h
# End Source File
# Begin Source File

SOURCE=.\C51symt.h
# End Source File
# Begin Source File

SOURCE=.\C51util.h
# End Source File
# Begin Source File

SOURCE=.\C51val.h
# End Source File
# Begin Source File

SOURCE=.\c51y.h
# End Source File
# Begin Source File

SOURCE=.\common.h
# End Source File
# Begin Source File

SOURCE=..\support\Util\dbuf.h
# End Source File
# Begin Source File

SOURCE=..\support\Util\dbuf_string.h
# End Source File
# Begin Source File

SOURCE=..\support\Util\MySystem.h
# End Source File
# Begin Source File

SOURCE=..\support\Util\newalloc.h
# End Source File
# Begin Source File

SOURCE=.\port.h
# End Source File
# Begin Source File

SOURCE=.\spawn.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\Resource\c51.ico
# End Source File
# End Target
# End Project
