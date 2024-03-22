#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
#include <unordered_map>
using namespace std;

int N, ans, arr[500][500];
int d, mv = 1, dy[] = { 0, 1, 0, -1 }, dx[] = { -1, 0, 1, 0 };
double mvsand[4][5][5] = {
	{
		{0, 0, 0.02, 0, 0},
		{0, 0.1, 0.07, 0.01, 0},
		{0.05, 0, 0, 0, 0},
		{0, 0.1, 0.07, 0.01, 0},
		{0, 0, 0.02, 0, 0}
	},
	{
		{0, 0, 0, 0, 0},
		{0, 0.01, 0, 0.01, 0},
		{0.02, 0.07, 0, 0.07, 0.02},
		{0, 0.1, 0, 0.1, 0},
		{0, 0, 0.05, 0, 0}
	},
	{
		{0, 0, 0.02, 0, 0},
		{0, 0.01, 0.07, 0.1, 0},
		{0, 0, 0, 0, 0.05},
		{0, 0.01, 0.07, 0.1, 0},
		{0, 0, 0.02, 0, 0}
	},
	{
		{0, 0, 0.05, 0, 0},
		{0, 0.1, 0, 0.1, 0},
		{0.02, 0.07, 0, 0.07, 0.02},
		{0, 0.01, 0, 0.01, 0},
		{0, 0, 0, 0, 0}
	}
};


void move_sand(int y, int x, int sand) {
	arr[y][x] = 0;
	int dr, dc, sum = 0;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (mvsand[d][i][j] == 0) continue;
			int temp_sand = mvsand[d][i][j] * sand;
			dr = y + (i - 2);
			dc = x + (j - 2);
			sum += temp_sand;
			if (dr < 0 || dr >= N || dc < 0 || dc >= N) {
				ans += temp_sand;
				continue;
			}
			arr[dr][dc] += temp_sand;
		}
	}

	sand -= sum;
	dr = y + dy[d];
	dc = x + dx[d];
	if (dr < 0 || dr >= N || dc < 0 || dc >= N) {
		ans += sand;
	}
	else {
		arr[dr][dc] += sand;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	int dr = N / 2;
	int dc = N / 2;
	
	while (1) {
		int temp_mv = 0;
		while (temp_mv < mv) {
			dr += dy[d];
			dc += dx[d];

			if (arr[dr][dc]) {
				move_sand(dr, dc, arr[dr][dc]);
			}
			temp_mv++;
		}

		if (dr == 0 && dc == 0) break;
		d = (d + 1) % 4;
		if ((d == 0 || d == 2) && dr != 0) {
			mv++;
			temp_mv = 0;
		}

	}
	cout << ans;
}