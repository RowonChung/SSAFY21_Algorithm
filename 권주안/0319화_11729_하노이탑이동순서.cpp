#include <iostream>
using namespace std;

int N;
int ans[3000000];
int now = 0;

void move(int level, int from, int to) {
	if (level > 1) {
		move(level - 1, from, 6 - from - to);
	}
	ans[now++] = from;
	ans[now++] = to;
	if (level > 1) {
		move(level - 1, 6 - from - to, to);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	move(N, 1, 3);
	int K = (2 << N - 1) - 1;
	cout << K << "\n";
	for (int i = 0; i < K * 2; i++) {
		cout << ans[i++] << " " << ans[i] << "\n";
	}

	int de = -1;
	return 0;
}