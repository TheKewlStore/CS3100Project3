#pragma once
#include <string>

#define ALPHABET_SIZE  27
#define END_OF_WORD_INDEX 26
#define END_OF_WORD '$'
#define EMPTY_NODE 0

using namespace std;


class TrieNode
{
private:
	TrieNode** alphabet;
	char value;

public:
	TrieNode();
	~TrieNode();

	TrieNode** getAlphabet();

	void setValue(char);
	char getValue();

	int index(char);

	void initializeAlphabet();

	void insert(string, int&);

	bool find(string);
};
