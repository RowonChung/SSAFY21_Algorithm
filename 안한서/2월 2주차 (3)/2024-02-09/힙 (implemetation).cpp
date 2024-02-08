#include <iostream>
#include <string>
#include <queue>
using namespace std;

int len = 0;
int max_heap[200100];

void insert(int data) {
	max_heap[++len] = data;
	int now = len;
	while (now > 1) {
		int parent = now / 2;
		if (max_heap[now] > max_heap[parent]) {
			swap(max_heap[now], max_heap[parent]);
			now = parent;
		}
		else break;
	}
}

void erase() {
	int MX = max_heap[1];
	max_heap[1] = max_heap[len];
	max_heap[len--] = 0;

	int now = 1;
	while ((now * 2 + 1) <= len) {
		int big = now;
		int left = now * 2, right = now * 2 + 1;
		if (max_heap[big] < max_heap[left]) big = left;
		if (max_heap[big] < max_heap[right]) big = right;

		if (now != big) {
			swap(max_heap[now], max_heap[big]);
			now = big;
		}
		else break;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T; cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int n; cin >> n;
		len = 0;
		for (int i = 0; i < 200100; i++) max_heap[i] = 0;

		cout << "#" << tc << ' ';
		for (int i = 0; i < n; i++) {
			int oper; cin >> oper;
			if (oper == 1) {
				int x; cin >> x;
				insert(x);
			}
			else {
				if (len == 0) cout << "-1 ";
				else {
					cout << max_heap[1] << ' ';
					erase();
				}
			}
		}
		cout << '\n';
	}
	return 0;
}