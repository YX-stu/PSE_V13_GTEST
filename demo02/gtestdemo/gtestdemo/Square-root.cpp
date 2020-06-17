#include "Square-root.h"
#include "cmath"
//
// define function
//

double square_root(const double a)
{
	if (a >= 0)
		return sqrt(a);
	else
		return -1;
}