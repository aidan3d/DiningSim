// Implementation file for the Server base class
#include "Server.h"

//*************************************************************
// Name:        addTable                                      *
//                                                            *
// Parms:       obj : Table & (reference to a Table object)   *
//                                                            *
// Return:                                                    *
//                                                            *
// Description: The addTable member functions simulates       *
//              the EVENT of a table being 'greeted' at a     *
//              by a server in order to initiate the          *
//              ordering process.                             *
//                                                            *
//*************************************************************

void DiningSim::Server::addTable(const Table &obj)
{ 
	m_cTable = obj;						//   1) Store the new table
										//      in the instance variable
										//      m_cTable

	m_bFree = false;					//   2) Lower the flag to signal
										//      that the server is not 
										//      free;

}


//*************************************************************
// Name:        addTableToHeadCount                           *
//                                                            *
// Parms:       nInputTableNumber    : int                    *
//              nInputNumberOfGuests : int                    *
//                                                            *
// Return:                                                    *
//                                                            *
// Description: Adds the table currently being served to the  *
//              servers 'head count' list.                    *
//                                                            *
//*************************************************************

void DiningSim::Server::addTableToHeadCount(int nInputTableNumber,
											int nInputNumberOfGuests)
{
	// Create a HeadCount node
	HeadCount cNewHeadCount;
	
	// Store the number of the servers' current table
	// in the new HeadCount object.
	cNewHeadCount.setTableNumber(nInputTableNumber);
	
	// Store the number of guests at the server's
	// current table in the HeadCount object.
	cNewHeadCount.setNumberOfGuests(nInputNumberOfGuests);

	// Add the HeadCount object to the 'head count' deque
	// stack for the server's total number of tables
	// served (along with the guest count for each table
	// served)
	m_scHeadCount.push(cNewHeadCount);
}

//***********************************************************
// Name:        isFree                                      *
//                                                          *
// Parms:                                                   *
//                                                          *
// Return:      true or false                               *
//                                                          *
// Description: This function is used to figure out         *
//              if the server is yet free to take another   *
//              table.                                      *
//                                                          *
//***********************************************************

bool DiningSim::Server::isFree()
{
	if (m_bFree == true)
	{
		return true;
	
	} // End of the if statement

	
	// If the party has finshed being giving
	// their order to their server...
	if (m_cTable.doneOrdering())
	{
		m_bFree = true;
	
	} // End of the if statement

	return m_bFree;

}

