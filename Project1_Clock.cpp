//*************************************************
// Name: Makena Bustos
// Date: 5/18/2022
// Class: CS-250 Programming Languages
// Assignment: Module 3 - Project 1 Clock
//*************************************************

#include <iostream>
#include <stdlib.h> // Used for clearing screen

using namespace std;

int options; // user input for menu
int minute = 0; // minute for both 24 & 12 clocks
int sec = 0; // seconds for both 24 & 12 clocks
int hr12 = 12; // 12 hour clock hours
int hr24 = 0; // 24 hour clock hours
bool isAMOrPM = false; // false is AM and true is PM
string AMorPM = "AM"; // Changes string to "AM" or "PM"



// prints out the time of 12-hour clock and 24-hour clock in proper format and will print the updated time
void printTime() {
	cout << "*********************\t" << "*********************" << endl;
	cout << "*   12-Hour Clock   *\t" << "*   24-Hour Clock   *" << endl;
	// Standard Time Formatting
	cout << "*     "; if (hr12 < 10) cout << "0" << hr12 << ":"; else cout << hr12 << ":"; if (minute < 10) cout << "0" << minute << ":"; else cout << minute << ":"; if (sec < 10) cout << "0" << sec; else cout << sec; cout << " " << AMorPM << "   *";
	// End of  formatting
	cout << "\t";
	// Military Time Formatting
	cout << "*     "; if (hr24 < 10) cout << "0" << hr24 << ":"; else cout << hr24 << ":"; if (minute < 10) cout << "0" << minute << ":";  else cout << minute << ":"; if (sec < 10) cout << "0" << sec; else cout << sec; cout  << " " <<  "     *";
	cout << endl;
	// End of formatting
	cout << "*********************\t" << "*********************" << endl;
	cout << endl;
}

// Displays menu
void printMenu() {

	cout << "\t**************************" << endl;
	cout << "\t* 1- Add One Hour        *" << endl;
	cout << "\t* 2- Add One Minute      *" << endl;
	cout << "\t* 3- Add One Second      *" << endl;
	cout << "\t* 4- Exit Program        *" << endl;
	cout << "\t**************************" << endl;
}

// Adds a hour to both blocks and has conditional statments to properly update the time
void addHour() {
	hr12++;
	hr24++;
	
		if (hr12 == 13) {
			hr12 = 1;
			// Changes between AM to PM once the clock resets
			switch (isAMOrPM) {
				case false:  // If it's AM
					isAMOrPM = true; // Set to PM
					AMorPM = "PM";
					break;

				case true: // If it's PM
					isAMOrPM = false; // Set to AM
					AMorPM = "AM";
					break;
			}
		}
		if (hr24 == 25) {
			hr24 = 0;
		}
	system("CLS"); //Clear screen
	printTime();
	printMenu();
}

// Adds a minute to both clocks and has conditional statements to properly update the time
void addMinute() {
	minute++;

		if (minute == 60) {
			hr12++;
			hr24++;
			minute = 0;
		}
		if (hr12 == 13) {
			hr12 = 1;
			// Changes between AM to PM once the clock resets
			switch (isAMOrPM) {
				case false:  // If it's AM
					isAMOrPM = true; // Set to PM
					AMorPM = "PM";
					break;

				case true: // If it's PM
					isAMOrPM = false; // Set to AM
					AMorPM = "AM";
					break;
			}
		}
		if (hr24 == 25) {
			hr24 = 0;
		}
	system("CLS"); //Clear screen
	printTime();
	printMenu();
}

// Adds a second to both clocks and has conditional statements to properly update the time
void addSecond() {
	sec++;

		if (sec == 60) {
			minute++;
			sec = 0;
		}
		if (minute == 60) {
			hr12++;
			hr24++;
			minute = 0;

			if (hr12 == 13) {
				hr12 = 1;
				// Changes between AM to PM once the clock resets
				switch (isAMOrPM) {
					case false:  // If it's AM
						isAMOrPM = true; // Set to PM
						AMorPM = "PM";
						break;

					case true: // If it's PM
						isAMOrPM = false; // Set to AM
						AMorPM = "AM";
						break;
				}
			}
			if (hr24 == 25) {
				hr24 = 0;
			}
		}
	system("CLS"); //Clear screen
	printTime();
	printMenu();

}

int main() {

	printTime();
	printMenu();

	// Tracks user input, uses appopriate case and goes through corresponding methods
	while (options != 4) {

		cin >> options;

		switch (options) {
		case 1:
			addHour();
			break;

		case 2:
			addMinute();
			break;

		case 3:
			addSecond();
			break;

		case 4:
			cout << "Exiting Clock Program" << endl;
			break;

		default:
			cout << "INVALID SELECTION" << endl;
			break;
		}
	}
	cout << "Program Exited" << endl;

	return 0;
}