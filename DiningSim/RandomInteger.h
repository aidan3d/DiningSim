// Specification file for the RandomInteger class
#ifndef RANDOMINTEGER_H
#define RANDOMINTEGER_H
#include <stdlib.h>							// Needed for rand, srand
#include <time.h>

namespace DiningSim							// DiningSim namespace definition
{

	class RandomInteger
	{
	public:
		// Overloaded () operator function.
		unsigned int operator () (unsigned int nMax);	
	
	};

} // End of the DiningSim namespace definition

#endif