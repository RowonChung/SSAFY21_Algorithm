#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int map[26][26];
int check[26][26];

int dat[700];

int N;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int cnt = 0;

vector<int> v;

struct node {
	int y;
	int x;
};

queue<node> q;

void bfs(int y,int x) {
	node input = { y,x };
	q.push(input);
	while (!q.empty()) {
		node now = q.front();
		q.pop();
		check[now.y][now.x] = cnt;
		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			if (ny < 0 || nx < 0 || nx >= N || ny >= N) {
				continue;
			}
			if (map[ny][nx] == 0)continue;
			if (check[ny][nx] != 0)continue;
			node nw = { ny,nx };
			check[ny][nx] = cnt;
			q.push(nw);
		}
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < N; j++) {
			map[i][j] = s.at(j)-'0';
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1 && check[i][j] == 0) {
				cnt++;
				bfs(i, j);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dat[check[i][j]]++;
		}
	}
	cout << cnt << "\n";
	for (int i = 1; i <= cnt; i++) {
		v.push_back(dat[i]);
	}
	sort(v.begin(), v.end());
	for (auto i :  v) {
		cout << i << "\n";
	}
}
