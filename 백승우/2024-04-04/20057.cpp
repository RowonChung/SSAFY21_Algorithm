#include <iostream>
using namespace std;

int n;
int graph[500][500];

int ans = 0;

struct Node {
	int y;
	int x;
};

// 좌하우상
int dy[4] = { 0,1,0,-1 };
int dx[4] = { -1,0,1,0 };

int real_d(int v_d)
{
	if (v_d < 0) return v_d + 4;
	if (v_d >= 4) return v_d - 4;
	return v_d;
}

struct Info
{
	Node sd;
	int p;
};

Info guess[4][10] = {
	{{{-1,1}, 1},{{1,1}, 1},{{-2,0}, 2},{{2,0}, 2},{{-1,0}, 7},{{1,0}, 7},{{-1,-1}, 10},{{1,-1}, 10},{{0,-2}, 5}, {{0,-1},100}},
	{{{-1,-1,}, 1},{{-1,1}, 1},{{0,-2}, 2},{{0,2}, 2},{{0,-1}, 7},{{0,1}, 7},{{1,-1}, 10},{{1,1}, 10},{{2,0}, 5}, {{1,0},100}},
	{{{-1,-1,}, 1},{{1,-1}, 1},{{-2,0}, 2},{{2,0}, 2},{{-1,0}, 7},{{1,0}, 7},{{-1,1}, 10},{{1,1}, 10},{{0,2}, 5}, {{0,1},100}},
	{{{1,-1,}, 1},{{1,1}, 1},{{0,-2}, 2},{{0,2}, 2},{{0,-1}, 7},{{0,1}, 7},{{-1,-1}, 10},{{-1,1}, 10},{{-2,0}, 5}, {{-1,0},100}},
};

void sandstorm(Node nxt, Node now, int d)
{
	int origin = graph[nxt.y][nxt.x];
	graph[nxt.y][nxt.x] = 0;

	int used = 0;
	for (int i = 0; i < 10; i++) {
		int ny = nxt.y + guess[d][i].sd.y;
		int nx = nxt.x + guess[d][i].sd.x;
		int n_sand;
		if (i != 9) n_sand = origin * guess[d][i].p / 100;
		else n_sand = origin - used;

		if (ny < 0 or nx < 0 or ny >= n or nx >= n) ans += n_sand;
		else graph[ny][nx] += n_sand;

		used += n_sand;
	}
	return;
}

void game()
{
	int length = 1, cnt = 0, d = 0;

	Node now = { n / 2, n / 2 };

	while (true) {
		cnt += 1;
		for (int i = 0; i < length; i++) {
			Node nxt;
			nxt.y = now.y + dy[d];
			nxt.x = now.x + dx[d];
			if (now.y == 0 and now.x == 0) {
				return;
			}
			sandstorm(nxt, now, d);
			now = nxt;
		}
		d = real_d(d + 1);

		if (cnt == 2) {
			cnt = 0;
			length += 1;
		}
	}
}

int main()
{
	cin >> n;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) cin >> graph[y][x];
	}

	game();

	cout << ans;

	return 0;
}
