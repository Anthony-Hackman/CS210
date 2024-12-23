# Grocery Tracking App

**Anthony Hackman**  
**Sunday, December 15, 2024**  

## CS210 Project Three  

The Grocery Tracker program is a C++ application that tracks and analyzes the frequency of grocery items from a text file. It allows users to check the frequency of a specific item, display all item frequencies, and view a histogram representation of the data.

---

## Components of the Program  

### ItemManager Class  
Defined in `ItemManager.h` and implemented in `ItemManager.cpp`, this class manages item frequency data using a map from the file system library. Key functionalities include:

- **`loadItemsFromFile`**: Loads item data from a text file into a map.
- **`getFrequencyOfItem`**: Retrieves the frequency of a specified item.
- **`displayAllItemsAndFrequencies`**: Outputs all items and their respective frequencies.
- **`displayItemHistogram`**: Creates a graphical histogram of item frequencies using scaled bars.

---

### Main Function  
The `main.cpp` file contains the program's entry point. Here the user chooses menu options where the program:

- Dynamically determines the input file path using the standard filesystem library.
- Interacts with the user through a menu interface to perform operations using the `ItemManager` class.

The input file is processed to count the occurrence of each item. The file path is dynamically resolved to ensure compatibility with various directory structures.

<img width="335" alt="image" src="https://github.com/user-attachments/assets/fcc480f5-764f-4741-93e1-54f0f6a2d2c5" />

---

## User Menu  

Users interact with the program through a menu, choosing from:

1. **Check the frequency of a specific item by name.**  
2. **Display all items and their frequencies.**  
3. **View a histogram showing the distribution of item frequencies.**  
4. **Exit the program.**  

---

## Loading Items  

The `loadItemsFromFile` method parses the input file and updates the map with item counts.  

- If the file cannot be opened, an error message is displayed, and the program terminates.  
- The input file must be present in the same directory as the built application.  

---

## Histogram Representation  

The histogram adjusts border lengths and text proportionally based on the highest frequency to ensure readability.
<img width="358" alt="image" src="https://github.com/user-attachments/assets/86568c55-6761-4faa-8a4a-329fa1003543" />

