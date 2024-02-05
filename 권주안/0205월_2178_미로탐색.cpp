#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Coord {
	int y;
	int x;
};

int N, M;
string input[101];
int map[101][101];
int visited[101][101];
int dr[] = { 0,0,1,-1 };
int dc[] = { 1,-1,0,0 };

void floodfill() {
	visited[0][0] = 1;
	queue<Coord> q;
	q.push({ 0,0 });
	while (!q.empty()) {
		Coord now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int dy = now.y + dr[i];
			int dx = now.x + dc[i];
			if (dy >= N || dx >= M || dy < 0 || dx < 0) continue;
			if (map[dy][dx] == 0) continue;
			if (visited[dy][dx] != 0) continue;
			visited[dy][dx] = visited[now.y][now.x] + 1;
			q.push({ dy,dx });
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}
	for (int y = 0; y < N; y++) {
		for (int x = M - 1; x >= 0; x--) {
			string temp = input[y].substr(x, 1);
			map[y][x] = stoi(temp);
		}
	}
	floodfill();
	cout << visited[N-1][M-1];
	
	return 0;
}