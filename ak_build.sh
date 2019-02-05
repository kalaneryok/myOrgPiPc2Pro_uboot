#!/bin/sh
echo -----hello ak !!!
echo -----now start compile
echo "*****Clear Projrct*****"
#make distclean
echo "*****export arrch64 *****"
export CROSS_COMPILE=aarch64-linux-gnu-
echo "*****ORGpipc2 Config*****"
make orangepi_pc2_defconfig
echo *****make*****
make

date
echo "-----Compile Ending"
