cmd_arch/arm/boot/compressed/string.o := arm-openwrt-linux-gnueabi-gcc -Wp,-MD,arch/arm/boot/compressed/.string.o.d  -nostdinc -isystem /home/dhleec/Project/R328/tina/prebuilt/gcc/linux-x86/arm/toolchain-sunxi-glibc/toolchain/bin/../lib/gcc/arm-openwrt-linux-gnueabi/6.4.1/include -I./arch/arm/include -I./arch/arm/include/generated/uapi -I./arch/arm/include/generated  -I./include -I./arch/arm/include/uapi -I./include/uapi -I./include/generated/uapi -include ./include/linux/kconfig.h -D__KERNEL__ -mlittle-endian -Iarch/arm/mach-sunxi/include -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration -Wno-format-security -std=gnu89 -fno-PIE -fno-dwarf2-cfi-asm -fno-ipa-sra -mabi=aapcs-linux -mno-thumb-interwork -mfpu=vfp -funwind-tables -marm -D__LINUX_ARM_ARCH__=7 -march=armv7-a -msoft-float -Uarm -fno-delete-null-pointer-checks -Wno-frame-address -Os -Wno-maybe-uninitialized --param=allow-store-data-races=0 -DCC_HAVE_ASM_GOTO -Wframe-larger-than=2048 -fstack-protector -Wno-unused-but-set-variable -Wno-unused-const-variable -fomit-frame-pointer -fno-var-tracking-assignments -g -Wdeclaration-after-statement -Wno-pointer-sign -fno-strict-overflow -fno-merge-all-constants -fmerge-constants -fno-stack-check -fconserve-stack -Werror=implicit-int -Werror=strict-prototypes -Werror=date-time -Werror=incompatible-pointer-types -DDISABLE_BRANCH_PROFILING -fpic -mno-single-pic-base -fno-builtin -Iarch/arm/boot/compressed -Os    -DKBUILD_BASENAME='"string"'  -DKBUILD_MODNAME='"string"' -c -o arch/arm/boot/compressed/string.o arch/arm/boot/compressed/string.c

source_arch/arm/boot/compressed/string.o := arch/arm/boot/compressed/string.c

deps_arch/arm/boot/compressed/string.o := \
  include/linux/string.h \
    $(wildcard include/config/binary/printf.h) \
  include/linux/compiler.h \
    $(wildcard include/config/sparse/rcu/pointer.h) \
    $(wildcard include/config/trace/branch/profiling.h) \
    $(wildcard include/config/profile/all/branches.h) \
    $(wildcard include/config/kasan.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/enable/warn/deprecated.h) \
    $(wildcard include/config/kprobes.h) \
  include/linux/compiler-gcc.h \
    $(wildcard include/config/arch/supports/optimized/inlining.h) \
    $(wildcard include/config/optimize/inlining.h) \
    $(wildcard include/config/gcov/kernel.h) \
    $(wildcard include/config/stack/validation.h) \
    $(wildcard include/config/arch/use/builtin/bswap.h) \
  include/uapi/linux/types.h \
  arch/arm/include/asm/types.h \
  include/asm-generic/int-ll64.h \
  include/uapi/asm-generic/int-ll64.h \
  arch/arm/include/generated/asm/bitsperlong.h \
  include/asm-generic/bitsperlong.h \
    $(wildcard include/config/64bit.h) \
  include/uapi/asm-generic/bitsperlong.h \
  include/uapi/linux/posix_types.h \
  include/linux/stddef.h \
  include/uapi/linux/stddef.h \
  arch/arm/include/uapi/asm/posix_types.h \
  include/uapi/asm-generic/posix_types.h \
  include/linux/types.h \
    $(wildcard include/config/have/uid16.h) \
    $(wildcard include/config/uid16.h) \
    $(wildcard include/config/lbdaf.h) \
    $(wildcard include/config/arch/dma/addr/t/64bit.h) \
    $(wildcard include/config/phys/addr/t/64bit.h) \
  /home/dhleec/Project/R328/tina/prebuilt/gcc/linux-x86/arm/toolchain-sunxi-glibc/toolchain/lib/gcc/arm-openwrt-linux-gnueabi/6.4.1/include/stdarg.h \
  include/uapi/linux/string.h \
  arch/arm/include/asm/string.h \

arch/arm/boot/compressed/string.o: $(deps_arch/arm/boot/compressed/string.o)

$(deps_arch/arm/boot/compressed/string.o):
