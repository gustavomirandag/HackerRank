#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream> 
#include <algorithm>
#include <climits>
using namespace std;

int mainFloydCityOfBlindingLights() {
	int n, m;
	cin >> n >> m;
	int dist[n][n];

	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			dist[i][j] = 99999;
		}
	}

	for (int i = 0; i<m; i++) {
		int x, y, r;
		cin >> x >> y >> r;
		x--;
		y--;
		dist[x][y] = r;
	}

	for (int i = 0; i<n; i++) {
		dist[i][i] = 0;
	}

	//Floyd-Warshall
	for (int k = 0; k<n; k++) {
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<n; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	int q;
	cin >> q;
	for (int i = 0; i<q; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		if (dist[x][y] == 99999)
			cout << "-1" << endl;
		else
			cout << dist[x][y] << endl;
	}
	return 0;
}
