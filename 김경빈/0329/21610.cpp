#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
#include <unordered_map>
#include <cmath>
using namespace std;

struct BUCKET {
	int water, is_cloud;
};
struct COMM {
	int d, s;
};
struct cloud {
	int y, x;
};
int N, M, ans;
int dr, dc, dy[] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 }, dx[] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
BUCKET A[51][51];
COMM comm[101];
queue<cloud> q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j].water;
		}
	}
	for (int i = 1; i <= M; i++) {
		cin >> comm[i].d >> comm[i].s;
	}

	q.push({ N - 1, 0 });
	q.push({ N - 1, 1 });
	q.push({ N - 2, 0 });
	q.push({ N - 2, 1 });

	for (int i = 1; i <= M; i++) {
		int q_size = q.size();
		for (int qs = 0; qs < q_size; qs++) {
			cloud qp = q.front();
			q.pop();

			dr = (qp.y + dy[comm[i].d] * comm[i].s) % N;
			dc = (qp.x + dx[comm[i].d] * comm[i].s) % N;

			if (dr < 0) {
				dr += N;
			}
			if (dc < 0) {
				dc += N;
			}

			A[dr][dc].water++;
			A[dr][dc].is_cloud = i;

			q.push({ dr, dc });
		}

		while (!q.empty()) {
			cloud qp = q.front();
			q.pop();

			int add = 0;
			for (int d = 2; d <= 8; d += 2) {
				dr = qp.y + dy[d];
				dc = qp.x + dx[d];

				if (dr < 0 || dr >= N || dc < 0 || dc >= N) continue;
				if (A[dr][dc].water == 0) continue;
				add++;
			}
			A[qp.y][qp.x].water += add;
		}

		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				if (A[r][c].water < 2 || A[r][c].is_cloud == i) continue;
				A[r][c].water -= 2;
				q.push({ r, c });
			}
		}
	}

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			ans += A[r][c].water;
		}
	}
	cout << ans;
}