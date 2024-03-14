#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
using namespace std;

int TC, N, students, input, cycle, visited[100001], team[100001];
vector<vector<int>> v;

int DFS(int node) {
	if (team[node] != 0) return 0;
	if (visited[node]) {
		team[node] = 1;
		visited[node] = 1;
		students--;
		cycle = node;
		return 1;
	}

	visited[node] = 1;
	int result = DFS(v[node][0]);
	if (result) {
		if (cycle == node) return 0;
		students--;
		team[node] = 1;
		
		return 1;
	}
	team[node] = -1;
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> TC;
	for (int tc = 0; tc < TC; tc++) {
		memset(team, 0, sizeof(team));
		memset(visited, 0, sizeof(visited));
		v.clear();
		cin >> N;
		students = N;
		v.resize(N + 1);
		for (int i = 1; i <= N; i++) {
			cin >> input;
			v[i].push_back(input);
		}

		for (int i = 1; i <= N; i++) {
			if (visited[i]) continue;
			cycle = 0;
			DFS(v[i][0]);
		}

		cout << students << '\n';
	}

}