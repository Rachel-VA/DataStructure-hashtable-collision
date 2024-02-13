
#include <iostream> 
#include <list>
#include <cmath> // 
using namespace std;

// Declare a template. it's can be worked with different data types easier.
//keep all code in this header file for the compiler to find all the code. and keep the cpp empty 
template<typename V>
class HashTable
{
private:
    int numIndexes;
    list<V>* hashT;  // Using lib list to declare the hash table array

public:
    HashTable(int numIndexes);  // Constructor declaration
    // Function prototype
    void insertItem(V key, int hashFuncNumber); 
    int hash1(V x);  
    int hash2(V x);
    int hash3(V x);
    void displayHT();  
    int hashPrime(V x);          

};

// Constructor implementation and set it to accomodate the numIndexes (grow/shrink dynamically based on the test size)
template <typename V>
HashTable<V>::HashTable(int numIndexes) {
    // Initialize the number of indexes  for the hash table
    this->numIndexes = numIndexes + 25;
    hashT = new list<V>[this->numIndexes];
}

// good for testing with larger data set as it's built-in func
template <typename V>
int HashTable<V>::hash1(V x) {
    //Using the built-in hash function for integers
    return hash<V>()(x) % numIndexes; 
}

// Implement the 2nd hash function
//using primes number (s) to reduce the chance of common factors leading to collisions
template <typename V>
int HashTable<V>::hash2(V x) {
    //int hashValue = 
    return (x * 181) % numIndexes; //multiply the input  by 17 then take it modulo numIndexes
}

// Implement the 3rd hash function
template <typename V>
int HashTable<V>::hash3(V x) {
    //int hashValue = 
    //return (x * 30 + 7) % numIndexes;
    return ((x * 109) + 11) % numIndexes;


}

template <typename V>
int HashTable<V>::hashPrime(V x) {
    const int prime1 = 149;
    const int prime2 = 71;
    return ((x * prime1) + prime2) % numIndexes;
}

// insertItem implementation
template <typename V>
void HashTable<V>::insertItem(V key, int hashFuncNumber) {
    
    int index = 0; //initiate index
    switch (hashFuncNumber)
    {
    case 1:
        index = hash1(key);
        break;
    case 2:
        index = hash2(key);
        break;
    case 3:
        index = hash3(key);
        break;
    case 4:
        index = hashPrime(key);
        break;
   
     default:
        cout << "Invalid input, please try again" << endl;
        return;

    }
    hashT[index].push_back(key);
}

// display the hash table
template <typename V>
void HashTable<V>::displayHT() 
{
    // iterate through the buckets/list and display their contents
    for (int i = 0; i < numIndexes; i++)
    {
        cout << "Index " << i << ": ";
        for (const auto& item : hashT[i]) 
        {
            cout << item << " ";
        }
        cout << endl;
    }

}
