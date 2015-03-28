// Implementation file for the Menu class.
#include "Menu.h"

//***********************************************************
// Name:        buildMyNewRestaurant                        *
//                                                          *
// Parms:                                                   *
//                                                          *
// Return:                                                  *
//                                                          *
// Description: This function gets the program setup        *
//              parameters from the user and saves them     *
//              to a text file.                             *
//                                                          *
//***********************************************************

void DiningSim::Menu::buildMyNewRestaurant()
{
	
	char chServerFileLoadDecision;
	
	// Refresh screen.
	system("cls");

	// Display the page title.
	std::cout << std::endl;
	std::cout << "\t\tB U I L D   M Y   N E W   R E S T A R A N T";
	std::cout << std::endl;
	std::cout << std::endl;
	
	// Display the simulation report
	std::cout << "\tlet's get a few details about your new restaurant:";
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "\t-------------------------------------------------";
	std::cout << std::endl;
	std::cout << std::endl;

	// Get the setup information for the program:
	std::cout << "\ta) what's the name of the restaurant? ";
	std::cin.ignore();											// Flush the newline
	std::getline(std::cin, m_strRestaurantName);

	// Get the number of tables
	std::cout << std::endl;
	std::cout << "\tb) enter the number of tables: ";
	std::cin >> m_nNumberOfTables;

	// Get the number of servers
	// a) from a file
	std::cout << std::endl;
	std::cout << "\tc) would you like to load the servers";
	std::cout << std::endl;
	std::cout << "\t\tin \"DiningSimServers.txt\"? (y/n) :";
	std::cin >> chServerFileLoadDecision;

	// Check the input to see if the user
	// wants to read in the list of servers
	// from the file:
	if (chServerFileLoadDecision == 'Y'
		|| chServerFileLoadDecision == 'y')
	{
		loadServersFromFile();
	
	
	} 
	else
	{
		// b) from screen
		std::cout << std::endl;
		std::cout << "\tplease enter the number of servers: ";
		std::cin >> m_nNumberOfServers;
	
	} // End of file load if/else statement


	// Get the number of line cooks.
	std::cout << std::endl;
	std::cout << "\td) enter the number of line cooks: ";
	std::cin >> m_nNumberOfLineCooks;


	// Save the preferences to file.
	std::cout << std::endl;
	std::cout << "\t\tthanks! saving your specs to file...";
	std::cout << std::endl;

	
	// Save the preferences to the file
	// "DiningSimServers.txt"
	saveProgramPrefs();

	// Let the user know that the preferences
	// have been saved.
	std::cout << std::endl;
	std::cout << "\t\tprogram settings sucessfully saved!";
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;


	// Pause while screen is read
	waitForKeyPress();
}

//***********************************************************
// Name:        reviewProgramPreferences                    *
//                                                          *
// Parms:                                                   *
//                                                          *
// Return:                                                  *
//                                                          *
// Description: This function displays the simulation's     *
//              saved preferences on screen.                *
//                                                          *
//***********************************************************

void DiningSim::Menu::reviewProgramPreferences()
{
	// Load the restaurant defaults.
	loadProgramPrefs();

	// Clear the screen.
	system("cls");

	// Display the page title.
	std::cout << std::endl;
	std::cout << "\t\tS I M U L A T I O N   R E P O R T";
	
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;


	std::cout << "\tconfiguration parameters";
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "\t------------------------";
	std::cout << std::endl;
	std::cout << std::endl;
	
	std::cout << "\trestaurant's name:    " << m_strRestaurantName;
	std::cout << std::endl << std::endl;
	std::cout << "\tnumber of tables:     " << m_nNumberOfTables;
	std::cout << std::endl << std::endl;
	std::cout << "\tnumber of servers:    " << m_nNumberOfServers;
	std::cout << std::endl << std::endl;
	std::cout << "\tnumber of line cooks: " << m_nNumberOfLineCooks;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	
	// Wait for the user to exit
	// the screen.
	waitForKeyPress();
}

//************************************************************
// Name:        displayHostsModule                           *
//                                                           *
// Parms:                                                    *
//                                                           *
// Return:                                                   *
//                                                           *
// Description: This function displays the Hosts' Module     *
//              menu on screen                               *
//                                                           *
//************************************************************

