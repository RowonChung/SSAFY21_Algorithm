#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

struct Node {
	int y, x, dir;
};

struct Switch {
	int y, x;
	bool on = false;
};

string map[16];
string path;

int lightMap[16][16];

int n;
vector<Node> zoms;
vector<Switch> lights;
Node Ari = { 0, 0, 0 };

int flag = false;

int dir[4][2] = { 1, 0, 0, -1, -1, 0, 0, 1 };
int lightDir[8][2] = { 1, 0, 0, -1, -1, 0, 0, 1, -1, 1, -1, -1, 1, -1, 1, 1 };
int zomDir[2] = { 1, -1 };

void input() {
	cin >> n;
	cin >> path;

	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 'Z') {
				zoms.push_back({ i, j, 0 });
			}
			if (map[i][j] == 'S') {
				lights.push_back({ i, j });
			}
		}
	}
}

void start(int sy, int sx, int d, char now) {
	if (now == 'F') {
		int ny = sy + dir[d][0];
		int nx = sx + dir[d][1];
		if (ny < 0 || ny >= n || nx < 0 || nx >= n) return;

		Ari.y = ny;
		Ari.x = nx;

	}
	else if (now == 'R') {
		Ari.dir = d + 1;
		if (Ari.dir == 4) Ari.dir = 0;
	}
	else if (now == 'L') {
		Ari.dir = d - 1;
		if (Ari.dir == -1) Ari.dir = 3;
	}

	// 불 켤 수 있는지 확인
	for (int i = 0; i < lights.size(); i++) {
		Switch s = lights[i];
		if (s.on) continue;
		if (s.y != Ari.y || s.x != Ari.x) continue;
		lightMap[s.y][s.x] = 1;
		lights[i].on = true;
		for (int d = 0; d < 8; d++) {
			int ny = s.y + lightDir[d][0];
			int nx = s.x + lightDir[d][1];
			if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
			if (lightMap[ny][nx] == 1) continue;

			lightMap[ny][nx] = 1;
		}
	}

	flag = false;
	// 좀비와 같이 있는데 불이 켜져있는지 꺼져있는지 확인
	for (int i = 0; i < zoms.size(); i++) {
		Node z = zoms[i];
		if (z.y == Ari.y && z.x == Ari.x) {
			if (lightMap[Ari.y][Ari.x] == 0) {
				flag = true;
				return;
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();

	if (zoms.size() == 0) {
		cout << "Phew...";
		return 0;
	}

	int now = 0;

	while (now != path.length()) {
		int de = -1;
		start(Ari.y, Ari.x, Ari.dir, path[now++]);

		if (flag) {
			cout << "Aaaaaah!";
			return 0;
		}

		// 좀비 이동
		for (int i = 0; i < zoms.size(); i++) {
			Node z = zoms[i];
			int next = z.y + zomDir[z.dir];
			if (next < 0 || next >= n) {
				zoms[i].dir ^= 1;
				continue;
			}
			zoms[i].y = next;
		}

		// 좀비와 같이 있는데 불이 켜져있는지 꺼져있는지 확인
		for (int i = 0; i < zoms.size(); i++) {
			Node z = zoms[i];
			if (z.y == Ari.y && z.x == Ari.x) {
				if (lightMap[Ari.y][Ari.x] == 0) {
					cout << "Aaaaaah!";
					return 0;
				}
			}
		}
	}

	cout << "Phew...";
}