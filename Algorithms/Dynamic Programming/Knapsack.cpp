#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int mainKnapsack() {
	vector<int> v;
	int t, n, k, aux;
	cin >> t;
	while (t--) {
		v.clear();
		cin >> n >> k;
		while (n--) {
			cin >> aux;
			v.push_back(aux);
		}

		vector<int> combinations(k + 1, 0);
		combinations[0] = 1;

		for (int i = 0; i<v.size(); i++)
			for (int j = v[i]; j <= k; j++)
				combinations[j] += combinations[j - v[i]];

		for (int i = k; i >= 0; i--)
			if (combinations[i]>0 || i == 0) {
				cout << i << endl;
				break;
			}

	}
	return 0;
}
