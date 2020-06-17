#pragma once
#include"math.h"

double Square_root(const double a)
{
	if (a >= 0)
		return sqrt(a);
	else
		return -1;
}