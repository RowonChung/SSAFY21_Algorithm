#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#include <unordered_map>
using namespace std;

int N, arr[100000][3], max_arr[2][3], min_arr[2][3];
int min_val = INT_MAX, max_val, dy[] = { 1, 1, 1 }, dx[] = { -1, 0, 1 };

int main() {	
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
			min_arr[N % 2][j] = INT_MAX;
		}
	}

	for (int i = 0; i < 3; i++) {
		max_arr[(N-1)%2][i] = arr[N - 1][i];
		min_arr[(N-1)%2][i] = arr[N - 1][i];
	}
	for (int i = N - 2; i >= 0; i--) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				int dr = i + dy[k];
				int dc = j + dx[k];

				if (dc < 0 || dc >= 3) continue;

				max_arr[i % 2][j] = max(max_arr[i % 2][j], arr[i][j] + max_arr[(i + 1) % 2][dc]);
				min_arr[i % 2][j] = min(min_arr[i % 2][j], arr[i][j] + min_arr[(i + 1) % 2][dc]);
			}
		}
		for (int j = 0; j < 3; j++) {
			min_arr[(i + 1) % 2][j] = INT_MAX;
		}
	}

	for (int i = 0; i < 3; i++) {
		if (max_arr[0][i] > max_val) max_val = max_arr[0][i];
		if (min_arr[0][i] < min_val) min_val = min_arr[0][i];
	}

	cout << max_val << " " << min_val << '\n';
}