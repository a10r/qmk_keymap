#!/usr/bin/env bash

# build constants
QMK_DIR=qmk_firmware
KEYBOARD=planck
KEYBOARD_MAKE=planck/rev6
KEYMAP=a10r

# clean previous build
rm -rf .build

# clean submodule
cd $QMK_DIR
git clean -fdx
git reset --hard
cd ..

# copy files
mkdir -p $QMK_DIR/keyboards/$KEYBOARD/keymaps/$KEYMAP
cp -r src/keyboards/$KEYBOARD/keymaps/$KEYMAP $QMK_DIR/keyboards/$KEYBOARD/keymaps

cd $QMK_DIR

# create another header file with the version; this should already be in version.h but it doesn't work for me for some reason...
QMK_GITVERSION=$(git describe --abbrev=6 --tags)
echo -e "#undef QMK_VERSION\n#define QMK_VERSION \"$QMK_GITVERSION\"" >> keyboards/$KEYBOARD/keymaps/$KEYMAP/version-override.h

# build
util/docker_build.sh $KEYBOARD_MAKE:$KEYMAP

# copy output
mkdir ../.build
cp -r .build ..

# clean submodule
git clean -fdx
git reset --hard
cd ..