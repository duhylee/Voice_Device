cmd_fs/fuse/fuse.ko := arm-openwrt-linux-gnueabi-ld -EL -r  -T ./scripts/module-common.lds --build-id  -o fs/fuse/fuse.ko fs/fuse/fuse.o fs/fuse/fuse.mod.o ;  true
