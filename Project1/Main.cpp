/*
* Main Application Loop
* 
* Date: September 12, 2022
* Author: Christopher Sharp
*/




#include "Clock.h"
#include <iostream>





auto myClock = Clock();

int main()
{
	
	// initializze userInput
	int userInput = -1;

	
	// main loop 
	while (userInput != 4) {

		// clear console screen
		system("CLS");

		// calling function to display clocks
		myClock.displayClocks();

		//calling function to display menu
		myClock.DisplayMenu();

		// adding one second to clock on userInput
		//myClock.addSecond();

		
		
		
		// getting userInput
		std::cin >> userInput;
		
		// used for menu to call functions to increment time
		switch (userInput)
		{
			case 1: {
				myClock.addHour();
				break;
			}
			case 2: {
				myClock.addMinute();
				break;
			}
			case 3: {
				myClock.addSecond();
				break;
			}
			case 4: {
				break;
			}
			default: {
				std::cout << "Invalid Selection. Use 1-4 to make your selection" << std::endl;
				break;
		
			}

		}

		// clearing buffer to stop possible infinite loops
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	}
	// program exit message
	std::cout << "Program Exited" << std::endl;
}



