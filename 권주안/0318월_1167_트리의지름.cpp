#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 2134567890;
struct Edge {
	int num;
	int cost;
};
int V;
vector<Edge> alis[100001];
int visited[100001];
int maxVal = 0;
int maxNode = 0;
int ans = 0;

void dfs(int nowEdge, int nowSum) {
	if (maxVal < nowSum) {
		maxVal = nowSum;
		maxNode = nowEdge;
	}
	int len = alis[nowEdge].size();
	for (int i = 0; i < len; i++) {
		Edge next = alis[nowEdge][i];
		if (visited[next.num] == 1) continue;
		visited[next.num] = 1;
		dfs(next.num, nowSum + next.cost);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> V;
	for (int i = 0; i < V; i++) {
		int from, to ,cost;
		cin >> from;
		while (1) {
			cin >> to;
			if (to == -1) break;
			cin >> cost;
			alis[from].push_back({ to,cost });
		}
	}
	visited[1] = 1;
	dfs(1, 0);
	int temp = maxNode;
	maxNode = 0;
	maxVal = 0;
	memset(visited, 0, sizeof(visited));
	visited[temp] = 1;
	dfs(temp, 0);
	cout << maxVal;

	int de = -1;
	return 0;
}