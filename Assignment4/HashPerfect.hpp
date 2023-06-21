#ifndef HASHPERFECT_HPP
#define HASHPERFECT_HPP

#include <vector>
#include <string>
#include "HashLin.hpp"

using namespace std;

class HashPerfect 
{
	private: 
		vector<HashLin*> hashTable;
		void init();
		int hash(const string& key);

	public:
		HashPerfect();
		void insert(const vector<string>& keys);
		void print();
};

#endif
