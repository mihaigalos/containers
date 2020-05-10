#!/bin/bash

pushd ../demo
for file in *.cpp; do

file_without_extension="${file%.*}"
avr-gcc -std=c++17  -Os -mmcu=atmega328p "${file_without_extension}".cpp -o "${file_without_extension}".elf

avr-size "${file_without_extension}".elf
avr-nm --size-sort -C -r --radix=d "${file_without_extension}".elf

echo ""

done

popd
