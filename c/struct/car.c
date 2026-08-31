#include <stdio.h>

// declares the struct type
// Sctructs are similar to classes in C++, but struct fields are public by default
struct Car { 			// 12 bytes			(32 bit-architecture)
	char *make;			// 4 bytes			(all pointers are 4 bytes)
	char *model;		// 4 bytes
	int year;			// 4 bytes
};

// We can also use typedef to create an alias for a struct type, this way we can use the alias
// to declare objects of the struct type
typedef struct {		// 16 bytes			(32 bit-architecture)
  	char *make;			// 4 bytes
   	char *model;		// 4 bytes
   	int year;			// 4 bytes
	char *status;		// 4 bytes
} Truck;

int main()
{
	// declares and initializes an object of a previously-declared struct type
	struct Car c = {
		.year = 1923,
		.make = "Nash",
		.model = "48 Sports Touring Car"
	};

    // declares and initializes an object of a struct type using the typedef alias
    Truck t = {
        .year = 1957,
        .make = "Ford",
        .model = "F-100",
		.status = "new"
	};

    // we can also use the dot operator to access the fields of the struct
    t.status = "used";

	printf("car: %d %s %s\n", c.year, c.make, c.model);
	printf("truck: %d %s %s %s\n", t.year, t.make, t.model, t.status);
    printf("Size of the struct Car: %zu bytes\n", sizeof(c));		// 24 bytes in a 64-bit architecture because of padding
    printf("Size of the struct Truck: %zu bytes\n", sizeof(t));		// 32 bytes in a 64-bit architecture because of padding
}  
