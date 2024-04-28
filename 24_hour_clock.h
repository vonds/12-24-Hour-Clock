#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <thread>

using namespace std;

// Function to display a 24-hour clock
string display24HourClock(int hours, int minutes, int seconds) {
    stringstream ss; // String stream to construct the display time

    // Clear the string stream
    ss.str("");

    // Construct the display time string
    ss << "*************************\n";
    ss << "*                       *\n";
    ss << "*  " << setw(2) << setfill('0') << hours << ":" 
        << setw(2) << setfill('0') << minutes << ":" 
        << setw(2) << setfill('0') << seconds << "  *\n";
    ss << "*                       *\n";
    ss << "*************************";

    // Return the display time string
    return ss.str();
}





