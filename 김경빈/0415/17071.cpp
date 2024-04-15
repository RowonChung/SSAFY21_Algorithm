#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <cstring>
using namespace std;

int N, K, sec, loc[2][500001];
queue<int> q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	loc[0][N] = sec + 1;
	while (loc[sec % 2][K] < sec + 1 && K <= 500000) {
		for (int i = 0; i <= 500000; i++) {
			if (loc[sec % 2][i] != sec + 1) continue;

			if (i > 0) loc[(sec + 1) % 2][i - 1] = sec + 2;
			if (i < 500000) loc[(sec + 1) % 2][i + 1] = sec + 2;
			if (i <= 250000) loc[(sec + 1) % 2][i * 2] = sec + 2;
		}
		sec++;
		K += sec;
	}
	if (K > 500000 || loc[sec % 2][K] < sec) cout << -1;
	else cout << sec;
}