#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct node {
	int to;
	int cost;

	bool operator<(node right) const {
		if (cost < right.cost)return false;
		else if (cost > right.cost)return true;
		return false;
	}
};



vector <node> arr[101];

int dist[101];

int item[101];
int N, m, r;

int func(int n) {
	priority_queue<node> pq;
	for (int i = 0; i < 101; i++) {
		dist[i] = 2134567890;
	}
	dist[n] = 0;
	pq.push({ n,0 });
	while (!pq.empty()) {
		node now = pq.top();
		pq.pop();
		if (now.cost > dist[now.to])continue;
		for (int i = 0; i < arr[now.to].size(); i++) {
			node next = arr[now.to][i];
			int nextcost = next.cost + dist[now.to];
			if (dist[next.to] <= nextcost)continue;
			if (nextcost > m)continue;
			pq.push({ next.to,nextcost });
			dist[next.to] = nextcost;
		}
	}
	int sum = 0;
	for (int i = 1; i <= N; i++) {
		if (dist[i] != 2134567890) {
			sum += item[i];
		}
	}
	return sum;
}

int main() {
	cin >> N >> m >> r;
	for (int i = 1; i <= N; i++) {
		cin >> item[i];
	}
	for (int i = 0; i < r; i++) {
		int from;
		int to;
		int cost;
		cin >> from >> to >> cost;
		arr[from].push_back({ to,cost });
		arr[to].push_back({ from,cost });
	}	
	int answer = -1;
	for (int i = 1; i <= N; i++) {
		answer = max(answer, func(i));

	}
	cout << answer;
	

}