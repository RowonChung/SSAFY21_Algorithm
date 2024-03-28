#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct Node {
	int y;
	int x;
};

int N;
Node queen[14];
int cnt = 0;
int xline[14];

bool possible(int y, int x) {
	for (int i = 0;i < y;i++) {
		if (abs(queen[i].y - y) == abs(queen[i].x - x)) return false;
	}

	return true;
}

void placeQueen(int level) {
	if (level == N) {
		cnt++;
		return;
	}

	for (int i = 0; i < N; i++) {
		if (xline[i] == 1) continue;
		if (!possible(level, i)) continue;

		queen[level] = { level,i };
		xline[i] = 1;
		placeQueen(level + 1);
		xline[i] = 0;
	}
}

int main() {
	cin >> N;

	placeQueen(0);

	cout << cnt;
}
