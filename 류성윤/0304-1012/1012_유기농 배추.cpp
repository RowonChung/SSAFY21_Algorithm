#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct Node {
	int y, x;
};
vector<int> dy = { -1, 1, 0, 0 };
vector<int> dx = { 0, 0, -1, 1 };

int T, N, M, K;
int field[64][64];

void floodFill(int y, int x, int num) {
	queue<Node> q;

	q.push({ y,x });
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (int i = 0; i < dy.size(); i++) {
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];

			if (ny >= N || nx >= M || ny < 0 || nx < 0) continue;
			if (field[ny][nx] == 0) continue;
			if (field[ny][nx] > 1) continue;

			q.push({ ny, nx });
			field[ny][nx] = num;
		}
	}
}

int searchField() {
	int aInd = 2;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (field[i][j] != 1) continue;
			else
				floodFill(i, j, aInd++);
		}
	}
	return aInd - 2;
}


int main() {
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> M >> N >> K;
		// initialize
		for (int i = 0; i <= N; i++)
			memset(field[i], 0, sizeof(int) * (M + 1));

		// input loop
		for (int i = 0; i < K; i++) {
			int x, y; cin >> x >> y;
			field[y][x] = 1;
		}
		// solve

		cout << searchField() << endl;
	}
}