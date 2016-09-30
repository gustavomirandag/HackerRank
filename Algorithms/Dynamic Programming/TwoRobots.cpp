// TwoRobots.cpp : Defines the entry point for the console application.
//
#include "TwoRobots.h"

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <tuple>
#include <climits>
#include <fstream>
#include <iostream>
#include <ctime>

using namespace std;

int getMyHash(int r1, int r2) {
	return (r1 << 10) | r2;
	//return r1 * 7 + r2 * 13;
}

int mainTwoRobots() {
	clock_t begin = clock();
	fstream stream("C:\\Users\\Gustavo\\Documents\\inputTest2.txt");
	cin.rdbuf(stream.rdbuf());

	int t;
	cin >> t;
	while (t--) {
		int m;
		int n;
		cin >> m;
		cin >> n;
		vector<int> inputs;
		for (int i = 0; i < n; i++) {
			int from;
			int to;
			cin >> from >> to;
			inputs.push_back(from);
			inputs.push_back(to);
		}

		if (n == 1) {
			cout << abs(inputs[1] - inputs[0]) << endl;
			continue;
		}

		unordered_map<int, tuple<int, int, int>> currentSteps;
		unordered_map<int, tuple<int, int, int>> nextSteps;
		tuple<int, int, int> firstStep(inputs[1], 0, abs(inputs[1] - inputs[0]));

		int minimum = INT_MAX;
		currentSteps[getMyHash(get<0>(firstStep), get<1>(firstStep))] = firstStep;

		for (int i = 1; i<n; i++) {
			for (auto item : currentSteps) {
				int total = get<2>(item.second);
				total += abs(inputs[(i * 2) + 1] - inputs[i * 2]) + abs(get<0>(item.second) - inputs[i * 2]);
				tuple<int, int, int> r1(inputs[(i * 2) + 1], get<1>(item.second), total);
				auto r1_hash = getMyHash(get<0>(r1), get<1>(r1));
				auto duplicate = nextSteps.find(r1_hash);
				if (duplicate != nextSteps.end()) {
					if (get<2>(duplicate->second) > total) {
						get<2>(duplicate->second) = total;
					}
				}
				else nextSteps[r1_hash] = r1;
				if (i == n - 1 && total < minimum) minimum = total;

				total = get<2>(item.second);
				total += abs(inputs[(i * 2) + 1] - inputs[i * 2]);
				total += get<1>(item.second) == 0 ? 0 : abs(get<1>(item.second) - inputs[i * 2]);
				tuple<int, int, int> r2(get<0>(item.second), inputs[(i * 2) + 1], total);
				auto r2_hash = getMyHash(get<0>(r2), get<1>(r2));
				duplicate = nextSteps.find(r2_hash);
				if (duplicate != nextSteps.end()) {
					if (get<2>(duplicate->second) > total) {
						get<2>(duplicate->second) = total;
					}
				}
				else nextSteps[r2_hash] = r2;
				if (i == n - 1 && total < minimum) minimum = total;
			}

			currentSteps = nextSteps;
			nextSteps.clear();
		}
		cout << n << " " << minimum << endl;
	}

	return 0;
}