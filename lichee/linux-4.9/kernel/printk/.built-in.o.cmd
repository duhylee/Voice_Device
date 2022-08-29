cmd_kernel/printk/built-in.o :=  arm-openwrt-linux-gnueabi-ld -EL    -r -o kernel/printk/built-in.o kernel/printk/printk.o kernel/printk/nmi.o 
