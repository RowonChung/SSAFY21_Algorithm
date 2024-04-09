#include <iostream>
#include <algorithm>
using namespace std;

int h;
int n, k;
int seg[400001];
int arr[100001];

void init() {
	h = 1;
	while (h < n) h <<= 1;

	for (int i = h; i <= h * 2; i++) {
		if ((i - h) <  n) seg[i] = arr[i - h];
		else seg[i] = 1;
	}
	for (int i = h - 1; i > 0; i--) seg[i] = seg[i << 1] * seg[i << 1 | 1];
}

void update(int idx, int diff) {
	idx += h;
	seg[idx] = diff;
	idx >>= 1;
	while (idx > 0) {
		seg[idx] = seg[idx << 1] * seg[idx << 1 | 1];
		idx >>= 1;
	}
}

int query(int l, int r) {
	int sum = 1;
	for (l += h, r += h; l < r; l >>= 1, r >>= 1) {
		if (l & 1) sum *= seg[l++];
		if (r & 1) sum *= seg[--r];
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (1) {
		cin >> n >> k;
		if (cin.eof()) break;

		for (int i = 0; i < n; i++) {
			int num; cin >> num;
			if (num == 0) arr[i] = 0;
			else if (num < 0) arr[i] = -1;
			else arr[i] = 1;
		}

		init();

		for (int i = 0; i < k; i++) {
			char q;
			int a, b;
			cin >> q >> a >> b;
			if (q == 'C') {
				if (b > 0) b = 1;
				else if (b < 0) b = -1;
				else b = 0;
				arr[a - 1] = b;
				update(a-1, b);
			}
			else if (q == 'P') {
				int res = query(a-1, b);
				if (res > 0) cout << '+';
				else if (res < 0) cout << '-';
				else cout << '0';
			}
		}
		cout << '\n';
	}
	return 0;
}