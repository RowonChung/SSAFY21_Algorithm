#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
const int MAX = 2134567890;

struct Node { int y, x; };
int N, M;
string board[50];
int visit[50][50];
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
			if (board[ny][nx] == 'W') continue;
			if (visit[ny][nx] != 0) continue;
			q.push({ ny,nx });
			visit[ny][nx] = visit[now.y][now.x] + 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		cin >> board[y];
	}
	int ans = 0;
	// 각 점마다 bfs 돌리고 최대값 찾기
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (y == 3 && x == 0) {
				int de = -1;
			}
			// visit 초기화
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					visit[i][j] = 0;
				}
			}
			// 한 점에서 bfs 돌리기
			if (board[y][x] == 'L' && visit[y][x] == 0) {
				visit[y][x] = 1;
				q.push({ y,x });
				bfs();
				// bfs 돌린 후 최대값 찾기
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < M; j++) {
						// 이번에 돌린 bfs에서 최대값이 있다면
						if (ans < visit[i][j]) {
							// 정답을 저장
							ans = visit[i][j];
						}
					}
				}
			}
		}
	}
	cout << ans - 1;

	int de = -1;
	return 0;
}