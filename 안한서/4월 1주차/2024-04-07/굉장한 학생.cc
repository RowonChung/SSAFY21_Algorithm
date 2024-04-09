#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 500001

int h;
int n, k, ans;
int seg[500001 * 4];
vector<vector<int>> arr;

void init() {
	h = 1;
	while (h < n) h <<= 1;

	for (int i = h; i <= h * 2; i++) seg[i] = INF;
	for (int i = h - 1; i > 0; i--) seg[i] = min(seg[i << 1], seg[i << 1 | 1]);
}

void update(int idx, int diff) {
	idx += h;
	seg[idx] = diff;
	idx >>= 1;
	while (idx > 0) {
		seg[idx] = min(seg[idx << 1], seg[idx << 1 | 1]);
		idx >>= 1;
	}
}

int query(int l, int r) {
	int sum = INF;
	for (l += h, r += h; l < r; l >>= 1, r >>= 1) {
		if (l & 1) sum = min(sum, seg[l++]);
		if (r & 1) sum = min(sum, seg[--r]);
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	arr.resize(n, vector<int>(3));

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < n; j++) {
			int rank; cin >> rank;
			arr[rank - 1][i] = j;
		}
	}
	sort(arr.begin(), arr.end());

	init();
	for (int i = 0; i < n; i++) {
		// 1번 시험으로 정렬
		// 자신의 2번 시험 등수 보다 앞에 탐색 : 가장 잘 본 등수
		// 탐색한 등수가 자신의 등수 보다 작으면 -> 굉장 X
		if (query(0, arr[i][1] + 1) > arr[i][2]) ans++;
		// 이후 자신의 2번 시험 등수 자리 -> 3번 시험 등수로 갱신
		update(arr[i][1], arr[i][2]);
	}
	cout << ans;
	return 0;
}