// Project3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
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


bool testComplete() {
	Trie myTrie;

	vector<string> results = myTrie.complete("unfound");

	if (results.size() != 0) {
		cout << "Trie::complete returns a vector with something in it when no words exist in the trie" << endl;
		return false;
	}

	myTrie.insert("test");
	myTrie.insert("testing");
	myTrie.insert("testingtesting");
	myTrie.insert("testers");
	myTrie.insert("unrelated");

	results = myTrie.complete("tes");

	if (results.size() != 4) {
		cout << "Trie::complete does not return the proper number of elements" << endl;
		return false;
	}

	myTrie.insert("testingtesting");
	myTrie.insert("unrelatedtwo");

	results = myTrie.complete("testin");

	if (results.size() != 2) {
		cout << "Trie::complete does not return the proper number of elements after inserting more elements" << endl;
		return false;
	}

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
	checkTestSuccess(testComplete(), passes, failures);

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

	Trie myTrie;

	myTrie.read(".\\wordlist.txt");

	cout << "Please enter a word prefix (or press enter to exit): ";

	string input;

	while (getline(cin, input)) {
		if (input == "") {
			break;
		}

		vector<string> completions = myTrie.complete(input);

		if (completions.size() == 0) {
			cout << "No completions available" << endl;
		} else {
			cout << "Completions: " << endl << "--------------" << endl;

			for (string completion : completions) {
				cout << completion << endl;
			}
		}

		cout << "Please enter a word prefix (or press enter to exit): ";
	}

	system("pause");
    return 0;
}

