#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int N, K;

int dist[100001];

struct node {
	int dest;
	int cost;
};

bool operator<(node left, node right) {
	if (left.cost < right.cost)return false;
	if (left.cost > right.cost)return true;
	return false;
}

priority_queue<node> pq;

int main() {
	cin >> N >> K;
	for (int i = 0; i < 100001; i++) {
		dist[i] = 2134567890;
	}
	pq.push({ N,0 });
	dist[N] = 0;
	while (!pq.empty()) {
		node now = pq.top();
		pq.pop();
		if (now.cost > dist[now.dest])continue;
		if (now.dest == K) {
			cout << now.cost;
			break;
		}
		// -1
		int next = now.dest - 1;
		int nextcost = now.cost + 1;
		if (next >= 0) {
			if (dist[next] > nextcost) {
				node d{ next,nextcost };
				pq.push(d);
				dist[next] = nextcost;
			}
		}


		// +1
		next = now.dest + 1;
		nextcost = now.cost + 1;
		if (next <= 100000) {
			if (dist[next] > nextcost) {
				node d{ next,nextcost };
				pq.push(d);
				dist[next] = nextcost;
			}
		}

		// *2
		next = now.dest * 2;
		if (next <= 100000) {
			if (dist[next] > now.cost) {
				node d{ next,now.cost };
				pq.push(d);
				dist[next] = now.cost;
			}
		}
	}


}