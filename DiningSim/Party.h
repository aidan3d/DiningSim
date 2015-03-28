// Specification for the Party class
#ifndef PARTY_H
#define PARTY_H
#include "RandomInteger.h"
#include <iostream>

namespace DiningSim
{
	
	class Party
	{
	protected:

		int           m_nNumberOfGuests;		// The party's guest count
												// 1, 2, 3 or 4

		unsigned int  m_nArrivalTime;			// Time party arrives at
												//   the restaurant, time is
												//   measured in minutes.

		unsigned int  m_nTimeInRestaurant;		// Length of the party's 
												// stay (in to out,) 
												//   time is measured
												//   in minutes

		RandomInteger m_cRandomizer;	//  Random arrival time
	
	public:
		
		// Constructor #1
		Party() 
			{ m_nNumberOfGuests = 0;
			  m_nArrivalTime = 0;
			  m_nTimeInRestaurant = 0; }

		// Constructor #2
		Party(int nInputArrivalTime) 
			{ m_nNumberOfGuests = 1 + m_cRandomizer(4);
			  m_nArrivalTime = nInputArrivalTime;
			  m_nTimeInRestaurant= 0; }

		// Accessors
		int arrival() const
			{ return m_nArrivalTime; }

		int getTimeInRestaurant() const
			{ return m_nTimeInRestaurant;}

		int getNumberOfGuests() const
			{ return m_nNumberOfGuests; }

		// Mutators			
		void addTimeInRestaurant(int nInputMinutes)		// Add minutes to the
			{ m_nTimeInRestaurant += nInputMinutes; }	//   party's elapsed time
														//   in the restaurant
					
		bool done()
			{return --m_nTimeInRestaurant == 0; }		// Return true if a 
														//   table is free.

		// Overloaded operator functions
		bool operator < (Party &obj)					// Order by arrival time
			{ return m_nArrivalTime < obj.m_nArrivalTime; }
	
		bool operator == (Party &obj)			// No two customers are alike
			{ return false; }					//   ...so return 'false' if
												//   they match.
	};

} // End of the DiningSim namespace definition

#endif

