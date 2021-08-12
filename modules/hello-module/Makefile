# "kbuild" is the build system used by the Linux kernel. Modules must use
# kbuild to stay compatible with changes in the build infrastructure and
# to pick up the right flags to "gcc."

# To build external modules, you must have a prebuilt kernel available
# that contains the configuration and header files used in the build.
# Also, the kernel must have been built with modules enabled. If you are
# using a distribution kernel, there will be a package for the kernel you
# are running provided by your distribution.

# The kbuild system will build <module_name>.o from <module_name>.c,
# and, after linking, will result in the kernel module <module_name>.ko.
obj-m := hello.o

KERNELDIR ?= /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)
       

# modules
# 		The default target for external modules. It has the
# 		same functionality as if no target was specified. See
# 		description above.
default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules

# clean
# 		Remove all generated files in the module directory onl
clean:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) clean
