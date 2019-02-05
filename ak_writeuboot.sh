#!/bin/bash
echo  " downloading....."
sunxi-fel -v -p spl sunxi-h5-spl32-ddr3.bin write 0x44000 bl31uboot.bin write 0x4a000000 u-boot.bin reset64 0x44000





