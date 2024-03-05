#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge { 
    int num;
    int cost;
    bool operator<(Edge right) const {
        if (cost < right.cost) return false;
        if (cost > right.cost) return true;
        return false;
    }
};
int V, E;
int start;
vector<Edge> alis[20001];
int dist[20001];

void dijkstra(int start) {
    for (int i = 1; i <= V; i++) {
        dist[i] = 2134567890;
    }
    dist[start] = 0;

    priority_queue<Edge> pq;
    pq.push({ start,0 });

    while (!pq.empty()) {
        Edge now = pq.top();
        pq.pop();
        for (int i = 0; i < alis[now.num].size(); i++) {
            Edge next = alis[now.num][i];
            int nextcost = next.cost + dist[now.num];
            if (dist[next.num] <= nextcost) continue;
            pq.push({ next.num,nextcost });
            dist[next.num] = nextcost;
        }
    }
}

int main() {
    cin >> V >> E;
    cin >> start;
    for (int i = 0; i < E; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        alis[from].push_back({ to,cost });
    }
    dijkstra(start);
    for (int i = 1; i <= V; i++) {
        if (dist[i] == 2134567890) {
            cout << "INF\n";
        }
        else cout << dist[i] << "\n";
    }

    return 0;
}