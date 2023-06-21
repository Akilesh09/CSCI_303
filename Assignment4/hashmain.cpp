#include <iostream>
#include <vector>
#include <string>
#include "HashLin.hpp"
#include "HashPerfect.hpp"
#include <cmath>


using namespace std;

int next_prime_number(int size) //Function to determine the next Biggest Prime
{
	int newSize = size;
	bool isPrime = false;

	while(!isPrime)
	{
		newSize++;
		isPrime = true;
		for (int i = 2; i <= sqrt(newSize); i++)
		{	
			if(newSize % i == 0)
			{
			isPrime = false;
			break;
			}
		}
}
return newSize;
}

int main(){
	cout << "Please enter strings to insert (one per line; end list with '!'):" << endl << endl;
	vector<string> input;
	int size = 0;
	string word;
	while(cin >> word && word != "!")
	{
		input.push_back(word);
		cout << word << endl;
		size++;
	} // Obtains input from user and keeps track of the size of the input.
	cout << "!" << endl << endl;

	int prime_size = next_prime_number(size);
	
	HashLin hashLin(prime_size);
	for(const string& x : input) // Takes each string in input and inserts it into hashLin
	{
		hashLin.insert(x);
	}
	cout << "Hash Table with Linear Probing (size = " << prime_size << "):" <<endl << endl;
	hashLin.print('p'); // Calls primary print, which prints without '\t' before the output
	
	HashPerfect hashPerfect;
	hashPerfect.insert(input);
	hashPerfect.print();
	return 0;
}
