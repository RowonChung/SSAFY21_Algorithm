#include <iostream>
using namespace std;

int n, m;
int arr[100100];
int segTree[100100 * 4];
int strIdx;


void init() {
	strIdx = 1;
	while (strIdx < n) strIdx *= 2;

	for (int i = 0; i < n; i++) {
		segTree[i + strIdx] = arr[i];
	}
	for (int i = n + strIdx; i < 2 * strIdx; i++) {
		segTree[i] = 1;
	}

	for (int i = strIdx - 1; i >= 1; i--) {
		segTree[i] = segTree[i << 1] * segTree[i << 1 | 1];
	}
}

void update(int idx, int val) {
	idx += strIdx;
	segTree[idx] = val;
	idx >>= 1;
	while (idx >= 1) {
		segTree[idx] = segTree[idx << 1] * segTree[idx << 1 | 1];
		idx >>= 1;
	}
}

void query(int left, int right) {
	int ans = 1;
	left += strIdx;
	right += strIdx;

	for (left, right; left != right; left >>= 1, right >>= 1) {
		if (left & 1) {
			ans *= segTree[left];
			left++;
		}
		if (right & 1) {
			right--;
			ans *= segTree[right];
		}
	}
	if (ans == 0) {
		cout << "0";
	}
	else if (ans > 0) {
		cout << "+";
	}
	else if (ans < 0) {
		cout << "-";
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (cin >> n >> m) {
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			if (arr[i] > 0) arr[i] = 1;
			else if (arr[i] == 0) arr[i] = 0;
			else arr[i] = -1;
		}
		init();
		for (int i = 0; i < m; i++) {
			char inst;
			cin >> inst;
			if (inst == 'C') {
				int idx, val;
				cin >> idx >> val;
				if (val > 0) val = 1;
				else if (val == 0) val = 0;
				else val = -1;
				update(idx - 1, val);
			}
			else if (inst == 'P') {
				int left, right;
				cin >> left >> right;
				query(left - 1, right);
			}
		}

		cout << "\n";
		for (int i = 1; i < 2 * strIdx; i++) {
			segTree[i] = 1;
		}
	}
}
