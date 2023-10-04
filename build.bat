@echo off

if exist "C:\Program Files (x86)\CMake\bin\" (
    echo "CMake is already installed."
    goto build_project
) else (
    echo "CMake is not installed."
    choice /c yn /m "Do you want to install it? "
    if errorlevel 2 (
        echo "Exiting the script."
        exit
    ) else if errorlevel 1 (
        :: powershell -Command "Invoke-WebRequest -Uri 'https://github.com/Kitware/CMake/releases/download/v3.27.6/cmake-3.27.6-windows-x86_64.msi' -OutFile 'cmake-install.msi'"
        msiexec /i .\cmake-install.msi /QN
        echo "CMake is installed."
    ) else (
        echo "Invalid choice."
        exit
    )
)

:build_project
mkdir build
cd build
cmake -G "Visual Studio 17 2022" ..
start reutils.sln