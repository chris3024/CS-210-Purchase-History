#include "Application.h"
#include <stdexcept>
#include <iostream>


/* For this main cpp file I used a very similar system to the one that I used for Module 6.
*  The reason for this is that it seemed to work very well for what we are doing. 
*  As the old saying goes. "If it ain't broke, don't fix it."
*/
auto myApp = Application();

void main() {
	int userInput = 0;

	// main application loop
	while (userInput != 4) {
		try {
			myApp.DisplayMenu(); // display user menu
			std::cin >> userInput;
			if (std::cin.fail()) {
				throw std::runtime_error("Please Enter A Valid Menu Selection");
			}

			system("CLS");
			
			// switch statement for menu system
			switch (userInput) {
			case 1:
				myApp.ItemPurchaseHistory();
				break;
			case 2:
				myApp.ItemFrequency();
				break;
			case 3:
				myApp.CreateHistogram();
				break;
			case 4:
				break;
			default:
				std::cout << "Please Enter a Valid Selection" << std::endl; // user validation for correct menu access
				system("PAUSE");
				system("CLS");
				
				break;
			}
		}

		catch (std::runtime_error& excpt) {
			std::cout << excpt.what() << std::endl;
			system("PAUSE");
			std::cin.clear();
			std::cin.ignore();
			system("CLS");

		}

	}
	

}
