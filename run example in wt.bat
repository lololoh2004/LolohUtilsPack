@echo off
set "WORK_DIR=%~dp0"
if "%WORK_DIR:~-1%"=="\" set "WORK_DIR=%WORK_DIR:~0,-1%"

wt -p "Command Prompt" -d "%WORK_DIR%" cmd /k "app_example.exe"