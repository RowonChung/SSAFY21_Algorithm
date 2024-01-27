#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;

int n;
vector<int>edge[100001];
bool visit[100001];
vector<int> ans;

void bfs() {
	queue<int> q;
	q.push(1);
	visit[1] = true;
	int index = 1;

	while (!q.empty()) {
		int cnt = 0;
		int current = q.front();
		q.pop();
		bool temp[100001];
		memset(temp, false, sizeof(temp));
		for (int i = 0; i < edge[current].size(); i++) {
			int next = edge[current][i];
			if (!visit[next]) {
				visit[next] = true;
				temp[next] = 1;
				cnt++;
			}
		}
		int a = index;
		for (int i = a; i < a + cnt; i++) {
			if (temp[ans[index]]) {
				q.push(ans[index]);
				index++;
			}
		}
	}
	if (index != n) {
		cout << 0;
	}
	else {
		cout << 1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		edge[n1].push_back(n2);
		edge[n2].push_back(n1);
	}
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		ans.push_back(temp);
	}

	bfs();
}
