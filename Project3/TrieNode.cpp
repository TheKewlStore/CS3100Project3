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
	return int(c - 'a');
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
	int alphabetIndex = index(value.at(0));
	TrieNode* nextLetterNode = this->alphabet[alphabetIndex];

	// Store the first character of the value in the next node's value field.
	nextLetterNode->setValue(value.at(0));

	if (value.length() > 1) {
		// The value parameter will only have one character left when we're done, 
		// so only recurse if we have more than one character.
		// Take a substring of the parameter, removing the first character, and call insert on our next letter node.
		string leftovers = value.substr(1, value.length());
		nextLetterNode->insert(leftovers, count);
	}
	count++;
}


bool TrieNode::find(string value)
{
	if (value.length() == 1) {
		return true;
	}

	char currentCharacter = value.at(0);

	if (this->alphabet == nullptr) {
		// If we haven't even inserted anything, there's nothing to find.
		return false;
	}

	string leftovers = value.substr(1, value.length());

	int alphabetIndex = index(currentCharacter);

	TrieNode* nextLetterNode = this->alphabet[alphabetIndex];

	if (nextLetterNode->getValue() != currentCharacter) {
		return false;
	}

	return nextLetterNode->find(leftovers);
}


void TrieNode::setValue(char value)
{
	this->value = value;
}


char TrieNode::getValue()
{
	return value;
}
