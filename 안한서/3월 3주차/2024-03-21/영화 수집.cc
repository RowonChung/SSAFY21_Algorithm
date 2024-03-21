#include <iostream>
#include <algorithm>
using namespace std;

int h;
int n, m;
int seg[800000];
int loc[100001];

void init() {
	h = 1;
	while (h < (n+m)) h <<= 1;

	for (int i = 1; i <= n; i++) loc[i] = n - i;

	for (int i = h; i <= h * 2; i++) {
		if (i < (h + n)) seg[i] = 1;
		else seg[i] = 0;
	}
	for (int i = h - 1; i > 0; i--) seg[i] = seg[i << 1] + seg[i << 1 | 1];
}

void update(int idx, int diff) {
	idx += h;
	while (idx > 0) {
		seg[idx] += diff;
		idx >>= 1;
	}
}

int query(int l, int r) {
	int sum = 0;
	for (l += h, r += h; l < r; l >>= 1, r >>= 1) {
		if (l & 1) sum += seg[l++];
		if (r & 1) sum += seg[--r];
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin >> t;
	for (int tc = 0; tc < t; tc++) {
		cin >> n >> m;
		init();

		for (int i = 0; i < m; i++) {
			int idx; cin >> idx;

			int curr = loc[idx];
			int nxt = n + i;
			if(seg[curr + h] != 0) update(curr, -1);
			update(nxt, 1);
			loc[idx] = nxt;

			cout << query(curr, nxt) << " ";
		}
		cout << '\n';
	}
	return 0;
}