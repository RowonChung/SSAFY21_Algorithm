#include <iostream>
#include <algorithm>
using namespace std;
#define ARRSIZE 1000000

int n, m;
long long arr[ARRSIZE];
long long tree[4 * ARRSIZE];
int start;

void init() {
	start = 1;
	while (start < n) {
		start <<= 1;
	}
}

void update(int index, long long dif) {
	index += start;
	while (1 <= index) {
		tree[index] += dif;
		index >>= 1;
	}
}

long long query(int l, int r) {
	l += start;
	r += start + 1;
	long long sum = 0;
	while (l != r) {
		if (l & 1) {
			sum += tree[l];
			l++;
		}
		if (r & 1) {
			r--;
			sum += tree[r];
		}
		l >>= 1;
		r >>= 1;
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	init();
	for (int i = 0; i < m; i++) {
		int a, b;
		long long c;
		cin >> a >> b >> c;
		if (a == 1) {
			long long dif = c - arr[b - 1];
			arr[b - 1] = c;
			update(b - 1, dif);
		}
		else {
			int maxi = max(b - 1, (int)(c - 1));
			int mini = min(b - 1, (int)(c - 1));
			cout << query(mini, maxi) << "\n";
		}
	}
}
