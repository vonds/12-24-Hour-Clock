#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <thread>

using namespace std;

// Function to display a 12-hour clock
string display12HourClock(int hours, int minutes, int seconds) {
    stringstream ss; // String stream to construct the display time

    // Clear the string stream
    ss.str("");

    // Construct the display time string
    ss << "*************************\n";
    ss << "*                       *\n";
    ss << "*  " << setw(2) << setfill('0') << (hours % 12 == 0 ? 12 : hours % 12) << ":" 
        << setw(2) << setfill('0') << minutes << ":" 
        << setw(2) << setfill('0') << seconds 
        << (hours < 12 ? " AM " : " PM ") << "  *\n";
    ss << "*                       *\n";
    ss << "*************************";

    // Return the display time string
    return ss.str();
}
