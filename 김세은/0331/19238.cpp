#include <iostream>
#include <queue>
using namespace std;

int N,M,E;
int visited[22][22];
int arr[22][22];
int dy[4] = {0,1,0,-1};
int dx[4] = {-1,0,1,0};
struct Node {
    int sy;
    int sx;
    int ty;
    int tx;
    int index;
};

int psgs[402];  // ex 여부 확인
//바꿔어야 하는 값들은 struct 가 아니라 따로 빼주기

struct passenger{
    int sy;
    int sx;
    int index;
    int dst = visited[sy][sx];
    
    bool operator<(const passenger& other) const {
           if (dst != other.dst) return dst > other.dst;
           if (sy != other.sy) return sy > other.sy;
           return sx > other.sx;
       }
};

       
Node psg[402];

void bfs(int y, int x){
    queue<pair <int,int>> q;
    q.push({y,x});
    visited[y][x] = 0;
    
    while(!q.empty()){
        int nowy = q.front().first;
        int nowx = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int ny = nowy + dy[i];
            int nx = nowx + dx[i];
            
            if(ny < 1 || ny > N || nx < 1 || nx > N) continue;
            if(arr[ny][nx] == 1) continue;
            
            if(visited[ny][nx] <= visited[nowy][nowx] + 1)continue;
            visited[ny][nx] = visited[nowy][nowx] + 1;
            q.push({ny, nx});
            
        }
        
    }
}
void init(){
    
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N; j++){
            if(arr[i][j] == 1)
                visited[i][j] = -1;
            else
                visited[i][j] = 21e8;
        }
    }
    
}
void print(){
    
    cout <<"\n";
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cout << visited[i][j]<<" ";
        }
        cout <<"\n";
    }
}
int main(){
    cin >> N >> M >> E;
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> arr[i][j];
        }
    }
    
    
    int cy, cx;
    cin >> cy >> cx;
    
    for(int i = 0; i < M; i++){
        cin >> psg[i].sy >> psg[i].sx >> psg[i].ty >> psg[i].tx;
        psg[i].index = i;
    }
    
    for(int i = 0; i < 402; i++){
        psgs[i] = 1;
    }

    //while 0이거나 e < 0
    int CM = M;
    while(M != 0 && E > 0){
        init();
        
        bfs(cy,cx);
        
        priority_queue<passenger> pq;
        
        //print();
        
        for(int i = 0; i < CM; i++){
             if(psgs[i] == 1) pq.push({psg[i].sy,psg[i].sx,i});
        }
        
        int idx = pq.top().index;
        psgs[idx] = 0;
        
        int e1 = visited[psg[idx].sy][psg[idx].sx];
        E -= e1;
        if(E < 0) break;
        
        init();
        
        bfs(psg[idx].sy,psg[idx].sx);
        
        int e2 = visited[psg[idx].ty][psg[idx].tx];
        E -= e2;
        if(E < 0) break;
        
        E += 2 * e2;
        
        cy = psg[idx].ty;
        cx = psg[idx].tx;
        M--;
        
       // cout << E;
    }
    
    if(M != 0) cout << -1;
    else cout << E;
    
    
}