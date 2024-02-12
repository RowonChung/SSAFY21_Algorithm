#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

int N, M, A, B;
map<int, int> inDegree;
vector<vector<int>> v;
priority_queue<int, vector<int>, greater<>> q;

int main() {
	ios::sync_with_stdio;
	cin.tie(0);

	cin >> N >> M;
	v.resize(N + 1);
	for (int i = 0; i <= N; i++) {
		inDegree[i] = 0;
	}
	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		v[A].push_back(B);
		inDegree[B]++;
	}
	
	for (int i = 1; i <= N; i++) {
		if (inDegree[i] == 0) q.push(i);
	}
	for (int i = 1; i <= N; i++) {
		if (q.empty()) break;
		int x = q.top();
		cout << x << " ";
		q.pop();
		for (int j = 0; j < v[x].size(); j++) {
			int y = v[x][j];
			if (--inDegree[y] == 0) q.push(y);
		}
	}
}