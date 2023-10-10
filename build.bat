@echo off

cd %~dp0

if exist "C:\Program Files\CMake\bin" (
    goto build_project
) else (
    echo CMake is not installed.
    choice /c yn /m "Do you want to install it? "
    if errorlevel 2 (
        echo Failure: You need to install CMake to build the project.
        pause
        exit
    ) else if errorlevel 1 (
        goto check_Permissions
    )
)

:build_project
if not exist "build" (
    mkdir build 
)
cd build
cmake -G "Visual Studio 16 2019" ..   
start reutils.sln
exit

:install
if not exist cmake-install.msi (
    powershell -Command "Invoke-WebRequest -Uri 'https://github.com/Kitware/CMake/releases/download/v3.27.6/cmake-3.27.6-windows-x86_64.msi' -OutFile 'cmake-install.msi'"
)

:: install CMake
start /wait msiexec.exe /I cmake-install.msi /passive
start /wait powershell -Command "Write-Output 'Configuring the environment variables...'; [System.Environment]::SetEnvironmentVariable('Path', $env:Path + ';C:\Program Files\CMake\bin', [System.EnvironmentVariableTarget]::Machine)"        
del cmake-install.msi

:: Clean up
cls
echo Building the project...

:: Make the build directory
if not exist "build" (
    mkdir build 
)

:: Building the source files
cd build
"C:\Program Files\CMake\bin\cmake.exe" -G "Visual Studio 16 2019" ..   
start reutils.sln
exit

:check_Permissions    
net session >nul 2>&1
if %errorLevel% == 0 (
    goto install
) else (
    echo Failure: You need to run this script as administrator.
    pause
)