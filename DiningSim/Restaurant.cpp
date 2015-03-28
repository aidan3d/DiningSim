// Implementation file for the Restaurant class
#include "Restaurant.h"

//***********************************************************
// Name:                                                    *
//                                                          *
// Parms:                                                   *
//                                                          *
// Return:                                                  *
//                                                          *
// Description: Constructor #1 (Default)                    *
//                                                          *
//***********************************************************

DiningSim::Restaurant::Restaurant()
{
	// Initialize the instance variables.
	m_nNumberOfMinutes     = 0;
	m_nNumberOfTables      = 0;
	m_nNumberOfServers     = 0;
	m_nNumberOfLineCooks   = 0;
	
	m_nLevelOfBusiness     = 0;
	
	m_nNumberOfParties     = 0;
	m_nMinWaitTime         = 0;
    m_nMaxWaitTime         = 0;
	m_nTotalWaitTime       = 0;
	m_nTotalServerWaitTime = 0;

	m_nBeginTime           = 0;
	m_nEndTime             = 0;
	m_nTime                = 0;	
}

//***********************************************************
// Name:                                                    *
//                                                          *
// Parms:                                                   *
//                                                          *
// Return:                                                  *
//                                                          *
// Description: Constructor #2. Starts the simulation.      *
//                                                          *
//***********************************************************

DiningSim::Restaurant::Restaurant(int nInputNumberOfMinutes,
								  int nInputNumberOfTables,
								  int nInputNumberOfServers,
								  int nInputNumberOfLineCooks)
{  
	// Initialize the instance variables
	m_nNumberOfMinutes     = nInputNumberOfMinutes;
	m_nNumberOfTables      = nInputNumberOfTables;
	m_nNumberOfServers     = nInputNumberOfServers;
	m_nNumberOfLineCooks   = nInputNumberOfLineCooks;

	m_nLevelOfBusiness     = 0;

	m_nNumberOfParties     = 0;
	m_nMinWaitTime         = 0;
    m_nMaxWaitTime         = 0;
	m_nTotalWaitTime       = 0;
	m_nTotalServerWaitTime = 0;

	m_nBeginTime           = 0;
	m_nEndTime             = 0;

	m_nTime                = 0;
	

	// Initialize the vector of tables.
	buildTables();
	std::cout << "\t\ttables built..."      << std::endl;
	std::cout << std::endl;


	// Deploy the servers
	deployServers();
	std::cout << "\t\tserver's \"aproned-up\" and ready to go!" << std::endl;
	std::cout << std::endl;
	
}

//***********************************************************
// Name:        addPartyToTableWaitList                     *
//                                                          *
// Parms:                                                   *
//                                                          *
// Return:                                                  *
//                                                          *
// Description: A party has just walked in the door.        *
//              This function puts them on the wait list    *
//              for the next available table.               *
//                                                          *
//***********************************************************

void DiningSim::Restaurant::addPartyToTableWaitQueue(
	const int nCurrentTime)
{				
	Party cNewParty(nCurrentTime);		// ...the next party 
										//   arriving in the
										//   restaurant has to
										//   go on a 'wait.

	m_qcTableWaitQueue.push(cNewParty);	// Add all incoming 
										//   parties to the 
										//   table wait list
}

//*************************************************************
// Name:        buildTables                                   *
//                                                            *
// Parms:                                                     *
//                                                            *
// Return:                                                    *
//                                                            *
// Description: This function 'builds' the tables for         *
//              the restaurant by adding the appropriate      * 
//              number of elements to the vector m_vcTables.  *
//                                                            *
//*************************************************************

void DiningSim::Restaurant::buildTables()
{
	for (int nCounter = 0; nCounter < m_nNumberOfTables; nCounter++)
	{
		Table cNewTable((nCounter + 1), 0);			// Create a temporary 
													//   Table object with
													//   a table number and
													//   zero for the 'sat
													//   time,' i.e. the tim
													//   a party sat at this
													//   element in the vector
													//  (in time units of 
													//    minutes)

		m_vcTables.push_back(cNewTable);			// Load up the vector 
													//    of tables.
				
	} // End of the for statement
}

