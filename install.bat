@echo off

set /p "PATH"="TOCHANGE"

cd %PATH%

if exist "C:\Program Files\CMake\bin" (
    goto build_project
    
) else (
    echo CMake is not installed.
    choice /c yn /m "Do you want to install it? "
    if errorlevel 2 (
        echo Exiting the build.
        exit
    ) else if errorlevel 1 (

        if not exist cmake-install.msi (
            powershell -Command "Invoke-WebRequest -Uri 'https://github.com/Kitware/CMake/releases/download/v3.27.6/cmake-3.27.6-windows-x86_64.msi' -OutFile 'cmake-install.msi'"
        )

        start /wait msiexec.exe /I cmake-install.msi /passive

        timeout /t 2
        start /wait powershell -Command "[System.Environment]::SetEnvironmentVariable('Path', $env:Path + ';C:\Program Files\CMake\bin', [System.EnvironmentVariableTarget]::Machine)"
        
        echo CMake is installed.
        
    ) else (
        echo Invalid choice
    )
)

:build_project
start /wait powershell -Command "Start-Process -FilePath 'YOUR_PATH_TO_REUTILS' + '\build.bat'"
