#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include "SnakesAndLadders.h"
using namespace std;


// GRAPH CODE
class Vertex {
	public:
		int id;
		vector<Vertex**> edges; //Points to a pointer of the Graph Vertices Vector: vector<Vertex*> vertices
		bool inQueue;
		int steps;

		Vertex() {
			inQueue = false;
			steps = 0;
		}
};

class Graph {
	private:
		std::vector<Vertex*> vertices;

	public:
		Graph() {
			vertices.resize(101);
			vertices[0] = nullptr;
		}

		void addVertex(Vertex * v) {
			vertices.push_back(v);
		}
		Vertex** getVertexPtr(int id) {
			return &vertices[id];
		}
		Vertex* getVertex(int id) {
			return vertices[id];
		}
		void setVertex(int id, Vertex* newVertex) {
			vertices[id] = newVertex;
		}
		void replaceVertex(int startPoint, int endPoint) {
			setVertex(startPoint, getVertex(endPoint));
		}

};
//END GRAPH CODE

Graph mountSnakesAndLaddersBoardGraph() {
	Graph graph;
	Vertex *currentVertex;

	for (int i = 1; i <= 100; i++) {
		currentVertex = new Vertex();
		currentVertex->id = i;
		graph.setVertex(i, currentVertex);
	}

	for (int i = 1; i <= 100; i++) {
		currentVertex = graph.getVertex(i);
		for (int j = 1; j <= 6; j++) {
			if (i + j <= 100)
				currentVertex->edges.push_back(graph.getVertexPtr(i + j)); //Point to the Address of the Vector Pointers and NOT the node by itself
		}
	}
	return graph;
}

void addLaddersToBoardGraph(Graph& graph, const vector<pair<int, int>> &ladders) {
	for (int i = 0; i<ladders.size(); i++) {
		int startPoint, endPoint;
		startPoint = ladders[i].first;
		endPoint = ladders[i].second;
		graph.replaceVertex(startPoint, endPoint);
	}
}

void addSnakesToBoardGraph(Graph& graph, const vector<pair<int, int>> &snakes) {
	for (int i = 0; i<snakes.size(); i++) {
		int startPoint, endPoint;
		startPoint = snakes[i].first;
		endPoint = snakes[i].second;
		graph.replaceVertex(startPoint, endPoint);
	}
}

int getMinStepsToFinish(Graph &graph) {
	//Breadth First Search
	queue <Vertex*> fifo;
	int minSteps = 2000;
	Vertex *currentVertex = graph.getVertex(1);
	currentVertex->inQueue = true;
	fifo.push(currentVertex);

	while (!fifo.empty()) {
		currentVertex = fifo.front();
		fifo.pop();
		for (int i = 0; i < currentVertex->edges.size(); i++) {
			Vertex *currentEdgeVertex = *currentVertex->edges[i];
			if (currentEdgeVertex->inQueue == true && currentEdgeVertex->id != 100)
				continue;
			currentEdgeVertex->steps = currentVertex->steps + 1;
			if (currentEdgeVertex == graph.getVertex(100)) {
				if (currentEdgeVertex->steps < minSteps)
					minSteps = currentEdgeVertex->steps;
			}
			else {
				currentEdgeVertex->inQueue = true;
				fifo.push(currentEdgeVertex);
			}
		}
	}
	if (minSteps == 2000)
		return -1;
	else
		return minSteps;
}

int mainSnakesAndLadders() {
	int t, laddersCount, snakesCount;
	cin >> t;

	while (t--) {
		cin >> laddersCount;
		vector <pair<int, int>> ladders;
		for (int i = 0; i < laddersCount; i++) {
			int startPoint, endPoint;
			cin >> startPoint >> endPoint;
			ladders.push_back(make_pair(startPoint, endPoint));
		}
		cin >> snakesCount;
		vector <pair<int, int>> snakes;
		for (int i = 0; i < snakesCount; i++) {
			int startPoint, endPoint;
			cin >> startPoint >> endPoint;
			snakes.push_back(make_pair(startPoint, endPoint));
		}

		//Mount the Board
		Graph graph = mountSnakesAndLaddersBoardGraph();
		addLaddersToBoardGraph(graph, ladders);
		addSnakesToBoardGraph(graph, snakes);
		//End Mount the Board

		cout << getMinStepsToFinish(graph) << endl;

	}
	return 0;
}



/* FIRST ATTEMPT */
//int mainSnakesAndLadders() {
//	int t, laddersCount, snakesCount;
//	cin >> t;
//
//	while (t--) {
//		vector <int> board(101,101);
//		cin >> laddersCount;
//		vector <pair<int, int>> ladders;
//		for (int i = 0; i<laddersCount; i++) {
//			int startPoint, endPoint;
//			cin >> startPoint >> endPoint;
//			board[startPoint] = endPoint;
//			ladders.push_back(make_pair(startPoint, endPoint));
//		}
//		cin >> snakesCount;
//		for (int i = 0; i<snakesCount; i++) {
//			int startPoint, endPoint;
//			cin >> startPoint >> endPoint;
//			board[startPoint] = endPoint;
//		}
//
//		//Make Ladders Heap
//		make_heap(ladders.begin(), ladders.end(), [](std::pair<int, int> const & lLadder, std::pair<int, int> const & rLadder) {
//			return lLadder.second-lLadder.first < rLadder.second-rLadder.first;
//		});
//		/*
//		// If you can't use c++11, then this is identical:
//		struct {
//		bool operator()(std::pair<int, int> lhs, std::pair<int, int> rhs) const {
//		return lhs.second < rhs.second;
//		}
//		} Compare;
//		*/
//
//		int boardPosition = 1; //Board Iterator / Character Position
//		int countSteps = 0; //The result of the problem
//		while (boardPosition < 100) {
//			for (auto ladderIter:ladders) {
//				while (boardPosition < ladderIter.first) {
//					//LadderIter < 6 => You can go with just one die tosse
//					if (ladderIter.first-boardPosition <= 6) {
//						countSteps++;
//						boardPosition = ladderIter.first;
//					}
//					else {
//						int dieResult = 6;
//						while (board[boardPosition + dieResult] < boardPosition + dieResult) {
//							dieResult--;
//							if (dieResult < 1)
//								return -1;
//						}
//						countSteps++;
//						boardPosition += dieResult;
//					}
//					if (boardPosition == ladderIter.first)
//						boardPosition = ladderIter.second;
//				}
//			}
//			while (boardPosition < 100) {
//				//LadderIter < 6 => You can go with just one tosse of the die
//				if (100-boardPosition <= 6) {
//					countSteps++;
//					boardPosition = 100;
//				}
//				else {
//					int dieResult = 6;
//					while (board[boardPosition + dieResult] < boardPosition + dieResult) {
//						dieResult--;
//						if (dieResult < 1)
//							return -1;
//					}
//					countSteps++;
//					boardPosition += dieResult;
//				}
//			}
//		}
//		cout<< countSteps <<endl;
//	}
//	return 0;
//}