void DiningSim::Menu::displayHostsModule()
{
	m_nMenuChoice = 0;					// Assign zero to the
										//   menu choice instance
										//   variable
	// While the user does not wish to return to
	// the previous menu...
	while (m_nMenuChoice != 2)
	{
		// Clear the screen
		system("cls");
		std::cout << std::endl;
		std::cout << "\t\tH O S T ' S   M O D U L E"<< std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;


		std::cout << "\twhat would you like to do?";
		std::cout << std::endl << std::endl;
		std::cout << "\t------------------------";
		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << "\t1.\tserver head count"   << std::endl << std::endl;
	
		std::cout << "\t2.\treturn to the main menu" << std::endl << std::endl;
		std::cout << std::endl;

		// Get the host's choice.
		std::cout << "\t\tplease choose an option (1 or 2): ";
		std::cin >> m_nMenuChoice;

		// Validate the input
		while(m_nMenuChoice != 1 && m_nMenuChoice !=2)
		{
			// Let the manager know that there is a problem.
			std::cout << "\t\ti'm sorry... i didn't quite catch that!";
			std::cout << std::endl;

			std::cout << "\t\tplease enter 1 or 2: ";
			std::cin >> m_nMenuChoice;
		
		} // End of the while menu-choice-validation loop

		
		// Loop through the hosts' module menu operations.
		switch (m_nMenuChoice)
		{	
			case 1:
				{
					// Display the head count report for
					// all servers working in the 
					// last 'run' of the simulation.
					displayServerHeadCount(				
					m_cRestaurant.getServersVector());	
					break;								
			
				} // End of case 1
			
		} // End of the host's module switch statement
		
		
	
	} // End of the outer while loop trapping for "3" to
	  // return to the previous menu.

}						

//************************************************************
// Name:        displayMainMenu                              *
//                                                           *
// Parms:                                                    *
//                                                           *
// Return:                                                   *
//                                                           *
// Description: This function displays the Main menu on      *
//              screen. The manager's choice is captured     *
//              and returned to the calling function.        *
//                                                           *
//************************************************************                                                                                                  

void DiningSim::Menu::displayMainMenu()
{
	m_nMenuChoice = 0;					// Assign zero to the menu
										//   choice instance variable
	
	// The main while loop traps for a "4", which
	// allows the user to exit the program.
	while (m_nMenuChoice != 4)
	{
		// Refresh screen.
		system("cls");


		// Display the menu screen title.
		std::cout << std::endl;
		std::cout << "\t\tM A I N   M E N U" << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		

		// Display the menu choices.
		std::cout << "\twhat would you like to do today?"  << std::endl;
		std::cout << std::endl;
		std::cout << "\t-------------------------------"   << std::endl;
		std::cout << std::endl;

		std::cout << "\t1.\tquick sim(tm) mode"  << std::endl << std::endl;
		
		std::cout << "\t2.\tmanagers' module"    << std::endl << std::endl;

		std::cout << "\t3.\thosts' module"       << std::endl << std::endl;

		std::cout << "\t4.\texit"                << std::endl << std::endl;

		std::cout << std::endl;
		

		// Get the manager's choice.
		std::cout << "\t\tplease enter your choice (1, 2, 3, or 4): ";
		std::cin >> m_nMenuChoice;


		// Validate the input
		while(m_nMenuChoice != 1 && m_nMenuChoice !=2 && m_nMenuChoice != 3
				  && m_nMenuChoice != 4)
		{
			// Let the manager know that there is a problem.
			std::cout << "\t\ti'm sorry... i didn't quite catch that!";
			std::cout << std::endl;

			std::cout << "\t\tplease enter 1, 2, 3, or 4: ";
			std::cin >> m_nMenuChoice;
		}


		// Loop through the menu's operations
		switch (m_nMenuChoice)
		{	
			case 1:
				{
					quickSim();
					break;

				} // End of case 1
			case 2:
				{
					displayManagersModule();
					break;

				} // End of case 2
			case 3:
				{
					displayHostsModule();
					break;

				} // End of case 3
			
		} // End of the main switch statement


	} // End of the main while loop which trapped
	  // for nMenuChoice holding the value "4"


	// Clear the screen.
	system("cls");

	// Thank the user for visiting DiningSim.
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "\tthanks for visting DiningSim!";
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
}

