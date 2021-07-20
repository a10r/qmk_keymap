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

# build
cd $QMK_DIR
util/docker_build.sh $KEYBOARD_MAKE:$KEYMAP

# copy output
mkdir ../.build
cp -r .build ..

# clean submodule
git clean -fdx
git reset --hard
cd ..