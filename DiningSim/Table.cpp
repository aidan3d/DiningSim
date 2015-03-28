// Implementation file for the Table class
#include "Table.h"

//***********************************************************
// Name:        addParty                                    *
//                                                          *
// Parms:       obj : Party & (reference)                   *
//                                                          *
// Return:                                                  *
//                                                          *
// Description: The addParty member functions simulates     *
//              the EVENT of a party being 'sat' at a       *
//              table.                                      *
//                                                          *
//***********************************************************

void DiningSim::Table::addParty(const Party &obj)
{ 
	m_cParty = obj;						//   1) Store the new party
										//      in the instance variable
										//      m_cParty

	m_nSeatsOccupied = 					//   2) Transfer the
		obj.getNumberOfGuests();		//       number of heads

	m_bFree = false;					//   3) Lower the flag to signal
										//      that the table is no 
										//      longer free;

}

//***********************************************************
// Name:        isFree                                      *
//                                                          *
// Parms:                                                   *
//                                                          *
// Return:      true or false                               *
//                                                          *
// Description: This function is used to figure out         *
//              if the table is yet free for a new          *
//              customer.
//                                                          *
//***********************************************************

bool DiningSim::Table::isFree()
{
	if (m_bFree)
	{
		return true;

	} // End of the if statement

	// If the party has finished their meal...
	if (m_cParty.done())
	{
		m_bFree = true;		// Make the table free
	}
	
	return m_bFree;

}

