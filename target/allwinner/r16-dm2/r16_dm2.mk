$(call inherit-product-if-exists, target/allwinner/r16-common/r16-common.mk)

PRODUCT_PACKAGES +=

PRODUCT_COPY_FILES +=

PRODUCT_AAPT_CONFIG := large xlarge hdpi xhdpi
PRODUCT_AAPT_PERF_CONFIG := xhdpi
PRODUCT_CHARACTERISTICS := musicbox

PRODUCT_BRAND := allwinner
PRODUCT_NAME := r16_dm2
PRODUCT_DEVICE := r16-dm2
PRODUCT_MODEL := Atar R16 Parrot
