@echo off
set compiler=g++

rem Compile the source files
%compiler% scripts_mgmt/main.cpp headers/colors.h -o runner

rem Check if compilation was successful
if %errorlevel%==0 (
    echo Compilation Runner successful
) else (
    echo Compilation Runner failed
)

pause