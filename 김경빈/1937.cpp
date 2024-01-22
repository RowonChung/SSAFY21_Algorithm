#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <deque>
#define endl "\n"
using namespace std;

int N, bamboo[500][500], dp[500][500], max_move = 0;
int dx[4] = { 0, 0, -1, 1 }, dy[4] = { -1, 1, 0, 0 };

int eat(int x, int y) {
	if (dp[y][x] > 0) { return dp[y][x]; }
	int dr, dc, temp;

	for (int i = 0; i < 4; i++) {
		dr = y + dy[i];
		dc = x + dx[i];
		if (dr >= 0 && dr < N && dc >= 0 && dc < N) {
			if (bamboo[y][x] < bamboo[dr][dc]) {
				temp = eat(dc, dr) + 1;
				if (temp > dp[y][x]) {
					dp[y][x] = temp;
				}
			}
		}
	}
	if (dp[y][x] > max_move) {
		max_move = dp[y][x];
	}
	return dp[y][x];
}


int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> bamboo[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			eat(j, i);
		}
	}
	cout << max_move << endl;

	return 0;
}