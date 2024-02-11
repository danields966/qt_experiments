# qt-experiments

For Windows XP and older Linux versions a better option is Qt 5.6

## Qt 5.6 static build instructions for Linux:

### Raspberry OS

    sudo apt update
    sudo apt upgrade
    
    sudo apt install git
    
    sudo apt install libxcb1 libxcb1-dev libx11-xcb1 libx11-xcb-dev libxcb-keysyms1 libxcb-keysyms1-dev libxcb-image0 libxcb-image0-dev libxcb-shm0 libxcb-shm0-dev libxcb-icccm4 libxcb-icccm4-dev libxcb-sync-dev libxcb-xfixes0-dev libxrender-dev libxcb-shape0-dev libxcb-randr0-dev libxcb-render-util0 libxcb-render-util0-dev libxcb-glx0-dev
    
    sudo apt install libfreetype6 libfreetype6-dev libfontconfig1-dev
    
    git clone -b 5.6 https://code.qt.io/qt/qt5.git
    mv qt5 Qt-5.6
    cd Qt-5.6
    git clone -b 5.6 https://code.qt.io/qt/qtbase.git
    
    git submodule foreach --recursive "git clean -dfx"
    
    ./configure -prefix "/usr/local/Qt-5.6-release" -static -release -opensource -confirm-license -fontconfig -system-freetype -no-cups -no-dbus -no-gif -no-iconv -no-icu -no-opengl -no-openssl -no-openvg -no-qml-debug -no-sql-sqlite -qt-harfbuzz -qt-libjpeg -qt-libpng -qt-pcre -qt-xcb -qt-xkbcommon-x11 -qt-zlib -nomake examples -nomake tests -skip qt3d -skip qtactiveqt -skip qtandroidextras -skip qtconnectivity -skip qtdeclarative -skip qtdoc -skip qtdocgallery -skip qtenginio -skip qtfeedback -skip qtgraphicaleffects -skip qtimageformats -skip qtlocation -skip qtmacextras -skip qtmultimedia -skip qtpim -skip qtpurchasing -skip qtqa -skip qtquick1 -skip qtquickcontrols -skip qtquickcontrols2 -skip qtrepotools -skip qtscript -skip qtsensors -skip qtserialbus -skip qtserialport -skip qtsvg -skip qtsystems -skip qttools -skip qttranslations -skip qtwayland -skip qtwebchannel -skip qtwebengine -skip qtwebkit -skip qtwebkit-examples -skip qtwebsockets -skip qtwebview -skip qtwinextras -skip qtx11extras -skip qtxmlpatterns
    
    gmake
    sudo rm -rf /usr/local/Qt-5.6-release/
    sudo gmake install

Example of shared requirements of compiled binary with this setup:

    ldd qt-experiments

Output:

	linux-vdso.so.1 (0x00007fffa84e8000)
	libX11-xcb.so.1 => /lib/aarch64-linux-gnu/libX11-xcb.so.1 (0x00007fffa7470000)
	libSM.so.6 => /lib/aarch64-linux-gnu/libSM.so.6 (0x00007fffa7450000)
	libICE.so.6 => /lib/aarch64-linux-gnu/libICE.so.6 (0x00007fffa7420000)
	libxcb.so.1 => /lib/aarch64-linux-gnu/libxcb.so.1 (0x00007fffa73d0000)
	libX11.so.6 => /lib/aarch64-linux-gnu/libX11.so.6 (0x00007fffa7270000)
	libfontconfig.so.1 => /lib/aarch64-linux-gnu/libfontconfig.so.1 (0x00007fffa7200000)
	libfreetype.so.6 => /lib/aarch64-linux-gnu/libfreetype.so.6 (0x00007fffa7120000)
	libstdc++.so.6 => /lib/aarch64-linux-gnu/libstdc++.so.6 (0x00007fffa6f00000)
	libm.so.6 => /lib/aarch64-linux-gnu/libm.so.6 (0x00007fffa6e60000)
	libgcc_s.so.1 => /lib/aarch64-linux-gnu/libgcc_s.so.1 (0x00007fffa6e20000)
	libc.so.6 => /lib/aarch64-linux-gnu/libc.so.6 (0x00007fffa6c60000)
	libuuid.so.1 => /lib/aarch64-linux-gnu/libuuid.so.1 (0x00007fffa6c30000)
	/lib/ld-linux-aarch64.so.1 (0x00007fffa84b0000)
	libbsd.so.0 => /lib/aarch64-linux-gnu/libbsd.so.0 (0x00007fffa6bf0000)
	libXau.so.6 => /lib/aarch64-linux-gnu/libXau.so.6 (0x00007fffa6bd0000)
	libXdmcp.so.6 => /lib/aarch64-linux-gnu/libXdmcp.so.6 (0x00007fffa6bb0000)
	libexpat.so.1 => /lib/aarch64-linux-gnu/libexpat.so.1 (0x00007fffa6b60000)
	libz.so.1 => /lib/aarch64-linux-gnu/libz.so.1 (0x00007fffa6b20000)
	libpng16.so.16 => /lib/aarch64-linux-gnu/libpng16.so.16 (0x00007fffa6ac0000)
	libbrotlidec.so.1 => /lib/aarch64-linux-gnu/libbrotlidec.so.1 (0x00007fffa6a90000)
	libmd.so.0 => /lib/aarch64-linux-gnu/libmd.so.0 (0x00007fffa6a60000)
	libbrotlicommon.so.1 => /lib/aarch64-linux-gnu/libbrotlicommon.so.1 (0x00007fffa6a20000)
