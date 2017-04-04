#pragma once
#include <string>
#include <iostream>
#include <vector>

#define ALPHABET_SIZE  27
#define END_OF_WORD_INDEX 26
#define END_OF_WORD '$'
#define EMPTY_NODE 0
#define INVALID_CHARACTER -1

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

	/* Determine if this node is a word end node.

		This is equivalent to this->getValue() == END_OF_WORD

		Best-case time complexity: T(1)
		Worst-case time complexity: T(1)
	*/
	bool wordEnd();

	/* Set the letter associated with this TrieNode.

		No checking is done in this function, but the value of a given TrieNode can really only validly be one thing, 
		being the character in the array of its parent node that it's assigned.

		Best-case time complexity: T(1)
		Worst-case time complexity: T(1)
	*/
	void setValue(char);

	/* Get the letter associated with this TrieNode.

		If the node has never been set, this will be equal to INVALID_CHARACTER

		Best-case time complexity: T(1)
		Worst-case time complexity: T(1)
	*/
	char getValue();

	/* Return the TrieNode in our alphabet array for the given character.

		See: TrieNode::index

		Best-case time complexity: T(1)
		Worst-case time complexity: T(1)
	*/
	TrieNode* getChild(char);

	/* Return the index of our alphabet array for the given character.

		This is basically a math operation plus a few ifs to check for invalid characters.

		Best-case time complexity: T(1)
		Worst-case time complexity: T(1)
	*/
	int index(char);

	/* Initialize the array of our TrieNode pointers.
		
		We can't do this inside the constructor because we get a stack overflow problem 
		Where we're trying to create nodes on top of nodes on top of nodes.
		The TrieNode constructor wants to construct 27 TrieNodes which wants to construct 27 TrieNodes which wants to construct 27 TrieNodes...
		Instead, this gets called whenever insert is called on the TrieNode so we don't have that issue.
		Fortunately that's not an issue because if no nodes ever get inserted everything is no-op anyway.

		Best-case time complexity: T(1)
		Worst-case time complexity: T(1)
	*/
	void initializeAlphabet();

	/* Insert the given word into this trie, and increment the count parameter based on the number of nodes that were inserted.

		The count parameter is used by the Trie class so that it knows how many nodes had to be inserted.
		It's necessary because we don't know ahead of time how many nodes already exist in the Trie for the given word, this takes care of that for us.

		Best-case time complexity: T(n)
		Worst-case time complexity: T(n)

		Where n is the number of letters in the given word.
	*/
	void insert(string, int&);

	/* Determine if a given word is contained in this trie.

		Returns true if the word is found, false otherwise.
		
		Best-case time complexity: T(n)
		Worst-case time complexity: T(n)

		Where n is the number of letters in the given word.
	*/
	bool find(string);

	/* Traverse the trie from this node, inserting values prepended by prefix into the results parameter.

		This is a recursive function that inserts nodes which have an END_OF_WORD node in their alphabet into the vector parameter.
		Prefix is used to keep track of the current nodes that have been traversed recursively.

		Best-case time complexity: T(n)
		Worst-case time complexity: T(n)

		Where n is the number of nodes in the trie starting at the root node.
	*/
	void traverse(vector<string>& results, string prefix);
};