//************************************************************
// Name:        displayManagersModule                        *
//                                                           *
// Parms:                                                    *
//                                                           *
// Return:      the menu choice (an integer)                 *
//                                                           *
// Description: This function displays the Manager's module  *
//              menu. The manager's choice is captured       *
//              and returned to the calling function.        *
//                                                           *
//************************************************************

void DiningSim::Menu::displayManagersModule()
{
	
	m_nMenuChoice = 0;			// Assign zero to the menu choice
								// instance variable m_nMenuChoice.

	// Trap for a "3" to return to the previous
	// menu.
	while (m_nMenuChoice != 3)
	{
		// Clear the screen.
		system("cls");

		std::cout << std::endl;
		std::cout << "\t\tM A N A G E R ' S   M O D U L E";
		std::cout << std::endl;;

		std::cout << std::endl; 
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;


		// Display the manager's module choices.
		std::cout << "\t1.\tbuild my new restaurant!" << std::endl;
		std::cout << std::endl;
		std::cout << "\t2.\treview my settings" << std::endl;
		std::cout << std::endl;
		std::cout << "\t3.\treturn to the main menu";
		std::cout << std::endl;
		std::cout << std::endl;


		// Get the manager's choice.
		std::cout << "\t\tplease enter your choice (1, 2 or 3): ";
		std::cin >> m_nMenuChoice;

		// Validate the input
		while(m_nMenuChoice != 1 && m_nMenuChoice !=2 && m_nMenuChoice != 3)
		{
			// Let the manager know that there is a problem.
			std::cout << "\t\ti'm sorry... i didn't quite catch that!";
			std::cout << std::endl;

			std::cout << "\t\tplease enter 1, 2 or 3: ";
			std::cin >> m_nMenuChoice;
		} // End of the while validation loop

	
		// Loop through the menu's operations.
		switch(m_nMenuChoice)
		{
		case 1:
			buildMyNewRestaurant();					// Build my new restaurant
			break;
		case 2:
			reviewProgramPreferences();				// Report the results of
			break;									//   the last sim.

		} // End of the switch statement.

	
	} // End of the outer while loop 
	  //   trapping for a "3" value in
	  //   m_nMenuChoice.

}


//*************************************************************
// Name:        displayServerHeadCount                        *
//                                                            *
// Parms:                                                     *
//                                                            *
// Return:                                                    *
//                                                            *
// Description: This function displays all server's 'head     *
//              counts,' or how many tables they've had       *
//              and number of guests per table.               *
//                                                            *
//*************************************************************

void DiningSim::Menu::displayServerHeadCount(const std::vector<Server> obj)
{

	int nLineCounter = 0;						// A variable to count the number
												// of 'tables' displayed, and 
												// add a 'newline' after four tables.


	// Firstly, clear the screen.
	system("cls");

	
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	// Secondly, let the user know that we are
	// displaying the server head count report.
	std::cout << "\tserver head count" << std::endl;
	std::cout << "\t-------------------------------------------------------------" << std::endl;
	std::cout << std::endl;


	// Loop through all servers who worked during the last 'run'
	// of the simulation.
	for (int nServerCounter = 0; nServerCounter < obj.size(); nServerCounter++)
    {

		// Display the server's last name.
		std::cout << "\t" << std::setw(16) << std::left;
		std::cout << obj[nServerCounter].getServerLastName();
		

		// Copy the current servers stack of tables
		// served during the last 'run' of the simulation
		// to a temporary stack.
		std::stack<HeadCount> scNewServerHeadCount = 
			obj[nServerCounter].getHeadCountList();

		// Keep displaying' and poppin'!
		while (!scNewServerHeadCount.empty())
		{
			if (nLineCounter % 7)	// Display the next table on a new line
			{
				std::cout << scNewServerHeadCount.top().getTableNumber();

				std::cout << "/";

				std::cout << scNewServerHeadCount.top().getNumberOfGuests();
		
				std::cout << "\t";

			}
			else
			{
				std::cout << std::endl;

				std::cout << "\t\t\t";
			
			}

			
			// Remove the table at the top of the stack.
			scNewServerHeadCount.pop();
		
			
			// (No need to accumulate a traverser because we
			//  are just 'popping' off the front of the stack!)
			//  But we do need to accumulate the line counter at
			//  the 'bottom' of the while loop.
			nLineCounter ++;

		
		} // End 'still poppin' while loop


		// End the line of tables displayed.
			std::cout << std::endl;
			std::cout << std::endl;


		// Reset the report's 'line counter.'
		nLineCounter = 0;
	} // End of the outer 'for' loop. Done
	  // 'tapping the shoulder' of each server to see
	  //  how many tables they've served in the last
	  // 'run' of the simulation

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	
	// Wait for the user to read the head count.
	waitForKeyPress();

}

