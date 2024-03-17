#include <iostream>
using namespace std;
#define ARRSIZE 100000
#define INF (1<<31)-1

struct NODE {
	int mini;
	int maxi;
};

int arr[ARRSIZE];
NODE tree[4 * ARRSIZE];
int n, m;
int start;

void init() {
	start = 2;
	while (start < n) {
		start *= 2;
	}
	for (int i = (start << 1) - 1; 0 < i; i--) {
		tree[i].mini = INF;
		tree[i].maxi = 0;
	}
	for (int i = start; i < start + n; i++) {
		tree[i].mini = arr[i-start];
		tree[i].maxi = arr[i-start];
	}
	for (int i = start >> 1; 1 <= i; i >>= 1) {
		for (int j = i; j < (i << 1); j++) {
			tree[j].mini = min(tree[j << 1].mini, tree[(j << 1) | 1].mini);
			tree[j].maxi = max(tree[j << 1].maxi, tree[(j << 1) | 1].maxi);
		}
	}
}

pair<int, int> query(int left, int right) {
	left += start;
	right += start;
	int maxi = 0;
	int mini = INF;
	while (left != right) {
		if (left & 1) {
			maxi = max(maxi, tree[left].maxi);
			mini = min(mini, tree[left].mini);
			left++;
		}
		if (right & 1) {
			right--;
			maxi = max(maxi, tree[right].maxi);
			mini = min(mini, tree[right].mini);
		}
		left >>= 1;
		right >>= 1;
	}
	return { mini,maxi };
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
	//for (int i = 1; i <= 31; i++) {
	//	cout << "first = " << tree[i].mini << " second = " << tree[i].maxi << endl;
	//}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		pair<int, int> res = query(a - 1, b);
		cout << res.first << " " << res.second << "\n";
	}
}
