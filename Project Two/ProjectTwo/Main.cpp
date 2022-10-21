#include "FinancialInformation.h"
#include <iostream>


auto information = FinancialInformation();

int main() {
	char userInput = 'a';

	// loop that allows program to continue running until exited by user
	while (userInput !='q') {
		// error checking
		try
		{
			// clearing screen then gathering user entered information
			system("CLS");

			information.userDataInput();

			system("CLS");
			
			//printing formatted tables with the calculated information
			information.calcBalanceNoDeposit(information.getInitialIvestmentAmount(), information.getInterest(), information.getNumberOfYears());
			std::cout << std::endl;
			information.calcBalanceWithDeposit(information.getInitialIvestmentAmount(), information.getMonthlyDeposit(), information.getInterest(), information.getNumberOfYears());

			std::cout << std::endl;

			// asking if user wants to continue or exit
			std::cout << "Enter press a character or number to continue. Press q to quit" << std::endl;
			std::cin >> userInput;

		}
		// catching error information then displaying to user then clearing screen to restart entering information
		catch (std::runtime_error & excpt)
		{
			std::cout << excpt.what() << std::endl;
			system("PAUSE");
			std::cin.clear();
			std::cin.ignore();
			
			system("CLS");
		
		}
		
		

	}


}