#include "Pangram.h"

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int mainPangram() {
	vector<int> alphabet;
	for (int ch = 'a'; ch <= 'z';ch++) {
		alphabet.push_back(0);
	}

	string str;
	std::getline(cin, str);

	for (int i = 0; i<str.size(); i++) {
		if (str[i] != ' ') {
			int index = tolower(str[i]) - 'a';
			alphabet[index]++;
		}
	}

	for (int i = 0; i<alphabet.size(); i++) {
		if (alphabet[i] == 0) {
			cout << "not pangram";
			return 0;
		}
	}
	cout << "pangram";
	return 0;
}
