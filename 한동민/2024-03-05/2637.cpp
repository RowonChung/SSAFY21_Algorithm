#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;

vector<int> base;
vector<pair<int,int>> v[101];
int infos[101][101];
bool visit[101];
int inDegree[101];

void solve() {
	int sum = 0;
	queue<int> q;
	vector<int> tmp;
	for (int i = 1; i <= N; i++) {
		if (inDegree[i] == 0) {
			q.push(i);
			base.push_back(i);
			infos[i][i] = 1;
		}
	}
	while (!q.empty()) {
		int current = q.front();
		q.pop();
		for (int i = 0; i < v[current].size(); i++) {
			int next = v[current][i].first;
			inDegree[next]--;
			for (int j = 0; j < base.size(); j++) {
				int tmp = base[j];
				infos[next][tmp] += v[current][i].second * infos[current][tmp];
			}
			if (inDegree[next] == 0) {
				q.push({ next });
			}
		}
	}
	for (int i = 0; i < base.size(); i++) {
		cout << base[i] << " " << infos[N][base[i]] << endl;
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[b].push_back({ a,c });
		inDegree[a]++;
	}
	solve();
}
