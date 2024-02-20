# qt-experiments

## Qt 5.15 static build instructions for Linux:

### Ubuntu 16.04

Install requirements:

    sudo apt update
    sudo apt upgrade
    
    sudo apt install git p7zip-full qtcreator
    
    sudo apt install libgl1-mesa-dev libglu1-mesa-dev mesa-common-dev libglu1-mesa-dev libdrm-dev libxdamage-dev libglapi-mesa libglapi-mesa libxext6 libxxf86vm-dev libc6-dev libssl-dev libfontconfig1-dev libfreetype6-dev libx11-dev libx11-xcb-dev libxext-dev libxfixes-dev libxi-dev libxrender-dev libxcb1-dev libxcb-glx0-dev libxcb-keysyms1-dev libxcb-image0-dev libxcb-shm0-dev libxcb-icccm4-dev libxcb-sync-dev libxcb-xfixes0-dev libxcb-shape0-dev libxcb-randr0-dev libxcb-render-util0-dev libxcb-util-dev libxcb-xinerama0 libxcb-xinerama0-dev libxcb-xkb-dev libxkbcommon-dev libxkbcommon-x11-dev libpulse-dev libasound2-dev libgstreamer1.0-dev libgstreamer-plugins-base1.0-dev libwayland-dev

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

    linux-gate.so.1 =>  (0xb7f43000)
    libX11.so.6 => /usr/lib/i386-linux-gnu/libX11.so.6 (0xb7dde000)
    libX11-xcb.so.1 => /usr/lib/i386-linux-gnu/libX11-xcb.so.1 (0xb7ddb000)
    libxcb.so.1 => /usr/lib/i386-linux-gnu/libxcb.so.1 (0xb7db5000)
    libfontconfig.so.1 => /usr/lib/i386-linux-gnu/libfontconfig.so.1 (0xb7d6c000)
    libfreetype.so.6 => /usr/lib/i386-linux-gnu/libfreetype.so.6 (0xb7cbb000)
    libdl.so.2 => /lib/i386-linux-gnu/libdl.so.2 (0xb7cb6000)
    librt.so.1 => /lib/i386-linux-gnu/librt.so.1 (0xb7cad000)
    libpthread.so.0 => /lib/i386-linux-gnu/libpthread.so.0 (0xb7c90000)
    libstdc++.so.6 => /usr/lib/i386-linux-gnu/libstdc++.so.6 (0xb7b19000)
    libm.so.6 => /lib/i386-linux-gnu/libm.so.6 (0xb7ac3000)
    libgcc_s.so.1 => /lib/i386-linux-gnu/libgcc_s.so.1 (0xb7aa6000)
    libc.so.6 => /lib/i386-linux-gnu/libc.so.6 (0xb78ef000)
    /lib/ld-linux.so.2 (0xb7f45000)
    libXau.so.6 => /usr/lib/i386-linux-gnu/libXau.so.6 (0xb78eb000)
    libXdmcp.so.6 => /usr/lib/i386-linux-gnu/libXdmcp.so.6 (0xb78e4000)
    libexpat.so.1 => /lib/i386-linux-gnu/libexpat.so.1 (0xb78b9000)
    libz.so.1 => /lib/i386-linux-gnu/libz.so.1 (0xb789e000)
    libpng12.so.0 => /lib/i386-linux-gnu/libpng12.so.0 (0xb7873000)

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
