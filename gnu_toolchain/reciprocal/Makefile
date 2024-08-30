reciprocal: main.o reciprocal.o
	g++  $(CFLAGS) -o reciprocal main.o reciprocal.o

main.o: main.c reciprocal.hpp
	gcc $(CFLAGS) -c main.c

reciprocal.o: reciprocal.cpp reciprocal.hpp
	g++ $(CFLAGS) -c reciprocal.cpp
	# @g++ $(CFLAGS) -c reciprocal.cpp -> @ will silent the rule.

clean:
	rm -f *.o reciprocal

# The $(CFLAGS) is a make variable.You can define this variable either
# in the Makefile itself or on the command line:
#
# % make CFLAGS=-O2
#
# Compile with debuging enabled:
# % make CFLAGS=-g
#
# If you now change main.c in some trivial way and type make again,
# you can see that make knew to rebuild main.o and to re-link the program,
# but it didn’t bother to recompile reciprocal.cpp because none of the
# dependencies for reciprocal.o had changed.
#
#
# TAREA PARA EL ALUMNO
# Suppose that your project has one directory called src, for source files, and another called include.
# To indicate that g++ should use the ../include directory:
# % g++ -c -I ../include reciprocal.cpp
# The -I option tell GCC where to search for header files.


