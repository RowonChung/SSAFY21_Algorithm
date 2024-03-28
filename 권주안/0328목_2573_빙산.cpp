#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

struct Node { int y, x; };
int N, M;
int board[300][300];
int visit[300][300];
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };
queue<Node> q;

void bfs() {
	while (!q.empty()) {
		Node now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = now.y + dr[i];
			int nx = now.x + dc[i];
			if (ny >= N || nx >= M || ny < 0 || nx < 0) continue;
			if (board[ny][nx] == 0) continue;
			if (visit[ny][nx] == 1) continue;
			q.push({ ny,nx });
			visit[ny][nx] = 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> board[y][x];
		}
	}
	int time = 0;
	while (1) {
		int islCnt = 0;
		int islSum = 0;

		// 빙산이 전부 다 녹을 때까지 두 덩어리 이상으로 분리되지 않으면 0을 출력
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				islSum += board[y][x];
			}
		}
		if (islSum == 0) {
			time = 0;
			break;
		}

		// 빙산 덩어리 개수 세기
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				if (board[y][x] != 0 && visit[y][x] == 0) {
					visit[y][x] = 1;
					q.push({ y,x });
					bfs();
					islCnt++;
				}
			}
		}

		// 빙산 덩어리가 2개 이상이면 중단. 그 때 time이 정답
		if (islCnt >= 2) break;
		
		time++;

		// 시간이 지나 빙산이 녹는다
		int temp[300][300] = { 0 };
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				if (board[y][x] == 0) continue;
				int zeroCnt = 0;
				for (int i = 0; i < 4; i++) {
					int ny = y + dr[i];
					int nx = x + dc[i];
					if (ny >= N || nx >= M || ny < 0 || nx < 0) continue;
					if (board[ny][nx] != 0) continue;
					zeroCnt++;
				}
				if (board[y][x] >= zeroCnt) {
					temp[y][x] = board[y][x] - zeroCnt;
				}
				else {
					temp[y][x] = 0;
				}
			}
		}
		memcpy(board, temp, sizeof(temp));

		// 다음 루프를 위해 visit을 초기화
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				visit[y][x] = 0;
			}
		}
	}
	cout << time;

	return 0;
}