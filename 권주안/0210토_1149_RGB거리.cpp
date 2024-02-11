#include <iostream>
#include <algorithm>
using namespace std;

int N;
int MAP[1000][3];
int SUM[1000][3];

int main() {
	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < 3; x++) {
			cin >> MAP[y][x];
		}
	}
	for (int y = 0; y < N; y++) {
		SUM[y][0] += min(SUM[y-1][1], SUM[y-1][2])+MAP[y][0];
		SUM[y][1] += min(SUM[y-1][0], SUM[y-1][2])+MAP[y][1];
		SUM[y][2] += min(SUM[y-1][0], SUM[y-1][1])+MAP[y][2];
	}
	int RES1= min(SUM[N - 1][0], SUM[N - 1][1]);
	int RES = min(RES1, SUM[N - 1][2]);
	cout << RES;

	return 0;
}