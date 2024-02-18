#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct yx {
	int y;
	int x;
};

int N;
char arr[100][100];
int flag[100][100] = { 0 };

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

yx findYX() {
	yx now = { 0,0 };

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (flag[i][j] == 0) {
				now.y = i;
				now.x = j;
				return now;
			}
		}
	}

	return now;
}

int cntColor(yx start) {
	queue<yx>q;

	int cnt = 1;
	char stand = arr[start.y][start.x];

	flag[start.y][start.x] = 1;
	q.push({ start.y, start.x });

	while (!q.empty()) {
		yx now = q.front();

		q.pop();

		for (int i = 0;i < 4;i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;

			if (flag[ny][nx] == 1) continue;

			if (stand != arr[ny][nx]) continue;

			cnt++;
			flag[ny][nx] = 1;

			q.push({ ny, nx });

		}
	}

	return cnt;
}

int main() {

	cin >> N;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> arr[i][j];
		}
	}

	int total = N * N;
	int cnt=0, result = 0;

	while (cnt != total) {
		yx start = findYX();
		cnt += cntColor(start);
		result++;
	}

	cout << result << " ";

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (arr[i][j] == 'G')
				arr[i][j] = 'R';
		}
	}

	 // 초기화
	memset(flag, 0, sizeof(flag));
	cnt = 0;
	result = 0;

	while (cnt != total) {
		yx start = findYX();
		cnt += cntColor(start);
		result++;
	}

	cout << result;

	return 0;
} 