// Project3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Trie.h"


using namespace std;


bool testInsert() {
	Trie myTrie;

	if (!myTrie.insert("test")) {
		cout << "Trie::insert fails to insert a new node when the trie is empty." << endl;
		return false;
	}
	else if (!myTrie.find("test")) {
		cout << "Trie::insert fails to find the inserted node in the trie." << endl;
		return false;
	}
	else if (myTrie.insert("test")) {
		cout << "Trie::insert succeeds on inserting duplicate nodes." << endl;
		return false;
	}

	return true;
}


bool testSizeAndCount() {
	Trie myTrie;

	myTrie.insert("test");
	myTrie.insert("testing");
	myTrie.insert("woo");
	myTrie.insert("woo");
	myTrie.insert("wooo");
	myTrie.insert("hoo");

	if (myTrie.getSize() != 19) {
		// Expected count is 5 more than the expected letter nodes to account for end of word $ nodes.
		cout << "Trie::getSize does not return the proper number of nodes" << endl;
		return false;
	}
	else if (myTrie.count() != 5) {
		cout << "Trie::count() does not return the proper number of words" << endl;
		return false;
	}

	return true;
}


void checkTestSuccess(bool success, int& passes, int& failures) {
	if (success) {
		cout << ".";
		passes++;
	}
	else {
		failures++;
	}
}


int main()
{
	int passes = 0;
	int failures = 0;

	checkTestSuccess(testInsert(), passes, failures);
	checkTestSuccess(testSizeAndCount(), passes, failures);

	cout << endl;

	if (failures > 0) {
		cout << "Testcase finished with failures" << endl;
		cout << "Tests Passed: " << passes << endl;
		cout << "Tests Failed: " << failures << endl;
	}
	else {
		cout << "PASSED" << endl;
		cout << "Tests Ran: " << passes << endl;
	}

	system("pause");
    return 0;
}

