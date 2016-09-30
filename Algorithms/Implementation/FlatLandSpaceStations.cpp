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


int mainFlatLandSpaceStations() {
	int n;
	int m;
	cin >> n >> m;
	vector<int> distance(n, -1);//-1 when the city has no space station
	vector<int> c(m);
	for (int c_i = 0;c_i < m;c_i++) {
		cin >> c[c_i];
		distance[c[c_i]] = 0;//0 when the city has a space station
	}

	int nearestLeftStation = -1;
	for (int i = 0; i<n; i++) {
		//if the city don't have a space station
		if (distance[i] != 0) {
			if (nearestLeftStation != -1)
				distance[i] = i - nearestLeftStation;
		}
		else {
			nearestLeftStation = i;
		}
	}

	int maxDistance = 0;
	int nearestRightStation = -1;
	for (int i = n - 1; i >= 0; i--) {
		//if the city don't have a space station
		if (distance[i] != 0) {
			if (nearestRightStation != -1)
				if (distance[i] == -1 || distance[i] > nearestRightStation - i)//NearestRightStation < NearestLeftStation
					distance[i] = nearestRightStation - i;
		}
		else {
			nearestRightStation = i;
		}
		if (distance[i]>maxDistance)
			maxDistance = distance[i];
	}

	cout << maxDistance;

	return 0;
}
