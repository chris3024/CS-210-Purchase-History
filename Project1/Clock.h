/*
* Clock.h
*
* Date: September 12, 2022
* Author: Christopher Sharp
*/



#pragma once
#include <chrono>
#include <string>





// creating clock class
class Clock {

// public functions
public:

	// function to add one hour
	void addHour();

	// function to add one minute
	void addMinute();

	// function to add one second
	void addSecond();

	// function to display user menu
	void DisplayMenu();

	// function getting current time and formatting it to 12 hour clock face
	std::string twelveHourClock();

	// function getting current time and formatting it to 24 hour clock face
	std::string twentyFourHourClock();

	// function displaying both formatted clocks 
	void displayClocks();


private:

	// using chrono library to retrieve current system time
	std::chrono::time_point<std::chrono::system_clock> currentTime { std::chrono::system_clock::now() };



	 

};