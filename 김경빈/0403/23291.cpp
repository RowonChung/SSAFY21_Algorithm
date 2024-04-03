#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#include <unordered_map>
using namespace std;

struct Node {
	int y, x;
};
int N, K, bowl[101][101], temp[101][101], visited[101][101][5], cnt, min_val = INT_MAX, max_val;
int height, is_over, none_over;
int dr, dc, dy[] = { -1, 1, 0, 0 }, dx[] = { 0, 0, -1, 1 };
queue<Node> q;

void pile1() {
	int cnt = 0;
	height = 2, is_over = 1, none_over = 2;
	bowl[99][1] = bowl[100][0];
	bowl[100][0] = 0;

	while (height <= N-none_over) {
		cnt++;
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < none_over - is_over; j++) {
				bowl[100 - (none_over - is_over - j)][i + none_over] = bowl[100 - i][j + is_over];
				bowl[100 - i][j + is_over] = 0;
			}
		}
		int temp_height = height, temp_none_over = none_over;
		none_over += temp_height;
		if (cnt % 2 == 0) height++;
		is_over = temp_none_over;
	}
}

void pile2() {
	int i, j, k;
	for (i = 0; i < 2; i++) {
		for (j = 0; j < N / pow(2, i+1); j++) {
			for (k = 0; k < i + 1; k++) {
				bowl[100 - (2*(i+1) - k - 1)][N - j - 1] = bowl[100 - k][j + N - int(N / pow(2, i))];
				bowl[100 - k][j + N - int(N / pow(2.0, i))] = 0;
			}
		}
	}
}

void spread() {
	for (int i = 0; i < none_over - is_over; i++) {
		for (int j = 0; j < height; j++) {
			bowl[100][i*height + j] = bowl[100 - j][i + is_over];
			bowl[100 - j][i + is_over] = 0;
		}
	}
}

void check_div(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int dr = y + dy[i];
		int dc = x + dx[i];

		if (dr < 0 || dr > 100 || dc < 0 || dc >= N) continue;
		if (bowl[dr][dc] == 0) continue;
		if (visited[dr][dc][i^1]) continue;

		if (not visited[dr][dc][4]) q.push({ dr, dc });
		visited[dr][dc][4] = 1;
		visited[y][x][i] = 1;
		visited[dr][dc][i ^ 1] = 1;

		int div = abs(bowl[y][x] - bowl[dr][dc]) / 5;
		if (div == 0) continue;

		if (bowl[y][x] > bowl[dr][dc]) {
			temp[y][x] -= div;
			temp[dr][dc] += div;
		}
		else if (bowl[y][x] < bowl[dr][dc]) {
			temp[y][x] += div;
			temp[dr][dc] -= div;
		}
	}
}

void share_fish() {
	memset(visited, 0, sizeof(visited));
	memset(temp, 0, sizeof(temp));
	visited[100][N - 1][4] = 1;
	check_div(100, N - 1);

	while (!q.empty()) {
		Node qp = q.front();
		q.pop();

		check_div(qp.y, qp.x);
	}

	for (int i = is_over; i < N; i++) {
		for (int j = 100; j > 100 - height; j--) {
			bowl[j][i] += temp[j][i];
			temp[j][i] = 0;
		}
	}
}

int main() {	
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> bowl[100][i];
		if (bowl[100][i] < min_val) min_val = bowl[100][i];
		if (bowl[100][i] > max_val) max_val = bowl[100][i];
	}

	while (abs(max_val - min_val) > K) {
		cnt++;

		for (int i = 0; i < N; i++) {
			if (bowl[100][i] == min_val) bowl[100][i]++;
		}
		min_val = INT_MAX; max_val = 0;

		pile1();
		share_fish();
		spread();
		pile2();
		none_over = N; is_over = N - N / 4; height = 4;

		share_fish();
		spread();

		
		
		for (int i = 0; i < N; i++) {
			if (bowl[100][i] < min_val) min_val = bowl[100][i];
			if (bowl[100][i] > max_val) max_val = bowl[100][i];
		}
	}
	cout << cnt << endl;
}