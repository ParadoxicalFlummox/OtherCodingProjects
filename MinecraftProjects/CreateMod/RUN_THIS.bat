@echo off
:: Close Minecraft and launcher processes
echo Closing Minecraft and launcher processes...
TASKKILL /IM javaw.exe /F >nul 2>&1 && (echo Closed javaw.exe) || (echo No javaw.exe process found, continuing...)
TASKKILL /IM MinecraftLauncher.exe /F >nul 2>&1 && (echo Closed MinecraftLauncher.exe) || (echo No MinecraftLauncher.exe process found, continuing...)

:: Set variables
set "FABRIC_INSTALLER_URL=https://maven.fabricmc.net/net/fabricmc/fabric-installer/1.0.3/fabric-installer-1.0.3.jar"
set "MINECRAFT_DIR=%APPDATA%\.minecraft"
set "MODS_DIR=%MINECRAFT_DIR%\mods"
set "SHADERS_DIR=%MINECRAFT_DIR%\shaderpacks"

echo Checking for .minecraft folder...
if not exist "%MINECRAFT_DIR%" (
    echo ERROR: Minecraft directory not found at %MINECRAFT_DIR%
    echo Please run the Minecraft launcher at least once before running this installer.
    pause
    goto :eof
)

echo Checking for Fabric installer...
:: Download Fabric installer if not present
if not exist "fabric-installer.jar" (
    echo Downloading Fabric installer...
    powershell -Command "Invoke-WebRequest -Uri '%FABRIC_INSTALLER_URL%' -OutFile fabric-installer.jar"
) else (
    echo Fabric installer already present.
)

echo Opening Fabric installer GUI. Please complete the installation for 1.20.1 and close the window to continue...
start /wait javaw -jar "fabric-installer.jar"

:: Unzip mod zip
if not exist "mods.zip" (
    echo ERROR: mods.zip not found in the current directory.
    echo Please place your mods.zip file here and run the installer again.
    pause
    goto :eof
) else (
    echo Extracting mods.zip to mods directory...
    if not exist "%MODS_DIR%" mkdir "%MODS_DIR%"
    powershell -Command "Expand-Archive -Path 'mods.zip' -DestinationPath '%MODS_DIR%' -Force"
    echo Mods extracted successfully.
)

:: Install Shaders
if not exist "%SHADERS_DIR%" mkdir "%SHADERS_DIR%"
move /y "%CD%\ComplementaryReimagined.zip" "%SHADERS_DIR%\ComplementaryReimagined.zip"

echo Installation complete! You can now launch Minecraft with the Fabric profile.
pause