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

int getRegionSize(vector< vector<int> > &grid, int row, int col) {
	int size = 1; //Current FilledCell
	int minRow = row - 1 >= 0 ? row - 1 : row;
	int maxRow = row + 1<grid.size() ? row + 1 : row;
	int minCol = col - 1 >= 0 ? col - 1 : col;
	int maxCol = col + 1<grid[0].size() ? col + 1 : col;
	grid[row][col] = 0;//Remove repetition
	for (int i = minRow; i <= maxRow; i++) {
		for (int j = minCol; j <= maxCol; j++) {
			if (grid[i][j] == 1)//Found a filled cell
				size += getRegionSize(grid, i, j);
		}
	}
	return size;
}

int get_biggest_region(vector< vector<int> > grid) {
	int maxSize = 0;
	for (int i = 0; i<grid.size(); i++) {
		for (int j = 0; j<grid[i].size(); j++) {
			if (grid[i][j] == 1) {//Found a filled cell
				maxSize = max(maxSize, getRegionSize(grid, i, j));
			}
		}
	}
	return maxSize;
}

int main() {
	int n;
	cin >> n;
	int m;
	cin >> m;
	vector< vector<int> > grid(n, vector<int>(m));
	for (int grid_i = 0; grid_i < n; grid_i++) {
		for (int grid_j = 0; grid_j < m; grid_j++) {
			cin >> grid[grid_i][grid_j];
		}
	}
	cout << get_biggest_region(grid) << endl;
	return 0;
}
