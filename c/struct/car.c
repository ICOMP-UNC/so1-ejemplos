#include <stdio.h>

// declares the struct type
struct Car { 
	char *make;
	char *model;
	int year;
};

int main()
{

	// declares and initializes an object of a previously-declared struct type
	struct Car c = {
		.year=1923, 
		.make="Nash", 
		.model="48 Sports Touring Car"
	};

	printf("car: %d %s %s\n", c.year, c.make, c.model);

}  
