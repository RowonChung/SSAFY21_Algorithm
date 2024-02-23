#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> alis[51];
int del;
int root;
int cnt = 0;

void dfs(int node) {
	if (alis[node].size() == 0) {
		cnt++;
		return;
	}
	for (int i = 0; i < alis[node].size(); i++) {
		int next = alis[node][i];
		dfs(next);
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int from;
		cin >> from;
		if (from == -1) {
			root = i;
			continue;
		}
		alis[from].push_back(i);
	}
	cin >> del;
	for (int from = 0; from < N; from++) {
		for (int to = 0; to < alis[from].size(); to++) {
			if (alis[from][to] == del) {
				alis[from].erase(alis[from].begin() + to);
			}
		}
	}
	if (root == del) cout << 0;
	else {
		dfs(root);
		cout << cnt;
	}
	return 0;
}