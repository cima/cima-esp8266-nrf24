rem This must be run in folder of ESP8266_RTOS_SDK
rem This is a windows equivalent to ESP8266_RTOS_SDK/install.sh

echo off

echo "Installing ESP-IDF tools"
%IDF_PATH%/tools/idf_tools.py install

echo "Installing Python environment and packages"
%IDF_PATH%/tools/idf_tools.py install-python-env

echo "All done! You can now run:"
echo ""
echo "  export.bat"
echo ""