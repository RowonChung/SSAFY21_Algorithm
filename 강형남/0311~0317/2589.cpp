#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;

char map[51][51];


int visited[51][51];



int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

struct node {
	int y;
	int x;
};

void reset_visit() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = 0;
		}
	}
}
int answer_dist = -1;


void fun(int y,int x) {
	int maxdist = -1;

	queue<node> q;
	q.push({ y,x });
	visited[y][x] = 1;
	while (!q.empty()) {
		node now = q.front();
		q.pop();
		maxdist = max(maxdist, visited[now.y][now.x]);
		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M)continue;
			if (map[ny][nx] == 'W')continue;
			if (visited[ny][nx])continue;
			
			visited[ny][nx] = visited[now.y][now.x] + 1; 
			q.push({ ny,nx });
		}
	}
	answer_dist = max(answer_dist, maxdist);
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {

		string s;
		cin >> s;
		for (int j = 0; j<s.size(); j++) {
			map[i][j] = s.at(j);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 'L') {
				fun(i, j);
				reset_visit();
			}
		}
	}

	cout << answer_dist-1;
	
}