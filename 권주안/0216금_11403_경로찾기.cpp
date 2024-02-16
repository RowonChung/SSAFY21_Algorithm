#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
int alis[101][101];
int dist[101][101];

void init() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (y == x) dist[y][x] = 2134567;
			else if (alis[y][x]) dist[y][x] = alis[y][x];
			else dist[y][x] = 2134567;
		}
	}
}

void floyd() {
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}

int main() {
	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> alis[y][x];
		}
	}
	init();
	floyd();
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (dist[y][x] >= 2134567 || dist[y][x] == 0) cout << "0 ";
			else cout << "1 ";
		}
		cout << "\n";
	}

	return 0;
}