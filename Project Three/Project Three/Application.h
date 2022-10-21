#pragma once
#include <Python.h>


// application named class to hold functions
class Application {

public:

	// display menu
	void DisplayMenu();

	// function returning item purchase history
	void ItemPurchaseHistory();

	// function getting the frequency of item purchased by getting user entered key
	void ItemFrequency();

	// function creating histogram from dat file 
	void CreateHistogram();


	
};