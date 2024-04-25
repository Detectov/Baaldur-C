@echo off
setlocal

set BUILD_DIR=build

echo Limpiando la carpeta build...
if exist "%BUILD_DIR%" rd /s /q "%BUILD_DIR%"
mkdir "%BUILD_DIR%"
cd "%BUILD_DIR%"

echo Configurando el proyecto con CMake...
cmake -G "Visual Studio 17 2022" ..

if %errorlevel% neq 0 (
    echo Falló la configuración de CMake.
    exit /b %errorlevel%
)

echo Construyendo el proyecto...
cmake --build . --config Release

if %errorlevel% neq 0 (
    echo Falló la construcción del proyecto.
    exit /b %errorlevel%
)

echo Script completado.
pause
endlocal