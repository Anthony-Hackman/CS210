//
// Created by Anthony Hackman on 12/14/24.
// Grocery Item Tracker
//

#include <iostream>
#include "ItemManager.h"
#include <filesystem> // For dynamic file path handling (C++ ver. 17+)

using namespace std;

// Function to dynamically determine the file path / ln 23 main
string getFilePath(const string& fileName) {
    string currentDir = filesystem::current_path().string(); // Get current directory
    return currentDir + "/" + fileName; // Concatenate with file name
}

int main() {
    ItemManager itemManager;

    // Dynamically get the file path
    string fileName = "CS210_Project_Three_Input_File.txt"; // Change file name as needed
    string inputFileName = getFilePath(fileName); // Fetch

    // Load the input file
    if (!itemManager.loadItemsFromFile(inputFileName)) { // Catch file loading error
        cerr << "Exiting program due to file load failure." << endl;
        return 1; // Exit if the file cannot be loaded
    }

    while (true) {
        // Display menu options
        cout << "\nMenu Options:\n";
        cout << "1. Check the frequency of a specific item.\n";
        cout << "2. Display all items and their frequencies.\n";
        cout << "3. Display a histogram of item frequencies.\n";
        cout << "4. Exit.\n";
        cout << "Choose an option (1-4): ";

        int userChoice; // Menu choice
        cin >> userChoice;

        // Clear input buffer to avoid residual input issues
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Possible switch case implementation
        if (userChoice == 1) {
            // Option 1: Check the frequency of an item
            cout << "Enter the item name: ";
            string itemName;
            getline(cin, itemName); // Read the full item name
            int frequency = itemManager.getFrequencyOfItem(itemName);
            if (frequency > 0) {
                cout << "The item '" << itemName << "' appears " << frequency << " time(s).\n";
            } else {
                cout << itemName << "' does not appear in the list.\n";
            }
        } else if (userChoice == 2) {
            // Option 2: Display all items and their frequencies
            itemManager.displayAllItemsAndFrequencies();
        } else if (userChoice == 3) {
            // Option 3: Display a histogram of item frequencies
            itemManager.displayItemHistogram();
        } else if (userChoice == 4) {
            // Option 4: Exit the program
            cout << "Now exiting. Goodbye!\n";
            break;
        } else {
            // Invalid numeric input
            cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }
    }

    return 0;
}
