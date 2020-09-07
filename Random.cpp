// Random.cpp
#include "Random.h"
#include <cstdlib>
// Returns a random number in r.
float Random(Range r)
{
	return r.mLow + rand() % ((r.mHigh + 1) - r.mLow);
}
// Returns a random number in [low, high].
float Random(float low, float high)
{
	return low + rand() % ((high + 1) - low);
}