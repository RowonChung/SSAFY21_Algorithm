#include <iostream>
using namespace std;

const int MAX = 100000;
long long seg[MAX * 4];
long long arr[MAX + 1];

long long init(int node, int start, int end) {
	if (start == end) return seg[node] = arr[start];
	int mid = (start + end) / 2;
	return seg[node] = (init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end));
}

long long sum(int node, int start, int end, int l, int r) {
	if (l > end || start > r) return 0;
	if (l <= start && end <= r) return seg[node];
	int mid = (start + end) / 2;
	return sum(node * 2, start, mid, l, r) + sum(node * 2 + 1, mid + 1, end, l, r);
}

void update(int node, int start, int end, int idx, long long diff) {
	if (idx > end || start > idx) return;
	seg[node] += diff;
	if (start != end) {
		int mid = (start + end) / 2;
		update(node * 2, start, mid, idx, diff);
		update(node * 2 + 1, mid + 1, end, idx, diff);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	init(1, 1, n);

	for (int i = 0; i < q; i++) {
		int x, y, a, b; cin >> x >> y >> a >> b;
		if (x > y) swap(x, y);
		cout << sum(1, 1, n, x, y) << '\n';
		update(1, 1, n, a, ((long long) b) - arr[a]);
		arr[a] = b;
	}
	return 0;
}