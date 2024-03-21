#include <iostream>
#include <vector>
using namespace std;

struct Shark {
	int row, col;
	int exist;
	int speed;
	int dir;
	int volume;
};

Shark arr[110][110];
vector <Shark> v;

int row, col, m;

int dr[5] = { 0, -1, 1, 0, 0 };
int dc[5] = { 0, 0, 0, 1, -1 };
int fisher = 0;
int ans = 0;

void fishing() {
	int r = 1;
	while (r <= row) {
		if (arr[r][fisher].exist == 1) {

			ans += arr[r][fisher].volume;

			arr[r][fisher].exist = 0;
			arr[r][fisher].speed = 0;
			arr[r][fisher].dir = 0;
			arr[r][fisher].volume = 0;
			arr[r][fisher].row = 0;
			arr[r][fisher].col = 0;

			break;
		}
		r++;
	}
}

void shark_move() {
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			if (arr[i][j].exist == 1) {
				v.push_back({ i, j, 1, arr[i][j].speed, arr[i][j].dir, arr[i][j].volume });
				arr[i][j].exist = 0;
				arr[i][j].speed = 0;
				arr[i][j].dir = 0;
				arr[i][j].volume = 0;
				arr[i][j].row = 0;
				arr[i][j].col = 0;
			}
		}
	}

	for (auto el : v) {
		int currR = el.row;
		int currC = el.col;
		int currS = el.speed;
		int currDir = el.dir;
		int currV = el.volume;


		//이동
		if (currDir == 1 || currDir == 2) {
			if (currR == 1 && currDir == 1) currDir = 2;
			else if (currR == row && currDir == 2) currDir = 1;

			currS = currS % ((row - 1) * 2);

			while (currS != 0) {
				currR += dr[currDir];
				if (currR == 1 && currDir == 1) currDir = 2;
				else if (currR == row && currDir == 2) currDir = 1;
				currS--;
			}
		}

		else if (currDir == 3 || currDir == 4) {
			if (currC == col && currDir == 3) currDir = 4;
			else if (currC == 1 && currDir == 4) currDir = 3;

			currS = currS % ((col - 1) * 2);

			while (currS != 0) {
				currC += dc[currDir];
				if (currC == col && currDir == 3) currDir = 4;
				else if (currC == 1 && currDir == 4) currDir = 3;
				currS--;
			}
		}

		currS = el.speed;

		//해당 자리보다 크기가 크면 넣음
		if (arr[currR][currC].volume < currV) {
			arr[currR][currC].exist = 1;
			arr[currR][currC].speed = currS;
			arr[currR][currC].dir = currDir;
			arr[currR][currC].volume = currV;
			arr[currR][currC].row = currR;
			arr[currR][currC].col = currC;
		}
	}
	v.clear();
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	cin >> row >> col >> m;
	for (int i = 0; i < m; i++) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		arr[r][c].exist = 1;
		arr[r][c].speed = s;
		arr[r][c].dir = d;
		arr[r][c].volume = z;
	}

	while (true) {
		if (fisher == col) break;
		fisher++;
		fishing();
		shark_move();
	}
	cout << ans;
}