//***************************************************************
// Name:        deployServers                                   * 
//                                                              *
// Parms:                                                       *
//                                                              *
// Return:                                                      *
//                                                              *
// Description: This function deploys the server onto the       *
//              restaurant 'floor' by adding the appropriate    * 
//              number of elements to the vector m_vcServers.   *
//                                                              *
//***************************************************************

void DiningSim::Restaurant::deployServers()
{
	for (int nCounter = 0; nCounter < m_nNumberOfServers; nCounter++ )
	{	
		Server cNewServer;					// Create a temporary 
											//   Server object
		cNewServer.setCutOrder(nCounter + 1);  // Set the 'cut order;'
											   // higher numbers get
											   // to serve first, and
											   // leave last

		m_vcServers.push_back(cNewServer);	// Load up the vector 
											//    of servers.
	
	} // End of the for statement


}

//************************************************************
// Name:        getAverageServerWaitTime                     *
//                                                           *
// Parms:                                                    *
//                                                           *
// Return:     The average time a table waited for a server  *
//             in minutes                                    *
//                                                           *
// Description: This accessor function returns the average   *
//              time a table has waited for a server to be   *
//              assigned to it. Measured in minutes.         *
//                                                           *
//************************************************************

double DiningSim::Restaurant::getAverageServerWaitTime() const
{
	double dAverageServerWaitTime;	// Create a variable to hold
									// the average time a table
									// has waited for a free
									// server. Measured in minutes

	// Compute the average server wait time in minutes.
	// Will recast total server wait time as a double to avoid
	// an integer division 'rounding' error.
	dAverageServerWaitTime = 
		static_cast<double>(m_nTotalServerWaitTime) 
		/ (m_nNumberOfParties + 1);



	return dAverageServerWaitTime;
}

//************************************************************
// Name:        getAverageTableWaitTime                      *
//                                                           *
// Parms:                                                    *
//                                                           *
// Return:      The average time a party has waited for a    *
//              table in minutes.                            *
//                                                           *
// Description: This accessor function returns the average   *
//              time that a party has waited for a table     *
//              to be free. Measured in minutes.             *
//                                                           *
//************************************************************

double DiningSim::Restaurant::getAverageTableWaitTime() const
{
	double dAverageWaitTime;		// Create a variable to hold the
									//   average wait time. Measured
									//   in minutes

	

	// Compute the average wait time in minutes.
	// Will recast total wait time as a double to avoid
	// an integer division 'rounding' error.
	dAverageWaitTime = 
		static_cast<double>(m_nTotalWaitTime) / (m_nNumberOfParties + 1);

	

	return dAverageWaitTime;
}

//*************************************************************
// Name:        greetTable                                    *
//                                                            *
// Parms:                                                     *
//                                                            *
// Return:                                                    *
//                                                            *
// Description: This function assigns a server to a table.    *
//                                                            *
//*************************************************************

void DiningSim::Restaurant::greetTable(
	const int nCurrentTime, const int nCurrentServer)
{
	
	int nServiceTime = 0;		// Create and initialize a varialbe
								// to hold the time a server needs
								// to server each guest, dependent
								// upon 'skill' level
	
	// 1) Return the party who've waited longest...
	Table cFrontTable = m_qcServerWaitQueue.front();

	// 2) Raise the 'we have a server' signal
	//    flag.
	cFrontTable.greeted();
	
	// 3) Add the current table to the server's
	//    'head count' of tables served.
	m_vcServers[nCurrentServer].addTableToHeadCount(
		cFrontTable.getTableNumber(),
		cFrontTable.getSeatsOccupied());

	// 4) Add an approximate 'take party's
	//         order' time 
	//        (i.e. nServiceTime * number of guests)

	switch (m_vcServers[nCurrentServer].getServerSkillLevel())
	{
		case 1:					// The server is a 'professional'
			nServiceTime = 2;
			break;
		case 2:					// The server is 'seasoned'
			nServiceTime = 3;
			break;
		case 3:					// The server is a 'newbie'
			nServiceTime = 5;
			break;
		
	} // End of the switch statement


	cFrontTable.addServiceTime(cFrontTable.getSeatsOccupied() 
		* nServiceTime);

	// 5) Greet the party
	m_vcServers[nCurrentServer].addTable(cFrontTable);
	
	// 6) State that the party has been
	//    greeted:
	std::cout << "Table " << cFrontTable.getTableNumber();
	std::cout << " waited "; 
	std::cout << (nCurrentTime - cFrontTable.getTimeSeated());
	std::cout << " mins for server #";
	std::cout << m_vcServers[nCurrentServer].getCutOrder();
	std::cout << "." << std::endl; 
	std::cout << std::endl;

	// 7) Accumulate the total time tables have waited
	//    for a free server.
	m_nTotalServerWaitTime 
		+= (nCurrentTime - cFrontTable.getTimeSeated());

	// 8) Remove the party which has waited
	//    longest from the server wait list...
	//    they've just gotten a server!
	m_qcServerWaitQueue.pop();

}

