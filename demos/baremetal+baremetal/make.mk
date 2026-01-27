include $(bao_demos)/guests/baremetal/make.mk

ifeq ($(PLATFORM),e3650)
vm0_image:=$(wrkdir_demo_imgs)/baremetal_vm0.bin
vm0_args:=MEM_BASE=0x00B00000 MEM_SIZE=0x00100000 ARCH_CFLAGS="-Wno-error=incompatible-pointer-types"
$(eval $(call build-baremetal, $(vm0_image), $(vm0_args)))

vm1_image:=$(wrkdir_demo_imgs)/baremetal_vm1.bin
vm1_args:=MEM_BASE=0x00C00000 MEM_SIZE=0x00100000 ARCH_CFLAGS="-Wno-error=incompatible-pointer-types"
$(eval $(call build-baremetal, $(vm1_image), $(vm1_args)))

guest_images:=$(vm0_image) $(vm1_image)
endif
