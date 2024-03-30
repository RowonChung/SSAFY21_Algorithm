#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int arr[1025][1025];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
		}
	}

	for (int i = 0; i < M; i++) {
		int sy, sx, ey, ex;
		cin >> sx >> sy >> ex >> ey;

		int res = arr[ex][ey] - arr[ex][sy - 1] - arr[sx - 1][ey] + arr[sx - 1][sy - 1];
		cout << res << "\n";
	}

	return 0;
}