#!/bin/sh

pushd keyboards/xd60
make
popd
pushd .build
sleep 5
dfu-programmer atmega32u4 erase
dfu-programmer atmega32u4 flash xd60_ymcatar.hex
dfu-programmer atmega32u4 reset
popd