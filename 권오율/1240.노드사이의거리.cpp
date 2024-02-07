#include <iostream>
using namespace std;
int n, m;
int arr[1010][1010];
int used[1010];
int mini = 1e9;

void dfs(int now, int to, int val) {
	if (now == to) {
		mini = min(mini, val);
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (arr[now][i] == 0 || used[i] == 1) continue;
		used[i] = 1;
		dfs(i, to, val + arr[now][i]);
		used[i] = 0;
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n-1; i++) {
		int from, to, val;
		cin >> from >> to >> val;
		arr[from][to] = val;
		arr[to][from] = val;
	}

	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		used[from] = 1;
		dfs(from, to, 0);
		cout << mini << "\n";
		for (int i = 1; i <= n; i++) {
			used[i] = 0;
		}
		mini = 1e9;
	}
}