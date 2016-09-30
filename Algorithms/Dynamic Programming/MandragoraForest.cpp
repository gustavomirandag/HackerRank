#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

typedef unsigned long long int ull_int;

ull_int mandragora(vector<ull_int>& v) {
	sort(v.begin(), v.end());
	ull_int total = accumulate(v.begin(), v.end(), (ull_int)0);//ull_int VERY IMPORTANT!
	ull_int s = 1;
	ull_int p = total;

	for (ull_int i = 1; i < v.size();i++) {
		total -= v[i - 1];
		ull_int aux = (++s)*total;
		if (aux <= p) break;
		p = aux;
	}
	return p;
}

int mainMandragoraForest() {
	ull_int t;
	cin >> t;
	vector<ull_int> results(t);
	for (ull_int i = 0; i < t; i++) cin >> results[i];
	while (t--) {
		ull_int n;
		cin >> n;
		vector<ull_int> v(n);
		for (ull_int i = 0; i < n; i++) cin >> v[i];
		cout << "Result: " << mandragora(v)<<endl;
		cout << "Expected: " << results[t] << endl;
		if (mandragora(v) != results[t])
			cin >> n;//stop
	}
	return 0;
}