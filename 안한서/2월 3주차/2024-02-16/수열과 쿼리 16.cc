#include <iostream>
#include <algorithm>
using namespace std;
const long long MAX_N = 100000;
const long long MAX = 1000000100;
long long n, h;

struct Node {
	long long x, idx;

	bool operator < (const Node &a) const {
		if (x == a.x) return idx < a.idx;
		return x < a.x;
	}
};

Node seg[MAX_N * 4];
long long arr[MAX_N];

void init() {
	for (long long  i = h; i < 2 * h; i++) {
		if ((i - h) >= n) seg[i] = { MAX, MAX_N + 1 };
		else seg[i] = { arr[i - h], i - h + 1 };
	}

	for (long long  i = (h - 1); i >= 1; i--) seg[i] = min(seg[i * 2], seg[i * 2 + 1]);
}

void update(long long  idx, long long  v) {
	idx += h;
	seg[idx].x = v;
	idx /= 2;
	while (idx != 0) {
		seg[idx] = min(seg[idx * 2], seg[idx * 2 + 1]);
		idx /= 2;
	}
}

long long query(long long l, long long r) {
	Node ans = seg[l + h];
	for (l += h, r += h; l < r; l /= 2, r /= 2) {
		if (l % 2) ans = min(ans, seg[l++]);
		if (r % 2) ans = min(ans, seg[--r]);
	}
	return ans.idx;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n; h = 1;
	while (h < n) h *= 2;
	for (int i = 0; i < n; i++) cin >> arr[i];

	init();

	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int cmd; cin >> cmd;
		long long a, b; cin >> a >> b;
		if (cmd == 1) update(a-1, b);
		else cout << query(a-1, b) << '\n';
	}
	return 0;
}