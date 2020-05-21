#!/bin/bash

function err() {
    echo -e "\e[1;31m${@}\e[0m" >&2
    exit 1
}

pushd demo
echo ""

for file in *.cpp; do

file_without_extension="${file%.*}"
avr-gcc -std=c++14  -Os -mmcu=atmega328p "${file_without_extension}".cpp -o "${file_without_extension}".elf  || err "Compiling ${file_without_extension} failed."

avr-size "${file_without_extension}".elf || err "Computing size of ${file_without_extension} failed."
avr-nm --size-sort -C -r --radix=d "${file_without_extension}".elf || err "Listing functional decomposition of ${file_without_extension} failed."

echo ""

done

popd
