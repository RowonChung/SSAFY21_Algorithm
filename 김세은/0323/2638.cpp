#include <iostream>
#include <queue>
// 바깥과 닿는 면이 1, 0 이 아니라면 다음에 없어짐.
// 내부에 있는지 어떻게 판단?  => flood fill 을 돌리자 .
// 기준은 뭐로 잡지? => 가장 자리를 기준으로 flood fill 을 돌리고, N이랑 M이 100까지니까 괜찮지 않을까
//0. 처음에 값이 1인 칸의 개수 모두 세기
//1. 가장자리 기준으로 flood fill 돌려서 visited = 1 표시하기
//2. 한시간 후 없어질 치즈 확인 => 값 == 1 이고, visited 인 면이 2개 이상이면 없어지는 애
//3. 없애
//4. 시간 추가 해.
//5. 전체 c의 개수 == 0 이면 끝.
//6. T출력
using namespace std;

int N,M;
int arr[101][101];
int visited[101][101] ={0,};
int dy[4] = {0,1,0,-1};
int dx[4] = {-1,0,1,0};
int cheese = 0;
void flood(int y, int x){
    queue<pair<int, int>> q;
    q.push({y,x});
    
    while(!q.empty()){
        int nowy = q.front().first;
        int nowx = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int ny = nowy + dy[i];
            int nx = nowx + dx[i];
            
            if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if(visited[ny][nx] == 1)continue;
            if(arr[ny][nx] != 0) continue;
            q.push({ny,nx});
            visited[ny][nx] = 1;
                
        }
    }
}
int check(int y, int x){
    int cnt = 0;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if(visited[ny][nx] == 1)
            cnt++;
    }
    
    return cnt;
}
void init(){
    
    for(int i = 0; i < 101; i++){
        for(int j = 0; j < 101; j++){
            visited[i][j] = 0;
        }
    }
    
}

int main(){
    cin >> N >> M;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1)
                cheese++;
        }
    }
    
    int T = 0;
    while(cheese != 0){
        init();
        flood(0,0);
        
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(arr[i][j] == 1 && check(i,j) >= 2){
                    arr[i][j] = 0;
                    cheese -= 1;
                }
            }
        }
        T++;
    }
    cout << T;
}