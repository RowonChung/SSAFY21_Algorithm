#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

struct User {
	int startY, startX, destY, destX;
	bool flag = false;
	int distToDest;
};

struct Taxi {
	int nowY, nowX, fuel;
};

int n, m, initFuel;
int map[21][21];
Taxi taxi;
vector<User> users;
int visited[21][21];
int userTaxiMap[402][21][21];

int dir[4][2] = { -1, 0, 1, 0, 0, -1, 0, 1 };

void input() {
	cin >> n >> m >> initFuel;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	taxi.fuel = initFuel;

	int y, x;
	cin >> y >> x;

	taxi.nowY = y - 1;
	taxi.nowX = x - 1;

	for (int i = 0; i < m; i++) {
		int sy, sx, dy, dx;
		cin >> sy >> sx >> dy >> dx;
		users.push_back({ sy - 1, sx - 1, dy - 1, dx - 1, false });
	}
}

void initUserMap(int num, int sy, int sx) {
	queue<pair<int, int>> q;
	q.push({ sy, sx });
	userTaxiMap[num][sy][sx] = 1;

	while (!q.empty()) {
		int nowY = q.front().first;
		int nowX = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = nowY + dir[i][0];
			int nx = nowX + dir[i][1];

			if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
			if (map[ny][nx] == 1) continue;
			if (userTaxiMap[num][ny][nx] != 0) continue;

			userTaxiMap[num][ny][nx] = userTaxiMap[num][nowY][nowX] + 1;
			q.push({ ny, nx });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();

	for (int i = 0; i < m; i++) {
		User now = users[i];
		initUserMap(i, now.startY, now.startX);
	}

	bool flag = true;
	for (int i = 0; i < m; i++) {

		// 택시가 승객 1명에게라도 못가면 끝
		if (userTaxiMap[i][taxi.nowY][taxi.nowX] == 0) {
			flag = false;
			break;
		}

		// 승객을 도착지까지 못가면 끝
		if (userTaxiMap[i][users[i].destY][users[i].destX] == 0) {
			flag = false;
			break;
		}
	}
	if (!flag) {
		cout << -1;
		return 0;
	}

	int used = 0;
	while (used != m) {

		int minDist = 1e9;
		int minUser = 0;

		for (int i = 0; i < m; i++) {
			int nowDist = userTaxiMap[i][taxi.nowY][taxi.nowX] - 1;

			if (users[i].flag) continue;

			if (minDist > nowDist) {
				minDist = nowDist;
				minUser = i;
			}
			else if (minDist == nowDist) {
				if (users[i].startY == users[minUser].startY) {
					if (users[i].startX < users[minUser].startX) {
						minUser = i;
					}
				}
				else if (users[i].startY < users[minUser].startY) {
					minUser = i;
				}
			}
		}

		used++;
		users[minUser].flag = true;
		int taxiToUser = userTaxiMap[minUser][taxi.nowY][taxi.nowX] - 1;
		int userToDest = userTaxiMap[minUser][users[minUser].destY][users[minUser].destX] - 1;

		if (taxi.fuel < taxiToUser + userToDest) {
			cout << -1;
			return 0;
		}

		taxi.fuel = taxi.fuel - taxiToUser - userToDest + 2 * userToDest;

		taxi.nowY = users[minUser].destY;
		taxi.nowX = users[minUser].destX;
	}

	for (int i = 0; i < m; i++) {
		if (!users[i].flag) {
			cout << -1;
			return 0;
		}
	}

	cout << taxi.fuel;
}