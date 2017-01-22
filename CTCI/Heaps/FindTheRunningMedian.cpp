#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, less<int> > lower = priority_queue<int, vector<int>, less<int> >();
priority_queue<int, vector<int>, greater<int> > higher = priority_queue<int, vector<int>, greater<int> >();

void add(int i) {
	if (lower.empty())
		lower.push(i);
	else {
		if (lower.size() > higher.size()) {
			if (lower.top() > i) {
				higher.push(lower.top());
				lower.pop();
				lower.push(i);
			}
			else
				higher.push(i);
		}
		else {
			if (higher.top() >= i)
				lower.push(i);
			else {
				lower.push(higher.top());
				higher.pop();
				higher.push(i);
			}
		}
	}
}

double find() {
	int n = lower.size() + higher.size();
	return (n % 2 == 0) ? (higher.top() + lower.top()) / 2.0 : (double)(lower.top());
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int a_i = 0; a_i < n; a_i++) {
		cin >> a[a_i];
		add(a[a_i]);
		printf("%.1f\n", find());
	}
	return 0;
}
