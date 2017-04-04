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

	this->root->insert(value + "$", this->numberNodes);

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


bool Trie::read(string filename) {
	ifstream infile(filename);

	if (!infile.good()) {
		// The file doesn't exist.
		return false;
	}

	string line;

	while (getline(infile, line)) {
		this->insert(line);
	}
}


vector<string> Trie::complete(string value)
{
	TrieNode* nextNode = this->root;

	for (int i = 0; i < value.length(); i++) {
		char nextCharacter = value.at(i);
		
		if (nextNode->getChild(nextCharacter) == nullptr) {
			// We couldn't find the value given, so there are no completions available.
			return vector<string>();
		}

		nextNode = nextNode->getChild(nextCharacter);
	}

	vector<string> results = vector<string>();
	nextNode->traverse(results, value.substr(0, value.length() - 1));

	return results;
}


TrieNode* Trie::getRoot()
{
	return root;
}
