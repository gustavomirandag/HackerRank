#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int t;
	unsigned long long int number;

	cin >> t;
	while (t--) {
		bool isPrime = true;
		cin >> number;
		if (number == 1) {
			cout << "Not prime" << endl;
			continue;
		}

		if (number <= 3) {
			cout << "Prime" << endl;
			continue;
		}

		for (int i = 2; i <= sqrt(number); i++) {
			if (((int)number) % i == 0) {
				cout << "Not prime" << endl;
				isPrime = false;
				break;
			}
		}
		if (isPrime)
			cout << "Prime" << endl;
	}

	return 0;
}
