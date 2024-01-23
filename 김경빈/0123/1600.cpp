#include <iostream>
#include <vector>
#include <deque>
#define endl "\n"
using namespace std;

struct loc {
	int x, y, time, k;
};

int K, W, H, board[201][201], dr, dc, ans = -1;
int horse_dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 }, horse_dx[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dy[] = { -1, 1, 0, 0 }, dx[] = { 0, 0, -1, 1 };
bool visited[201][201][31];
deque<loc> q;

int main() {
	cin >> K >> W >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> board[i][j];
		}
	}
	loc loc_temp, qp;
	loc_temp.x = 0; loc_temp.y = 0;
	loc_temp.time = 0; loc_temp.k = 0;
	q.push_back(loc_temp);
	visited[0][0][0] = true;

	while (!q.empty()) {
		qp = q.front();
		q.pop_front();

		if (qp.x == W - 1 && qp.y == H - 1) {
			ans = qp.time;
			break;
		}

		if (qp.k < K) {
			for (int i = 0; i < 8; i++) {
				dr = qp.y + horse_dy[i];
				dc = qp.x + horse_dx[i];

				if (dr >= 0 && dr < H && dc >= 0 && dc < W) {
					if (not visited[dr][dc][qp.k+1] && board[dr][dc] != 1) {
						loc ht;
						visited[dr][dc][qp.k+1] = true;
						ht.y = dr;
						ht.x = dc;
						ht.time = qp.time + 1;
						ht.k = qp.k + 1;
						q.push_back(ht);
					}
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			dr = qp.y + dy[i];
			dc = qp.x + dx[i];

			if (dr >= 0 && dr < H && dc >= 0 && dc < W) {
				if (not visited[dr][dc][qp.k] && board[dr][dc] != 1) {
					loc lt;
					visited[dr][dc][qp.k] = true;
					lt.y = dr;
					lt.x = dc;
					lt.time = qp.time + 1;
					lt.k = qp.k;
					q.push_back(lt);
				}
			}
		}
	}
	cout << ans << endl;
}