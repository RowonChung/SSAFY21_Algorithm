#include <iostream>
#include <deque>
#include <vector>
#include <string>
using namespace std;

int m, s;
int sy, sx;

struct Node {
	int y;
	int x;
};

deque <int/*direction*/> graph[4][4];
deque <int> temp_graph[4][4];
deque <int> copy_graph[4][4];

int/*timer*/ smells[4][4];

int dy[8] = { 0,-1,-1,-1,0,1,1,1 };
int dx[8] = { -1,-1,0,1,1,1,0,-1 };

int real_d(int v_d)
{
	if (v_d < 0) return v_d + 8;
	if (v_d >= 8) return v_d - 8;
	return v_d;
}

void copy_init()
{
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			copy_graph[y][x] = graph[y][x];
		}
	}
}

void fish_move(int d, Node pos)
{
	for (int i = 0; i < 8; i++) {
		int nd = real_d(d - i);

		int ny = pos.y + dy[nd];
		int nx = pos.x + dx[nd];

		if (ny < 0 or nx < 0 or ny >= 4 or nx >= 4) continue;
		if (smells[ny][nx] > 0) continue;
		if (ny == sy and nx == sx) continue;

		temp_graph[ny][nx].push_back(nd);
		return;
	}

	temp_graph[pos.y][pos.x].push_back(d);
	return;
}

void clear()
{
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			temp_graph[y][x].clear();
		}
	}
}
void fish_moves()
{
	clear();
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			int fish_cnt = graph[y][x].size();
			for (int i = 0; i < fish_cnt; i++) {
				int now = graph[y][x].front();
				graph[y][x].pop_front();

				fish_move(now, { y,x });
			}
		}
	}

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			graph[y][x] = temp_graph[y][x];
		}
	}
}

string best_road;
int turn_best;

// 상은 0, 좌는 1, 하는 2, 우는 3로 변환
int sdy[4] = { -1,0,1,0 };
int sdx[4] = { 0,-1,0,1 };

void each_move(int level, string now, int eaten_cnt, Node pos)
{
	if (level >= 3) {
		if (turn_best <= eaten_cnt) {
			best_road = now;
			turn_best = eaten_cnt;
		}
		return;
	}

	for (int i = 3; i >=0; i--) {
		string nxt = now + (to_string(i));

		int nsy = pos.y + sdy[i];
		int nsx = pos.x + sdx[i];
		if (nsy < 0 or nsx < 0 or nsy >= 4 or nsx >= 4) continue;

		deque <int> temp = graph[nsy][nsx];
		graph[nsy][nsx].clear();
		each_move(level + 1, nxt, eaten_cnt + temp.size(), { nsy, nsx });
		graph[nsy][nsx] = temp;
	}
	return;
}
void shark_move()
{
	turn_best = 0;
	best_road = "333";

	each_move(0, "", 0, { sy, sx });
	for (int i = 0; i < 3; i++) {
		int d = best_road[i] - '0';
		sy = sy + sdy[d];
		sx = sx + sdx[d];

		if (graph[sy][sx].size() > 0) smells[sy][sx] = (2 + 1);

		graph[sy][sx].clear();
	}
}

void erase_smell()
{
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (smells[y][x] == 0) continue;
			smells[y][x] -= 1;
		}
	}
}

void copy_activate()
{
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			graph[y][x].insert(graph[y][x].end(), copy_graph[y][x].begin(), copy_graph[y][x].end());
		}
	}
}

int how_fishes()
{
	int ans = 0;
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			ans += graph[y][x].size();
		}
	}
	return ans;
}

int main()
{
	cin >> m >> s;

	int v_fy, v_fx, v_d;
	for (int i = 0; i < m; i++) {
		cin >> v_fy >> v_fx >> v_d;
		graph[v_fy - 1][v_fx - 1].push_back(v_d - 1);
	}

	int v_sy, v_sx;
	cin >> v_sy >> v_sx;
	sy = v_sy - 1;
	sx = v_sx - 1;

	for (int i = 0; i < s; i++) {
		// step1 => fin
		copy_init();
		// step2 => fin
		fish_moves();
		// step3 => fin
		shark_move();
		// step4 => fin
		erase_smell();
		// step5 => fin
		copy_activate();
	}

	cout << how_fishes();

	return 0;
}
