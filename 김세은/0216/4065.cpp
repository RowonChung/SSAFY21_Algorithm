#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
int T, N, M; // N 한변길이, M 돌 놓는 횟수

int map[10][10];
int dy[8] = {-1,-1,0,1,1,1,0,-1};
int dx[8] = {0,1,1,1,0,-1,-1,-1};

int nny, nnx;

vector<pair <int,int>> a;
void search(int y, int x, int c) {
    int c_num;
    int flag = 0;
    a.clear();
    for (int i = 0; i < 8; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny<1 || nx<1 || ny>N || nx>N) continue;
        if (map[ny][nx] == 0 || map[ny][nx] == c) continue;
 
        c_num = 0;
        for (int j = 0; j < 8; j++) {
            
            nny = ny + dy[j];
            nnx = nx + dx[j];
            if (nny<1 || nnx<1 || nny>N || nnx>N) continue;
            if (map[nny][nnx] == 0) continue;
            
            if(map[nny][nnx] == c && (nny != y || nnx != x))
                c_num++;
        }
        if (c_num >= 1) {
            if (y != ny || x != nx){
                a.push_back({ny,nx});
                flag = 1;
            }
            
        }
 
    }
    if(flag == 1)
        map[y][x] = c;
    for(int i = 0; i < a.size(); i++){
        map[a[i].first][a[i].second] = c;
    }
}

int main() {
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N >> M;
        
        for (int i = 1; i <= N; i++){
            for (int j = 1; j <= N; j++){
                map[i][j] = 0;
            }
        }
        
        map[N / 2][N / 2] = 2;
        map[(N / 2) + 1][(N / 2) + 1] = 2;
        map[(N / 2) + 1][N / 2] = 1;
        map[N / 2][(N / 2) + 1] = 1;
        
        
        int y, x, c;
        for (int i = 1; i <= M; i++) {
            cin >> x >> y >> c;
            search(y, x, c);
        }
 
        int cnt1=0, cnt2=0;
        for (int y = 1; y <= N; y++) {
            for (int x = 1; x <= N; x++) {
                if (map[y][x] == 1) cnt1++;
                if (map[y][x] == 2) cnt2++;
            }
        }
        cout <<"#"<< t << " "<< cnt1 << " " << cnt2;
    }
    return 0;
}