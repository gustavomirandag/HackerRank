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

int mainEqualStacks() {
	int n1;
	int n2;
	int n3;
	cin >> n1 >> n2 >> n3;
	vector<int> h1(n1);
	for (int h1_i = 0;h1_i < n1;h1_i++) {
		cin >> h1[h1_i];
	}
	vector<int> h2(n2);
	for (int h2_i = 0;h2_i < n2;h2_i++) {
		cin >> h2[h2_i];
	}
	vector<int> h3(n3);
	for (int h3_i = 0;h3_i < n3;h3_i++) {
		cin >> h3[h3_i];
	}

	int height1 = accumulate(h1.begin(), h1.end(), (int)0);
	int height2 = accumulate(h2.begin(), h2.end(), (int)0);
	int height3 = accumulate(h3.begin(), h3.end(), (int)0);
	int i1 = 0;
	int i2 = 0;
	int i3 = 0;
	while (height1 != height2 || height1 != height3) {
		//n1 is the biggest
		if (height1 >= height2 && height1 >= height3) {
			height1 -= h1[i1];
			i1++;
		}
		else {
			//n2 is the biggest
			if (height2 >= height1 && height2 >= height3) {
				height2 -= h2[i2];
				i2++;
			}
			else {
				//n3 is the biggest
				if (height3 >= height1 && height3 >= height2) {
					height3 -= h3[i3];
					i3++;
				}
			}
		}
	}

	cout << height1;//Could print height1,height2 or height3

	return 0;
}
