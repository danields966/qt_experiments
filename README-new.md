# qt-experiments

## Qt 5.15 static build instructions for Linux:

### Ubuntu 16.04

Install requirements:

    sudo apt update
    sudo apt upgrade
    
    sudo apt install git p7zip-full qtcreator
    
    sudo apt install libgl1-mesa-dev:i386 libglu1-mesa-dev:i386 mesa-common-dev:i386 libglu1-mesa-dev:i386 libdrm-dev:i386 libxdamage-dev:i386 libglapi-mesa:i386 libglapi-mesa:i386 libxext6:i386 libxxf86vm-dev:i386 libc6-dev:i386 libssl-dev:i386 libfontconfig1-dev:i386 libfreetype6-dev:i386 libx11-dev:i386 libx11-xcb-dev:i386 libxext-dev:i386 libxfixes-dev:i386 libxi-dev:i386 libxrender-dev:i386 libxcb1-dev:i386 libxcb-glx0-dev:i386 libxcb-keysyms1-dev:i386 libxcb-image0-dev:i386 libxcb-shm0-dev:i386 libxcb-icccm4-dev:i386 libxcb-sync-dev:i386 libxcb-xfixes0-dev:i386 libxcb-shape0-dev:i386 libxcb-randr0-dev:i386 libxcb-render-util0-dev:i386 libxcb-util-dev:i386 libxcb-xinerama0:i386 libxcb-xinerama0-dev:i386 libxcb-xkb-dev:i386 libxkbcommon-dev:i386 libxkbcommon-x11-dev:i386 libpulse-dev:i386 libasound2-dev:i386 libgstreamer1.0-dev:i386 libgstreamer-plugins-base1.0-dev:i386 libwayland-dev:i386

Clone Qt 5.15:

    git clone -b 5.15 https://code.qt.io/qt/qt5.git
    mv qt5 Qt-5.15
    cd Qt-5.15
    git clone -b 5.15 https://code.qt.io/qt/qtbase.git

Or:

    wget http://danields966.ru:9724/Qt-5.15.7z
    7z x Qt-5.15.7z
    cd Qt-5.15

Apply patch to remove xinerama:

    cd ..
    git clone -b testing https://github.com/danields966/qt-experiments.git
    cp qt-experiments/remove-xinerama.patch Qt-5.15/qtbase/
    cd Qt-5.15/qtbase
    git apply remove-xinerama.patch
    cd ..

Compile Qt:

    git submodule foreach --recursive "git clean -dfx"
    
    ./configure -v -prefix "/usr/local/Qt-5.15-release" -platform linux-g++-64 -static -optimize-size -ltcg -release -opensource -confirm-license -fontconfig -system-freetype -bundled-xcb-xinput -nomake examples -nomake tests -nomake tools -no-cups -no-dbus -no-gif -no-iconv -no-icu -no-opengl -no-openssl -no-openvg -no-pch -no-sql-sqlite -make libs -qt-harfbuzz -qt-libjpeg -qt-libpng -qt-pcre -qt-zlib -skip wayland -skip qt3d -skip qtactiveqt -skip qtandroidextras -skip qtcharts -skip qtconnectivity -skip qtdatavis3d -skip qtdeclarative -skip qtdoc -skip qtdocgallery -skip qtfeedback -skip qtgamepad -skip qtgraphicaleffects -skip qtimageformats -skip qtlocation -skip qtlottie -skip qtmacextras -skip qtmultimedia -skip qtnetworkauth -skip qtpim -skip qtpurchasing -skip qtqa -skip qtquick3d -skip qtquickcontrols -skip qtquickcontrols2 -skip qtquicktimeline -skip qtremoteobjects -skip qtrepotools -skip qtscript -skip qtscxml -skip qtsensors -skip qtserialbus -skip qtserialport -skip qtspeech -skip qtsvg -skip qtsystems -skip qttools -skip qttranslations -skip qtvirtualkeyboard -skip qtwayland -skip qtwebchannel -skip qtwebengine -skip qtwebglplugin -skip qtwebsockets -skip qtwebview -skip qtwinextras -skip qtx11extras -skip qtxmlpatterns
    
    make
    sudo rm -rf /usr/local/Qt-5.15-release/
    sudo make install

For x86_64 just replace configure argument `-platform linux-g++-32` to `-platform linux-g++-64`

Example of shared requirements of compiled binary with this setup:

    ldd qt-experiments

