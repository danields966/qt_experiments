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
    
    ./configure -prefix "/usr/local/Qt-5.6-release" -static -platform freebsd-g++ -release -opensource -confirm-license -fontconfig -system-freetype -no-cups -no-dbus -no-gif -no-iconv -no-icu -no-opengl -no-openssl -no-openvg -no-pch -no-qml-debug -no-sql-sqlite -qt-harfbuzz -qt-libjpeg -qt-libpng -qt-pcre -qt-xcb -qt-xkbcommon-x11 -qt-zlib -nomake examples -nomake tests
    
    make
