#include <iostream>  // Input/output stream library
#include <thread>    // Thread library for multi-threading
#include <string>    // String library for using std::string
#include "24_hour_clock.h"  // Include the header file for the 24-hour clock functionality
#include "12_hour_clock.h"  // Include the header file for the 12-hour clock functionality

using namespace std;

// Function prototypes
void handleChoice(int& hours, int& minutes, int& seconds, char choice);
void displayMenu();
void addHour(int& hours, int& minutes, int& seconds);           // Function that adds an hour to the current time
void addMinute(int& hours, int& minutes, int& seconds);         // Function that adds a minute to the current time
void addSecond(int& hours, int& minutes, int& seconds);         // Function that adds a second to the current time
string display12HourClock(int hours, int minutes, int seconds); // Function displaying the 12-hour clock
string display24HourClock(int hours, int minutes, int seconds); // Function displaying the 24-hour clock

int main() {
    int hours, minutes, seconds;

    // Get User Input for Initial Time
    cout << "Enter initial time (hours minutes seconds): ";
    cin >> hours >> minutes >> seconds;

    char choice;
    do {
        // Display Menu
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        // Handle the user choice
        handleChoice(hours, minutes, seconds, choice);

        cout << display12HourClock(hours, minutes, seconds) << endl;
        cout << display24HourClock(hours, minutes, seconds) << endl;
    } while (choice != '4');

    return 0; // Exit the program
}

// Function to display the menu
void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Add Hour\n";
    cout << "2. Add Minute\n";
    cout << "3. Add Second\n";
    cout << "4. Exit\n";
}

// Function to handle user choice
void handleChoice(int& hours, int& minutes, int& seconds, char choice) {
    switch (choice) {
        case '1':
            // Add an hour to the time
            addHour(hours, minutes, seconds);
            break;
        case '2':
            // Add a minute to the time
            addMinute(hours, minutes, seconds);
            break;
        case '3':
            // Add a second to the time
            addSecond(hours, minutes, seconds);
            break;
        case '4':
            cout << "Exiting...\n";
            return;
        default:
            cout << "Invalid choice! Please enter again.\n";
            return;
    }
}

// Function to add an hour to the current time
void addHour(int& hours, int& minutes, int& seconds) {
    hours = (hours + 1) % 24; // Increment hours and wrap around if it exceeds 24
}

// Function to add a minute to the current time
void addMinute(int& hours, int& minutes, int& seconds) {
    minutes = (minutes + 1) % 60; // Increment minutes and wrap around if it exceeds 60
    if (minutes == 0) {
        hours = (hours + 1) % 24; // Increment hours if minutes wrap around
    }
}

// Function to add a second to the current time
void addSecond(int& hours, int& minutes, int& seconds) {
    seconds = (seconds + 1) % 60; // Increment seconds and wrap around if it exceeds 60
    if (seconds == 0) {
        minutes = (minutes + 1) % 60; // Increment minutes if seconds wrap around
        if (minutes == 0) {
            hours = (hours + 1) % 24; // Increment hours if minutes wrap around
        }
    }
}
