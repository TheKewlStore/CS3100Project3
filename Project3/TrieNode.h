#pragma once
#include <string>

#define ALPHABET_SIZE  27
#define END_OF_WORD -1
#define EMPTY_NODE '-2'

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

	void insert(string);

	bool find(string);
};
