#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

struct Node {
	int num;
	int dist;
};

int V;
vector<Node>v[100001];
int flag[100001];
int maxDist = 0;
int maxNum = 0;

void dfs(int node, int len) {
	if (len > maxDist) {
		maxNum = node;
		maxDist = len;
	}

	for (int i = 0; i < v[node].size(); i++) {
		if (flag[v[node][i].num] == 1) continue;
		flag[v[node][i].num] = 1;
		dfs(v[node][i].num, len + v[node][i].dist);
	}
}

int main() {
	cin >> V;

	for (int i = 0; i < V; i++) {
		int n;
		cin >> n;
		while (1) {
			int a, b;
			cin >> a;
			if (a == -1) break;
			cin >> b;
			v[n].push_back({ a,b });
		}
	}

	flag[1] = 1;
	dfs(1, 0);

	int tmp = maxDist;
	maxDist = 0;
	memset(flag, 0, sizeof(flag));

	flag[maxNum] = 1;
	dfs(maxNum, 0);

	int res = max(tmp, maxDist);

	cout << res;

	return 0;
}