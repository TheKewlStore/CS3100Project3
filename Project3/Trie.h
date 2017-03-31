#pragma once
#include <string>
#include <vector>
#include "TrieNode.h"

using namespace std;

class Trie
{
private:
	TrieNode* root;
	int numberWords;
	int numberNodes;
public:
	Trie();
	~Trie();

	int count();

	int getSize();

	bool insert(string);

	bool find(string);

	int completeCount(string);

	vector<string> complete(string);

	TrieNode* getRoot();
};
