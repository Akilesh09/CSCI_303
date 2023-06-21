#include "HashLin.hpp"
#include <iostream>

HashLin::HashLin(int size) //Initializes an empty hashTable
{
	hashTable.resize(size, "");
	hashSize = size;
	init();
}

void HashLin::init() // Not necessary because everything is already initialized, but it is included due to project specifications
{

}

int HashLin::hash(const string& key)
{
const int R = 37; //Weiss value for R
unsigned long hashVal = 0;

for (char c : key)
{
	hashVal = (R * hashVal + c)%hashSize;
}
return hashVal;
}

void HashLin::insert(const string& key)
{
int index = hash(key);

while (hashTable[index] != "") // Collision Case
{
index = (index + 1) % hashSize; // Linear Probing
}

hashTable[index] = key;
}

void HashLin::print(char type) 
{
int ind = 0;
if (type == 'p') // Prints primary table
{
	for (const string& key : hashTable)
	{	
		cout << ind << ": " << key << endl;
		ind++;
	}
}
else if (type == 's') // Prints secondary table
{
	for (const string& key : hashTable)
	{
		cout << '\t' << ind << ": " << key << endl;
		ind++;
	}
}
}
