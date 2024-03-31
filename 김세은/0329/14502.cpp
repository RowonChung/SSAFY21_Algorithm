#include <iostream>
#include <queue>
using namespace std;

int N,M;
int arr[10][10];
int arr2[10][10];
pair <int,int> info1[65]; // 0 저장
pair <int,int> info2[65]; // 2 저장
int nums[3];
int k = 0; //intfo1 index
int p = 0; // info 2 index
int visited[65] = {0,};
int ans;
int dy[4] = {0,1,0,-1};
int dx[4] = {-1,0,1,0};
int real_ans = 0;
int visited2[10][10] ={ 0,};
queue<pair <int,int>> q;
void print(){
    for(int i = 1; i <= N; i++){
        for(int j = 1 ; j <= M; j++){
            cout << arr2[i][j] <<" ";
        }
        cout << "\n";
    }
    
    cout << ans<<"\n";
}
void bfs(){
    
    while(!q.empty()){
        int nowy = q.front().first;
        int nowx = q.front().second;
        q.pop();
        
        for(int i = 0 ; i < 4 ; i++){
            int ny = nowy + dy[i];
            int nx = nowx + dx[i];
            
            if(ny < 1|| ny > N || nx < 1 || nx > M)continue;
            if(arr2[ny][nx] == 1 || arr2[ny][nx] == 2)continue;
            if(visited2[ny][nx] != 0)continue;
            
            arr2[ny][nx] = 2;
            ans--;
            visited2[ny][nx] = 1;
            q.push({ny,nx});
                
        }
        //print();
    }
}
void init(){
    for(int i = 0; i < 10; i ++){
        for(int j = 0; j < 10; j++){
            visited2[i][j] = 0;
        }
    }
}
int run(){
    for(int i = 0; i < 10; i ++){
        for(int j = 0; j < 10 ; j++){
            arr2[i][j] = arr[i][j];
        }
    }
    
    for(int i = 0; i < 3; i++){
        arr2[info1[nums[i]].first][info1[nums[i]].second] = 1;
    }
    
    ans = k;
    
    for(int i = 0; i < p; i++){
        q.push({info2[i].first,info2[i].second});
        visited2[info2[i].first][info2[i].second] = 1;
    }
    bfs();
    
    init();
    
    //print();
    
    
    return ans;
}
void dfs(int level,int bf){
    
    if(level == 3){
        
//        for(int i = 0; i < 3; i++){
//            cout << nums[i]<<" ";
//        }
//        cout <<"\n";
        
        real_ans = max(real_ans, run());
        //cout << real_ans<<"\n";
        return;
    }
    
    for(int i = bf ; i <= k; i++){
        nums[level] = i;
        if(visited[i] != 0)continue;
        visited[i] = 1;
        dfs(level + 1,i);
        nums[level] = -1;
        visited[i] = 0;
    }
}
int main(){
    cin >> N >> M;
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 0) {
                info1[k].first = i;
                info1[k].second = j;
                k++;
            }
            
            if(arr[i][j] == 2) {
                info2[p].first = i;
                info2[p].second = j;
                p++;
            }
            
        }
    }
    
    dfs(0,0);
    
    
    cout << real_ans - 3;
}