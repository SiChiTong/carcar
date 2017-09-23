#!/bin/bash
rm -rf /home/slxk/gwb/$1/proto/*.h /home/slxk/gwb/$1/proto/*.cc
chmod 777 /home/slxk/gwb/$1/proto/build.sh
cd /home/slxk/gwb/$1/proto && ./build.sh
rm -rf /home/slxk/gwb/$1/zbcar_car
makePath="/home/slxk/gwb/$1/Makefile"
if [ -f "$makePath" ];then
    
    cd /home/slxk/gwb/$1 && make clean
    cd /home/slxk/gwb/$1 && make 

else
    cd /home/slxk/gwb/$1/src && make clean
    cd /home/slxk/gwb/$1/src && make 
fi
