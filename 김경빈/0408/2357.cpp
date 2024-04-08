#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#include <unordered_map>
using namespace std;

int N, M, a, b;
long long min_tree[200001], max_tree[200001], num;

void init() {
	for (int i = N - 1; i > 0; i--) {
		min_tree[i] = min(min_tree[i << 1], min_tree[i << 1 | 1]);
		max_tree[i] = max(max_tree[i << 1], max_tree[i << 1 | 1]);
	}
}

void query(int l, int r) {
	long long max_val = 0, min_val = LLONG_MAX;
	for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
		if (l & 1) {
			max_val = max(max_val, max_tree[l]);
			min_val = min(min_val, min_tree[l]);
			l++;
		}
		if (r & 1) {
			max_val = max(max_val, max_tree[r - 1]);
			min_val = min(min_val, min_tree[r - 1]);
			r--;
		}
	}
	cout << min_val << " " << max_val << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = N; i < 2 * N; i++) {
		cin >> num;
		min_tree[i] = num;
		max_tree[i] = num;
	}

	init();


	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		query(a - 1, b);
	}
	
}