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


int mainFairRations() {
	int N;
	cin >> N;
	vector<int> B(N);
	for (int B_i = 0;B_i < N;B_i++) {
		cin >> B[B_i];
	}

	int countLoaves = 0;
	for (int i = 0; i<N; i++) {
		if (B[i] % 2 != 0) {
			if (i<N - 1) {
				B[i]++;
				B[i + 1]++;
				countLoaves += 2;
			}
			else {
				countLoaves = -1;
				break;
			}
		}
	}

	if (countLoaves != -1)
		cout << countLoaves;
	else
		cout << "NO";
	return 0;
}
