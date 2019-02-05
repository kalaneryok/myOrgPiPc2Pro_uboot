1.在myuboot目录下有个bl31.bin文件先将这个文件mv 成bl3uboot.bin
2.不然用bl31.bin文件编译会报错 但不影响uboot.bin的产生
3.任何主线下的代码和其他sunxi分支否不能在H5上执行fel
只有sunxi64-fel32的uboot可以在H5-a64上使用fel下载uboot
4.解决方法：
    后来查资料http://linux-sunxi.org/A64
    发现由于FEL引导完全在AArch32中完成，并且需要随后以相同的状态返回到引导ROM，所以主线U-Boot SPL（使用AArch64）不支持FEL引导
    根据资料下载uboot分支及atf文件
        资料原文：   
        you have to use a FEL capable SPL. Since FEL booting is done entirely in AArch32 and requires returning to the Boot ROM in the same state afterwards, the mainline U-Boot SPL (using AArch64) does not support FEL boot. There is a branch maintaining a 32-bit port/config of U-Boot's A64 support, which allows to build a 32-bit, FEL-capable SPL binary. This is meant to be combined with the normal (mainline) AArch64 U-Boot proper and the normal ATF build. For convenience reasons binaries are provided. To boot a firmware stack via this method, after entering FEL mode use the following sunxi-fel command line
        1.sunxi64-fel32
            git clone https://github.com/apritzel/u-boot.git
        2.ATF的bl3文件
            https://github.com/apritzel/pine64.git
            
下载新uboot尝试编译运行试试fel
pine64在这个目录下binaries中有两个文件很重要sunxi-h5-spl32-ddr3.bin和 bl31.bin，一个是引导fel程序文件，之前说了不能用aarch64编译的文件来引导fel是不行的
有了这两个文件后再加上相对应板子的uboot文件就可以下载了命令如下
sunxi-fel -v -p spl sunxi-h5-spl32-ddr3.bin write 0x44000 bl31.bin write 0x4a000000 u-boot.bin reset64 0x44000
/home/ak/my_work_space/orangePiPc2/sunxi-tools-master/sunxi-fel -v -p spl sunxi-h5-spl32-ddr3.bin write 0x44000 bl31uboot.bin write 0x4a000000 u-boot.bin reset64 0x44000
这里将bl31.bin欢乐一个名字bl31uboot.bin，是因为在uboot下会去找这个文件参与编译不符合会瞎几把高，但是下载就需要这个文件下载到板子上
