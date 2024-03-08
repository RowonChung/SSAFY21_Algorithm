#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int map[10001][101];

int  M,N, H;

int dy[4] = { -1,1,0,0 };

int dx[4] = { 0,0,-1,1 };

int dyy[2];

struct node {
	int y;
	int x;
	int level;
};

int main() {
	queue<node> q;
	
	cin >> M >> N >> H;
	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> map[i+(N*k)][j];
				if (map[i + (N * k)][j] == 1) {
					q.push({ i+(N*k),j,k});
				}
			}
		}
	}

	dyy[0] = -N;
	dyy[1] = N;

	while (!q.empty()) {
		node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y  + dy[i];
			int nx = now.x  + dx[i];
			if (ny < 0+ (N * now.level) || nx < 0 || nx >= M || ny >= N+((N * now.level)))continue;
			if (map[ny ][nx] == -1)continue;
			if (map[ny ][nx] !=0)continue;
			map[ny][nx] = map[now.y][now.x]+1;
			q.push({ ny,nx,now.level });
		}

		for (int i = 0; i < 2; i++) {
			int ny = now.y + dyy[i];
			int nx = now.x;
			if (ny < 0 || ny >= N * H)continue;
			if (map[ny][nx] == -1)continue;
			if (map[ny][nx] != 0)continue;
			map[ny][nx] = map[now.y][now.x] + 1;
			if (i == 0) {

				q.push({ ny,nx ,now.level-1});
			}
			else {
				q.push({ ny,nx,now.level+1 });
			}
		}
		
	}

	int maxx = 1;
	bool notyet = false;
	for (int i = 0; i < N*H; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				notyet = true;
				break;
			}
			maxx = max(maxx, map[i][j]);
		}
		if (notyet)break;
	}

	if (notyet) {
		cout << -1;
	}
	else if (maxx == 1) {
		cout << 0;
	}
	else {
		cout << maxx - 1;
	}
}