#include <iostream>
using namespace std;

int n, m;
int path[8];

void dfs(int now, int next){

    if (now == m) {
        for (int i = 0; i < m; i++){
            cout << path[i] << " ";
        }
        cout << "\n";
        return;
    }

    

    for (int i = next; i <= n; i++){
        path[now] = i;
        dfs(now + 1, i);
        path[now] = 0;
    }

}

int main(){

    cin >> n >> m;
    
    dfs(0, 1);

}