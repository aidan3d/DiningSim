// Implementation file for the RandomInteger class
#include "RandomInteger.h"
#include <iostream>
#include <cstdlib>				// Needed by the rand function

//**************************************************************
// Name:                                                       *
//                                                             *
// Parms:       nMax : unsigned int                            *
//                                                             *
// Return:      unsigned int (a positive integer in the range  *
//                            0 - max)                         *
//                                                             *
// Description: Overload () operator function.                 *
//                                                             *
//**************************************************************

unsigned int DiningSim::RandomInteger::operator () (unsigned int nMax)
{
	
	// Converts the unsigned int returned by rand 
	// into a positive number...
	unsigned int rval = rand();
	
	// ...and then return the 'remainder':
	// a number in the range 0 to (max - 1)
	return rval % (nMax);

}

