# cima-esp8266-nrf24

A minimalistic project combining 8-bit ESP processor [ESP8266LuaNodeMcu V3](https://www.laskakit.cz/iot-esp8266-lua-nodemcu-v3-wifi-modul--tcp-ip/) with [nRF24L01p+ PA+ LNA 2.4GHz](https://www.laskakit.cz/bezdratovy-modul-nrf24l01p--pa--lna-2-4ghz/) transciever as a base for a remote controler.

# Development

Created by following Espressif's [Get Started](https://docs.espressif.com/projects/esp8266-rtos-sdk/en/latest/get-started/index.html)

## Prerequisities

- [Python 3.9+](https://www.python.org/downloads/) [^1]
- [Git](https://git-scm.com/download/win)
- [USB-SERIAL CH340](https://www.wch-ic.com/search?q=CH340&t=downloads) -  drivers for debug/console over USB
- [Putty](https://www.chiark.greenend.org.uk/~sgtatham/putty/latest.html)
  - Create serial port connection to port determined in previous step
    - Speed (baud): 115 200
    - Data bits: 8, stopbit: 1, flow control: XON/XOFF, parity: none
    - Terminal: Implicit CR in every LF
- [VSCode](https://code.visualstudio.com/)
  - [C++ extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
  - [ESP32 extension](https://marketplace.visualstudio.com/items?itemName=espressif.esp-idf-extension)
- [CMAKE](https://cmake.org/)[^1] - project definition tools and language
- [ninja](https://github.com/ninja-build/ninja/releases) [^1] - a very significantly faster alternative to _make_
- [mconf-idf](https://github.com/espressif/kconfig-frontends/releases/) - some generic tool used to control compilation and build
- [BOOST](https://www.boost.org/users/download/) - set of very handy macros that makes c++ code even pretties and safer

[^1]: Make sure it is either available on path or modify the file *init_cmd.bat* so it is at its path at least
## Prepare environment

1. Clone this project somewhere e.g. `./cima-esp8266-nrf24/`
2. Create separate ESP toolchain and libraries folder e.g. `./ESP8266/`
```
    mkdir ./ESP8266/
    cd ./ESP8266/
```
3. Unpack Espressif's ESP8266 toolchain into above created ./ESP8266/ directory
- [Espressif's ESP8266 toolchain](https://docs.espressif.com/projects/esp8266-rtos-sdk/en/latest/get-started/windows-setup.html)
  - **xtensa-lx106-elf** compilers are sufficient
  - ~~MSYS prebuilt toolchain~~ is not necessary
4. Clone _ESP8266_RTOS_SDK_ to folder from step 2. e.g. `./ESP8266/ESP8266_RTOS_SDK/`
```
    git clone --recursive https://github.com/espressif/ESP8266_RTOS_SDK.git
```
5. Clone _ESP-IoT-solution_ to folder from step 2. e.g. `./ESP/esp-iot-solution/`
```
    git clone --recursive https://github.com/espressif/esp-iot-solution.git
```
6. get Boost via [BOOST download](https://www.boost.org/users/download/) and unpack it to folder from step 2. E.g. `./ESP8266/boost_1_85_0/`

7. Update file `init_cmd.bat` in this project (from step 1) so the first variable `ESP_TOOLCHAIN_DIR` contains the absolute prefix of your toolchain directory. Also change the name of the boost folder in the bat file.
8. Fisrt build
```
  cd ./cima-esp8266-nrf24/
  ./init_cmd.bat
  python -m %IDF_PATH%/tools/idf.py build
```

## Build
```
   python -m %IDF_PATH%/tools/idf.py build
```

## Flash
```
  python -m %IDF_PATH%/tools/idf.py -p COM6 flash
```

## Run
Using putty

## ESP8266LuaNodeMcu V3

![ESP8266LuaNodeMcu V3 Pinout](https://www.laskakit.cz/user/related_files/nodemcuv3_0-pinout.jpg)