#ifndef HASHLIN_HPP
#define HASHLIN_HPP

#include <vector>
#include <string>
using namespace std;

class HashLin 
{
	private:
		vector<string> hashTable; 
		void init();
		int hashSize;
		int hash(const string& key);
	public:
		HashLin(int size);
		void insert(const string& key);
		void print(char type);
};
#endif
