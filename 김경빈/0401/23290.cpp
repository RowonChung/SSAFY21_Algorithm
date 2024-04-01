#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <unordered_map>
using namespace std;

struct FISH {
	int y, x, d;
};
struct SHARK {
	int y, x, num, d;
};
int M, S, sx, sy, dont[4][4], y, x, d;
int dy[] = { 0, -1, -1, -1, 0, 1, 1, 1 }, dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dsy[] = { -1, 0, 1, 0 }, dsx[] = { 0, -1, 0, 1 };
deque<FISH> fish[4][4], temp[4][4], mv;
vector<vector<SHARK>> shark;

bool cmp(vector<SHARK>& left, vector<SHARK>& right) {
	bool ret = true;
	if (left[2].num > right[2].num) return true;
	else if (left[2].num < right[2].num) return false;
	else {
		for (int i = 0; i < 3; i++) {
			if (left[i].d > right[i].d) {
				return false;
			}
			else if (left[i].d < right[i].d) {
				return true;
			}
		}
	}
	return false;
}

void mv_shark(int depth, int sx, int sy, int num, vector<SHARK> v) {
	if (depth == 3) {
		shark.push_back(v);
		return;
	}

	for (int d = 0; d < 4; d++) {
		int dr = sy + dsy[d];
		int dc = sx + dsx[d];

		if (dr < 0 || dr >= 4 || dc < 0 || dc >= 4) continue;
		int add = temp[dr][dc].size();
		for (int i = 0; i < depth; i++) {
			if (v[i].y == dr && v[i].x == dc) {
				add = 0;
				break;
			}
		}
		SHARK temp_shark = { dr, dc, num + add, d };
		v.push_back(temp_shark);
		mv_shark(depth + 1, dc, dr, num + add, v);
		v.pop_back();
	}
}

int main() {	
	cin >> M >> S;
	for (int i = 1; i <= M; i++) {
		cin >> y >> x >> d;
		fish[y - 1][x - 1].push_back({ y - 1, x - 1, d - 1 });
	}
	cin >> sy >> sx;
	sy--; sx--;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			dont[i][j] = -10;
		}
	}

	for (int s = 1; s <= S; s++) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < fish[i][j].size(); k++) {
					mv.push_back(fish[i][j][k]);
				}
			}
		}

		while (!mv.empty()) {
			FISH qp = mv.front();
			mv.pop_front();

			int dr = qp.y + dy[qp.d];
			int dc = qp.x + dx[qp.d];
			if (dr < 0 || dr >= 4 || dc < 0 || dc >= 4 || (dr == sy && dc == sx) || dont[dr][dc] >= s - 2) {
				for (int d = 0; d < 8; d++) {
					qp.d--;
					qp.d = (8 + qp.d) % 8;
					dr = qp.y + dy[qp.d];
					dc = qp.x + dx[qp.d];
					if (dr >= 0 && dr < 4 && dc >= 0 && dc < 4 && (dr != sy || dc != sx) && dont[dr][dc] < s - 2) break;
				}
			}

			if (dr < 0 || dr >= 4 || dc < 0 || dc >= 4 || (dr == sy && dc == sx) || dont[dr][dc] >= s - 2) {
				temp[qp.y][qp.x].push_back(qp);
			}
			else {
				qp.y = dr;
				qp.x = dc;
				temp[dr][dc].push_back(qp);
			}
		}

		// while (!temp[sy][sx].empty()) temp[sy][sx].pop_back();
		mv_shark(0, sx, sy, 0, {});
		std::sort(shark.begin(), shark.end(), cmp);
		vector<SHARK> kill = shark[0];
		for (int i = 0; i < 3; i++) {
			SHARK mv = kill[i];
			if (temp[mv.y][mv.x].size()) {
				dont[mv.y][mv.x] = s;
				while (!temp[mv.y][mv.x].empty()) temp[mv.y][mv.x].pop_back();
			}
		}
		sy = kill[2].y;
		sx = kill[2].x;
		shark.clear();

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				while (!temp[i][j].empty()) {
					fish[i][j].push_back(temp[i][j].front());
					temp[i][j].pop_front();
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			ans += fish[i][j].size();
		}
	}
	cout << ans;
	
}