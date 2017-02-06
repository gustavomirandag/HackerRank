#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

class Graph {
	vector<unordered_map<int, bool>> *nodes;
public:
	Graph(int n) {
		nodes = new vector<unordered_map<int, bool>>(n);
	}

	void add_edge(int u, int v) {
		(*nodes)[u][v] = true;
		(*nodes)[v][u] = true;
	}

	vector<int> shortest_reach(int start) {
		unordered_map<int, int> visitedNodes;//Second is the distance
		queue<pair<int, int>> nodesToVisit;

		int distance = 0;
		nodesToVisit.push(make_pair(start, 0));
		while (!nodesToVisit.empty()) {
			pair<int, int> front = nodesToVisit.front();
			nodesToVisit.pop();
			if (visitedNodes.find(front.first) == visitedNodes.end())
				visitedNodes[front.first] = front.second;
			distance = front.second + 6;//Distance for the Edges of the Current Node
			for (auto node : (*nodes)[front.first]) {
				if (visitedNodes.find(node.first) == visitedNodes.end())
					nodesToVisit.push(make_pair(node.first, distance));
			}
		}
		vector<int> result((*nodes).size(), -1);
		for (auto iter : visitedNodes)
			result[iter.first] = iter.second;
		return result;
	}

};

int main() {
	int queries;
	cin >> queries;

	for (int t = 0; t < queries; t++) {

		int n, m;
		cin >> n;
		// Create a graph of size n where each edge weight is 6: 
		Graph graph(n);
		cin >> m;
		// read and set edges
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			u--, v--;
			// add each edge to the graph
			graph.add_edge(u, v);
		}
		int startId;
		cin >> startId;
		startId--;
		// Find shortest reach from node s
		vector<int> distances = graph.shortest_reach(startId);

		for (int i = 0; i < distances.size(); i++) {
			if (i != startId) {
				cout << distances[i] << " ";
			}
		}
		cout << endl;
	}

	return 0;
}