//*************************************************************
// Name:        addTableToServerWaitList                      *
//                                                            *
// Parms:                                                     *
//                                                            *
// Return:                                                    *
//                                                            *
// Descritpion: A party has just been 'sat.'                  *
//              This function puts the on the wait list for   *
//              the next available server                     *
//                                                            *
//*************************************************************

void DiningSim::Restaurant::addTableToServerWaitQueue(
	const int nCurrentTime, const Table &obj)
{
	m_qcServerWaitQueue.push(obj);		// 1) put the newly-seated
										//    party's table on
										//    the server wait
										//    list
}

//***************************************************************
// Name:        resetServers                                    *
//                                                              *
// Parms:                                                       *
//                                                              *
// Returns:                                                     *
//                                                              *
// Description: This function clears all elements from          *
//              the vector of Server objects.                   *
//                                                              *
//***************************************************************

void DiningSim::Restaurant::resetServers()
{
	// Empty the vector of Server objects.
	while (!m_vcServers.empty())
	{
		m_vcServers.pop_back();
	
	} // End of while statement

}

//*************************************************************
// Name:       resetServerWaitQueue                           *
//                                                            *
// Parms:                                                     *
//                                                            *
// Return:                                                    *
//                                                            *
// Description: This function empties the table wait queue.   *
//                                                            *
//*************************************************************

void DiningSim::Restaurant::resetServerWaitQueue()
{
	// Dequeue all elements from the server
	// wait queue.
	while (!m_qcServerWaitQueue.empty())
	{
		m_qcServerWaitQueue.pop();
	
	} // End of while statement

}

//***************************************************************
// Name:        resetTables                                     *
//                                                              *
// Parms:                                                       *
//                                                              *
// Returns:                                                     *
//                                                              *
// Description: This function clears all elements from the      *
//              vector of Table objects.                        *
//                                                              *
//***************************************************************

void DiningSim::Restaurant::resetTables()
{
	// Empty the vector of Server objects.
	while (!m_vcTables.empty())
	{
		m_vcTables.pop_back();
	
	} // End of while statement

}

//*************************************************************
// Name:       resetTableWaitQueue                            *
//                                                            *
// Parms:                                                     *
//                                                            *
// Return:                                                    *
//                                                            *
// Description: This function empties the table wait queue.   *
//                                                            *
//*************************************************************

void DiningSim::Restaurant::resetTableWaitQueue()
{
	// Dequeue all elements from table
	// wait queue
	while (!m_qcTableWaitQueue.empty())
	{
		m_qcTableWaitQueue.pop();
	
	} // End of while statement

}

//*************************************************************
// Name:        seatParty                                     *
//                                                            *
// Parms:                                                     *
//                                                            *
// Return:                                                    *
//                                                            *
// Description: This function removes the party at the front  *
//              of the wait queue and shows them to their     *
//              table.                                        *
//                                                            *
//*************************************************************

void DiningSim::Restaurant::seatParty(
	const int nCurrentTable, const int nCurrentTime)
{
	// 1. Add an approximate dine time.
	m_qcTableWaitQueue.front().addTimeInRestaurant(
		38 + m_cRandomizer(60));
	
	// 2. Return the party who've waited longest...
	Party cFrontParty = m_qcTableWaitQueue.front();

	
	// 3. Increment the number of parties which
	//    have been seated.
	m_nNumberOfParties++;

	// 4. Display time in 'wait' queue.
	std::cout << "Party #" << m_nNumberOfParties << std::endl;
	std::cout << "Table " << m_vcTables[nCurrentTable].getTableNumber(); 
	std::cout << " (" << cFrontParty.getNumberOfGuests();
	std::cout << "-top) seated, having waited ";
	std::cout << (nCurrentTime - cFrontParty.arrival());
	std::cout << " mins for a table.\n";

	// 5. Accumulate the total wait time.
	m_nTotalWaitTime += (nCurrentTime - cFrontParty.arrival());


	// 6. Seat the party.
	m_vcTables[nCurrentTable].addParty(cFrontParty);

	// 7. Assign the time that the table was 'sat' to
	//    the Table object
	m_vcTables[nCurrentTable].setTimeSeated(nCurrentTime);

	// 8. Remove the party who've waited longest from
	//    the 'wait' list... they've just been seated!
	m_qcTableWaitQueue.pop();
				
}

