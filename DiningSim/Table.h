// Specification file for the Table class
#ifndef TABLE_H
#define TABLE_H
#include "Party.h"
#include <iostream>

namespace DiningSim							// Define namespace DiningSim
{

	class Table
	{
	protected:
		bool        m_bFree;				// Signal flag, raised if the
											//   table is unoccupied

		bool        m_bAwaitingServer;		// Signal flag: raised when a
											//   table has been 'sat,'
											//   but a server has not yet
											//   been assigned

		int          m_nTableNumber;		// Table number (i.e. "11")

		unsigned int m_nSat;				// Time the table was 'sat'

		int          m_nSeatsOccupied;		// Head count received from
											//  new party when it is 'sat'

		unsigned int m_nServiceTime;		// Time the table was ordering
											//    their food from the server

		unsigned int m_nTimeOrdering;

		Party        m_cParty;				// Party object


	public:
		// Constructor #1
		Table()
			{ m_bFree = true;
			  m_bAwaitingServer = false;
			  m_nTableNumber = 0;
			  m_nSat = 0;
			  m_nSeatsOccupied = 0;
			  m_nServiceTime = 0;}

		// Constructor #2
		Table(int nInputTableNumber, unsigned int nInputTimeSat)
			{ m_bFree = true;
			  m_bAwaitingServer = false;
		      m_nTableNumber = nInputTableNumber;
			  m_nSeatsOccupied = 0;
			  m_nServiceTime = 0; }

		// Constructor #3
		Table(int nInputTableNumber);

			
		// Accessors
		unsigned int getTimeSeated() const		// Return time table
			{ return m_nSat; }					//   was 'sat' with
												//   a party.

		int  getTableNumber() const
			{ return m_nTableNumber; }
		
		bool getServerStatus() const
			{ return m_bAwaitingServer; }		// Has the table
												//   been greeted?
		int getSeatsOccupied() const
			{ return m_nSeatsOccupied; }
		
		// Mutators

		void addParty(const Party &obj);		// Start servicing 
												//   the next party

		void addServiceTime(int nInputServiceTime)		// Add time server
			{ m_nServiceTime += nInputServiceTime; }	//   needs to take
														//   party's order

		void addOrderTime(int nInputOrderTime);


		void awaitingServer()					// Raise 'awaiting
			{ m_bAwaitingServer = true;}		//   server' flag


		bool doneOrdering()
		{ return --m_nServiceTime == 0; }		// Return true if a
												//   server is free


		void greeted()							// Raise the signal flag
			{ m_bAwaitingServer = false; }		//   to announce that
												//   a server has been
												//   assigned to this
												//   table
		

		bool isFree();							// See if the Table 
												//    is unoccupied
		
		void setTableNumber(int nInputTableNumber)
			{ m_nTableNumber = nInputTableNumber; }

		void setTimeSeated(unsigned int nInputTimeSeated)
			{ m_nSat = nInputTimeSeated; }


		// Overloaded operator functions
		bool operator < (const Table &obj)		// Order by time 'sat'
			{ return m_nSat < obj.m_nSat; }


		bool operator == (const Table &obj)		// No two tables are
			{ return false; }					//   alike ...so return
												//   false if they are 
												//   alike		
	};

} // End of DiningSIm namespace definition

#endif

