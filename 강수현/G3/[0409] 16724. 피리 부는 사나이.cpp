#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstring>
using namespace std;

struct Node {
	int y;
	int x;
};

int N, M;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int arr[1000][1000];
int flag[1000][1000]; // 0 빈칸, 1 방문&길x 2 방문&길o 3 safezone

int detect(int y, int x) {
	int ny = y + dy[arr[y][x]];
	int nx = x + dx[arr[y][x]];

	if (flag[ny][nx] == 0) {
		flag[ny][nx] = 1;
		int tf = detect(ny, nx);
		if (tf == 1) {
			flag[y][x] = 2;
			return 1;
		}
		else return 0;
	}
	
	if (flag[ny][nx] == 1) {
		flag[y][x] = 3;
		return 1;
	}

	if (flag[ny][nx] == 2 || flag[ny][nx] == 3) {
		flag[y][x] = 2;
		return 1;
	}
}

int main() {
	cin >> N >> M;

	// input
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < M; j++) {
			if (str[j] == 'U') arr[i][j] = 0;
			else if (str[j] == 'D') arr[i][j] = 1;
			else if (str[j] == 'L') arr[i][j] = 2;
			else arr[i][j] = 3;
		}
	}

	// detect
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (flag[i][j] != 0) continue;

			flag[i][j] = 1;
			int res = detect(i, j);
			if (res == 1) flag[i][j] = 2;
		}
	}

	int cnt = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (flag[i][j] == 3) cnt++;
		}
	}

	cout << cnt;

	return 0;
}