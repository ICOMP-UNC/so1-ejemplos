// s.d is a flexible array member
struct s { 
	int n;
	double d[];
};

/*
Initialization, sizeof, and the assignment operator
ignore the flexible array member. 

Structures with flexible array members (or unions whose
last member is a structure with flexible array member)
cannot appear as array elements or as members of other structures.
*/

int main()
{

	// OK: d is as if double d[1], but undefined behaviour (UB) to access
	struct s t1 = {0};

	// error: non-static initialization of a flexible array member
	struct s t2 = {0,1};

	// error: initialization ignores flexible array
	// error: non-static initialization of a flexible array member
	struct s t3 = { 1, { 4.2 } }; 
}
