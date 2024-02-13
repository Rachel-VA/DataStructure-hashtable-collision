
/*
Rachael Savage
CSC382-Data Strcuture & Algorithm
Jill Coddington
1/25/2024
*/

/*                              Hash Table (dictionary/map):
*
* Hash Functions: Convert input keys to array indices. Ideally, keys are uniformly and randomly distributed.
* Collision Scenario: Different keys may hash to the same index (collision)
* Collision Resolution:
  - Chaining: Store collided elements in a list at the index. Simple, but may be inefficient with large data.

  The purpose of the assignment is to implement and analyze a hash table using three different hash functions, then
  evaluate their effectiveness in distributing a set of values like 50, 100, 500 across the table's indexes and handling collisions.


*/
#include <iostream>
#include "HashTable.h"
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
using namespace std;

int main() {
    srand(time(NULL)); // Seed the random number generator

    // Define test sizes
    int testSizes[] = { 18, 69, 91 };
    int numHashFunctions = 4; // var for the total hash funcs implemented in header to loop theme

    for (int size : testSizes) {
        cout << "TEST WITH " << size << " ELEMENTS:\n" << endl;
        for (int hashFuncNumber = 1; hashFuncNumber <= numHashFunctions; hashFuncNumber++) {
            cout << "USING HASH FUNCTION: " << hashFuncNumber << " \n" << endl;

            // Create a hash table with 'size' indexes
            HashTable<int> intHashTable(size);

            // Insert random numbers into the table
            for (int i = 0; i < size; i++) {
                int randNumb = rand();
                intHashTable.insertItem(randNumb, hashFuncNumber);
            }

            // Display the contents of the hash table
            cout << "\nHash Table Contents:\n" << endl;
            intHashTable.displayHT();

            // Display the updated contents of the hash table
            cout << "\nUpdated Hash Table Contents:\n" << endl;
            intHashTable.displayHT();

            // Separator for outputs of each function
            cout << "\n------------------------------------------------------------------------------------------------" << endl;
        }
        // Separator for output of different test sizes
        cout << "-----------------------------------------------------------------------------------------------\n" << endl;
    }

    return 0;
}