Output:

    linux-vdso.so.1 =>  (0x00007fff0317c000)
    libpthread.so.0 => /lib/x86_64-linux-gnu/libpthread.so.0 (0x00007f89fba76000)
    libstdc++.so.6 => /usr/lib/x86_64-linux-gnu/libstdc++.so.6 (0x00007f89fb6f4000)
    libm.so.6 => /lib/x86_64-linux-gnu/libm.so.6 (0x00007f89fb3eb000)
    libgcc_s.so.1 => /lib/x86_64-linux-gnu/libgcc_s.so.1 (0x00007f89fb1d5000)
    libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007f89fae0b000)
    libfontconfig.so.1 => /usr/lib/x86_64-linux-gnu/libfontconfig.so.1 (0x00007f89fabc8000)
    libfreetype.so.6 => /usr/lib/x86_64-linux-gnu/libfreetype.so.6 (0x00007f89fa91e000)
    libxcb-icccm.so.4 => /usr/lib/x86_64-linux-gnu/libxcb-icccm.so.4 (0x00007f89fa719000)
    libxcb-image.so.0 => /usr/lib/x86_64-linux-gnu/libxcb-image.so.0 (0x00007f89fa514000)
    libxcb-shm.so.0 => /usr/lib/x86_64-linux-gnu/libxcb-shm.so.0 (0x00007f89fa310000)
    libxcb-keysyms.so.1 => /usr/lib/x86_64-linux-gnu/libxcb-keysyms.so.1 (0x00007f89fa10d000)
    libxcb-randr.so.0 => /usr/lib/x86_64-linux-gnu/libxcb-randr.so.0 (0x00007f89f9eff000)
    libxcb-render-util.so.0 => /usr/lib/x86_64-linux-gnu/libxcb-render-util.so.0 (0x00007f89f9cfb000)
    libxcb-sync.so.1 => /usr/lib/x86_64-linux-gnu/libxcb-sync.so.1 (0x00007f89f9af4000)
    libxcb-xfixes.so.0 => /usr/lib/x86_64-linux-gnu/libxcb-xfixes.so.0 (0x00007f89f98ec000)
    libxcb-render.so.0 => /usr/lib/x86_64-linux-gnu/libxcb-render.so.0 (0x00007f89f96e2000)
    libxcb-shape.so.0 => /usr/lib/x86_64-linux-gnu/libxcb-shape.so.0 (0x00007f89f94de000)
    libxcb-xkb.so.1 => /usr/lib/x86_64-linux-gnu/libxcb-xkb.so.1 (0x00007f89f92c3000)
    libxcb.so.1 => /usr/lib/x86_64-linux-gnu/libxcb.so.1 (0x00007f89f90a1000)
    libxkbcommon-x11.so.0 => /usr/lib/x86_64-linux-gnu/libxkbcommon-x11.so.0 (0x00007f89f8e99000)
    libxkbcommon.so.0 => /usr/lib/x86_64-linux-gnu/libxkbcommon.so.0 (0x00007f89f8c5a000)
    libdl.so.2 => /lib/x86_64-linux-gnu/libdl.so.2 (0x00007f89f8a56000)
    libglib-2.0.so.0 => /lib/x86_64-linux-gnu/libglib-2.0.so.0 (0x00007f89f8745000)
    /lib64/ld-linux-x86-64.so.2 (0x00007f89fbc93000)
    libexpat.so.1 => /lib/x86_64-linux-gnu/libexpat.so.1 (0x00007f89f851c000)
    libz.so.1 => /lib/x86_64-linux-gnu/libz.so.1 (0x00007f89f8302000)
    libpng12.so.0 => /lib/x86_64-linux-gnu/libpng12.so.0 (0x00007f89f80dd000)
    libxcb-util.so.1 => /usr/lib/x86_64-linux-gnu/libxcb-util.so.1 (0x00007f89f7ed7000)
    libXau.so.6 => /usr/lib/x86_64-linux-gnu/libXau.so.6 (0x00007f89f7cd3000)
    libXdmcp.so.6 => /usr/lib/x86_64-linux-gnu/libXdmcp.so.6 (0x00007f89f7acd000)
    libpcre.so.3 => /lib/x86_64-linux-gnu/libpcre.so.3 (0x00007f89f785d000)

## Qt 5.15 static build instructions for Windows 11 (MinGW 8.1.0):

Download, unpack and add to PATH compiler MinGW `i686-8.1.0-release-posix-dwarf-rt_v6-rev0`, then

Clone Qt 5.15:

    git clone -b 5.15 https://code.qt.io/qt/qt5.git
    ren qt5 "Qt-5.15"
    cd Qt-5.15
    git clone -b 5.15 https://code.qt.io/qt/qtbase.git

Or:

    $ProgressPreference = "SilentlyContinue"
    $QtDistro = "Qt-5.15"
    $QtDistro7z = "$QtDistro.7z"
    Invoke-WebRequest "http://danields966.ru:9724/$QtDistro7z" -OutFile "$QtDistro7z"
    & 'C:\Program Files\7-Zip\7z.exe' x $QtDistro7z -o"."
    cd Qt-5.15

Compile Qt:

    git submodule foreach --recursive "git clean -dfx"
    
    ./configure -v -prefix "C:\Qt\Qt-5.15-debug-and-release" -platform win32-g++ -static -optimize-size -static-runtime -debug-and-release -opensource -confirm-license -nomake examples -nomake tests -nomake tools -no-angle -no-cups -no-dbus -no-fontconfig -no-gif -no-iconv -no-icu -no-incredibuild-xge -no-opengl -no-openssl -no-openvg -no-pch -no-sql-sqlite -no-ssl -make libs -qt-freetype -qt-harfbuzz -qt-libjpeg -qt-libpng -qt-pcre -qt-zlib -skip qt3d -skip qtactiveqt -skip qtandroidextras -skip qtcharts -skip qtconnectivity -skip qtdatavis3d -skip qtdeclarative -skip qtdoc -skip qtdocgallery -skip qtfeedback -skip qtgamepad -skip qtgraphicaleffects -skip qtimageformats -skip qtlocation -skip qtlottie -skip qtmacextras -skip qtmultimedia -skip qtnetworkauth -skip qtpim -skip qtpurchasing -skip qtqa -skip qtquick3d -skip qtquickcontrols -skip qtquickcontrols2 -skip qtquicktimeline -skip qtremoteobjects -skip qtrepotools -skip qtscript -skip qtscxml -skip qtsensors -skip qtserialbus -skip qtserialport -skip qtspeech -skip qtsvg -skip qtsystems -skip qttools -skip qttranslations -skip qtvirtualkeyboard -skip qtwayland -skip qtwebchannel -skip qtwebengine -skip qtwebglplugin -skip qtwebsockets -skip qtwebview -skip qtwinextras -skip qtx11extras -skip qtxmlpatterns
    
    mingw32-make
    mingw32-make install

For x86_64 compilation all instructions are the same, just replace compiler to `x86_64-8.1.0-release-posix-seh-rt_v6-rev0`
