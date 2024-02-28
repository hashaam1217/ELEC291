# Microsoft Developer Studio Project File - Name="bison" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=bison - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "bison.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "bison.mak" CFG="bison - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "bison - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "bison - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "bison - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD BASE RSC /l 0x1009 /d "NDEBUG"
# ADD RSC /l 0x1009 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386 /out:"../bin/bison.exe"

!ELSEIF  "$(CFG)" == "bison - Win32 Debug"

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
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD BASE RSC /l 0x1009 /d "_DEBUG"
# ADD RSC /l 0x1009 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /out:"../bin/bison.exe" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "bison - Win32 Release"
# Name "bison - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\alloca.c
# ADD CPP /D "HAVE_STRING_H" /D "HAVE_STDLIB_H"
# End Source File
# Begin Source File

SOURCE=.\allocate.c
# ADD CPP /D "HAVE_STRING_H" /D "HAVE_STDLIB_H"
# End Source File
# Begin Source File

SOURCE=.\closure.c
# ADD CPP /D "HAVE_STRING_H" /D "HAVE_STDLIB_H"
# End Source File
# Begin Source File

SOURCE=.\conflicts.c
# ADD CPP /D "HAVE_STRING_H" /D "HAVE_STDLIB_H"
# End Source File
# Begin Source File

SOURCE=.\derives.c
# ADD CPP /D "HAVE_STRING_H" /D "HAVE_STDLIB_H"
# End Source File
# Begin Source File

SOURCE=.\files.c
# ADD CPP /D "HAVE_STRING_H" /D "HAVE_STDLIB_H"
# End Source File
# Begin Source File

SOURCE=.\getargs.c
# ADD CPP /D "HAVE_STRING_H" /D "HAVE_STDLIB_H"
# End Source File
# Begin Source File

SOURCE=.\getopt.c
# ADD CPP /D "HAVE_STRING_H" /D "HAVE_STDLIB_H"
# End Source File
# Begin Source File

SOURCE=.\getopt1.c
# ADD CPP /D "HAVE_STRING_H" /D "HAVE_STDLIB_H"
# End Source File
# Begin Source File

SOURCE=.\gram.c
# ADD CPP /D "HAVE_STRING_H" /D "HAVE_STDLIB_H"
# End Source File
# Begin Source File

SOURCE=.\lalr.c
# ADD CPP /D "HAVE_STRING_H" /D "HAVE_STDLIB_H"
# End Source File
# Begin Source File

SOURCE=.\lex.c
# ADD CPP /D "HAVE_STRING_H" /D "HAVE_STDLIB_H"
# End Source File
# Begin Source File

SOURCE=.\LR0.c
# ADD CPP /D "HAVE_STRING_H" /D "HAVE_STDLIB_H"
# End Source File
# Begin Source File

SOURCE=.\main.c
# ADD CPP /D "HAVE_STRING_H" /D "HAVE_STDLIB_H"
# End Source File
# Begin Source File

SOURCE=.\nullable.c
# ADD CPP /D "HAVE_STRING_H" /D "HAVE_STDLIB_H"
# End Source File
# Begin Source File

SOURCE=.\output.c
# ADD CPP /D "HAVE_STRING_H" /D "HAVE_STDLIB_H"
# End Source File
# Begin Source File

SOURCE=.\print.c
# ADD CPP /D "HAVE_STRING_H" /D "HAVE_STDLIB_H"
# End Source File
# Begin Source File

SOURCE=.\reader.c
# ADD CPP /D "HAVE_STRING_H" /D "HAVE_STDLIB_H"
# End Source File
# Begin Source File

SOURCE=.\reduce.c
# ADD CPP /D "HAVE_STRING_H" /D "HAVE_STDLIB_H"
# End Source File
# Begin Source File

SOURCE=.\symtab.c
# ADD CPP /D "HAVE_STRING_H" /D "HAVE_STDLIB_H"
# End Source File
# Begin Source File

SOURCE=.\warshall.c
# ADD CPP /D "HAVE_STRING_H" /D "HAVE_STDLIB_H"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\alloc.h
# End Source File
# Begin Source File

SOURCE=.\bison_hairy.h
# End Source File
# Begin Source File

SOURCE=.\bison_simple.h
# End Source File
# Begin Source File

SOURCE=.\files.h
# End Source File
# Begin Source File

SOURCE=.\getopt.h
# End Source File
# Begin Source File

SOURCE=.\gram.h
# End Source File
# Begin Source File

SOURCE=.\lex.h
# End Source File
# Begin Source File

SOURCE=.\machine.h
# End Source File
# Begin Source File

SOURCE=.\state.h
# End Source File
# Begin Source File

SOURCE=.\symtab.h
# End Source File
# Begin Source File

SOURCE=.\system.h
# End Source File
# Begin Source File

SOURCE=.\test.h
# End Source File
# Begin Source File

SOURCE=.\types.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
