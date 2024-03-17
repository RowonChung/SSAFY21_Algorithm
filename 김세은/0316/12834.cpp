#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int dist[1001]; // 정답 저장
int N,V,E; // 팀원 수,장소 수, 도로 수
int A,B; // kist와 씨알푸트 위치
int info[101]; // 팀원들 집 위치, 즉 다익스트라 시작 지점

struct Node {
    int num;
    int cost;

    bool operator < (Node right) const {
     return cost > right.cost;

    }
};

vector <Node> alis[1001];
void dikstra(int node){
    
    priority_queue <Node> pq;

    
    pq.push({ node, 0 });
    dist[node] = 0;
    
    while (!pq.empty()) {
        Node now = pq.top();
        pq.pop();

        for (int i = 0; i < alis[now.num].size(); i++) {
            Node next = alis[now.num][i];
            int nextcost = next.cost + dist[now.num];
            if (dist[next.num] <= nextcost) continue;
            pq.push({ next.num, nextcost });
            dist[next.num] = nextcost;
        }
    }
}

void init(){
    
    for(int i = 1; i <= V; i++){
            dist[i]= 21e8;
    }
}
int main(){
  
    cin >> N >> V >> E;
    
    init();
    
    cin >> A >> B;
    
    for(int i = 0; i < N; i++){
        cin >> info[i];
    }
    
    
    for(int i = 0; i < E; i++){
        int a, b, l;
        cin >> a >> b >>l;
        
        alis[a].push_back({b,l});
        alis[b].push_back({a,l});
    }
    int ans = 0;
    
    for(int i = 0; i < N; i++){
        dikstra(info[i]);
        if( dist[A] == 21e8) ans += -1;
        else ans += dist[A];
        if( dist[B] == 21e8) ans += -1;
        else ans += dist[B];
        init();
    }
    
    cout <<ans;
    
}
