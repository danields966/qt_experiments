# qt-experiments

### OS X 10.10.5 Yosemite

Install `Xcode_7.2.1.dmg`

Install Xcode command line tools:

    xcode-select --install

Install `MacPorts-2.9.1-10.10-Yosemite.pkg`

Install Qt Creator and required libs:

    sudo port install qt4-creator-mac

    sudo port install freetype +universal

Compile Qt:

    git clone -b 5.6 https://code.qt.io/qt/qt5.git
    mv qt5 Qt-5.6
    cd Qt-5.6
    git clone -b 5.6 https://code.qt.io/qt/qtbase.git
    
    git submodule foreach --recursive "git clean -dfx"

    ./configure -prefix "/usr/local/Qt-5.6-release" -static -platform macx-g++ -release -opensource -confirm-license -fontconfig -system-freetype -no-cups -no-dbus -no-gif -no-iconv -no-icu -no-opengl -no-openssl -no-openvg -no-qml-debug -no-sql-sqlite -no-xcb -no-xkbcommon-x11 -qt-harfbuzz -qt-libjpeg -qt-libpng -qt-pcre -qt-zlib -nomake examples -nomake tests -skip qt3d -skip qtactiveqt -skip qtandroidextras -skip qtconnectivity -skip qtdeclarative -skip qtdoc -skip qtdocgallery -skip qtenginio -skip qtfeedback -skip qtgraphicaleffects -skip qtimageformats -skip qtlocation -skip qtmacextras -skip qtmultimedia -skip qtpim -skip qtpurchasing -skip qtqa -skip qtquick1 -skip qtquickcontrols -skip qtquickcontrols2 -skip qtrepotools -skip qtscript -skip qtsensors -skip qtserialbus -skip qtserialport -skip qtsvg -skip qtsystems -skip qttools -skip qttranslations -skip qtwayland -skip qtwebchannel -skip qtwebengine -skip qtwebkit -skip qtwebkit-examples -skip qtwebsockets -skip qtwebview -skip qtwinextras -skip qtx11extras -skip qtxmlpatterns

    make
