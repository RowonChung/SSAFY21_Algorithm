#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

struct User {
	int startY, startX, destY, destX;
	int distFromTaxi = -1, distFromDest;

	bool operator<(User right) const {
		if (distFromTaxi == right.distFromTaxi) {
			if (startY == right.startY)
				return startX > right.startX;
			return startY > right.startY;
		}

		return distFromTaxi > right.distFromTaxi;
	}
};

struct Taxi {
	int nowY, nowX, fuel, startFuel, destFuel;
};

int n, m, initFuel;
int map[21][21];
int visited[21][21];
Taxi taxi;
vector<User> initUsers;
priority_queue<User> users;

int dir[4][2] = { -1, 0, 1, 0, 0, -1, 0, 1 };

void input() {
	cin >> n >> m >> initFuel;

	taxi.fuel = initFuel;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	// 택시 초기 위치
	cin >> taxi.nowY >> taxi.nowX;
	taxi.nowY--;
	taxi.nowX--;

	// 처음 승객들 정보 저장
	for (int i = 0; i < m; i++) {
		int sy, sx, dy, dx;
		cin >> sy >> sx >> dy >> dx;

		initUsers.push_back({ sy - 1, sx - 1, dy - 1, dx - 1 });
	}
}

void findDist(int sy, int sx) {
	memset(visited, 0, sizeof(visited));

	queue<pair<int, int>> q;
	q.push({ sy, sx });
	visited[sy][sx] = 1;

	while (!q.empty()) {
		int nowY = q.front().first;
		int nowX = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = nowY + dir[i][0];
			int nx = nowX + dir[i][1];
			if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
			if (map[ny][nx] == 1) continue;
			if (visited[ny][nx] != 0) continue;

			visited[ny][nx] = visited[nowY][nowX] + 1;
			q.push({ ny, nx });
		}
	}
}

void userToDest(int num, int sy, int sx) {
	memset(visited, 0, sizeof(visited));

	queue<pair<int, int>> q;
	q.push({ sy, sx });
	visited[sy][sx] = 1;

	while (!q.empty()) {
		int nowY = q.front().first;
		int nowX = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = nowY + dir[i][0];
			int nx = nowX + dir[i][1];
			if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
			if (map[ny][nx] == 1) continue;
			if (visited[ny][nx] != 0) continue;

			visited[ny][nx] = visited[nowY][nowX] + 1;
			if (ny == initUsers[num].destY && nx == initUsers[num].destX) {
				initUsers[num].distFromDest = visited[ny][nx] - 1;
				return;
			}
			q.push({ ny, nx });
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();
	findDist(taxi.nowY, taxi.nowX);

	// 처음 택시와 승객들과의 거리
	for (int i = 0; i < m; i++) {
		initUsers[i].distFromTaxi = visited[initUsers[i].startY][initUsers[i].startX] - 1;
	}

	// 각 승객들 도착점까지의 거리
	for (int i = 0; i < m; i++) {
		if (initUsers[i].distFromTaxi == -1) continue;
		userToDest(i, initUsers[i].startY, initUsers[i].startX);
	}


	for (int i = 0; i < m; i++) {
		if (initUsers[i].distFromDest == 0) {
			cout << -1;
			return 0;
		}
		users.push(initUsers[i]);
	}


	while (!users.empty()) {
		User nowUser = users.top();
		users.pop();

		taxi.startFuel = nowUser.distFromTaxi;
		taxi.destFuel = nowUser.distFromDest;

		if (taxi.startFuel + taxi.destFuel > taxi.fuel) {
			cout << -1;
			return 0;
		}
		else {
			taxi.fuel = taxi.fuel - taxi.startFuel - taxi.destFuel + taxi.destFuel * 2;
			taxi.nowY = nowUser.destY;
			taxi.nowX = nowUser.destX;

			findDist(taxi.nowY, taxi.nowX);

			queue<User> temp;
			while (!users.empty()) {
				User remainUser = users.top();
				users.pop();

				remainUser.distFromTaxi = visited[remainUser.startY][remainUser.startX] - 1;
				temp.push(remainUser);
			}

			while (!temp.empty()) {
				User remainUser = temp.front();
				temp.pop();

				users.push(remainUser);
			}
		}
	}

	cout << taxi.fuel;

	return 0;
}