:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
:: CrossIde support batch file for the 8051 port of c51
::
@echo off
::
:: WARNING: This names are case sensitive for crosside
set CodeLoc=0x0000
set ToolDir=c:\source\call51
set Bin=c:\source\call51\bin
set Inc=c:\source\call51\include
set COpt= --use-stdout --model-small --debug -DMONITOR_LOC=%CodeLoc%
set LOpt= --code-loc %CodeLoc% --code-size 0x2000 --xram-loc 0x1f00 --xram-size 0x100 %COpt%
set OOpt=obj

if "%1"=="cc" goto docc
if "%1"=="ld" goto dold
echo Don't know what to do with %1
goto end

::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
:: Compile a C file with c51
::
:docc
echo %2.c:1: Compiling
::echo %Bin%\c51 %COpt% -c %2.c
%Bin%\c51 %COpt% -c %2.c
if errorlevel 1 goto call51error
goto end
:call51error
::This error message is used by crosside to prevent linking
echo **** "%2" has errors! ****
goto end

::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
:: Link object files and libraries using call51
::
:dold
set tgt=%2
echo %tgt%.hex:1: Linking to...
::Read the possible large number of object files
set obj=
:getobj1
shift
if "%2"=="" goto done1
set obj=%obj% %2
goto getobj1
:done1
::
:: The linker
::echo %Bin%\c51 %COpt% %LOpt% %obj%
%Bin%\c51 %COpt% %LOpt% %obj%
echo Done!
goto end

:end

set CodeLoc=
set ToolDir=
set Bin=
set Inc=
set COpt=
set LOpt=
set OOpt=