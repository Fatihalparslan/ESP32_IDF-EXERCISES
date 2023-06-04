# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/acer/esp/esp-idf/components/bootloader/subproject"
  "C:/Users/acer/OneDrive/Desktop/esp32-tutorial/Esp32_FreeRTOSEventGroups/build/bootloader"
  "C:/Users/acer/OneDrive/Desktop/esp32-tutorial/Esp32_FreeRTOSEventGroups/build/bootloader-prefix"
  "C:/Users/acer/OneDrive/Desktop/esp32-tutorial/Esp32_FreeRTOSEventGroups/build/bootloader-prefix/tmp"
  "C:/Users/acer/OneDrive/Desktop/esp32-tutorial/Esp32_FreeRTOSEventGroups/build/bootloader-prefix/src/bootloader-stamp"
  "C:/Users/acer/OneDrive/Desktop/esp32-tutorial/Esp32_FreeRTOSEventGroups/build/bootloader-prefix/src"
  "C:/Users/acer/OneDrive/Desktop/esp32-tutorial/Esp32_FreeRTOSEventGroups/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/acer/OneDrive/Desktop/esp32-tutorial/Esp32_FreeRTOSEventGroups/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
