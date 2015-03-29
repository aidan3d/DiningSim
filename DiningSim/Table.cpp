// Implementation file for the Table class.
#include "Table.h"

//***********************************************************
// Name:        Table                                       *
//                                                          *
// Parms:       nInputTableNumber : int                     *
//                                                          *
// Return:                                                  *
//                                                          *
// Description: Constructor #3. Creates a table with        *
//              its table number as the onlyd parameter.    *
//              E.g. "Build table 41."                      *
//                                                          *
//***********************************************************

DiningSim::Table::Table(int nInputTableNumber)
{
	// TODO: Implement Method
	throw "Not Implemented Exception: DiningSim::Table::Table(int nInputTableNumber)";
}

//***********************************************************
// Name:        addOrderTime                                *
//                                                          *
// Parms:       nInputOrderTime : int                       *
//                                                          *
// Return:                                                  *
//                                                          *
// Description:                                             *
//                                                          *
//***********************************************************

void DiningSim::Table::addOrderTime(int nInputOrderTime)
{
	// TODO: Implement Method
	throw "Not Implemented Exception: void DiningSim::Table::addOrderTime(int nInputOrderTime)";
}

//***********************************************************
// Name:        addParty                                    *
//                                                          *
// Parms:       obj : Party & (reference)                   *
//                                                          *
// Return:                                                  *
//                                                          *
// Description: The addParty member function  simulates     *
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
// Description: This member function is used to figure      *
//              out if the table is yet free for a new      *
//              customer.                                   *
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
		m_bFree = true;		// ...make the table free
	}

	return m_bFree;

}

