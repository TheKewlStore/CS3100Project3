#include "stdafx.h"
#include "TrieNode.h"


TrieNode::TrieNode()
{
	alphabet = nullptr;
	value = EMPTY_NODE;
}


TrieNode::~TrieNode()
{
	if (alphabet) {
		delete[] this->alphabet;
	}
}

TrieNode** TrieNode::getAlphabet()
{
	return this->alphabet;
}


int TrieNode::index(char c)
{
	if (c == '$') {
		return 26;
	}
	else {
		return int(c - 'a');
	}
}


void TrieNode::initializeAlphabet()
{
	alphabet = new TrieNode*[ALPHABET_SIZE];

	for (int i = 0; i < ALPHABET_SIZE; i++) {
		alphabet[i] = new TrieNode();
	}
}


void TrieNode::insert(string value, int& count)
{
	if (this->alphabet == nullptr) {
		// We can't instantiate our array of TrieNodes in the constructor or we'll get a stack overflow.
		// Initialize it on an insert if it hasn't already been done.
		this->initializeAlphabet();
	}

	// Get the index of the node that references the next character.
	char nextCharacter = value.at(0);
	int alphabetIndex = index(nextCharacter);
	TrieNode* nextLetterNode = this->alphabet[alphabetIndex];

	if (nextLetterNode->value != nextCharacter) {
		nextLetterNode->value = nextCharacter;
		count++;
	}

	if (value.length() > 1) {
		// The value parameter will only have one character left when we're done, 
		// so only recurse if we have more than one character.
		// Take a substring of the parameter, removing the first character, and call insert on our next letter node.
		string leftovers = value.substr(1, value.length());
		nextLetterNode->insert(leftovers, count);
	}
}


bool TrieNode::find(string value)
{
	if (this->alphabet == nullptr) {
		// If we haven't even inserted anything, there's nothing to find.
		return false;
	}

	if (value.length() == 0) {
		return this->alphabet[END_OF_WORD_INDEX]->value == END_OF_WORD;
	}

	char nextCharacter = value.at(0);
	string leftovers = value.substr(1, value.length());

	int alphabetIndex = index(nextCharacter);
	TrieNode* nextLetterNode = this->alphabet[alphabetIndex];

	if (nextLetterNode->getValue() != nextCharacter) {
		return false;
	}
	else {
		return nextLetterNode->find(leftovers);
	}
}


void TrieNode::setValue(char value)
{
	this->value = value;
}


char TrieNode::getValue()
{
	return value;
}
