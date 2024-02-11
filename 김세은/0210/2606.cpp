#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int cnt = 0;
int N,M,V;
vector<int> alis[1001];
int visited[10001] = {0,};
void dfs(int node){
    
    //cout << node << " ";
    cnt++;
    visited[node] = 1;
        
    
    for(int i = 0; i < alis[node].size(); i++){
        int next = alis[node][i];
        if( visited[next] == 0){
            dfs(next);
        }
    }
}

int main(){
    cin >> N >> M ;
    
    int from, to;
    
    for(int i = 0; i < M; i++){
        cin >> from >> to;
        alis[from].push_back(to);
        alis[to].push_back(from);
    }
    
    for(int i = 1; i <= N ; i++) {
           sort(alis[i].begin(), alis[i].end());
    }
    
    dfs(1);
    
    cout << cnt - 1;
   
}