//*************************************************************
// Name:        loadBusinessLevels                            *
//                                                            *
// Parms:                                                     *
//                                                            *
// Return:                                                    *
//                                                            *
// Description: This function loads the hourly likelyhood     *
//              (percentage chance) of a new party arriving   *
//               at the restaurant.                           *
//                                                            *
//*************************************************************

void DiningSim::Menu::loadBusinessLevels()
{
	int nHourCounter = 0;		// Define and initialize a
								//   counter variable to hold
								//   the level of business. 
								//  (The level of business changes
								//   each hour)

	int nHoursInDay = 24;		// maximum 'hour slots'
								// which can be read in
	
	int nLevelOfBusiness;		// Level of business for a
								//   particular hour of the day
								//  (e.g. 10am - 11am)

	std::ifstream inFile("DiningSimBusinessLevels.txt");

	std::vector<int> vnBusinessLevels;

	// Check to see if we can work the the 'levels of business'
	// input file.
	if (inFile.fail())
	{
		std::cout << "\t\ti'm sorry, the file containing" << std::endl;
		std::cout << "\t\tthe levels of business could not be opened!";
		std::cout << std::endl;
		std::cout << std::endl;

		// Wait for the user to hit a key before
		// continuing
		waitForKeyPress();
		
		std::cout << std::endl;
	}
	else
	{
		while ((nHourCounter < nHoursInDay) && !(inFile.eof()))
		{
			// Read in the level of business for that hour.
			inFile >> nLevelOfBusiness;

			// Add it to the vector of business levels.
			vnBusinessLevels.push_back(nLevelOfBusiness);
		
			// Increment the number of hours
			nHourCounter++;


		} // End of file read loop

	
	} // End of file open check 'if' selection statement

	// Replace the vector of hourly business levels in
	// the Restaurant object with the vector loaded
	// from "DiningSimBusinessLevels.txt"
	m_cRestaurant.replaceLevelsOfBusiness(vnBusinessLevels);
	
	
	// Let the user know that the hourly 'levels of business'
	// have been read in from the file "DiningSimBusinessLevels.txt"
	std::cout << std::endl;
	std::cout << "\t\tthe daily levels of business have";
	std::cout << std::endl;
	std::cout << "\t\tsuccessfully been loaded from file!";
	std::cout << std::endl << std::endl;

}

//*************************************************************
// Name:       loadProgramPrefs                               *
//                                                            *
// Parms:                                                     *
//                                                            *
// Return:                                                    *
//                                                            *
// Description: This function opens up a text file and        *
//              reads in the configuration data for the       *
//              program.                                      *
//                                                            *
//*************************************************************

void DiningSim::Menu::loadProgramPrefs()
{
	std::ifstream inFile("DiningSimPrefs.txt");

	// Check to see if we can work with the preferences file.
	if (inFile.fail())
	{
		std::cout << "\t\ti'm sorry, the preferences file could not be opened!";
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;

		// Wait for the user to hit a key before
		// continuing
		waitForKeyPress();
		
		std::cout << std::endl;
	
	}
	else
	{	
		// While we are not at the end-of-file
		while(!inFile.eof())
		{
			std::getline(inFile, m_strRestaurantName);
			inFile >> m_nNumberOfTables; 
			inFile >> m_nNumberOfServers;
			inFile >> m_nNumberOfLineCooks;


		} // End of the while loop
		

		// Let the user know that the program
		// preferences have been loaded from file.
		std::cout << "\t\tprogram preferences successfully loaded from file!";
		std::cout << std::endl;
		std::cout << std::endl;

		// Close the input file.
		inFile.close();
	}

}

