//
// Created by Anthony Hackman on 12/14/24.
//

#ifndef ITEM_MANAGER_H
#define ITEM_MANAGER_H

#include <string>
#include <map>
using namespace std;

class ItemManager {
private:
    map<string, int> itemFrequencyMap; // Stores item frequencies

public:
    // Constructor and destructor
    ItemManager() = default;
    ~ItemManager() = default;

    // Methods to manage items
    bool loadItemsFromFile(const string& inputFileName);
    [[nodiscard]] int getFrequencyOfItem(const string& itemName) const;
    void displayAllItemsAndFrequencies() const;
    void displayItemHistogram() const;
};

#endif // ITEM_MANAGER_H
