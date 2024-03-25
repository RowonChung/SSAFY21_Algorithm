#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define INF (1<<31)-1

struct NODE {
	int index;
	int cost;
	bool operator < (const NODE& n) const {
		return cost > n.cost;
	}
};

struct DISTNODE {
	int cost;
	int prev;
	int cnt;
};

int n, m;
int targetStart, targetEnd;
DISTNODE dist[1001];
vector<pair<int, int>> v[1001];
priority_queue<NODE> pq;

void Dijaksta() {
	pq.push({ targetStart, 0 });
	dist[targetStart].cost = 0;
	while (!pq.empty()) {
		NODE current = pq.top();
		if (current.index == targetEnd) {
			break;
		}
		pq.pop();
		for (int i = 0; i < v[current.index].size(); i++) {
			int nextIndex = v[current.index][i].first;
			int nextCost = current.cost + v[current.index][i].second;
			if (nextCost < dist[nextIndex].cost) {
				pq.push({ nextIndex,nextCost });
				dist[nextIndex].cost = nextCost;
				dist[nextIndex].prev = current.index;
				dist[nextIndex].cnt = dist[current.index].cnt + 1;
			}
		}
	}
	vector<int> temp;
	int index = targetEnd;
	while (dist[index].prev != index) {
		temp.push_back(index);
		index = dist[index].prev;
	}
	temp.push_back(index);
	reverse(temp.begin(), temp.end());
	cout << dist[targetEnd].cost << "\n";
	cout << dist[targetEnd].cnt << "\n";
	for (int i = 0; i < temp.size(); i++) {
		cout << temp[i] << " ";
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		dist[i].cost = INF;
		dist[i].prev = i;
		dist[i].cnt = 1;
	}
	for (int i = 0; i < m; i++) {
		int start, end, cost;
		cin >> start >> end >> cost;
		v[start].push_back({ end,cost });
	}
	cin >> targetStart >> targetEnd;
	Dijaksta();
}
