#include "Application.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <ranges>


// Using same style menu system that I have used in previous projects for this class
void Application::DisplayMenu() {

	std::cout << std::setfill('*') << std::setw(44) << "" << std::endl;
	std::cout << '*' << std::setfill(' ') << std::setw(3) << "" << "1 - Item Purchase History" << std::setfill(' ') << std::setw(15) << '*' << std::endl;
	std::cout << '*' << std::setfill(' ') << std::setw(3) << "" << "2 - Item Purchase Frequency" << std::setfill(' ') << std::setw(13) << '*' << std::endl;
	std::cout << '*' << std::setfill(' ') << std::setw(3) << "" << "3 - Create Histogram" << std::setfill(' ') << std::setw(20) << '*' << std::endl;
	std::cout << '*' << std::setfill(' ') << std::setw(3) << "" << "4 - Exit" << std::setfill(' ') << std::setw(32) << '*' << std::endl;
	std::cout << std::setfill('*') << std::setw(44) << "" << std::endl;

	// getting user selection
	std::cout << "Enter a selection as a number 1, 2, 3, or 4" << std::endl;

	return;
}

// calling Python function to iterate through file to get item purchase history
void Application::ItemPurchaseHistory() {

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("python_modules.PythonCode");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, "ItemHistory");
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	system("PAUSE");
	system("CLS");

}

// calling Python function that takes a user defined key to look through a Python dictionary to return the values of the user defined keys
void Application::ItemFrequency() {

	std::string userInput;

	
	std::cout << "Enter Item to View Quantity" << std::endl;
	std::cin >> userInput;
	std::string str = userInput;
	str[0] = toupper(str[0]); // capitalizing first letter of string
	if (std::all_of(userInput.begin(), userInput.end(), [](char ch) { return (!isalpha(ch)); })) {
		throw std::runtime_error("Please Enter Valid Item");
	}
	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"python_modules.PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, "ItemFrequency");
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", userInput.c_str());
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	std::cout << "Number of " << str << " sold today: " << _PyLong_AsInt(presult) << std::endl;

	system("PAUSE");
	system("CLS");
}

// calling Python function to create data file from Python dictionary then reading that data file to create a histogram for viewing
void Application::CreateHistogram() {
	std::ifstream readDat;
	std::string itemName;
	int itemNum;

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("python_modules.PythonCode");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, "WriteDatFile");
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	// opening dat file
	readDat.open("frequency.dat");
	if (!readDat.is_open()) {
		std::cout << "Could not open file" << std::endl;
	}

	// looping through dat file and printing to the screen
	while (!readDat.fail()) {
		readDat >> itemName;
		readDat >> itemNum;

		if (readDat.eof()) {
			break;
		}
		std::cout << itemName << " " << std::string(itemNum, '*') << std::endl;


	}
	readDat.close();
	system("PAUSE");
	system("CLS");
}



