#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

int N, M;
vector<int> tree;

long long bs(long long start, long long end) {
	long long mid, cnt;
	long long res = 0;

	while (start <= end) {
		cnt = 0;
		mid = (start + end) / 2;

		for (int i = 0;i < N;i++) {
			if (tree[i] <= mid) continue;

			cnt += tree[i] - mid;
		}

		if (cnt >= M) {
			res = max(res, mid);
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}

	return res;
}

int main() {
	cin >> N >> M;

	for (int i = 0;i < N;i++) {
		int input;
		cin >> input;

		tree.push_back(input);
	}

	long long ret = bs(0, 20e8);

	cout << ret;

	return 0;
}