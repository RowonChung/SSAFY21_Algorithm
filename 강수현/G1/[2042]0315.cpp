#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

#define ARRSIZE 1000000

long long N, M, K;
long long arr[ARRSIZE];
long long tree[4 * ARRSIZE];
long long start = 2;

void init() {
	while (start < N) {
		start *= 2;
	}

	for (long long i = start; i < N+start; i++) {
		tree[i] = arr[i - start];
	}

	for (long long i = start / 2; i >= 1; i /= 2) {
		for (long long j = i; j < i * 2; j++) {
			tree[j] = tree[2 * j] + tree[2 * j + 1];
		}
	}
}

void update(long long index, long long change) {
	index += start;
	tree[index] = change;

	for (long long i = index / 2; i >= 1; i /= 2) {
		tree[i] = tree[2 * i] + tree[2 * i + 1];
	}

	return;
}

void query(long long left, long long right) {
	left += start;
	right += start;

	long long sum = 0;

	while (left != right) {
		if (left % 2 == 1) {
			sum += tree[left];
			left++;
		}
		if (right % 2 == 1) {
			right--;
			sum += tree[right];
		}

		left /= 2;
		right /= 2;
	}

	cout << sum << "\n";

	return;
}

int main() {
	cin >> N >> M >> K;

	for (long long i = 0; i < N; i++) {
		cin >> arr[i];
	}

	init();

	for (long long i = 0; i < M+K; i++) {
		long long num;
		cin >> num;

		long long a = 0, b = 0;
		cin >> a >> b;
		if (num == 1) {
			update(a-1, b);
		}
		else {
			query(a-1, b);
		}
	}

	return 0;
}