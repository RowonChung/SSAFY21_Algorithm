#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

struct Node {
	int y;
	int x;
};

int N, M;
vector<Node> chicken;
vector<Node> house;
vector<int> dist[13];
int check[13];
int minres = 21e8;

void calDist() {
	for (int i = 0; i < chicken.size(); i++) {
		for (int j = 0; j < house.size(); j++) {
			int d = abs(chicken[i].y - house[j].y) + abs(chicken[i].x - house[j].x);

			dist[i].push_back(d);
		}
	}
}

void calMin() {
	int res = 0;
	for (int i = 0; i < house.size(); i++) {
		int minD = 999;
		for (int j = 0; j < chicken.size(); j++) {
			if (check[j] == 0) continue;
			minD = min(minD, dist[j][i]);
		}
		res += minD;
	}
	minres = min(res, minres);
}

void run(int index, int level) {
	if (level == M) {
		int cnt = 0;
		for (int i = 0; i < chicken.size(); i++) {
			if (check[i] == 1) cnt++;
		}
		if (cnt != M) return;

		calMin();
		return;
	}

	for (int i = index; i < chicken.size(); i++) {
		check[i] = 1;
		run(i+1, level + 1);
		check[i] = 0;
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int input;
			cin >> input;

			if (input == 1)
				house.push_back({ i,j });
			
			if (input == 2)
				chicken.push_back({ i,j });
		}
	}

	calDist();
	
	run(0, 0);

	cout << minres;

	return 0;
}