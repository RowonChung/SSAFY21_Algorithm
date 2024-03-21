#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

struct Node {
	int w;
	int v;
};

int N, K;
Node arr[101];
int map[101][100001];

int main() {
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i].w >> arr[i].v;
	}

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= K; j++) {
			if (i == 0) {
				map[i][j] = 0;
				continue;
			}

			if (j < arr[i].w) {
				map[i][j] = map[i-1][j];
				continue;
			}

			int tmp = map[i - 1][j - arr[i].w] + arr[i].v;

			map[i][j] = max(tmp, map[i - 1][j]);
		}
	}

	cout << map[N][K];

	return 0;
}