$(call inherit-product-if-exists, target/allwinner/r18-common/r18-common.mk)

PRODUCT_PACKAGES +=

PRODUCT_COPY_FILES +=

PRODUCT_AAPT_CONFIG := large xlarge hdpi xhdpi
PRODUCT_AAPT_PERF_CONFIG := xhdpi
PRODUCT_CHARACTERISTICS := musicbox

PRODUCT_BRAND := allwinner
PRODUCT_NAME := r18_m64
PRODUCT_DEVICE := r18-m64
PRODUCT_MODEL := Tulip R18 M64