//***********************************************************
// Name:        loadServersFromFile                         *
//                                                          *
// Parms:                                                   *
//                                                          *
// Return:                                                  *
//                                                          *
// Description: This function loads a vector of servers     *
//              from a file named "DiningSimServers.txt     *
//                                                          *
//***********************************************************

void DiningSim::Menu::loadServersFromFile()
{  
	int nServerCounter = 0;						// Create and initialize a
												//    'counter variable,' 
												//    helps to add a 'cut order'
												//    as the servers are read in
												//    from the file 

	int nInputServerId;							// The server's id number
	
	std::string strInputServerLastName;			// The server's last name
	
	int nInputSkillLevel;						// The servers 'skill level'
												//   1 = 'Professional'
												//   2 =  Seasoned server
												//   3 =  Newbie
	
	// Create a vector of servers.
	std::vector<Server> vcServers;


	// Open the input file.
	std::ifstream inFile("DiningSimServers.txt");

	// Check to see if we can work with the servers
	// file.
	if (inFile.fail())
	{
		std::cout << "\t\ti'm sorry, the file containing" << std::endl;
		std::cout << "\t\tthe list of servers could not be opened!";
		std::cout << std::endl;
		std::cout << std::endl;

		// Wait for the user to hit a key before
		// continuing
		waitForKeyPress();
		
		std::cout << std::endl;
	
	}
	else
	{
		// The file should be good... let's load it!
		while (!inFile.eof())
		{
			inFile >> nInputServerId;			// Get the server id number
			
			inFile >> strInputServerLastName;	// Get the server's last name
			
			inFile >> nInputSkillLevel;			// Get the server's skill level

			
			// Create a new Server object to hold
			// the data before we 'push' the element
			// onto the back of the vector vcServers.
			Server cNewServer((nServerCounter + 1), 
							  nInputServerId,
							  strInputServerLastName,
							  nInputSkillLevel);


			// Add the element to the vecotr
			vcServers.push_back(cNewServer);
		
			//Increment the counter variable (also the 'cut' ordinal)
			nServerCounter++; 

		} // End of the inner while loop
	
		
		// Replace the vector of servers held
		// by the main Restaurant simulation object
		// with the ones we just read in from the file
		// "DiningSimServers.txt"
		m_cRestaurant.replaceServers(vcServers);

		// Update the number of servers on the 'floor.'
		// this is held in the Menu object, and will be
		// passed to the Restaurant object when quickSim
		// is run.
		m_nNumberOfServers = nServerCounter;


		// Let the user know that the servers' detail were
		// loaded successfully.
		std::cout << "\t\t" << nServerCounter;
		std::cout << " servers successfully loaded from file!\n";

	} // End of the outer if/else statement

}

//***********************************************************
// Name:        quickSim                                    *
//                                                          *
// Parms:                                                   *
//                                                          *
// Return:                                                  *
//                                                          *
// Description: This function runs a simulation based       *
//              on the preferences held on file in          *
//              DiningSimPrefs.txt                          *
//                                                          *
//***********************************************************

