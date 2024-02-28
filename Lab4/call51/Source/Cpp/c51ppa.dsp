# Microsoft Developer Studio Project File - Name="c51ppa" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Generic Project" 0x010a

CFG=c51ppa - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "c51ppa.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "c51ppa.mak" CFG="c51ppa - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "c51ppa - Win32 Release" (based on "Win32 (x86) Generic Project")
!MESSAGE "c51ppa - Win32 Debug" (based on "Win32 (x86) Generic Project")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
MTL=midl.exe

!IF  "$(CFG)" == "c51ppa - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""

!ELSEIF  "$(CFG)" == "c51ppa - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""

!ENDIF 

# Begin Target

# Name "c51ppa - Win32 Release"
# Name "c51ppa - Win32 Debug"
# Begin Source File

SOURCE=".\auto-host_vc_in.h"

!IF  "$(CFG)" == "c51ppa - Win32 Release"

# Begin Custom Build
InputPath=".\auto-host_vc_in.h"

"auto-host.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy auto-host_vc_in.h auto-host.h > nul

# End Custom Build

!ELSEIF  "$(CFG)" == "c51ppa - Win32 Debug"

# Begin Custom Build
InputPath=".\auto-host_vc_in.h"

"auto-host.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy auto-host_vc_in.h auto-host.h > nul

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\c51pp.opt

!IF  "$(CFG)" == "c51ppa - Win32 Release"

# Begin Custom Build
InputPath=.\c51pp.opt

BuildCmds= \
	..\Tools\bin\gawk -f opt-gather.awk c51pp.opt | ..\Tools\bin\gawk -f opt-functions.awk -f optc-gen.awk -v header_name="config.h system.h options.h" > options.c \
	..\Tools\bin\gawk -f opt-gather.awk c51pp.opt | ..\Tools\bin\gawk -f opt-functions.awk -f opth-gen.awk > options.h \
	

"options.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"options.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "c51ppa - Win32 Debug"

# Begin Custom Build
InputPath=.\c51pp.opt

BuildCmds= \
	..\Tools\bin\gawk -f opt-gather.awk c51pp.opt | ..\Tools\bin\gawk -f opt-functions.awk -f optc-gen.awk -v header_name="config.h system.h options.h" > options.c \
	..\Tools\bin\gawk -f opt-gather.awk c51pp.opt | ..\Tools\bin\gawk -f opt-functions.awk -f opth-gen.awk > options.h \
	

"options.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"options.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF 

# End Source File
# End Target
# End Project
