#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<int>v;

long long bs(long start, long end) {
	long long res = 21e12;

	while (start <= end) {
		long long mid = (start + end) / 2;

		long cnt = 0;
		for (int i = 0; i < M; i++) {
			cnt += mid / v[i];
		}

		if (cnt >= N - M) {
			res = min(mid, res);
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}

	}

	return res;
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int input;
		cin >> input;
		v.push_back(input);
	}

	if (N <= M) {
		cout << N;
		return 0;
	}

	long long ret = bs(1, 21e12);

	int cnt = M;
	for (int i = 0;i < M;i++) {
		cnt += (ret - 1) / v[i];
	}

	int index = 0;

	while (cnt < N) {
		if (ret % v[index++] == 0) cnt++;
	}

	cout << index;

	return 0;
}