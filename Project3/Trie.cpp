#include "stdafx.h"
#include "Trie.h"


Trie::Trie()
{
	root = new TrieNode();
	numberWords = 0;
	numberNodes = 0;
}


Trie::~Trie()
{
	delete root;
}


int Trie::count()
{
	return numberWords;
}


int Trie::getSize()
{
	return numberNodes;
}


bool Trie::insert(string value)
{
	if (this->find(value)) {
		return false;
	}

	this->root->insert(value, this->numberNodes);

	numberWords++;
	return true;
}


bool Trie::find(string value)
{
	return this->root->find(value);
}


int Trie::completeCount(string value)
{
	return this->complete(value).size();
}


vector<string> Trie::complete(string value)
{
	return vector<string>();
}


TrieNode* Trie::getRoot()
{
	return root;
}
