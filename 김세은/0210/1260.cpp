//1260
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N,M,V;
vector<int> alis[1001];
int visited[10001] = {0,};
void dfs(int node){
    
    cout << node << " ";
    visited[node] = 1;
        
    
    for(int i = 0; i < alis[node].size(); i++){
        int next = alis[node][i];
        if( visited[next] == 0){
            dfs(next);
        }
    }
}
void bfs(int node){
    for(int i = 0; i <= N;i++){
        visited[i] = 0;
    }
    
    queue<int>q;
    
    q.push(node);
    
    visited[node] = 1;
    
    while(!q.empty()){
        int now = q.front();
        q.pop();
        
        cout << now << " ";
        
        for(int i = 0; i < alis[now].size(); i++){
            int next = alis[now][i];
            
            if(visited[next] != 0) continue;
            
            q.push(next);
            visited[next] = visited[now] + 1;
        }
    }
    
}
int main(){
    cin >> N >> M >> V;
    
    int from, to;
    
    for(int i = 0; i < M; i++){
        cin >> from >> to;
        alis[from].push_back(to);
        alis[to].push_back(from);
    }
    
    for(int i = 1; i <= N ; i++) {
           sort(alis[i].begin(), alis[i].end());
    }
    
    dfs(V);
    cout <<"\n";
    bfs(V);
}
