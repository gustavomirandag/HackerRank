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

vector<int> array_left_rotation(vector<int> a, int n, int k) {
	int realK = k%n;
	vector<int> aRotated(n, -1);
	for (int i = 0; i<n; i++) {
		int newPos = i - realK < 0 ? n - abs(i - realK) : i - realK;
		aRotated[newPos] = a[i];
	}
	return aRotated;
}

int mainLeftRotation() {
	int n;
	int k;
	cin >> n >> k;
	vector<int> a(n);
	for (int a_i = 0; a_i < n; a_i++) {
		cin >> a[a_i];
	}
	vector<int> output = array_left_rotation(a, n, k);
	for (int i = 0; i < n; i++)
		cout << output[i] << " ";
	cout << endl;
	return 0;
}
