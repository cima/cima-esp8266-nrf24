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
2. Clone project with shared components []() side-by-side to this project. E.g. `./cima-esp-components/`
```
git clone git@github.com:cima/cima-esp-components.git
```
3. Create separate ESP toolchain and libraries folder e.g. `./ESP8266/`
```
    mkdir ./ESP8266/
    cd ./ESP8266/
```
4. Unpack Espressif's ESP8266 toolchain into above created ./ESP8266/ directory
- [Espressif's ESP8266 toolchain](https://docs.espressif.com/projects/esp8266-rtos-sdk/en/latest/get-started/windows-setup.html)
  - **xtensa-lx106-elf** compilers are sufficient
  - ~~MSYS prebuilt toolchain~~ is not necessary
5. Clone _ESP8266_RTOS_SDK_ to folder from step 2. e.g. `./ESP8266/`
```
    git clone --recursive https://github.com/espressif/ESP8266_RTOS_SDK.git
```
6. Modify file *env.bat* so the variable `ESP_TOOLCHAIN_DIR` points towards the directory from step 2.

7. Run *install_idf.bat* from direcrtory of this project.
```
  ./install_idf.bat
```
8. Clone _ESP-IoT-solution_ to folder from step 2. e.g. `./ESP/esp-iot-solution/`
```
    git clone --recursive https://github.com/espressif/esp-iot-solution.git
```
9. get Boost via [BOOST download](https://www.boost.org/users/download/) and unpack it to folder from step 2. E.g. `./ESP8266/boost_1_85_0/`

10. Update file `init_cmd.bat` in this project (from step 1) with the name of the boost folder.
11. Fisrt build
```
  ./init_cmd.bat
  idf.py build
```

## Build
```
  idf.py build
```

## Flash
```
  python -m %IDF_PATH%/tools/idf.py -p COM6 flash
```

## Run
Using putty

## Debug

### Analyse crashdump stacktrace

```bat
xtensa-lx106-elf-addr2line.exe -fe build\CIMA-ESP8266-NRF24.elf 0x4000bf80:0x3ffe9ff0 0x4022869d:0x3ffe9ff0
```

the hexa mess are items from stack trace obtained from crash dump report

```
Guru Meditation Error: Core  0 panic'ed (LoadProhibited). Exception was unhandled.
Core 0 register dump:
PC      : 0x4000bf80  PS      : 0x00000030  A0      : 0x4022869d  A1      : 0x3ffe9ff0
A2      : 0x00000000  A3      : 0xfffffffc  A4      : 0x000000ff  A5      : 0x0000ff00
A6      : 0x00ff0000  A7      : 0xff000000  A8      : 0x00000000  A9      : 0x00000003
A10     : 0xffffffff  A11     : 0x3ffe87f8  A12     : 0x00000002  A13     : 0x3ffea1ec
A14     : 0x00000003  A15     : 0x00000000  SAR     : 0x00000004  EXCCAUSE: 0x0000001c

Backtrace: 0x4000bf80:0x3ffe9ff0 0x4022869d:0x3ffe9ff0 Guru Meditation Error: Core  0 panic'ed (LoadStoreAlignment). Exception was unhandled.
Core 0 register dump:
PC      : 0x4021f3a5  PS      : 0x00000033  A0      : 0x4021f318  A1      : 0x3ffe8ca0
A2      : 0x0001868d  A3      : 0x0000199d  A4      : 0x3ffea013  A5      : 0x3ffea00f
A6      : 0x000007fe  A7      : 0x000000a3  A8      : 0x000000c0  A9      : 0x00000003
A10     : 0xffffffff  A11     : 0x3ffe87f8  A12     : 0x4022869d  A13     : 0x3ffe8cd4
A14     : 0x4022869d  A15     : 0x4022869d  SAR     : 0x0000001f  EXCCAUSE: 0x00000009

Backtrace: 0x4021f3a5:0x3ffe8ca0 0x40213b77:0x3ffe8cd0 0x40100edc:0x3ffe8d10
```

to prevenrt ESP from restarting on exception just compile the project with *./sdkconfig* file containing line `CONFIG_ESP_PANIC_PRINT_HALT=y`

## ESP8266LuaNodeMcu V3

![ESP8266LuaNodeMcu V3 Pinout](https://www.laskakit.cz/user/related_files/nodemcuv3_0-pinout.jpg)

### LED
- *D4 (GPIO2)*
The built-in LED on the NodeMCU ESP8266 v3 development board is connected to GPIO2 (also labeled as D4). Keep in mind that this LED operates with active low logic: setting PIN 2 to ‘0’ turns the LED ON, while setting it to ‘1’ turns the LED OFF. 

### Button (flash)
- *D3 (GPIO0)*
a button subtitled flash is connected to pin D3 and can be used for any purpose within your programm.
It does have special meaning during program upploading in some scenarios to switch to flashing mode. When program uuns it is available for general purpose usage.

### PWM
- 10bit resolution
- 1 KHz frequency

Pins
- D1 (GPIO5)
- D2 (GPIO4)
- D5 (GPIO14)
- D6 (GPIO12)

## nRF24

I use [nRF24L01p+ PA+ LNA 2.4GHz](https://www.laskakit.cz/bezdratovy-modul-nrf24l01p--pa--lna-2-4ghz/) transciever as a base for a remote controler.

The connection to NodeMCU is done based on arduino tutorial [ESP8266 NRF24L01 Wifi Gateway with Arduino NRF24L01 Node](ESP8266 NRF24L01 Wifi Gateway with Arduino NRF24L01 Node)

|NRF24L01|Node MCU|GPIO|
|--------|--------|----|
|MISO    |      D6| HMISO/GPIO12|
|MOSI    |      D7| HMOSI/GPIO13|
|SCK     |      D5| HSCLK/GPIO45|
|CE      |      D4| GPIO2|
|CSN     |      D2| GPIO4|
|VCC     |      3V| 3.3 V|
|GND     |       G| GND|

![Receiver Circuit: NRF24L01 ESP8266 Gateway](https://how2electronics.com/wp-content/uploads/2020/06/NRF24L01-ESP8266-Node.jpg)

# Readings

[atomic_c11.c](https://github.com/iot-lab/riot-upstream/blob/master/core/atomic_c11.c)