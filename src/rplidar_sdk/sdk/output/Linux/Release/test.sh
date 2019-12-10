#!/bin/bash
for i in {0..10}
do
   ./ultra_simple /dev/ttyUSB$i
done
