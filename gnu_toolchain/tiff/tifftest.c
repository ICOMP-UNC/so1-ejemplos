 /*
 * Using libtiff
 * Small program that uses libtiff to open a TIFF image file
 *
 * First install the lib:
 * $ sudo apt install libtiff-dev
 * 
 * Then, you can check the manual:
 * $ man libtiff
 *
 */

#include <stdio.h>
#include <tiffio.h>

int main (int argc, char** argv)
{
	TIFF* tiff;
	tiff = TIFFOpen (argv[1], "r");
	TIFFClose (tiff);

	return 0;
}

/*
$ ldd a.out 
	linux-vdso.so.1 (0x00007ffdee17b000)
	libtiff.so.5 => /usr/lib/x86_64-linux-gnu/libtiff.so.5 (0x00007fc834b8a000)
	libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007fc834998000)
	libwebp.so.6 => /usr/lib/x86_64-linux-gnu/libwebp.so.6 (0x00007fc83472f000)
	libzstd.so.1 => /usr/lib/x86_64-linux-gnu/libzstd.so.1 (0x00007fc834686000)
	liblzma.so.5 => /lib/x86_64-linux-gnu/liblzma.so.5 (0x00007fc83465d000)
	libjbig.so.0 => /usr/lib/x86_64-linux-gnu/libjbig.so.0 (0x00007fc83444f000)
	libjpeg.so.8 => /usr/lib/x86_64-linux-gnu/libjpeg.so.8 (0x00007fc8343c8000)
	libz.so.1 => /lib/x86_64-linux-gnu/libz.so.1 (0x00007fc8343ac000)
	libm.so.6 => /lib/x86_64-linux-gnu/libm.so.6 (0x00007fc83425d000)
	/lib64/ld-linux-x86-64.so.2 (0x00007fc834c2b000)
	libpthread.so.0 => /lib/x86_64-linux-gnu/libpthread.so.0 (0x00007fc83423a000)
*/

// (base) pablo@pablo:~/so1/clases/2_gnu_toolchain/examples/tiff$ gcc tifftest.c
// tifftest.c: In function ‘main’:
// tifftest.c:18:2: error: unknown type name ‘TIFF’
//    18 |  TIFF* tiff;
//       |  ^~~~
// tifftest.c:19:9: warning: implicit declaration of function ‘TIFFOpen’ [-Wimplicit-function-declaration]
//    19 |  tiff = TIFFOpen (argv[1], "r");
//       |         ^~~~~~~~
// tifftest.c:19:7: warning: assignment to ‘int *’ from ‘int’ makes pointer from integer without a cast [-Wint-conversion]
//    19 |  tiff = TIFFOpen (argv[1], "r");
//       |       ^
// tifftest.c:20:2: warning: implicit declaration of function ‘TIFFClose’ [-Wimplicit-function-declaration]
//    20 |  TIFFClose (tiff);
//       |  ^~~~~~~~~

// link against libtiff.so
// (base) pablo@pablo:~/so1/clases/2_gnu_toolchain/examples/tiff$ gcc tifftest.c -ltiff
