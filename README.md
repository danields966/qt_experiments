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
