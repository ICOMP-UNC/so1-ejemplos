#include <cassert>
#include "reciprocal.hpp"

double reciprocal(int i)
{
	// It should be non-zero.
	assert (i != 0);

	return 1.0/i;
}
