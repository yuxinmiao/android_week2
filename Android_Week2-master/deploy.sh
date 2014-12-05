#!/bin/bash
#adb shell su
#adb shell mount -o remount,rw /system /system
adb push out/bin/helloworldservice /data/local/tmp
adb push out/bin/helloworldclient /data/local/tmp
adb push out/lib/libhelloworldservice.so /system/lib 
cd -
s