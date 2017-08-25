#!/bin/bash

cat /dev/null >src.log
cat /dev/null >src1.log
cat /dev/null >log.log

cat $1 |awk -F '|' '{print $3}' >src.log
cat src.log |awk -F ':' '{print $1,$2}' >src1.log
cat src1.log |sort|uniq -c |sort -k 1 -n >log.log

rm -rf ./src.log
rm -rf ./src1.log

