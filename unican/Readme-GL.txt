En la ventana "Programa de instalación de MSYS2 64bit" en "Carpeta de instalación" poner:
C:\Users\mmart\Documents\fit-opti-vis\unican\software\soft\msys64
C:\Users\thales\Documents\fit-opti-vis\unican\software\soft\msys64
C:\Users\Thales\Documents\fit-opti-vis\unican\software\soft\msys64
NOTA: Primero hay que crear la carpeta msys64

Descomprimir CameraServer.zip en software\workspace (software\workspace\CameraServer\example)
Descomprimir RIE.zip en software\soft (software\soft\RIE\include)

Compilar el proyecto
Abrir una consola de MSYS2
cd /c/Users/mmart/Documents/fit-opti-vis/unican/software/workspace/CameraServer
cd /c/Users/thales/Documents/fit-opti-vis/unican/software/workspace/CameraServer
cd /c/Users/Thales/Documents/fit-opti-vis/unican/software/workspace/CameraServer
cp Debug/CameraServer.exe . && ./CameraServer.exe



remote: error: GH001: Large files detected. You may want to try Git Large File Storage - https://git-lfs.github.com.
remote: error: Trace: 7cd367661009260267df5f7d2c54b04cb9416311dd7b02405aa769a9314b1644
remote: error: See http://git.io/iEPt8g for more information.
remote: error: File unican/software/download/eclipse-cpp-2020-06-R-win32-x86_64.zip is 239.02 MB; this exceeds GitHub's file size limit of 100.00 MB
remote: error: File unican/software/download/openjdk-14.0.2_windows-x64_bin.zip is 189.55 MB; this exceeds GitHub's file size limit of 100.00 MB
To github.com:gjlendrino/fit-opti-vis-uc.git