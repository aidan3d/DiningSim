// Specification file for the Restaurant class
#ifndef RESTAURANT_H
#define RESTAURANT_H
#include "Party.h"
#include "RandomInteger.h"
#include "Server.h"
#include "Table.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <queue>
#include <stack>
#include <string>
#include <vector>


namespace DiningSim								// namespace declaration
{

	const int MINUTES_PER_HOUR = 60;			// The number of minutes
												//   in an hour, needed 
												//   by m_nBeginTime and
												//      m_nEndTime

	// the restaurant
	class Restaurant 
	{
	protected:

		int			 m_nNumberOfMinutes;		// The amount of real 
												//   time simulated by
												//   the program, the 
												//   time is measured 
												//   in minutes

		int			 m_nLevelOfBusiness;		// Likelyhood that a party
												//   will walk in the front
												//   door of the restaurant
												//  (0 - 100)

		int			 m_nNumberOfTables;			// The number of tables
												//   in the restaurant

		int			 m_nNumberOfServers;		// The number of servers
												//   on the 'floor'
		
		int			 m_nNumberOfLineCooks;		// The number of line 
												//   cooks

		unsigned int m_nMinWaitTime;			// Minimum wait time 
												//   experienced
												//   by a party

		unsigned int m_nMaxWaitTime;			// Maximum wait time 
												//   experienced
												//   by a party
		
		unsigned int m_nBeginTime;				// Start time of simulation

		unsigned int m_nEndTime;				// End time of simulation

		unsigned int m_nTime;					// Counter variable for
												//   main 'timing belt' 
												//   loop

		unsigned int m_nTotalWaitTime;			// The total time all 
												//   parties have 
												//   waited, time being 
												//   measured in
												//   minutes
		
		unsigned int m_nTotalServerWaitTime;	// The total time all
												//    tables have
												//    waited for a server,
												//    after a party has
												//    been seated.

		int					m_nNumberOfParties;	// The total number of 
												//   parties served


		std::string         m_strRestaurantName;	// The name of the 
													//   restaurant
		
		RandomInteger       m_cRandomizer;		// Random number functor

		std::vector<Table> m_vcTables;			// All tables in 
												//   the restaurant

		std::vector<Server> m_vcServers;		// All servers currently
												//   on the 'floor'

		std::vector<int>    m_vnBusinessLevels;	// Likelyhood of a new
												//   party walking in
												//   the 'front door'
												//   of the restaurant

		std::queue<Party>   m_qcTableWaitQueue;	// The 'wait list' for 
												//   parties waiting
												//   for a table

		std::queue<Table>   m_qcServerWaitQueue; // The 'wait list' for 
												 //   'sat' tables who
												 //   are waiting for 
												 //   a server

	public:
		// Constructor #1 (Default)
		Restaurant();
		
		// Constructor #2
		Restaurant(int nInputNumberOfMinutes,
			       int nInputNumberOfTables,
				   int nInputNumberOfServers,
				   int nInputNumberOfLineCooks);

		
		// Destructor
		virtual ~Restaurant()
			{ }

		
		// Accessors
		std::string getRestaurantName() const
			{ return m_strRestaurantName;}
		
		double getAverageTableWaitTime() const;		// Returns the average 
													//   time a new party
													//   has waited for a
													//   free table.


		double getAverageServerWaitTime() const;	// Returns the average
													//   time a newly seated
													//   table has waited
													//   for a free server.

		
		int getNumberOfMinutes() const			// Returns the duration
			{ return m_nNumberOfMinutes; }		//   of the simulation
												//   in units of minutes.

		int getNumberOfParties() const			// Returns the number of
			{ return m_nNumberOfParties; }		//   parties served in
												//   the current 
												//  'session'

		std::vector<Server> getServersVector() const
			{ return m_vcServers;}

		
		std::queue<Party> getTableWaitQueue() const
			{ return m_qcTableWaitQueue; }
		
		
		std::queue<Table> getServerWaitQueue() const
			{ return m_qcServerWaitQueue; }
		
