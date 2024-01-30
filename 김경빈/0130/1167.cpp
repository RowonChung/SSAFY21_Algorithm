#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define endl "\n"
using namespace std;

int V, head, node, dist, max_dist = 0, max_node;
bool visited[100001];
vector<vector<pair<int, int>>> v;

void DFS(int now, int dist) {
	if (dist > max_dist) {
		max_dist = dist;
		max_node = now;
	}
	
	for (pair<int, int> x : v[now]) {
		if (not visited[x.first]) {
			visited[x.first] = true;
			DFS(x.first, dist + x.second);
		}
	}
}

int main() {
	cin >> V;
	v.resize(V + 1);
	for (int i = 0; i < V; i++) {
		cin >> head;
		while (true) {
			cin >> node;
			if (node == -1) break;
			cin >> dist;
			v[head].push_back(make_pair(node, dist));
		}
	}
	memset(visited, false, V + 1);
	visited[1] = true;
	DFS(1, 0);
	memset(visited, false, V + 1);
	visited[max_node] = true;
	DFS(max_node, 0);
	cout << max_dist << endl;
}