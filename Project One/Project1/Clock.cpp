/*
* Clock.cpp
*
* Date: September 12, 2022
* Author: Christopher Sharp
*/


#include "Clock.h"
#include <iostream>
#include <iomanip>


// getting and formatting the 12 hr clock face
std::string Clock::twelveHourClock() {

	auto time = std::chrono::system_clock::to_time_t(currentTime);

	char timeString[100];

	tm buffer{};
	localtime_s(&buffer, &time);

	strftime(timeString, 50, "%I:%M:%S %p", &buffer);

	return timeString;

}

// getting and formatting the 24 hr clock face
std::string Clock::twentyFourHourClock() {

	auto time = std::chrono::system_clock::to_time_t(currentTime);

	char timeString[100];

	tm buffer{};
	localtime_s(&buffer, &time);

	strftime(timeString, 50, "%H:%M:%S", &buffer);

	return timeString;

}

// creating menu into a table type format to be displayed to the user
void Clock::DisplayMenu() {
	std::cout << std::setfill(' ') << std::setw(14) << "" << std::setfill('*') << std::setw(26) << "" << std::endl;
	std::cout << std::setfill(' ') << std::setw(14) << "" << '*' << std::setfill(' ') << std::setw(3) << "" << "1 - Add One Hour" << std::setfill(' ') << std::setw(6) << '*' << std::endl;
	std::cout << std::setfill(' ') << std::setw(14) << "" << '*' << std::setfill(' ') << std::setw(3) << "" << "2 - Add One Minute" << std::setfill(' ') << std::setw(4) << '*' << std::endl;
	std::cout << std::setfill(' ') << std::setw(14) << "" << '*' << std::setfill(' ') << std::setw(3) << "" << "3 - Add One Second" << std::setfill(' ') << std::setw(4) << '*' << std::endl;
	std::cout << std::setfill(' ') << std::setw(14) << "" << '*' << std::setfill(' ') << std::setw(3) << "" << "4 - Exit Program" << std::setfill(' ') << std::setw(6) << '*' << std::endl;
	std::cout << std::setfill(' ') << std::setw(14) << "" << std::setfill('*') << std::setw(26) << "" << std::endl;

	return;

}

// getting clock faces and formatting them into a table type format
void Clock::displayClocks() {

	
	std::cout << std::setfill('*') << std::setw(26) << "" << std::setfill(' ') << std::setw(3) << "" << std::setfill('*') << std::setw(26) << "" << std::endl;
	
	std::cout << '*' << std::setfill(' ') << std::setw(6) << "" << "12 Hour Clock" << std::setfill(' ') << std::setw(6) << '*' << std::setfill(' ') << std::setw(3) << "" 
		<< '*' << std::setfill(' ') << std::setw(5) << "" << "24 Hour Clock" << std::setfill(' ') << std::setw(7) << '*' << std::endl;
	
	std::cout << '*' << std::setfill(' ') << std::setw(7) << "" << twelveHourClock() << std::setfill(' ') << std::setw(7) << '*' << std::setfill(' ') << std::setw(3) << ""
		<< '*' << std::setfill(' ') << std::setw(7) << "" << twentyFourHourClock() << std::setfill(' ') << std::setw(10) << '*' << std::endl;
	
	std::cout << std::setfill('*') << std::setw(26) << "" << std::setfill(' ') << std::setw(3) << "" << std::setfill('*') << std::setw(26) << "" << std::endl;

	return;
	
}



// incrementing one hour
void Clock::addHour() {
	using namespace std::chrono_literals;
	currentTime += 1h;
}

// incrementing one minute
void Clock::addMinute() {
	using namespace std::chrono_literals;
	currentTime += 1min;
}

// incrementing one second
void Clock::addSecond() {
	using namespace std::chrono_literals;
	currentTime += 1s;
}




