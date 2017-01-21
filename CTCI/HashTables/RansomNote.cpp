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

bool ransom_note(vector<string> magazine, vector<string> ransom) {
	unordered_map<string, int> magazineMap;
	unordered_map<string, int> ransomMap;

	for (string value : magazine)
		if (magazineMap.find(value) == magazineMap.end())
			magazineMap[value] = 1;
		else
			magazineMap[value]++;
	for (string value : ransom) {
		if (magazineMap.find(value) != magazineMap.end() && magazineMap[value] > 0)
			magazineMap[value]--;
		else
			return false;
	}
	return true;
}

int mainRansomNote() {
	int m;
	int n;
	cin >> m >> n;
	vector<string> magazine(m);
	for (int magazine_i = 0; magazine_i < m; magazine_i++) {
		cin >> magazine[magazine_i];
	}
	vector<string> ransom(n);
	for (int ransom_i = 0; ransom_i < n; ransom_i++) {
		cin >> ransom[ransom_i];
	}
	if (ransom_note(magazine, ransom))
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}
