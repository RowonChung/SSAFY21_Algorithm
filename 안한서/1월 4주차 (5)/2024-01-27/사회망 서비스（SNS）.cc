#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector<int> alist[1000001];
bool visited[1000001];
int n, ans = 0;

int dfs(int node) {
	bool adt = false; // node의 Adt 여부
	int cnt = 0; // Adt인 친구의 수
	visited[node] = 1;
	for (auto nxt : alist[node]) {
		if (visited[nxt]) continue;

		if (dfs(nxt)) adt = true; // 친구가 Adt 아니면 나는 무조건 Adt
		else cnt++;
	}
	if (adt) ans++; // Adt라면 정답 개수 추가
	return cnt == (alist[node].size() - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < (n-1); i++) {
		int u, v; cin >> u >> v;
		alist[u].push_back(v);
		alist[v].push_back(u);
	}
	// 가장 밑의 node는 무조건 Adt 아님
	// 이후에 자식 node를 모두 Adt로 만들도록
	// 부모의 Adt 여부 정하며 탐색
	dfs(1);
	cout << ans;
	return 0;
}