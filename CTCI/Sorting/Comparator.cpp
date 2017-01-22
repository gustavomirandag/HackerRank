#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Player {
	string name;
	int score;
};

bool cmp(const Player &p1, const Player &p2) {
	if (p1.score > p2.score)
		return true;
	else if (p2.score > p1.score)
		return false;
	else {
		if (p1.score == p2.score) {
			if (p1.name < p2.name)
				return true;
			else
				return false;
		}
	}
	return false;
}

vector<Player> comparator(vector<Player> players) {
	sort(players.begin(), players.end(), cmp);
	return players;
}

int main() {

	int n;
	cin >> n;
	vector< Player > players;
	string name;
	int score;
	for (int i = 0; i < n; i++) {
		cin >> name >> score;
		Player p1;
		p1.name = name, p1.score = score;
		players.push_back(p1);
	}

	vector<Player > answer = comparator(players);
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i].name << " " << answer[i].score << endl;
	}
	return 0;
}
