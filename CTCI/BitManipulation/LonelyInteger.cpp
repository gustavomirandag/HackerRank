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

int lonely_integer(vector < int > a) {
	sort(a.begin(), a.end());
	int current = -1;
	bool needPair = false;
	vector<int> lonelyIntegers;
	for (int i = 0; i<a.size(); i++) {
		if (needPair == false || a[i] != current) {
			lonelyIntegers.push_back(a[i]); //Start adding as lonely   
			current = a[i];
			needPair = true;
		}
		else {
			lonelyIntegers.erase(lonelyIntegers.end() - 1);
			needPair = false;
		}
	}
	unsigned long long int result = 0;
	for (auto lonely : lonelyIntegers) {
		result << 8;
		result |= lonely;
	}
	return result;
}

int mainLonelyInteger() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int a_i = 0; a_i < n; a_i++) {
		cin >> a[a_i];
	}
	cout << lonely_integer(a) << endl;
	return 0;
}
