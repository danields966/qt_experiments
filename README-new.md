# qt-experiments

## Qt 5.15 static build instructions for Linux:

### Ubuntu 16.04

### Warning: This setup is not working yet

    sudo apt update
    sudo apt upgrade
    
    sudo apt install git
    
    sudo apt install libxcb1 libxcb1-dev libx11-xcb1 libx11-xcb-dev libxcb-keysyms1 libxcb-keysyms1-dev libxcb-image0 libxcb-image0-dev libxcb-shm0 libxcb-shm0-dev libxcb-icccm4 libxcb-icccm4-dev libxcb-sync-dev libxcb-xfixes0-dev libxrender-dev libxcb-shape0-dev libxcb-randr0-dev libxcb-render-util0 libxcb-render-util0-dev libxcb-glx0-dev
    
    sudo apt install libfreetype6 libfreetype6-dev libfontconfig1-dev
    
    git clone -b 5.15 https://code.qt.io/qt/qt5.git
    mv qt5 Qt-5.15
    cd Qt-5.15
    git clone -b 5.15 https://code.qt.io/qt/qtbase.git
    
    git submodule foreach --recursive "git clean -dfx"
    
    ./configure -prefix "/usr/local/Qt-5.15-release" -static -optimize-size -platform linux-g++-32 -release -opensource -confirm-license -fontconfig -system-freetype -no-cups -no-dbus -no-gif -no-iconv -no-icu -no-opengl -no-openssl -no-openvg -no-sql-sqlite -qt-harfbuzz -qt-libjpeg -qt-libpng -qt-pcre -qt-xcb -qt-xkbcommon-x11 -qt-zlib -nomake examples -nomake tests -skip qt3d -skip qtactiveqt -skip qtandroidextras -skip qtcharts -skip qtconnectivity -skip qtdatavis3d -skip qtdeclarative -skip qtdoc -skip qtdocgallery -skip qtfeedback -skip qtgamepad -skip qtgraphicaleffects -skip qtimageformats -skip qtlocation -skip qtlottie -skip qtmacextras -skip qtmultimedia -skip qtnetworkauth -skip qtpim -skip qtpurchasing -skip qtqa -skip qtquick3d -skip qtquickcontrols -skip qtquickcontrols2 -skip qtquicktimeline -skip qtremoteobjects -skip qtrepotools -skip qtscript -skip qtscxml -skip qtsensors -skip qtserialbus -skip qtserialport -skip qtspeech -skip qtsvg -skip qtsystems -skip qttools -skip qttranslations -skip qtvirtualkeyboard -skip qtwayland -skip qtwebchannel -skip qtwebengine -skip qtwebglplugin -skip qtwebsockets -skip qtwebview -skip qtwinextras -skip qtx11extras -skip qtxmlpatterns
    
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

    git clone -b 5.15 https://code.qt.io/qt/qt5.git
    ren qt5 "Qt-5.15"
    cd Qt-5.15
    git clone -b 5.15 https://code.qt.io/qt/qtbase.git
    
    git submodule foreach --recursive "git clean -dfx"
    
    ./configure -prefix "C:\Qt\Qt-5.15-debug-and-release" -static -optimize-size -static-runtime -platform win32-g++ -debug-and-release -opensource -confirm-license -no-angle -no-cups -no-dbus -no-fontconfig -no-gif -no-iconv -no-icu -no-incredibuild-xge -no-opengl -no-openssl -no-openvg -no-sql-sqlite -no-ssl -qt-freetype -qt-harfbuzz -qt-libjpeg -qt-libpng -qt-pcre -qt-zlib -nomake examples -nomake tests -skip qt3d -skip qtactiveqt -skip qtandroidextras -skip qtcharts -skip qtconnectivity -skip qtdatavis3d -skip qtdeclarative -skip qtdoc -skip qtdocgallery -skip qtfeedback -skip qtgamepad -skip qtgraphicaleffects -skip qtimageformats -skip qtlocation -skip qtlottie -skip qtmacextras -skip qtmultimedia -skip qtnetworkauth -skip qtpim -skip qtpurchasing -skip qtqa -skip qtquick3d -skip qtquickcontrols -skip qtquickcontrols2 -skip qtquicktimeline -skip qtremoteobjects -skip qtrepotools -skip qtscript -skip qtscxml -skip qtsensors -skip qtserialbus -skip qtserialport -skip qtspeech -skip qtsvg -skip qtsystems -skip qttools -skip qttranslations -skip qtvirtualkeyboard -skip qtwayland -skip qtwebchannel -skip qtwebengine -skip qtwebglplugin -skip qtwebsockets -skip qtwebview -skip qtwinextras -skip qtx11extras -skip qtxmlpatterns
    
    mingw32-make
    mingw32-make install

For x86_64 compilation all instructions are the same, just replace compiler to `x86_64-8.1.0-release-posix-seh-rt_v6-rev0`
