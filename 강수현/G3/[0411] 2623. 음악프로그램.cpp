#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
int inDegree[1001];
vector<int>v[1001];

void run() {
	queue<int>q;
	queue<int>res;

	for (int i = 1; i <= N; i++) {
		if (inDegree[i] != 0) continue;
		q.push(i);
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		res.push(now);

		for (int i = 0; i < v[now].size(); i++) {
			inDegree[v[now][i]]--;

			if (inDegree[v[now][i]] == 0) q.push(v[now][i]);
		}
	}

	if (res.size() == N) {
		while (!res.empty()) {
			cout << res.front() << "\n";
			res.pop();
		}
	}
	else
		cout << "0";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		int prev;
		for (int j = 0; j < num; j++) {
			int tmp;
			cin >> tmp;

			if (j == 0) {
				prev = tmp;
				continue;
			}

			v[prev].push_back(tmp);
			inDegree[tmp]++;
			prev = tmp;
		}
	}

	run();

	return 0;
}