/**
 * @file tempconverter.cpp
 * @brief Interactive Temperature Converter Application
 * @author: Ninglu_Tang
 * @date:   2025-07-30
 * @version: 1.0
 * 
 * This program prompts the user for their name and then repeatedly offers
 * a menu to convert temperatures between Fahrenheit and Celsius or exit.
 * It validates menu input to accept only integer options 1, 2, or 3.
 *
 * Usage:
 *   1. Compile: g++ -std=c++11 -o tempconverter tempconverter.cpp
 *   2. Run: ./tempconverter
 *
 */

#include <iostream>
#include <iomanip>      // For formatting decimal precision
#include <limits>       // For input validation
#include <cmath>        // For checking integer input

using namespace std;

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32;
}

int main() {
    string name;
    int choice = 0;
    double temp;

    // Ask for user's name
    cout << "Please enter your name: " << endl;
    getline(cin, name);

    // Welcome message
    cout << "Welcome " << name << " to the Temperature Converter Application" << endl;

    // Main menu loop
    do {
        cout << "Please type 1 for Fahrenheit to Celsius conversion" << endl;
        cout << "Type 2 for Celsius to Fahrenheit conversion." << endl;
        cout << "Or type 3 to exit the program" << endl;

        // Read user input as string to reject non-integer entries like "1.1"
        string input;
        cin >> input;

        if (input == "1" || input == "2" || input == "3") {
            choice = stoi(input);
        } else {
            choice = -1;  // mark as invalid
        }

        if (choice == 1) {
            cout << "Please enter your temperature in Fahrenheit: " << endl;
            cin >> temp;
            cout << "\nComputing..." << endl;
            cout << "The temperature in Celsius is "
                 << fixed << setprecision(0) << fahrenheitToCelsius(temp) << endl << endl;

        } else if (choice == 2) {
            cout << "Please enter your temperature in Celsius: " << endl;
            cin >> temp;
            cout << "\nComputing..." << endl;
            cout << "The temperature in Fahrenheit is "
                 << fixed << setprecision(0) << celsiusToFahrenheit(temp) << endl << endl;

        } else if (choice == 3) {
            cout << "\nThank you for using the Temperature Converter. Goodbye!\n";
        } else {
            cout << "That is not a option" << endl;
        }

        // clear rest of line (in case of leftover input)
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (choice != 3);

    return 0;
}
