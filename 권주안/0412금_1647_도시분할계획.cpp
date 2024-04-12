#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
	int from;
	int to;
	int cost;
};
int N, M;
Edge alis[1000001];
int ans = 0;
int arr[100001];
bool cmp(Edge left, Edge right) {
	if (left.cost < right.cost) return true;
	if (left.cost > right.cost) return false;
	return false;
}

void init() {
	for (int i = 1; i <= N; i++) {
		arr[i] = i;
	}
}

int find(int tar) {
	if (tar == arr[tar]) return tar;
	int ret = find(arr[tar]);
	arr[tar] = ret;
	return ret;
}

void setUnion(int a, int b) {
	int pa = find(a);
	int pb = find(b);
	if (pa == pb) return;
	arr[pa] = pb;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// init
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> alis[i].from >> alis[i].to >> alis[i].cost;
	}
	init();

	// solve
	sort(alis, alis + M, cmp);
	int target = N - 2;
	int cnt = 0;
	for (int i = 0; i < M; i++) {
		int a = alis[i].from;
		int b = alis[i].to;
		int cost = alis[i].cost;
		if (find(a) == find(b)) continue;
		setUnion(a, b);
		ans += cost;
		cnt++;
		if (cnt == target) break;
	}

	// print
	if (N == 2) cout << 0;
	else cout << ans;

	return 0;
}