void DiningSim::Menu::quickSim()
{
	// Clear the screen.
	system("cls");
					
	// Load the program preferences from file.
	loadProgramPrefs();

	// Load the server's available from file.
	loadServersFromFile();
					
	// Load the hourly 'likelyhood of a new party
	// arriving' percentages from file.
	loadBusinessLevels();

	// Ask the user how long they would like
	// to run the simulation for.
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "\twhen would you like the simulation to start" << std::endl;  
	std::cout << "\t(24 hr format, whole hour only please: e.g. \"13\" for 1pm): ";
	std::cin >> m_nBeginTime;
	std::cout << "\t... and at what hour would you like the simulation to end?";
	std::cout << std::endl;
	std::cout << "\t(24 hr format, e.g. \"15\" for 3pm): ";
	std::cin >> m_nEndTime;
	
	
	// Set up parameters.
	m_cRestaurant.setNumberOfTables(m_nNumberOfTables);
	m_cRestaurant.setNumberOfServers(m_nNumberOfServers);
	m_cRestaurant.setNumberOfLineCooks(m_nNumberOfLineCooks);
	m_cRestaurant.setMinWaitTime(0);
	m_cRestaurant.setMaxWaitTime(0);
	m_cRestaurant.setTotalTableWaitTime(0);
	m_cRestaurant.setTotalServerWaitTime(0);
	m_cRestaurant.setNumberOfParties(0);			
	
	m_cRestaurant.setTime(0);			  // Initialize loop counter to
										  //   be safe.

	m_cRestaurant.setBeginTime(
		m_nBeginTime);

	m_cRestaurant.setEndTime(
		m_nEndTime);

	// Set up infrastructure.
	m_cRestaurant.resetTables();		  // Clear the tables' vector
	m_cRestaurant.resetTableWaitQueue();  // Clear the table wait 
										  //    queue
	m_cRestaurant.resetServerWaitQueue(); // Clear the server wait 
										  //   queue
	
	m_cRestaurant.buildTables();		  // Load the vector of tables
	

	// Let's burn!!
	m_cRestaurant.startDiningSim();		  // Call the simulator 
										  //   start function 


	// Show the number of customers
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "\t\t";
	std::cout << m_cRestaurant.getNumberOfParties();
	std::cout << " parties proudly served in ";
	std::cout << (m_nEndTime - m_nBeginTime) * MINUTES_PER_HOUR;
	std::cout << " mins." << std::endl;;

	// Show the average wait time
	std::cout << std::setprecision(2);
	std::cout << std::fixed << std::showpoint;
					
	std::cout << std::endl;
	std::cout << "\t\tAverage table wait time experienced: ";
	std::cout << m_cRestaurant.getAverageTableWaitTime();
	std::cout << " mins." << std::endl;
	

	std::cout << std::endl;
	std::cout << "\t\tAverage server wait time experienced: ";
	std::cout << m_cRestaurant.getAverageServerWaitTime();
	std::cout << " mins." << std::endl;


	std::cout << std::endl;
	std::cout << "\t\tparties waiting for a table: ";
	std::cout << m_cRestaurant.getTableWaitQueue().size();
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "\t\ttables without a server: ";
	std::cout << m_cRestaurant.getServerWaitQueue().size();
	std::cout << std::endl;
	std::cout << std::endl;

	// Wait for the user to view on-screen
	// results.
	waitForKeyPress();
}

//**************************************************************
// Name:        saveProgramPrefs                               *
//                                                             *
// Parms:                                                      *
//                                                             *
// Return:                                                     *
//                                                             *
// Description: This function writes the program preferences   *
//              to a text file.                                *
//                                                             *
//**************************************************************

void DiningSim::Menu::saveProgramPrefs()
{
	// Create a text file to write the program
	// preferences to.
	std::ofstream outFile("DiningSimPrefs.txt");

	// Write the program preferences to file.
	outFile << m_strRestaurantName << std::endl;
	outFile << m_nNumberOfTables   << std::endl; 
	outFile << m_nNumberOfServers  << std::endl;
	outFile << m_nNumberOfLineCooks;

	// Close the output file.
	outFile.close();
}

//************************************************************
// Name:        waitForKeyPress                              *
//                                                           *
// Parms:                                                    *
//                                                           *
// Return:                                                   *
//                                                           *
// Description: This function pauses the program while       *
//              the user reads the output displayed on       *
//              the screen. The user presses any key         *
//              to move forward.                             *
//                                                           *
//************************************************************                                                                                                  

void DiningSim::Menu::waitForKeyPress()
{
	// Let the user know how to move forward:
	std::cout << "\t\t/|  press any key to return to the" << std::endl;
	std::cout << "\t\t\\|  previous screen..."             << std::endl;

	// Wait for the user to press the next key.
	m_nWait = _getch();

	// Flush the newline character from
	// the keyboard input buffer.
	std::cin.ignore(255, '\n');
}
