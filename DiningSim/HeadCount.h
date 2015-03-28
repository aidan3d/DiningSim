// Specification for the HeadCount class
#ifndef HEADCOUNT_H
#define HEADCOUNT_H
#include <string>

namespace DiningSim						// DiningSim namespace
										// definition
{

	class HeadCount 
	{
	protected:
		int m_nTableNumber;
		int m_nNumberOfGuests;
	public:
		// Constructor
		HeadCount()
			{ m_nTableNumber = 0;
			  m_nNumberOfGuests = 0;}

		// Mutators
		void setTableNumber(int nInputTableNumber)
			{ m_nTableNumber = nInputTableNumber; }

		void setNumberOfGuests(int nInputNumberOfGuests)
			{ m_nNumberOfGuests = nInputNumberOfGuests; }

		// Accessors
		int getTableNumber() const
			{ return m_nTableNumber; }

		int getNumberOfGuests() const
			{ return m_nNumberOfGuests; }
	};

}										// End of the DiningSim namespace
										// definition

#endif

