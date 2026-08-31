#include <stdlib.h>
#include <stdio.h>
/*
struct with flexible array member
+++++++++++++++++++++++++++++++++

Initialization, sizeof, and the assignment operator
ignore the flexible array member. 

Structures with flexible array members (or unions whose
last member is a structure with flexible array member)
cannot appear as array elements or as members of other structures.
*/

// s.d is a flexible array member
struct s { 
	int n;
	double d[];
};

int main()
{
	// OK: d is as if double d[1], but undefined behaviour (UB) to access
	struct s t1 = {0};

    #if 0
	// error: non-static initialization of a flexible array member
	struct s t2 = {0, 1};

	// error: initialization ignores flexible array
	// error: non-static initialization of a flexible array member
	struct s t3 = { 1, { 4.2 } };
	#endif

    // To work with flexible array members, you must allocate memory for the struct
	struct s *t4 = malloc(sizeof(struct s) + sizeof(double) * 2);
	t4->n = 7;
	t4->d[0] = 1.0;
	t4->d[1] = 2.0;

	printf("Memory allocated for 2\n");
	for (int i = 0; i < 5; i++) {		// Undefined behavior for i >= 2
		printf("%f\n", t4->d[i]);
	}

	// To change the size of the flexible array member, you must reallocate memory
	t4 = realloc(t4, sizeof(struct s) + sizeof(double) * 5);
    t4->d[2] = 3.0;
    t4->d[3] = 4.0;
    t4->d[4] = 5.0;

    printf("Memory allocated for 5\n");
	for (int i = 0; i < 5; i++) {
		printf("%f\n", t4->d[i]);
	}
}
