// Implementation file for the Menu class.
#ifndef MENU_H
#define MENU_H
#include "Restaurant.h"
#include "Server.h"
#include <conio.h>			// Needed by _getch to 'pause'
							//   program execution until
							//   any key is pressed by the
							//   user
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>


namespace DiningSim			// Definition of the DiningSim 
{							// 	namespace
							


	class Menu
	{
	protected:
		int m_nMenuChoice;					// Holds the user's menu choice

		int m_nWait;						// Used by the _getch function.

		int m_nLevelOfBusiness;				// Likelyhood that a new party will
											//   arrive at the restaurant
											//  (0 - 100%)

		int m_nNumberOfMinutes;				// Duration of the simulation, in minutes.

		int m_nNumberOfTables;				// The number of tables in
											//   the restaurant.

		int m_nNumberOfServers;				// The number of servers
											//   on the 'floor'

		int m_nNumberOfLineCooks;			// The number of line cooks.

		
		unsigned int m_nBeginTime;			// Start hour for the simulation 
											//  (24-hour format)

		unsigned int m_nEndTime;			// End hour for the simulation
											//  (24-hour format)


		std::string m_strRestaurantName;	// The restaurant's name
		
		Restaurant  m_cRestaurant;			// This Restaurant object
											//   will begin the actual
											//   simulation.

	public:
		// Constructor
		Menu()
			{ m_nMenuChoice = 0; 			// Initialize the menu's 
			  m_nWait = 0;					//   instance variables
			  displayMainMenu(); }			//   and run the main
											//   menu display function

		// Accessors
		std::string getNameOfRestaurant() const
			{ return m_strRestaurantName; }

		int getNumberOfLineCooks() const
			{ return m_nNumberOfLineCooks; }
		
		int getNumberOfMinutes() const
			{ return m_nNumberOfMinutes; }

		int getNumberOfServers() const
			{ return m_nNumberOfServers; }

		int getNumberOfTables() const
			{ return m_nNumberOfTables; }


		// Mutators
		void buildMyNewRestaurant();		//    Manager's 
											//      Module
											//      choice #1

		
		void displayMainMenu();				// Display the main menu


		void displayManagersModule();		// Main menu option 2


		void displayHostsModule();			// Main menu option 3


		void displayServerHeadCount(		// Host's Mod
			const std::vector<Server> obj);	//    choice #1

		
		void loadBusinessLevels();			// Load the hourly
											//   likelyhood (percentage
											//   chance) of a new party
											//   arriving at the
											//   restaurant.


		void loadProgramPrefs();			// Load the setup
											//   details (e.g. 
											//   the name of
											//   the restaurant)
											//   from a text file
		
		
		void loadServersFromFile();			// Load the server
											//   details (e.g.
											//   the id number,
											//   last name and
											//  'skill level' of
											//   each server


		void quickSim();					// Runs a simulation
											//   using default
											//   configuration
											//   loaded from a
											//   stored text file 
											//  (DiningSimPrefs.txt)


		void reviewProgramPreferences();	//    Manager's Mod 
											//      choice #2

		
		void saveProgramPrefs();			// Writes the program
											//   preferences to file
											//  (e.g. "11" servers,
											//   etc.)

				
		void waitForKeyPress();				// Pause the program while
											//   the user reads the 
											//   output displayed on
											//   screen

	};

	
} 											// End of the DiningSim
											//   namespace definition

#endif

