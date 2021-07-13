@echo off

echo Crea directorio para proyectos de software
mkdir software
del /f /q software\*.bat
echo Crea directorio con los programas
rmdir /s /q software\soft
mkdir software\soft
echo Crea directorio para descargas
rmdir /s /q software\download
mkdir software\download
echo Crea directorio de trabajo
mkdir software\workspace


echo Descarga ficheros
cd .\software\download
curl -o msys2-x86_64-20200903.exe https://repo.msys2.org/distrib/x86_64/msys2-x86_64-20200903.exe
curl -o eclipse-cpp-2020-06-R-win32-x86_64.zip http://mirror.dkm.cz/eclipse/technology/epp/downloads/release/2020-06/R/eclipse-cpp-2020-06-R-win32-x86_64.zip
curl -o openjdk-14.0.2_windows-x64_bin.zip https://download.java.net/java/GA/jdk14.0.2/205943a0976c4ed48cb16f1043c5c647/12/GPL/openjdk-14.0.2_windows-x64_bin.zip


echo Extrae eclipse
cd ..\soft
tar -xf ..\download\eclipse-cpp-2020-06-R-win32-x86_64.zip

echo Extrae java
tar -xf ..\download\openjdk-14.0.2_windows-x64_bin.zip


echo ************************************ ATENCION ***********************************
echo Se abrira una ventana adicional
echo PONER ESTE DIRECTORIO EN: 
echo Especifique el directorio en el que se instalara MSYS2 64bit.
echo ---------------------------------------------------------------------------------------
echo %CD%\msys64
echo ---------------------------------------------------------------------------------------

echo Inicia msys
..\download\msys2-x86_64-20200903.exe
 


echo crea scripts
 
echo set MINGW_HOME=%CD%\msys64\mingw64> eclipse.bat
echo set MSYS_HOME= %CD%\msys64>> eclipse.bat
echo set PATH=%CD%\jdk-14.0.2\bin;%CD%\msys64\usr\bin;%CD%\msys64\mingw64\bin;%PATH%>> eclipse.bat
echo java -version  >> eclipse.bat
echo cd %CD%\..  >> eclipse.bat
echo %CD%\eclipse\eclipse.exe  >> eclipse.bat

echo set MINGW_HOME=%CD%\msys64\mingw64> msys.bat
echo set MSYS_HOME= %CD%\msys64>> msys.bat
echo set PATH=%CD%\jdk-14.0.2\bin;%CD%\msys64\usr\bin;%CD%\msys64\mingw64\bin;%PATH%>> msys.bat
echo %CD%\msys64\msys2_shell.cmd  >> msys.bat

cmd /C ".\msys64\msys2_shell.cmd -lc 'exit' "
echo IMPORTANT -- Wait until the MSYS2 window finishs
pause

cmd /C ".\msys64\msys2_shell.cmd -lc 'pacman --noconfirm  -Syuu --disable-download-timeout;exit' "
echo IMPORTANT -- Wait until the MSYS2 window finishs
pause

cmd /C ".\msys64\msys2_shell.cmd -lc 'pacman --noconfirm  -Syuu --disable-download-timeout; exit' "
echo IMPORTANT -- Wait until the MSYS2 window finishs
pause

cmd /C ".\msys64\msys2_shell.cmd -lc 'pacman --noconfirm  -Syuu --disable-download-timeout; exit' "
echo IMPORTANT -- Wait until the MSYS2 window finishs
pause

mkdir msys64\home\develop
echo mkdir msys64\home\develop
echo echo ++++ WORKING - This step takes a lot of time ! > msys64\home\develop\script.sh
echo pacman --noconfirm  -S --disable-download-timeout mingw-w64-i686-toolchain  ^&^>^> install.log >> msys64\home\develop\script.sh
echo echo 1 2 3 4 5 12 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56  ^|  pacman   --noconfirm -S --disable-download-timeout base-devel  >> msys64\home\develop\script.sh
echo pacman --noconfirm -S --disable-download-timeout mingw-w64-x86_64-cmake   ^&^>^> install.log >> msys64\home\develop\script.sh
echo pacman --noconfirm -S --disable-download-timeout mingw-w64-x86_64-ffmpeg  mingw-w64-x86_64-python-numpy   ^&^>^> install.log >> msys64\home\develop\script.sh
echo pacman --noconfirm -S --disable-download-timeout mingw-w64-x86_64-gcc   ^&^>^> install.log >> msys64\home\develop\script.sh
echo pacman --noconfirm -S --disable-download-timeout mingw-w64-x86_64-gdb   ^&^>^> install.log >> msys64\home\develop\script.sh
echo pacman --noconfirm -S --disable-download-timeout mingw-w64-x86_64-python-pytest   ^&^>^> install.log >> msys64\home\develop\script.sh
echo pacman --noconfirm -S --disable-download-timeout mingw64/mingw-w64-x86_64-opencv  ^&^>^> install.log >> msys64\home\develop\script.sh
echo pacman --noconfirm -S --disable-download-timeout mingw64/mingw-w64-x86_64-ninja   ^&^>^> install.log >> msys64\home\develop\script.sh
echo pacman --noconfirm -S --disable-download-timeout mingw64/mingw-w64-x86_64-dlfcn   ^&^>^> install.log >> msys64\home\develop\script.sh
echo pacman --noconfirm -S --disable-download-timeout mingw-w64-x86_64-opencl-icd-git mingw-w64-x86_64-opencl-headers   ^&^>^> install.log >> msys64\home\develop\script.sh
echo pacman --noconfirm -S --disable-download-timeout mingw-w64-x86_64-gtest mingw-w64-x86_64-benchmark mingw-w64-x86_64-grpc   ^&^>^> install.log >> msys64\home\develop\script.sh
echo pacman --noconfirm -Syuu --disable-download-timeout ^&^>^> install.log >> msys64\home\develop\script.sh
echo echo  END_INSTALL_SCRIPT ^&^>^> install.log >> msys64\home\develop\script.sh


echo Init script execution in a different window -- IT TAKES A LOT OF TIME!!!!
cmd /C ".\msys64\msys2_shell.cmd -lc 'cd /home/develop; source script.sh; exit' "
echo IMPORTANT -- Wait until the MSYS2 window finishs
pause

echo With COMMAND, check that the last line is "******** END_INSTALL_SCRIPT ********"
echo COMAND: more software\soft\msys64\home\develop\install.log
cd ../..