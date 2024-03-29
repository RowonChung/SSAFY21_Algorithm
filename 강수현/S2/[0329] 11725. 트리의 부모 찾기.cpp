#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

int N;
vector<int>v[100001];
queue<int>q;
int arr[100001];

void bfs() {
	q.push(1);
	arr[1] = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];

			if (arr[next] != 0) continue;

			arr[next] = now;
			q.push(next);
		}
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	bfs();

	for (int i = 2; i <= N; i++) {
		cout << arr[i] << "\n";
	}

	return 0;
}