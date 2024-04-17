#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M, p, q, g, parent[1001];
char re;
vector<vector<int>> e, f;

int find_parent(int a) {
	if (a == parent[a]) return a;
	return parent[a] = find_parent(parent[a]);
}

void union_parent(int a, int b) {
	a = find_parent(a);
	b = find_parent(b);

	if (a == b) return;

	if (a < b) {
		parent[b] = a;
	}
	else if (a > b) {
		parent[a] = b;
	}
	g--;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	g = N;
	e.resize(N + 1);
	f.resize(N + 1);

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < M; i++) {
		cin >> re >> p >> q;
		if (re == 'E') {
			e[p].push_back(q);
			e[q].push_back(p);

			for (int j = 0; j < e[p].size(); j++) {
				if (e[p][j] == q) continue;
				union_parent(q, e[p][j]);
			}
			for (int j = 0; j < e[q].size(); j++) {
				if (e[q][j] == p) continue;
				union_parent(p, e[q][j]);
			}
		}
		else if (re == 'F') {
			f[p].push_back(q);
			f[q].push_back(p);

			union_parent(p, q);
		}
	}
	cout << g;
}