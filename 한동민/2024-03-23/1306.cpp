#include <iostream>
using namespace std;
#define ARRSIZE 1000000

int arr[ARRSIZE];
int tree[ARRSIZE * 4];

int n, m;
int start;

void init() {
	start = 1;
	while (start < n) {
		start <<= 1;
	}

	for (int i = start; i < start + n; i++) {
		tree[i] = arr[i - start];
	}
	for (int i = start - 1; 1 <= i; i--) {
		tree[i] = max(tree[i << 1], tree[i << 1 | 1]);
	}
}

int query(int left, int right) {
	int res = 0;
	left += start;
	right += start + 1;
	while (left != right) {
		if (left & 1) {
			res = max(res, tree[left]);
			left++;
		}
		if (right & 1) {
			right--;
			res = max(res, tree[right]);
		}
		left >>= 1;
		right >>= 1;
	}

	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	init();
	int index = m - 1;
	while (index + m - 1 <= n - 1) {
		int left = index - m + 1;
		int right = index + m - 1;
		cout << query(left, right) << " ";
		index++;
	}
	return 0;
}
