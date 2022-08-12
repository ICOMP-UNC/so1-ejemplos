# create objects
gcc -c test1.c 
gcc -c test2.c 
gcc -c app.c 

# create lib
ar cr libtest.a test1.o test2.o

# list files in library
ar -t libtest.a
# test1.o
# test2.o

# BAD ORDER, link against the lib
gcc -o app -L. -ltest app.o

# NO location option
gcc -o app app.o -ltest
# /usr/bin/ld: cannot find -ltest
# collect2: error: ld returned 1 exit status

# link against the lib
gcc -o app app.o -L. -ltest

# run and check result
./app 
echo $?

# Inspecting Symbols
# ------------------
nm app.o
#                  U f
#                  U g
#                  U _GLOBAL_OFFSET_TABLE_
# 0000000000000000 T main
nm libtest.a
# test1.o:
# 0000000000000000 T f
# test2.o:
# 0000000000000000 T g

nm app | grep  -n -E -w "g|f"
# -n print line numbers
# -E To use a Regular Expression (g or f function)
# -w match entire words only

# MORE INFO
# ---------

# About _GLOBAL_OFFSET_TABLE_
# https://refspecs.linuxfoundation.org/ELF/zSeries/lzsabi0_zSeries/x2251.html

# About grep
https://phoenixnap.com/kb/grep-command-linux-unix-examples

# list dynamic dependencies
ldd app
# linux-vdso.so.1 (0x00007ffc261ed000)
# libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007f6a7b2e8000)
# /lib64/ld-linux-x86-64.so.2 (0x00007f6a7b4fa000)
