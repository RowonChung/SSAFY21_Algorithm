#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#include <unordered_map>
using namespace std;

int N, M, comm, a;
long long arr[1000001], what;

void init() {
	for (int i = N - 1; i > 0; i--) arr[i] = arr[i << 1] + arr[i << 1 | 1];
}

void update(long long loc, int val) {
	for (arr[loc += N] += val; loc > 1; loc >>= 1) arr[loc >> 1] = arr[loc] + arr[loc ^ 1];
}

void query(long long loc) {
	int left = 0, right = N;
	
	while (left <= right) {
		long long sum = 0;
		int mid = (left + right) / 2;
		int l = N, r = mid + N;

		for (l, r; l < r; l >>= 1, r >>= 1) {
			if (l & 1) sum += arr[l++];
			if (r & 1) sum += arr[--r];
		}

		if (loc <= sum && loc > sum - arr[mid + N - 1]) {
			cout << "sum : " << sum << " sum - arr[mid + N - 1] : " << sum - arr[mid + N - 1] << " mid : ";
			cout << mid << '\n';
			return;
		}
		else if (loc > sum) {
			left = mid + 1;
		}
		else if (loc <= sum - arr[mid + N - 1]) {
			right = mid - 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = N; i < 2 * N; i++) {
		cin >> arr[i];
	}
	init();
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> comm;
		if (comm == 1) {
			cin >> what >> a;
			update(what - 1, a);
		}
		else if (comm == 2) {
			cin >> what;
			query(what);
		}
	}
}