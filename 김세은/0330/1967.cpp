#include <iostream>
#include <vector>
using namespace std;

int n;
int visited[10002] = {0,};
int result = 0;
int e = 0;
vector<pair<int,int>> alis[10002];

void dfs(int node,int level){
    if(visited[node] == 1){
        return;
    }
    
    visited[node] = 1;
    if(result < level) {
        result = level;
        e = node;
    }
    for(int i = 0; i < alis[node].size(); i++){
        dfs(alis[node][i].first, level + alis[node][i].second);
    }
}
void init(){
    
    for(int i = 0; i < 10002; i++){
        visited[i] = 0;
    }
    
}
int main(){
    cin >> n;
    
    for(int i = 0; i < n - 1; i++){
        int s,f,w;
        cin >> s >> f >> w;
        alis[s].push_back({f,w});
        alis[f].push_back({s,w});
    }
    
    dfs(1,0);
    
    result = 0;
    init();
    
    dfs(e,0);
    cout <<result;
}