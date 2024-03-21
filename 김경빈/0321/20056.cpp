#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
#include <unordered_map>
using namespace std;

struct FIRE {
	int r, c, m, s, d;
};
struct ARR {
	int m, s, d, cnt;
	bool isodd = false, iscross = false;
};
int N, M, K, r, c, m, s, d, ans;
int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 }, dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
queue<FIRE> fire;
ARR arr[51][51];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		cin >> r >> c >> m >> s >> d;
		fire.push({ r-1, c-1, m, s, d });
		ans += m;
	}

	for (int k = 0; k < K; k++) {
		while (!fire.empty()) {
			FIRE qp = fire.front();
			fire.pop();

			int dr = (qp.r + dy[qp.d] * qp.s) % N;
			int dc = (qp.c + dx[qp.d] * qp.s) % N;
			
			if (dr < 0) dr += N;
			if (dc < 0) dc += N;

			if (arr[dr][dc].cnt == 0) {
				arr[dr][dc].m = qp.m;
				arr[dr][dc].s = qp.s;
				arr[dr][dc].d = qp.d;
				arr[dr][dc].cnt = 1;
				arr[dr][dc].isodd = qp.d % 2;
			}
			else {
				arr[dr][dc].m += qp.m;
				arr[dr][dc].s += qp.s;
				arr[dr][dc].cnt++;
				if ((arr[dr][dc].isodd ^ bool(qp.d % 2))) arr[dr][dc].iscross = true;
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j].cnt == 0) continue;
				if (arr[i][j].cnt == 1) {
					fire.push({ i, j, arr[i][j].m, arr[i][j].s, arr[i][j].d });
					continue;
				}
				int temp_m = arr[i][j].m / 5;
				ans -= arr[i][j].m;
				if (temp_m == 0) continue;
				int temp_s = arr[i][j].s / arr[i][j].cnt;

				for (int l = 0; l < 4; l++) {
					if (arr[i][j].iscross) {
						fire.push({ i, j, temp_m, temp_s, 2 * l + 1 });
					}
					else {
						fire.push({ i, j, temp_m, temp_s, 2 * l });
					}
				}
				
				ans += temp_m * 4;
			}
		}
		memset(arr, 0, sizeof(arr));
	}
	cout << ans;
}