//***********************************************************
// Name:        startDiningSim                              *
//                                                          *
// Parms:                                                   *
//                                                          *
// Return:                                                  *
//                                                          *
// Description: The startDiningSim function starts the      *
//              simulation.                                 *
//                                                          *
//***********************************************************

void DiningSim::Restaurant::startDiningSim()
{		
	// Main for loop runs the simulation.
	for (m_nTime = 0; m_nTime < (m_nEndTime - m_nBeginTime) * MINUTES_PER_HOUR; 
		m_nTime++)
	{
		// Display the simulator time.
		std::cout << "\nT = " << m_nTime + 1 << " mins.\n";
		
		
		m_nLevelOfBusiness = m_vnBusinessLevels[((
			m_nBeginTime * MINUTES_PER_HOUR) + m_nTime) / 60];	// Integer division is okay.
																//   here.


		// If a party comes into the restaurant...
		if (m_cRandomizer(100) < m_nLevelOfBusiness)			// nLevelOfBusiness: 0 = 10
																// 10 = 100% likelyhood of new
																//      guest arriving,
																//  9 = 90% likelyhood of new
																//      party arriving at the
																//      restaurant, etc...
		{
			addPartyToTableWaitQueue(m_nTime);			

		} // End of the first nested if statement
	

		
		
		// Algorithm A ...look through all tables and see if one is yet free.
		//             This loop just 'sweeps' all tables in the restaurant
		//             looking for one that is available, and assigns that
		//             table to the party at the front of the wait queue.
		for (int nTableCounter = 0; nTableCounter < m_nNumberOfTables; 
			nTableCounter++)
		{


			// First if statement (A1)
			// If the table is free (and if the wait list
			// is not yet exhausted)... skip this if statement when the
			// no parties are on a 'wait'
			if (m_vcTables[nTableCounter].isFree() 
				&& !(m_qcTableWaitQueue.empty()))
			{					
				// A1.1) Sit the party.
				seatParty(nTableCounter, m_nTime);

				// A1.2) Raise the 'waiting for a server' flag
				m_vcTables[nTableCounter].awaitingServer();

				// A1.3) Add the table to the server wait list
				addTableToServerWaitQueue(m_nTime, 
					m_vcTables[nTableCounter]);

			} // End of the if statement nested in the 
			  // inner for loop (clear a party from the list)
					

		} // End of the Algorithm A 'for' loop (sniff's for free tables)
	
		
		// Algorithm B... 'Tap the shoulder' of all servers to
		//                 see if one is 'free' to take a table.
		for (int nServerCounter = 0; nServerCounter < m_nNumberOfServers;
			nServerCounter++)
		{
			// First if statement B1 ...If a server is free, and the 
			// table is waiting for a server, dequeue the table which 
			// has been waiting longest (i.e. the Table element at the 
			// 'front' of the queue)...
			if (m_vcServers[nServerCounter].isFree()
				&& !(m_qcServerWaitQueue.empty()))
			{
				// if the front table is waiting for a server
				Table cNewTable = m_qcServerWaitQueue.front();
				if (cNewTable.getServerStatus()) 
				{
					// Take the table off the wait (Table object holds
					// a Party object - so they travel together)
					greetTable(m_nTime, nServerCounter);
				
				} // End of 'table-waiting-for-a-server' if statement
		
			} // End of if 'server-shoulder-tapper'
			  // statement B1

		
		} // End of the Algorithm B 'for' loop (sniff's for free servers)



	} // End of the outer 'for' loop (simulation loop: adds minutes unit at max
	  //                              number of minutes for the simulation)

}

