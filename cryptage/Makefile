obj-m :=  cryptage.o
KDIR  := /lib/modules/$(shell uname -r)/build
PWD   := $(shell pwd)

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
	@rm -f *~ Module.symvers modules.order


install: cryptage.ko
	@insmod cryptage.ko

remove:
	@rmmod cryptage
