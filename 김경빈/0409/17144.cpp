#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <stdio.h>
using namespace std;

struct DUST {
	int y, x, val;
};
int R, C, T, cleaner[2], arr[51][51], input;
int dy[] = { -1, 0, 1, 0 }, dx[] = { 0, -1, 0, 1 };
queue<DUST> q;

void spread_dust() {
	while (!q.empty()) {
		DUST qp = q.front();
		q.pop();

		int cnt = 0, div = qp.val / 5;
		for (int i = 0; i < 4; i++) {
			int dr = qp.y + dy[i];
			int dc = qp.x + dx[i];

			if (dr < 0 || dr >= R || dc < 0 || dc >= C) continue;
			if (arr[dr][dc] == -1) continue;

			cnt++;
			arr[dr][dc] += div;
		}
		arr[qp.y][qp.x] += qp.val - cnt * div;
	}
}

void blow_dust() {
	for (int i = 0; i < 2; i++) {
		if (i == 0) {
			int before_y = cleaner[i], before_x = 0, before_val = arr[before_y][before_x];
			for (int d = 0; d < 4; d++) {
				int delta = (d + 3) % 4;
				if (delta % 2) {
					for (int c = 0; c < C-1; c++) {
						int x = before_x + dx[delta];
						if (before_val == -1) {
							before_x = x;
							before_val = arr[before_y][x];
							arr[before_y][x] = 0;
						}
						else {
							int temp = before_val;
							before_val = arr[before_y][x];
							arr[before_y][x] = temp;
							before_x = x;
						}
					}
				}
				else {
					for (int r = 0; r < cleaner[i]; r++) {
						int y = before_y + dy[delta];
						if (arr[y][before_x] == -1) {
							break;
						}
						else {
							int temp = before_val;
							before_val = arr[y][before_x];
							arr[y][before_x] = temp;
							before_y = y;
						}
					}
				}
			}
		}
		else {
			int before_y = cleaner[i], before_x = 0, before_val = arr[before_y][before_x];
			for (int d = 3; d >= 0; d--) {
				if (d % 2) {
					for (int c = 0; c < C-1; c++) {
						int x = before_x + dx[d];
						if (before_val == -1) {
							before_x = x;
							before_val = arr[before_y][x];
							arr[before_y][x] = 0;
						}
						else {
							int temp = before_val;
							before_val = arr[before_y][x];
							arr[before_y][x] = temp;
							before_x = x;
						}
					}
				}
				else {
					for (int r = cleaner[i]; r < R-1; r++) {
						int y = before_y + dy[d];
						if (arr[y][before_x] == -1) {
							break;
						}
						else {
							int temp = before_val;
							before_val = arr[y][before_x];
							arr[y][before_x] = temp;
							before_y = y;
						}
					}
				}
			}
		}
	}
}

void push_q() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (arr[i][j] == -1) continue;
			q.push({ i, j, arr[i][j] });
			arr[i][j] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C >> T;
	int idx = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> input;
			if (input == -1) {
				cleaner[idx] = i;
				arr[i][j] = -1;
				idx++;
			}
			else if (input > 0) {
				q.push({ i, j, input });
			}
		}
	}

	for (int t = 0; t < T; t++) {
		spread_dust();
		blow_dust();
		push_q();
	}

	int sum = 0;
	while (!q.empty()) {
		DUST qp = q.front();
		q.pop();
		sum += qp.val;
	}
	cout << sum;
}