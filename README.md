# qt-experiments

### OS X 10.10.5 Yosemite

Install `Xcode_7.2.1.dmg`

Install Xcode command line tools:

    xcode-select --install

Install `MacPorts-2.9.1-10.10-Yosemite.pkg`

Install Qt Creator and required libs:

    sudo port install qt4-creator-mac

    sudo port install fontconfig freetype +universal

Compile Qt:

    git clone -b 5.6 https://code.qt.io/qt/qt5.git
    mv qt5 Qt-5.6
    cd Qt-5.6
    git clone -b 5.6 https://code.qt.io/qt/qtbase.git
    
    git submodule foreach --recursive "git clean -dfx"

    ./configure -prefix "/usr/local/Qt-5.6-release" -static -platform macx-clang -release -opensource -confirm-license -fontconfig -system-freetype -no-cups -no-dbus -no-gif -no-iconv -no-icu -no-opengl -no-openssl -no-openvg -no-qml-debug -no-sql-sqlite -no-xcb -no-xkbcommon-x11 -qt-harfbuzz -qt-libjpeg -qt-libpng -qt-pcre -qt-zlib -nomake examples -nomake tests -skip qt3d -skip qtactiveqt -skip qtandroidextras -skip qtconnectivity -skip qtdeclarative -skip qtdoc -skip qtdocgallery -skip qtenginio -skip qtfeedback -skip qtgraphicaleffects -skip qtimageformats -skip qtlocation -skip qtmacextras -skip qtmultimedia -skip qtpim -skip qtpurchasing -skip qtqa -skip qtquick1 -skip qtquickcontrols -skip qtquickcontrols2 -skip qtrepotools -skip qtscript -skip qtsensors -skip qtserialbus -skip qtserialport -skip qtsvg -skip qtsystems -skip qttools -skip qttranslations -skip qtwayland -skip qtwebchannel -skip qtwebengine -skip qtwebkit -skip qtwebkit-examples -skip qtwebsockets -skip qtwebview -skip qtwinextras -skip qtx11extras -skip qtxmlpatterns

    make
    sudo make install

App dependencies:

    otool -L qt-experiments.app/Contents/MacOS/qt-experiments
    
	/System/Library/Frameworks/DiskArbitration.framework/Versions/A/DiskArbitration (compatibility version 1.0.0, current version 1.0.0)
	/System/Library/Frameworks/IOKit.framework/Versions/A/IOKit (compatibility version 1.0.0, current version 275.0.0)
	/System/Library/Frameworks/Foundation.framework/Versions/C/Foundation (compatibility version 300.0.0, current version 1256.1.0)
	/System/Library/Frameworks/CoreServices.framework/Versions/A/CoreServices (compatibility version 1.0.0, current version 728.6.0)
	/System/Library/Frameworks/AppKit.framework/Versions/C/AppKit (compatibility version 45.0.0, current version 1404.32.0)
	/System/Library/Frameworks/ApplicationServices.framework/Versions/A/ApplicationServices (compatibility version 1.0.0, current version 48.0.0)
	/System/Library/Frameworks/CoreFoundation.framework/Versions/A/CoreFoundation (compatibility version 150.0.0, current version 1256.14.0)
	/System/Library/Frameworks/Cocoa.framework/Versions/A/Cocoa (compatibility version 1.0.0, current version 22.0.0)
	/System/Library/Frameworks/OpenGL.framework/Versions/A/OpenGL (compatibility version 1.0.0, current version 1.0.0)
	/System/Library/Frameworks/AGL.framework/Versions/A/AGL (compatibility version 1.0.0, current version 1.0.0)
	/System/Library/Frameworks/Carbon.framework/Versions/A/Carbon (compatibility version 2.0.0, current version 157.0.0)
	/usr/lib/libcups.2.dylib (compatibility version 2.0.0, current version 2.11.0)
	/usr/lib/libz.1.dylib (compatibility version 1.0.0, current version 1.2.5)
	/usr/lib/libSystem.B.dylib (compatibility version 1.0.0, current version 1226.10.1)
	/usr/lib/libc++.1.dylib (compatibility version 1.0.0, current version 120.1.0)
	/usr/lib/libobjc.A.dylib (compatibility version 1.0.0, current version 228.0.0)
