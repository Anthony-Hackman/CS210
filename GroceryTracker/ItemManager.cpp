//
// Created by Anthony Hackman on 12/14/24.
//

#include "ItemManager.h"
#include <iostream>
#include <fstream>
#include <filesystem> // For dynamic file path handling (C++17 or later)

using namespace std;

// Try to load items from file
bool ItemManager::loadItemsFromFile(const string& inputFileName) {
    ifstream inputFile(inputFileName);
    if (!inputFile) { // File open failed
        cerr << "Error: Could not open file at: " << inputFileName << endl;
        return false;
    }

    string item;
    while (inputFile >> item) { // Read each item and update the map
        itemFrequencyMap[item]++;
    }

    inputFile.close();
    return true; // Successfully loaded file
}

// Get the frequency of a specific item
int ItemManager::getFrequencyOfItem(const string& itemName) const {
    auto it = itemFrequencyMap.find(itemName);
    if (it != itemFrequencyMap.end()) {
        return it->second; // Found item, return its frequency
    }
    return 0; // Item not found
}

// Display all items and their frequencies
void ItemManager::displayAllItemsAndFrequencies() const {
    for (const auto& pair : itemFrequencyMap) {
        cout << pair.first << ": " << pair.second << endl;
    }
}

// Display histogram of item frequencies
void ItemManager::displayItemHistogram() const {
    // Find the longest item name for alignment
    size_t maxItemLength = 0;
    for (const auto& pair : itemFrequencyMap) {
        if (pair.first.length() > maxItemLength) {
            maxItemLength = pair.first.length();
        }
    }

    // Determine the maximum frequency for proportional scaling
    int maxFrequency = 0;
    for (const auto& pair : itemFrequencyMap) {
        if (pair.second > maxFrequency) {
            maxFrequency = pair.second;
        }
    }

    // Display the histogram
    cout << "\nItem Frequency Histogram:\n";
    cout << string(maxItemLength + 35, '-') << endl; // Divider

    for (const auto& pair : itemFrequencyMap) {
        // Align item names with padding
        cout << pair.first << string(maxItemLength - pair.first.length() + 2, ' ') << ": ";

        // Scale the bars proportionally if the maximum frequency is large
        int barLength = (maxFrequency > 50) ? (pair.second * 50) / maxFrequency : pair.second;

        // Print the bar
        for (int i = 0; i < barLength; i++) {
            cout << "|";
        }
        cout << endl;
        // Display the frequency count on the right
        // cout << " (" << pair.second << ")" << endl;
    }

    cout << string(maxItemLength + 35, '-') << endl; // Divider
}
