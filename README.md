This repo contains my OLKB Planck keymap.

Make sure to check out all submodules:

    git clone --recurse-submodules

To build, run `build.sh`. The build script uses a docker image to build the keymap, so installing QMK is not necessary. On Windows, using WSL works fine for building. The built firmware file will be put into the .build folder. Use QMK Toolbox to flash the file to you keyboard.