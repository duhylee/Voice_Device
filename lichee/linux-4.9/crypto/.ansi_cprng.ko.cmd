cmd_crypto/ansi_cprng.ko := arm-openwrt-linux-gnueabi-ld -EL -r  -T ./scripts/module-common.lds --build-id  -o crypto/ansi_cprng.ko crypto/ansi_cprng.o crypto/ansi_cprng.mod.o ;  true