		// Mutators
		void addPartyToTableWaitQueue(			// A new party has
			const int nCurrentTime);			// just walked in...


		void addTableToServerWaitQueue(					// Put 'sat' party on 
			int nCurrentTime, const Table &obj);		//   the 'wait list'
														//   for the next 
														//   available server
		

		void buildTables();								// Build the tables for
														//   the restaurant

		
		void deployServers();							// Send all servers
														//   out onto the 'floor'
														//   to handle the tables


		void greetTable(int nCurrentTime,				// Take party of the server
					    int nCurrentServer);			// wait list and give them
														// them their server

		
		void replaceLevelsOfBusiness(						// Replace the
			const std::vector<int> &vnInputBusinessLevels)	//   instance
			{ m_vnBusinessLevels = vnInputBusinessLevels; }	//   variable
															//   m_vnBusinessLevels
															//   with a new
															//   set of hourly
															//   'percentange
															//    chances' of a
															//    new party arriving


		void replaceServers(							// Replace the instance
			const std::vector<Server> &vcInputServers)	//   variable m_vcServers
			{ m_vcServers = vcInputServers; }			//   with a new cadre of
														//	 servers (previously
														//   loaded from a file)
		
		
		void resetTableWaitQueue();						// Empty the list of parties
														//   waiting for a table
		
		void resetServerWaitQueue();					// Empty the queue of parties
														//   waiting for a server
		
		
		void resetServers();							// Take all servers 
														//   off the 'floor'
														//   for the next run 
														//   of the sim

		void resetTables();								// Empty the tables for
														//   the next run of the 
														//   sim
	


		void seatParty(const int nCurrentTable,			// Take party of table
					   const int nCurrentTime);			// wait list and give 
														// them their table

		

		void setBeginTime(unsigned int nInputBeginTime)
			{ m_nBeginTime = nInputBeginTime; }
		

		void setEndTime(unsigned int nInputEndTime)
			{ m_nEndTime = nInputEndTime; }


		void setLevelOfBusiness(int nInputLevelOfBusiness)
			{ m_nLevelOfBusiness = nInputLevelOfBusiness; }
		

		void setMaxWaitTime(int nInputMaxWaitTime)
			{ m_nMaxWaitTime = nInputMaxWaitTime; }

		
		void setMinWaitTime(int nInputMinWaitTime)
			{ m_nMinWaitTime = nInputMinWaitTime; }
		
		
		void setNumberOfLineCooks(int nInputNumberOfLineCooks)
			{ m_nNumberOfLineCooks = nInputNumberOfLineCooks; }
		
		
		void setNumberOfMinutes(int nInputNumberOfMinutes)
			{ m_nNumberOfMinutes = nInputNumberOfMinutes; }

	
		void setNumberOfParties(int nInputNumberOfParties)
			{ m_nNumberOfParties = nInputNumberOfParties; }
		
		
		void setNumberOfServers(int nInputNumberOfServers)
			{ m_nNumberOfServers = nInputNumberOfServers; }

	
		void setNumberOfTables(int nInputNumberOfTables)
			{ m_nNumberOfTables = nInputNumberOfTables; }
		
	
		void setRestaurantName(std::string strInputRestaurantName)
			{ m_strRestaurantName = strInputRestaurantName; }

		void setTime(unsigned int nInputTime)		// Set counter variable
			{ m_nTime = nInputTime; }				//   for main simulation
													//   'timing belt' loop

		
		void setTotalTableWaitTime(unsigned int nInputTotalTableWaitTime)
			{ m_nTotalWaitTime = nInputTotalTableWaitTime; }

		
		
		void setTotalServerWaitTime( unsigned int nInputTotalServerWaitTime)
			{ m_nTotalServerWaitTime = nInputTotalServerWaitTime; }



		void startDiningSim();						// Chocks away!!
													// Start the
													// simulation
	
		protected:
			// The 'wait list' for
			std::queue<Party> m_qcTableWaitList;
			// The 'wait list' for
			std::queue<Table> m_qcServerWaitList;
	};

} // End of DiningSim namespace declaration

#endif