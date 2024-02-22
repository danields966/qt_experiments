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


### OS X 10.15.7 Catalina

Install `Xcode_12.4.xip`

Install Homebrew (don't forget to follow commands after installing):

    /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

Install Xcode command line tools:

    xcode-select --install

Clone Qt 5.15:

    git clone -b 5.15 https://code.qt.io/qt/qt5.git
    mv qt5 Qt-5.15
    cd Qt-5.15
    git clone -b 5.15 https://code.qt.io/qt/qtbase.git

Or:

    brew install p7zip wget
    wget http://danields966.ru:9724/Qt-5.15.7z
    7za x Qt-5.15.7z
    cd Qt-5.15

Compile Qt:

    ./configure -v -prefix "/usr/local/Qt-5.15-release" -platform macx-clang -static -optimize-size -ltcg -release -opensource -confirm-license -nomake examples -nomake tests -nomake tools -no-cups -no-dbus -no-gif -no-iconv -no-icu -no-opengl -no-openssl -no-openvg -no-pch -no-sql-sqlite -make libs -qt-harfbuzz -qt-libjpeg -qt-libpng -qt-pcre -qt-zlib -skip wayland -skip qt3d -skip qtactiveqt -skip qtandroidextras -skip qtcharts -skip qtconnectivity -skip qtdatavis3d -skip qtdeclarative -skip qtdoc -skip qtdocgallery -skip qtfeedback -skip qtgamepad -skip qtgraphicaleffects -skip qtimageformats -skip qtlocation -skip qtlottie -skip qtmacextras -skip qtmultimedia -skip qtnetworkauth -skip qtpim -skip qtpurchasing -skip qtqa -skip qtquick3d -skip qtquickcontrols -skip qtquickcontrols2 -skip qtquicktimeline -skip qtremoteobjects -skip qtrepotools -skip qtscript -skip qtscxml -skip qtsensors -skip qtserialbus -skip qtserialport -skip qtspeech -skip qtsvg -skip qtsystems -skip qttools -skip qttranslations -skip qtvirtualkeyboard -skip qtwayland -skip qtwebchannel -skip qtwebengine -skip qtwebglplugin -skip qtwebsockets -skip qtwebview -skip qtwinextras -skip qtx11extras -skip qtxmlpatterns
    
    make
    sudo make install

Install Qt Creator 6.0.2 from GitHub (file `qt-creator-macOS-1717511949.dmg`):

App dependencies:

    otool -L qt-experiments.app/Contents/MacOS/qt-experiments
    
	/System/Library/Frameworks/Carbon.framework/Versions/A/Carbon (compatibility version 2.0.0, current version 164.0.0)
	/System/Library/Frameworks/QuartzCore.framework/Versions/A/QuartzCore (compatibility version 1.2.0, current version 1.11.0)
	/System/Library/Frameworks/CoreVideo.framework/Versions/A/CoreVideo (compatibility version 1.2.0, current version 1.5.0)
	/System/Library/Frameworks/IOSurface.framework/Versions/A/IOSurface (compatibility version 1.0.0, current version 1.0.0)
	/usr/lib/libcups.2.dylib (compatibility version 2.0.0, current version 2.14.0)
	/System/Library/Frameworks/CoreText.framework/Versions/A/CoreText (compatibility version 1.0.0, current version 1.0.0)
	/System/Library/Frameworks/ImageIO.framework/Versions/A/ImageIO (compatibility version 1.0.0, current version 1.0.0)
	/usr/lib/libz.1.dylib (compatibility version 1.0.0, current version 1.2.11)
	/System/Library/Frameworks/Metal.framework/Versions/A/Metal (compatibility version 1.0.0, current version 244.32.7)
	/System/Library/Frameworks/CoreGraphics.framework/Versions/A/CoreGraphics (compatibility version 64.0.0, current version 1463.2.1)
	/System/Library/Frameworks/DiskArbitration.framework/Versions/A/DiskArbitration (compatibility version 1.0.0, current version 1.0.0)
	/System/Library/Frameworks/IOKit.framework/Versions/A/IOKit (compatibility version 1.0.0, current version 275.0.0)
	/usr/lib/libSystem.B.dylib (compatibility version 1.0.0, current version 1292.60.1)
	/System/Library/Frameworks/AppKit.framework/Versions/C/AppKit (compatibility version 45.0.0, current version 2022.20.117)
	/System/Library/Frameworks/Security.framework/Versions/A/Security (compatibility version 1.0.0, current version 59754.60.13)
	/System/Library/Frameworks/ApplicationServices.framework/Versions/A/ApplicationServices (compatibility version 1.0.0, current version 54.0.0)
	/System/Library/Frameworks/CoreServices.framework/Versions/A/CoreServices (compatibility version 1.0.0, current version 1122.11.0)
	/System/Library/Frameworks/CoreFoundation.framework/Versions/A/CoreFoundation (compatibility version 150.0.0, current version 1770.255.0)
	/System/Library/Frameworks/Foundation.framework/Versions/C/Foundation (compatibility version 300.0.0, current version 1770.255.0)
	/usr/lib/libc++.1.dylib (compatibility version 1.0.0, current version 904.4.0)
	/System/Library/Frameworks/ColorSync.framework/Versions/A/ColorSync (compatibility version 1.0.0, current version 4.7.0)
	/usr/lib/libobjc.A.dylib (compatibility version 1.0.0, current version 228.0.0)
