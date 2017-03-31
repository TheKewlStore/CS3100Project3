#include "stdafx.h"
#include "Trie.h"


Trie::Trie()
{
	root = new TrieNode();
}


Trie::~Trie()
{
	delete root;
}


int Trie::count()
{
	return 0;
}


int Trie::getSize()
{
	return 0;
}


bool Trie::insert(string value)
{
	if (this->find(value)) {
		return false;
	}

	this->root->insert(value);

	return true;
}


bool Trie::find(string value)
{
	return this->root->find(value);
}


int Trie::completeCount(string)
{
	return 0;
}


vector<string> Trie::complete(string)
{
	return vector<string>();
}


TrieNode* Trie::getRoot()
{
	return root;
}
