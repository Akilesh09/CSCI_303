#include "HashPerfect.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

HashPerfect::HashPerfect()
{
	init();
}

void HashPerfect::init() 
{
	hashTable = vector<HashLin*>(10,NULL);
}

int HashPerfect::hash(const string& key)
{
	const int R = 37;
	unsigned long hashVal = 0;
	for (char c : key) 
	{
		hashVal = (R * hashVal + c) % 10;
    	}

    return hashVal;
}

void HashPerfect::insert(const vector<string>& keys)
{
vector<vector<string>> master_vector(10); // Creates master_vector to keep track of which strings hash to which location 

for(const string& key : keys)
{
int index = hash(key);
master_vector[index].push_back(key); 
}
int counter = 0;
for(const vector<string>& table : master_vector) // For each location stored in master_vector a new HashLin is create of size n*n
{
	int size = table.size();
	if(size>0)
	{
		hashTable[counter] = new HashLin(size*size);
		for ( const string& element : table)
		{
		hashTable[counter]->insert(element);
		}
	}
	counter++;

}

}

void HashPerfect::print()
{
	cout << endl << "Perfect Hash Table" << endl;
	int counter = 0;
	for(HashLin* hash : hashTable)
	{
		if (hash != NULL)
		{
		cout << counter << ": -->" << endl;
		hash->print('s');
		}
		else
		{
		cout << counter << ": -->" << endl;
		}
		counter++;
	}
}
