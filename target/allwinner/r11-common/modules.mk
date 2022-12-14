#
# Copyright (C) 2015-2016 Allwinner
#
# This is free software, licensed under the GNU General Public License v2.
# See /build/LICENSE for more information.
#
define KernelPackage/sunxi-vfe
  SUBMENU:=$(VIDEO_MENU)
  TITLE:=sunxi-vfe support
  FILES:=$(LINUX_DIR)/drivers/media/video/videobuf-core.ko
  FILES+=$(LINUX_DIR)/drivers/media/video/videobuf-dma-contig.ko
  FILES+=$(LINUX_DIR)/drivers/media/video/sunxi-vfe/csi_cci/cci.ko
  FILES+=$(LINUX_DIR)/drivers/media/video/sunxi-vfe/vfe_os.ko
  FILES+=$(LINUX_DIR)/drivers/media/video/sunxi-vfe/vfe_subdev.ko
  FILES+=$(LINUX_DIR)/drivers/media/video/sunxi-vfe/device/hm2131.ko
  FILES+=$(LINUX_DIR)/drivers/media/video/sunxi-vfe/device/n3.ko
  FILES+=$(LINUX_DIR)/drivers/media/video/sunxi-vfe/vfe_v4l2.ko
  AUTOLOAD:=$(call AutoLoad,90,videobuf-core videobuf-dma-contig cci vfe_os vfe_subdev hm2131 n3 vfe_v4l2)
endef

define KernelPackage/sunxi-vfe/description
  Kernel modules for sunxi-vfe support
endef

$(eval $(call KernelPackage,sunxi-vfe))

define KernelPackage/sunxi-sound
  SUBMENU:=$(SOUND_MENU)
  DEPENDS:=+kmod-sound-core
  TITLE:=sun8iw8 sound support
  FILES:=$(LINUX_DIR)/sound/soc/sunxi/audiocodec/sun8iw8_sndcodec.ko
  FILES+=$(LINUX_DIR)/sound/soc/snd-soc-core.ko
  FILES+=$(LINUX_DIR)/sound/soc/sunxi/audiocodec/sunxi_sndcodec.ko
  FILES+=$(LINUX_DIR)/drivers/base/regmap/regmap-i2c.ko
  FILES+=$(LINUX_DIR)/drivers/base/regmap/regmap-spi.ko
  FILES+=$(LINUX_DIR)/sound/soc/sunxi/audiocodec/switch_hdset.ko
  FILES+=$(LINUX_DIR)/sound/soc/sunxi/audiocodec/sunxi_codecdma.ko
  FILES+=$(LINUX_DIR)/sound/soc/sunxi/audiocodec/sunxi_codec.ko
  FILES+=$(LINUX_DIR)/sound/core/seq/snd-seq.ko
  FILES+=$(LINUX_DIR)/sound/soc/snd-soc-core.ko
  AUTOLOAD:=$(call AutoLoad,30,sun8iw8_sndcodec switch_hdset snd-soc-core sunxi_sndcodec sunxi_codecdma sunxi_codec snd-seq regmap-i2c   regmap-spi)
endef

define KernelPackage/sunxi-sound/description
  Kernel modules for sun8iw8-sound support
endef

$(eval $(call KernelPackage,sunxi-sound))

define KernelPackage/leds-sunxi
  SUBMENU:=$(LEDS_MENU)
  TITLE:=leds-sunxi support
  FILES:=$(LINUX_DIR)/drivers/leds/leds-sunxi.ko
  KCONFIG:=CONFIG_LEDS_SUNXI
  AUTOLOAD:=$(call AutoLoad,60,leds-sunxi)
endef

define KernelPackage/leds-sunxi/description
  Kernel modules for leds sunxi support
endef

$(eval $(call KernelPackage,leds-sunxi))

define KernelPackage/ledtrig-doubleflash
  SUBMENU:=$(LEDS_MENU)
  TITLE:=LED DoubleFlash Trigger
  KCONFIG:=CONFIG_LEDS_TRIGGER_DOUBLEFLASH
  FILES:=$(LINUX_DIR)/drivers/leds/ledtrig-doubleflash.ko
  AUTOLOAD:=$(call AutoLoad,50,ledtrig-doubleflash)
endef

define KernelPackage/ledtrig-doubleflash/description
 Kernel module that allows LEDs to be controlled by a programmable doubleflash
 via sysfs
endef

$(eval $(call KernelPackage,ledtrig-doubleflash))
