#include <iostream>
using namespace std;

int h, n, q; 
long long seg[4000000];

void update(int idx, long long diff) {
	idx += h;
	while (idx > 0) {
		seg[idx] += diff;
		idx >>= 1;
	}
}

long long query(int l, int r) {
	long long sum = 0;
	for (l += h, r += h; l < r; l >>= 1, r >>= 1) {
		if (l & 1) sum += seg[l++];
		if (r & 1) sum += seg[--r];
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> q;

	h = 1;
	while (h < n) { h <<= 1; }

	for (int i = 0; i < q; i++) {
		int cmd, p, q; cin >> cmd >> p >> q;
		if (cmd == 1) update(p - 1, q);
		else cout << query(p - 1, q) << '\n';
	}
	return 0;
}