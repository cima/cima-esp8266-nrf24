IF DEFINED IDF_PATH (
    ECHO IDF_PATH exists: %IDF_PATH%
) ELSE (
    ECHO IDF_PATH variable does not exist.
    EXIT 1
)

echo "Adding ESP-IDF tools to PATH..."
SET IDF_TOOLS_EXPORT_CMD=%IDF_PATH%/export.sh
SET IDF_TOOLS_INSTALL_CMD=%IDF_PATH%/install.sh

%IDF_PATH%/tools/idf_tools.py export > generated_export.bat
CALL generated_export.bat

python %IDF_PATH%/tools/check_python_dependencies.py

SET PATH = %IDF_PATH%/components/esptool_py/esptool;^
%IDF_PATH%/components/partition_table/;^
%PATH%