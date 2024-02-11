# qt-experiments

### FreeBSD 14.0

Install Xorg and Xfce for better appearance:

    pkg install xorg
    echo "kern.vty=vt" >> /boot/loader.conf
    
    pkg install drm-kmod
    echo "kld_list=\"i915kms\"" >> /etc/rc.conf
    
    pkg install xfce
    echo "exec /usr/local/bin/startxfce4 --with-ck-launch" > ~/.xinitrc
    startx

Compile Qt (GCC 12.2.0, perl 5.36.3):

    pkg install git gcc nano curl wget
    
    git clone -b 5.6 https://code.qt.io/qt/qt5.git
    mv qt5 Qt-5.6
    cd Qt-5.6
    git clone -b 5.6 https://code.qt.io/qt/qtbase.git
    
    git submodule foreach --recursive "git clean -dfx"
    
    ./configure -prefix "/usr/local/Qt-5.6-release" -static -platform freebsd-g++ -release -opensource -confirm-license -fontconfig -system-freetype -no-cups -no-dbus -no-gif -no-iconv -no-icu -no-opengl -no-openssl -no-openvg -no-pch -no-qml-debug -no-sql-sqlite -qt-harfbuzz -qt-libjpeg -qt-libpng -qt-pcre -qt-xcb -qt-xkbcommon-x11 -qt-zlib -nomake examples -nomake tests  -skip qt3d -skip qtactiveqt -skip qtandroidextras -skip qtconnectivity -skip qtdeclarative -skip qtdoc -skip qtdocgallery -skip qtenginio -skip qtfeedback -skip qtgraphicaleffects -skip qtimageformats -skip qtlocation -skip qtmacextras -skip qtmultimedia -skip qtpim -skip qtpurchasing -skip qtqa -skip qtquick1 -skip qtquickcontrols -skip qtquickcontrols2 -skip qtrepotools -skip qtscript -skip qtsensors -skip qtserialbus -skip qtserialport -skip qtsvg -skip qtsystems -skip qttools -skip qttranslations -skip qtwayland -skip qtwebchannel -skip qtwebengine -skip qtwebkit -skip qtwebkit-examples -skip qtwebsockets -skip qtwebview -skip qtwinextras -skip qtx11extras -skip qtxmlpatterns
    
    make
    sudo make install

Deps:

    libX11.so.6 => /usr/local/lib/libX11.so.6 (0x384e4ce07000)
    libX11-xcb.so.1 => /usr/local/lib/libX11-xcb.so.1 (0x384e4dca6000)
    libXi.so.6 => /usr/local/lib/libXi.so.6 (0x384e4f091000)
    libxcb.so.1 => /usr/local/lib/libxcb.so.1 (0x384e4e7e8000)
    libfontconfig.so.1 => /usr/local/lib/libfontconfig.so.1 (0x384e4fea8000)
    libfreetype.so.6 => /usr/local/lib/libfreetype.so.6 (0x384e50d98000)
    libexecinfo.so.1 => /usr/lib/libexecinfo.so.1 (0x384e513b7000)
    libstdc++.so.6 => /usr/local/lib/gcc12/libstdc++.so.6 (0x384e53000000)
    libm.so.5 => /lib/libm.so.5 (0x384e5190b000)
    libgcc_s.so.1 => /lib/libgcc_s.so.1 (0x384e525ab000)
    libthr.so.3 => /lib/libthr.so.3 (0x384e540f6000)
    libc.so.7 => /lib/libc.so.7 (0x384e54594000)
    libXext.so.6 => /usr/local/lib/libXext.so.6 (0x384e55d7e000)
    libXau.so.6 => /usr/local/lib/libXau.so.6 (0x384e556fa000)
    libXdmcp.so.6 => /usr/local/lib/libXdmcp.so.6 (0x384e579b2000)
    libexpat.so.1 => /usr/local/lib/libexpat.so.1 (0x384e5613c000)
    libz.so.6 => /lib/libz.so.6 (0x384e56609000)
    libbz2.so.4 => /usr/lib/libbz2.so.4 (0x384e57288000)
    libpng16.so.16 => /usr/local/lib/libpng16.so.16 (0x384e582d6000)
    libbrotlidec.so.1 => /usr/local/lib/libbrotlidec.so.1 (0x384e597db000)
    libelf.so.2 => /lib/libelf.so.2 (0x384e58412000)
    libbrotlicommon.so.1 => /usr/local/lib/libbrotlicommon.so.1 (0x384e58d3a000)
    [vdso] (0x384e4cba2000)
