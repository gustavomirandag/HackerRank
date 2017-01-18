#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<int, int> fibMap;

int fib(int n) {
	if (n <= 1) return 1;
	if (n == 2) return 2;
	if (fibMap.find(n) == fibMap.end())
		fibMap[n] = fib(n - 1) + fib(n - 2) + fib(n - 3);
	return fibMap[n];
}

int mainDavisStaircase() {
	int t, s;

	cin >> t;
	while (t--) {
		cin >> s;
		cout << fib(s) << endl;
	}
	return 0;
}
