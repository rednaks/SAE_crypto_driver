obj-m := comm.o
KDIR  := /lib/modules/$(shell uname -r)/build
PWD   := $(shell pwd)
DRV   := /dev/comm


all: 
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
	@rm -f *~ Module.symvers modules.order
#
$(DRV):
	@mknod $(DRV) c 150 3
	@mknod $(DRV)0 c 150 0
	@mknod $(DRV)1 c 150 1
	@chmod a+rw $(DRV)*


install:$(DRV)
	@insmod comm.ko

remove:
	@rmmod comm

