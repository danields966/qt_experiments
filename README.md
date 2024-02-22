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
    rm -rf /usr/local/Qt-5.6-release/
    make install

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

### FreeBSD 14.0 Qt 5.15

Install Xorg and Xfce for better appearance:

    pkg install xorg
    echo "kern.vty=vt" >> /boot/loader.conf
    
    pkg install drm-kmod
    echo "kld_list=\"i915kms\"" >> /etc/rc.conf
    
    pkg install xfce
    echo "exec /usr/local/bin/startxfce4 --with-ck-launch" > ~/.xinitrc
    startx

Install requirements (GCC 12.2.0, perl 5.36.3):

    pkg install git gcc nano curl wget 7-zip
    pkg install -g libx* libX*

Clone Qt 5.15:

    git clone -b 5.15 https://code.qt.io/qt/qt5.git
    mv qt5 Qt-5.6
    cd Qt-5.6
    git clone -b 5.6 https://code.qt.io/qt/qtbase.git

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
    
    ./configure -v -prefix "/usr/local/Qt-5.15-release" -platform freebsd-g++ -static -optimize-size -release -opensource -confirm-license -fontconfig -system-freetype -bundled-xcb-xinput -nomake examples -nomake tests -nomake tools -no-cups -no-dbus -no-gif -no-iconv -no-icu -no-opengl -no-openssl -no-openvg -no-pch -no-sql-sqlite -make libs -qt-harfbuzz -qt-libjpeg -qt-libpng -qt-pcre -qt-zlib -skip wayland -skip qt3d -skip qtactiveqt -skip qtandroidextras -skip qtcharts -skip qtconnectivity -skip qtdatavis3d -skip qtdeclarative -skip qtdoc -skip qtdocgallery -skip qtfeedback -skip qtgamepad -skip qtgraphicaleffects -skip qtimageformats -skip qtlocation -skip qtlottie -skip qtmacextras -skip qtmultimedia -skip qtnetworkauth -skip qtpim -skip qtpurchasing -skip qtqa -skip qtquick3d -skip qtquickcontrols -skip qtquickcontrols2 -skip qtquicktimeline -skip qtremoteobjects -skip qtrepotools -skip qtscript -skip qtscxml -skip qtsensors -skip qtserialbus -skip qtserialport -skip qtspeech -skip qtsvg -skip qtsystems -skip qttools -skip qttranslations -skip qtvirtualkeyboard -skip qtwayland -skip qtwebchannel -skip qtwebengine -skip qtwebglplugin -skip qtwebsockets -skip qtwebview -skip qtwinextras -skip qtx11extras -skip qtxmlpatterns
    
    make
    rm -rf /usr/local/Qt-5.15-release/
    make install

Install Qt Creator:

    pkg install qtcreator

Check dependencies via `ldd qt-experiments`:

	libfontconfig.so.1 => /usr/local/lib/libfontconfig.so.1 (0x24fff5ee0000)
	libfreetype.so.6 => /usr/local/lib/libfreetype.so.6 (0x24fff69c8000)
	libX11-xcb.so.1 => /usr/local/lib/libX11-xcb.so.1 (0x24fff6e39000)
	libxcb-icccm.so.4 => /usr/local/lib/libxcb-icccm.so.4 (0x24fff77d6000)
	libxcb-image.so.0 => /usr/local/lib/libxcb-image.so.0 (0x24fff7e71000)
	libxcb-shm.so.0 => /usr/local/lib/libxcb-shm.so.0 (0x24fff8aaf000)
	libxcb-keysyms.so.1 => /usr/local/lib/libxcb-keysyms.so.1 (0x24fff99d7000)
	libxcb-randr.so.0 => /usr/local/lib/libxcb-randr.so.0 (0x24fff9f0f000)
	libxcb-render-util.so.0 => /usr/local/lib/libxcb-render-util.so.0 (0x24fffabfb000)
	libxcb-render.so.0 => /usr/local/lib/libxcb-render.so.0 (0x24fffb9c6000)
	libxcb-shape.so.0 => /usr/local/lib/libxcb-shape.so.0 (0x24fffc5be000)
	libxcb-sync.so.1 => /usr/local/lib/libxcb-sync.so.1 (0x24fffc90c000)
	libxcb-xfixes.so.0 => /usr/local/lib/libxcb-xfixes.so.0 (0x24fffd48b000)
	libxcb-xkb.so.1 => /usr/local/lib/libxcb-xkb.so.1 (0x24fffdc87000)
	libxcb.so.1 => /usr/local/lib/libxcb.so.1 (0x24fffeff4000)
	libXext.so.6 => /usr/local/lib/libXext.so.6 (0x24fffe499000)
	libX11.so.6 => /usr/local/lib/libX11.so.6 (0x250000916000)
	libxkbcommon.so.0 => /usr/local/lib/libxkbcommon.so.0 (0x24ffff31f000)
	libxkbcommon-x11.so.0 => /usr/local/lib/libxkbcommon-x11.so.0 (0x24ffff961000)
	libexecinfo.so.1 => /usr/lib/libexecinfo.so.1 (0x2500018f3000)
	libdouble-conversion.so.3 => /usr/local/lib/libdouble-conversion.so.3 (0x250002144000)
	libzstd.so.1 => /usr/local/lib/libzstd.so.1 (0x250002ef3000)
	libstdc++.so.6 => /usr/local/lib/gcc12/libstdc++.so.6 (0x250006200000)
	libm.so.5 => /lib/libm.so.5 (0x250004776000)
	libgcc_s.so.1 => /lib/libgcc_s.so.1 (0x250003ad3000)
	libthr.so.3 => /lib/libthr.so.3 (0x250005091000)
	libc.so.7 => /lib/libc.so.7 (0x25000770a000)
	libexpat.so.1 => /usr/local/lib/libexpat.so.1 (0x250005193000)
	libz.so.6 => /lib/libz.so.6 (0x2500059db000)
	libbz2.so.4 => /usr/lib/libbz2.so.4 (0x2500070bb000)
	libpng16.so.16 => /usr/local/lib/libpng16.so.16 (0x2500088f9000)
	libbrotlidec.so.1 => /usr/local/lib/libbrotlidec.so.1 (0x250008e73000)
	libxcb-util.so.1 => /usr/local/lib/libxcb-util.so.1 (0x250009a4f000)
	libXau.so.6 => /usr/local/lib/libXau.so.6 (0x25000a323000)
	libXdmcp.so.6 => /usr/local/lib/libXdmcp.so.6 (0x25000ab5b000)
	libelf.so.2 => /lib/libelf.so.2 (0x25000c37b000)
	libc++.so.1 => /lib/libc++.so.1 (0x25000af4e000)
	libcxxrt.so.1 => /lib/libcxxrt.so.1 (0x25000b378000)
	libbrotlicommon.so.1 => /usr/local/lib/libbrotlicommon.so.1 (0x25000cdff000)
	[vdso] (0x24fff5dca000)
