#include <iostream>
#include <memory.h>
using namespace std;

int Move[8][2] = {
	{0,1}, {1,0}, {-1,0}, {0,-1},
	{1,1}, {1,-1}, {-1,1}, {-1,-1}

};

int cnt = 0;

//bool checkValid(int row, int col, bool valid[][13], int n) {
//	for (int i = 0; i < 8; i++) {
//		int nextRow = row;
//		int nextCol = col;
//		while (0 <= nextRow && nextRow < n && 0 <= nextCol && nextCol < n) {
//			if (valid[nextRow][nextCol]) {
//				return false;
//			}
//			nextRow += Move[i][0];
//			nextCol += Move[i][1];
//		}
//	}
//	return true;
//}

void changeTrue(int row, int col, int valid[][15], int n) {
	for (int i = 0; i < 8; i++) {
		int nextRow = row;
		int nextCol = col;
		while (0 <= nextRow && nextRow < n && 0 <= nextCol && nextCol < n) {
			if (!valid[nextRow][nextCol]) {
				valid[nextRow][nextCol] = col + 1;
			}
			nextRow += Move[i][0];
			nextCol += Move[i][1];
		}
	}
}

void changeFalse(int row, int col, int valid[][15], int n) {
	for (int i = 0; i < 8; i++) {
		int nextRow = row;
		int nextCol = col;
		while (0 <= nextRow && nextRow < n && 0 <= nextCol && nextCol < n) {
			if (valid[nextRow][nextCol] == col + 1) {
				valid[nextRow][nextCol] = 0;
			}
			nextRow += Move[i][0];
			nextCol += Move[i][1];
		}
	}
}

void recursion(int n, int index, int valid[][15]) {
	int sum = 0;
	if (index == n) {
		cnt++;
	}
	else {
		for (int i = 0; i < n; i++) {
			if (!valid[i][index]) {
				changeTrue(i, index, valid, n);
				recursion(n, index + 1, valid);
				changeFalse(i, index, valid, n);
			}
		}
	}
	return;
}

int main() {
	int n;
	cin >> n;
	int valid[15][15];
	memset(valid, false, sizeof(valid));
	recursion(n, 0, valid);
	cout << cnt;
}
