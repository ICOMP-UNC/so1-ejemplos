#include <cassert>
#include "reciprocal.hpp"

double reciprocal(int i)
{
	// It should be non-zero.
	assert (i != 0);

	// return 1/i; //Floating point exception (core dumped)
	return 1.0/i;
}


/*
% ./reciprocal 0
The reciprocal of 0 is inf

% gcc --version
gcc (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0
Copyright (C) 2019 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/