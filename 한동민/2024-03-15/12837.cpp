#include <iostream>
using namespace std;
#define ARRSIZE 1000000
long long tree[4 * ARRSIZE];

int n, q;
int height;

void init() {
	height = 2;
	while (height <= n) {
		height <<= 1;
	}
}

void update(int index, long long dif) {
	index += height;
	tree[index] += dif;
	for (int i = index >> 1; 1 <= i; i >>= 1) {
		tree[i] = tree[2 * i] + tree[2 * i + 1];
	}
}

long long query(int l, int r) {
	long long ret = 0;
	l += height;
	r += height + 1;
	while (l != r) {
		if (l % 2 == 1) {
			ret += tree[l];
			l++;
		}
		if (r % 2 == 1) {
			r--;
			ret += tree[r];
		}
		l >>= 1;
		r >>= 1;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> q;
	init();
	for (int i = 0; i < q; i++) {
		int t;
		cin >> t;
		if (t == 1) {
			int tmp, dif;
			cin >> tmp >> dif;
			update(tmp - 1, dif);
		}
		else {
			int a, b;
			cin >> a >> b;
			cout << query(a - 1, b - 1) << "\n";
		}
	}
}
