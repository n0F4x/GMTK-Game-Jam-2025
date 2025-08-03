#!/bin/bash

#make sure we have a build
conan build .

# detect machine's architecture
export ARCH=$(uname -m)

# get the missing tools if necessary
if [ ! -d ./build ]; then mkdir ../build; fi
if [ ! -x ./build/appimagetool-$ARCH.AppImage ]; then
  curl -L -o ./build/appimagetool-$ARCH.AppImage https://github.com/AppImage/AppImageKit/releases/download/continuous/appimagetool-$ARCH.AppImage
  chmod a+x ./build/appimagetool-$ARCH.AppImage
fi

rm -rf ./build/appimage

mkdir ./build/appimage

cp -r linux-packaging/* build/appimage
cp -r assets build/appimage
cp build/Release/game build/appimage

export TARGET="$PWD/build/appimage/lib/"

mkdir ./build/appimage/lib

pushd /usr/lib/
cp \
 libGLEW.so.2.2 \
 libc++.so.1 \
 libc++abi.so.1 \
 libSM.so.6 \
 libuuid.so.1 \
 libxcb-res.so.0 \
 libxcb-ewmh.so.2 \
 libxcb-composite.so.0 \
 libxcb-present.so.0 \
 libxcb-glx.so.0 \
 libxcb-dri2.so.0 \
 libxcb-cursor.so.0 \
 libxcb-dri3.so.0 \
 libxcb-util.so.1 \
 libxcb-xinerama.so.0 \
 libxcb-xfixes.so.0 \
 libxcb-sync.so.1 \
 libxcb-shape.so.0 \
 libxcb-render-util.so.0 \
 libxcb-render.so.0 \
 libxcb-randr.so.0 \
 libxcb-keysyms.so.1 \
 libxcb-image.so.0 \
 libxcb-shm.so.0 \
 libxcb-icccm.so.4 \
 libxcb-xkb.so.1 \
 libXxf86vm.so.1 \
 libXv.so.1 \
 libXtst.so.6 \
 libXss.so.1 \
 libXRes.so.1 \
 libXrender.so.1 \
 libXrandr.so.2 \
 libXpm.so.4 \
 libXmuu.so.1 \
 libXmu.so.6 \
 libxkbfile.so.1 \
 libXinerama.so.1 \
 libXi.so.6 \
 libXext.so.6 \
 libXdmcp.so.6 \
 libXdamage.so.1 \
 libXfixes.so.3 \
 libXcursor.so.1 \
 libXcomposite.so.1 \
 libXaw.so.7 \
 libXt.so.6 \
 libXau.so.6 \
 libICE.so.6 \
 libfontenc.so.1 \
 libX11-xcb.so.1 \
 libxcb.so.1 \
 libX11.so.6 \
 libudev.so.1 \
 libm.so.6 \
 libgcc_s.so.1 \
 libc.so.6 \
 ld-linux-x86-64.so.2 \
 $TARGET

popd

chmod +x build/appimage/AppRun
strip build/appimage/game

patchelf --set-interpreter ./lib/ld-linux-x86-64.so.2 build/appimage/game

# the build command itself:
./build/appimagetool-$ARCH.AppImage ./build/appimage

# move result in build folder
# mv hello-world-appimage-*-$ARCH.AppImage ../build