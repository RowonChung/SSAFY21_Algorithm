#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
#include <unordered_map>
#include <cmath>
using namespace std;

struct Node {
	int y, x;
};
int N, Q, arr[100][100], temp_arr[100][100], L, visited[100][100], total, dung;
int dy[] = { -1, 1, 0, 0 }, dx[] = { 0, 0, -1, 1 };
queue<Node> q;

void magic(int level) {
	if (level == 0) return;

	int d = pow(2, level);
	memcpy(&temp_arr, &arr, sizeof(arr));

	for (int i = 0; i < N; i += d) {
		for (int j = 0; j < N; j += d) {
			for (int r = 0; r < d; r++) {
				for (int c = 0; c < d; c++) {
					arr[i + r][j + c] = temp_arr[i + d - c - 1][j + r];
				}
			}
		}
	}
}

void melt() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 0) continue;
			int near = 0;
			for (int d = 0; d < 4; d++) {
				int dr = i + dy[d];
				int dc = j + dx[d];

				if (dr < 0 || dr >= N || dc < 0 || dc >= N) continue;
				if (arr[dr][dc] <= 0) continue;
				near++;
			}
			if (near < 3) {
				q.push({ i, j });
			}
		}
	}
	while (!q.empty()) {
		Node qp = q.front();
		q.pop();
		arr[qp.y][qp.x]--;
		total--;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> Q;
	N = pow(2, N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			total += arr[i][j];
		}
	}
	for (int i = 0; i < Q; i++) {
		cin >> L;
		magic(L);
		melt();
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 0 || visited[i][j]) continue;
			int temp_dung = 0;
			visited[i][j] = 1;
			q.push({ i, j });

			while (!q.empty()) {
				Node qp = q.front();
				q.pop();
				temp_dung++;

				for (int d = 0; d < 4; d++) {
					int dr = qp.y + dy[d];
					int dc = qp.x + dx[d];

					if (dr < 0 || dr >= N || dc < 0 || dc >= N) continue;
					if (visited[dr][dc] || arr[dr][dc] <= 0) continue;

					visited[dr][dc] = 1;
					q.push({ dr, dc });
				}
			}
			dung = max(dung, temp_dung);
		}
	}
	cout << total << "\n" << dung << "\n";

}