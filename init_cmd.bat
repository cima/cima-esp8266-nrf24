CALL env.bat

SET CXX=xtensa-lx106-elf-g++.exe
SET IOT_SOLUTION_PATH=%ESP_TOOLCHAIN_DIR%/esp-iot-solution
SET BOOST_ROOT=%ESP_TOOLCHAIN_DIR%/boost_1_85_0

SET PATH=%ESP_TOOLCHAIN_DIR%\xtensa-lx106-elf\bin;^
%ESP_TOOLCHAIN_DIR%\xtensa-lx106-elf\xtensa-lx106-elf\bin;^
%ESP_TOOLCHAIN_DIR%\mconf-v4.6.0.0-idf-20190628-win32;^
C:\tools\ESP\esp-framework\tools\cmake\3.23.1\bin;^
%PATH%

cd /D %IDF_PATH%/

call %ESP_PROJECT%/export.bat

cd /D %ESP_PROJECT%