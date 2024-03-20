@echo off
set compiler=g++

rem Compile the source files
%compiler% main.cpp tui/mainwindow.cpp src/creator.cpp src/settings.cpp src/read_projects.cpp src/check_requrements.cpp  -o main

rem Check if compilation was successful
if %errorlevel%==0 (
    echo Compilation SuperVisor successful
) else (
    echo Compilation SuperVisor failed
)

pause