#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[8];
int path[8];
bool used[8];

void input(){
    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
}

void dfs(int now){
     if (now == m){
         for(int i=0; i<m; i++){
             cout << path[i] << " ";
         }
         cout << "\n";
         return;
     }
    
    for(int i=0; i<n; i++){
        if (used[i]) continue;
        path[now] = arr[i];
        used[i] = true;
        dfs(now + 1);
        path[now] = 0;
        used[i] = false;
    }
}


int main(){
    input();
    
    sort(arr, arr + n);
    
    dfs(0);
}