#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int number_needed(string a, string b) {
	unordered_map<char, int> aLetters;
	unordered_map<char, int> bLetters;

	//Map A letters
	for (auto letter : a) {
		if (aLetters.find(letter) == aLetters.end())
			aLetters[letter] = 1;
		else
			aLetters[letter]++;
	}
	//Map B letters 
	for (auto letter : b) {
		if (bLetters.find(letter) == bLetters.end())
			bLetters[letter] = 1;
		else
			bLetters[letter]++;
	}

	int countDiff = 0;
	//Compare A letters with B
	for (auto it : aLetters) {
		char letter = it.first;
		if (bLetters.find(letter) != bLetters.end()) { //Check for letters in common
			countDiff += abs(bLetters[letter] - aLetters[letter]);
		}
		else {
			countDiff += aLetters[letter]; //Letter exist only in A
		}
	}

	//Compare A letters with B
	for (auto it : bLetters) {
		char letter = it.first;
		if (aLetters.find(letter) == aLetters.end()) { //Letters that exist only in B
			countDiff += bLetters[letter];
		}
	}

	return countDiff;
}

int mainMakingAnagrams() {
	string a;
	cin >> a;
	string b;
	cin >> b;
	cout << number_needed(a, b) << endl;
	return 0;
}
