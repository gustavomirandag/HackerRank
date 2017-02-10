#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

//Calculate the number of operations to Zero or Less
int numberOfOperations(int value) {
	if (value == 0)
		return 0;
	if (value <= 2)
		return 1;
	if (value <= 4)
		return 2;
	return value / 5 + numberOfOperations(value % 5);
}

int main() {
	int t;
	cin >> t; //Test Cases
	while (t--) {
		int n;
		cin >> n; //Number of Colleages
		vector<int> chocolate(n);

		//Fill Chocolates and get the MIN number of Chocolates with a Colleage - O(n)
		int min = INT_MAX;
		for (int i = 0; i<n; i++) {
			cin >> chocolate[i];
			if (chocolate[i]<min)
				min = chocolate[i];
		}

		int operations = INT_MAX; //MIN number of Operations
		for (int i = min; i >= min - 2; i--) {
			int sum = 0; //Number of Operations needed to Zero
			for (int j = 0; j<n; j++)
				sum += numberOfOperations(chocolate[j] - i);
			if (sum < operations)
				operations = sum;

		}
		cout << operations << endl;
	}
	return 0;
}