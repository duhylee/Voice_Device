cmd_drivers/mmc/host/sunxi-mmc-v5px.o := arm-openwrt-linux-gnueabi-gcc -Wp,-MD,drivers/mmc/host/.sunxi-mmc-v5px.o.d  -nostdinc -isystem /home/dhleec/Project/R328/tina/prebuilt/gcc/linux-x86/arm/toolchain-sunxi-glibc/toolchain/bin/../lib/gcc/arm-openwrt-linux-gnueabi/6.4.1/include -I./arch/arm/include -I./arch/arm/include/generated/uapi -I./arch/arm/include/generated  -I./include -I./arch/arm/include/uapi -I./include/uapi -I./include/generated/uapi -include ./include/linux/kconfig.h -D__KERNEL__ -mlittle-endian -Iarch/arm/mach-sunxi/include -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration -Wno-format-security -std=gnu89 -fno-PIE -fno-dwarf2-cfi-asm -fno-ipa-sra -mabi=aapcs-linux -mno-thumb-interwork -mfpu=vfp -funwind-tables -marm -D__LINUX_ARM_ARCH__=7 -march=armv7-a -msoft-float -Uarm -fno-delete-null-pointer-checks -Wno-frame-address -Os -Wno-maybe-uninitialized --param=allow-store-data-races=0 -DCC_HAVE_ASM_GOTO -Wframe-larger-than=2048 -fstack-protector -Wno-unused-but-set-variable -Wno-unused-const-variable -fomit-frame-pointer -fno-var-tracking-assignments -g -Wdeclaration-after-statement -Wno-pointer-sign -fno-strict-overflow -fno-merge-all-constants -fmerge-constants -fno-stack-check -fconserve-stack -Werror=implicit-int -Werror=strict-prototypes -Werror=date-time -Werror=incompatible-pointer-types    -DKBUILD_BASENAME='"sunxi_mmc_v5px"'  -DKBUILD_MODNAME='"sunxi_mmc_host"' -c -o drivers/mmc/host/sunxi-mmc-v5px.o drivers/mmc/host/sunxi-mmc-v5px.c

source_drivers/mmc/host/sunxi-mmc-v5px.o := drivers/mmc/host/sunxi-mmc-v5px.c

deps_drivers/mmc/host/sunxi-mmc-v5px.o := \
    $(wildcard include/config/arch/sun8iw10p1.h) \

drivers/mmc/host/sunxi-mmc-v5px.o: $(deps_drivers/mmc/host/sunxi-mmc-v5px.o)

$(deps_drivers/mmc/host/sunxi-mmc-v5px.o):
