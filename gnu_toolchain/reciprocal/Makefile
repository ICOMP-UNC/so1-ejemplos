reciprocal: main.o reciprocal.o
	g++ $(CFLAGS) -o reciprocal main.o reciprocal.o

main.o: main.c reciprocal.hpp
	gcc $(CFLAGS) -c main.c

reciprocal.o: reciprocal.cpp reciprocal.hpp
	g++ $(CFLAGS) -c reciprocal.cpp

clean:
	rm -f *.o reciprocal

# TAREA PARA EL ALUMNO
# Suppose that your project has one directory called src, for source files, and another called include.
# To indicate that g++ should use the ../include directory:
# % g++ -c -I ../include reciprocal.cpp
# The -I option tell GCC where to search for header files.
