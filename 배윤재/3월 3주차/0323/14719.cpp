#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
	int y, x;
};

int h, w;
int map[501][501];
int ans = 0;

void input() {
	cin >> h >> w;

	for (int i = 0; i < w; i++) {
		int num;
		cin >> num;

		for (int j = h - 1; j >= h - num; j--) {
			map[j][i] = -1;
		}
	}

	int flag = 0;
	int left = -1, right = -1;
	for (int i = h - 1; i >= 0; i--) {
		left = -1;
		for (int j = 0; j < w; j++) {
			if (left == -1 && map[i][j] == 0 && map[i][j - 1] == -1) {
				left = j - 1;
			}
			else if (map[i][j] == -1) {
				if (left == -1) {
					left = j;
				}
				else {
					if (j == left + 1) continue;
					if (map[i][j - 1] == -1) continue;

					right = j;

					ans += right - left - 1;

					left = -1;
					right = -1;
				}
			}
		}
	}
}


int main() {

	input();

	cout << ans;

}