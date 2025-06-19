@echo off
if "%1"=="" (
    echo Usage: run filename.cpp
    goto :eof
)
set filename=%1
set exe=%~n1

g++ -std=c++17 -Wall -o %exe% %filename%
if %errorlevel%==0 (
    %exe%
)
