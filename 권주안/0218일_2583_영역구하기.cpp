#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

struct Node {
	int y;
	int x;
};

int N, M, K;
int MAP[101][101];
int visited[101][101];
int dr[] = { 0,0,1,-1 };
int dc[] = { 1,-1,0,0 };

int bfs(Node node) {
	Node q[100001];
	int h = 0;
	int t = 0;
	q[t++] = { node.y,node.x };
	visited[node.y][node.x] = 1;
	while (h != t) {
		Node now = q[h++];
		for (int i = 0; i < 4; i++) {
			int ny = now.y + dr[i];
			int nx = now.x + dc[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (MAP[ny][nx] != 0) continue;
			if (visited[ny][nx] != 0) continue;
			visited[ny][nx] = visited[now.y][now.x] + 1;
			q[t++] = { ny,nx };
		}
	}
	return t;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		Node start, end;
		cin >> start.x >> start.y >> end.x >> end.y;
		for (int y = start.y; y < end.y; y++) {
			for (int x = start.x; x < end.x; x++) {
				MAP[y][x]++;
			}
		}
	}
	vector<int> res;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (MAP[y][x] == 0 && visited[y][x] == 0) {
				res.push_back(bfs({ y, x }));
			}
		}
	}
	sort(res.begin(), res.end());
	int ressize = res.size();
	cout << ressize << "\n";
	for (int i = 0; i < ressize; i++) {
		cout << res[i] << " ";
	}

	return 0;
}