// Specification file for the pure abstract Server class
#ifndef SERVER_H
#define SERVER_H
#include "HeadCount.h"
#include "Table.h"
#include <stack>
#include <string>

namespace DiningSim
{

	class Server
	{
	protected:
		bool m_bFree;								// Signal flag, 'raised'
													//  if the server is 
													//  free

		int m_nCutOrder;							// The order (in reverse)
													//   of the server's time
													//   floor. Higher numbers
													//   are cut first, number "1"
													//   is cut last and stays
													//   on the 'floor' the longest.
													//   Forward order for being
													//   'sat,' i.e. number "1"
													//   'sat' first, number "2"
													//   'sat' second, etc.
		
		int  m_nServerId;							// Server's ID number

		
		int  m_nServerSkillLevel;					// Server's 'skill 
													// level:'
													//   1 = newbie, x
													//   2 = seasoned
													//   3 = professional
													//
													//   Distinguishes 
													//   the min time 
													//   interval to
													//   take a guest's
													//   order


		int m_nNumberOfGuestsServed;				// The number of guests
													// the server has served.


		Table m_cTable;								// Table object
	

		std::string m_strServerLastName;			// The server's last name

		
		std::stack<HeadCount> m_scHeadCount;		// The server's 'head count'
													//   (i.e. the number of tables 
													//    which he or she has 
													//   served, and the number 
													//   of guests at each table)


	public:
		// Constructor #1
		Server()
			{ m_bFree                 = true;
			  m_nCutOrder             = 0;
			  m_nNumberOfGuestsServed = 0;
			  m_nServerId             = 0;
			  m_nServerSkillLevel     = 0;
			  m_strServerLastName     = ""; }

		// Constructor #2
		Server(int nInputCutOrder, 
			   int nInputServerId, 
			   std::string strInputServerLastName,
			   int nInputServerSkillLevel)
			{ m_bFree = true;
			  m_nCutOrder = nInputCutOrder;
			  m_nNumberOfGuestsServed = 0;
			  m_nServerId = nInputServerId;
			  m_strServerLastName = strInputServerLastName;
			  m_nServerSkillLevel = nInputServerSkillLevel; }
	
		// Mutators
		void addTableToHeadCount(					// Add the table
			int nInputTableNumber,					//   currently being
			int nInputNumberOfGuests);				//   served to the
													//   server's 'head
													//   count'
		
		void addTable(const Table &obj);			// Start servicing
													//   next table

		bool isFree();								// See if the server
													//   is busy
		void setCutOrder(int nInputCutOrder)
			{ m_nCutOrder = nInputCutOrder; }

		// Accessor
		int getCutOrder() const
			{ return m_nCutOrder; }

		std::stack<HeadCount> getHeadCountList() const
			{ return m_scHeadCount; }

		int getServerId() const
			{ return m_nServerId; }

		std::string getServerLastName() const
			{ return m_strServerLastName; }
		
		int getServerSkillLevel() const
			{ return m_nServerSkillLevel; }
	
};

} // End of the DiningSim namespace definition

#endif

