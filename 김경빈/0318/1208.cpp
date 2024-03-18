#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <unordered_map>
using namespace std;

long long N, ans, S, arr[41];
unordered_map<long long, int> um;

void DFS1(int now, int end, long long num) {
	if (now == end) {
		um[num]++;
		return;
	}

	DFS1(now + 1, end, num);
	DFS1(now + 1, end, num + arr[now]);
}

void DFS2(int now, int end, long long num) {
	if (now == end) {
		ans += um[S - num];
		return;
	}

	DFS2(now + 1, end, num);
	DFS2(now + 1, end, num + arr[now]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	DFS1(0, N / 2, 0);
	DFS2(N / 2, N, 0);
	if (!S) cout << ans - 1;
	else cout << ans;
}