cmd_crypto/cts.ko := arm-openwrt-linux-gnueabi-ld -EL -r  -T ./scripts/module-common.lds --build-id  -o crypto/cts.ko crypto/cts.o crypto/cts.mod.o ;  true
