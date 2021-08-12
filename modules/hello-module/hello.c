#include <linux/kernel.h>
#include <linux/module.h>

/*
* Get rid of the WARNING: modpost: missing MODULE_LICENSE()
* by declaring code as GPL.
*/
MODULE_LICENSE("GPL");

int hello_init(void)
{
    printk(KERN_INFO "Hola Mundo!\n");
    return 0;
}

void hello_exit(void)
{
    printk(KERN_INFO "Adios Mundo Cruel!\n");
}


module_init(hello_init);
module_exit(hello_exit);

/*

$ sudo insmode ./hello.ko

$ cat  /proc/modules | grep hello
hello 16384 0 - Live 0x0000000000000000 (OE)

$ kmod list | grep hello
Module                  Size  Used by
hello                  16384  0

$ cat /var/log/syslog | grep Hola
Nov  5 19:27:41 pablo kernel: [ 7353.271985] Hola Mundo!

$ sudo rmod ./hello.ko

$ cat /var/log/syslog | grep Adios
Nov  5 19:51:52 pablo kernel: [ 8804.273746] Adios Mundo Cruel!

# or ussing dmesg - print or control the kernel ring buffer
$ dmesg -T
*/
