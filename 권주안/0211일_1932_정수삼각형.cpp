#include <iostream>
#include <algorithm>
using namespace std;

int n;
int map[501][501];

int main() {
	cin >> n;
	cin >> map[0][0];
	for (int y = 1; y < n; y++) {
		for (int x = 0; x <= y; x++) {
			int temp;
			cin >> temp;
			if (x == 0) {
				map[y][0] = map[y - 1][0] + temp;
				continue;
			}
			if (x == y) {
				map[y][x] = map[y - 1][x - 1] + temp;
				continue;
			}
			map[y][x] = max(map[y - 1][x - 1], map[y - 1][x]) + temp;
		}
	}
	int maxNum = 0;
	for (int i = 0; i < n; i++) {
		if (maxNum < map[n - 1][i]) {
			maxNum = map[n - 1][i];
		}
	}
	cout << maxNum;

	return 0;
}