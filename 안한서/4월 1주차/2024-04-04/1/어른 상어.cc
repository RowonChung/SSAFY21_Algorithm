#include <iostream>
#include <vector>
using namespace std;

struct Player{
    int x, y, live;
};

Player player[401];
pair<int, int> board[21][21];
int ans;
int n, m, k;
int player_dir[401];
int moves[401][4][4];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool checkMove(int idx, int dir){
    int x = player[idx].x, y = player[idx].y;
    for(int i=0; i<4; i++){
        int nx = x + dx[moves[idx][dir][i]-1];
        int ny = y + dy[moves[idx][dir][i]-1];

        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if(board[nx][ny].first == 0) return true;
    }
    return false;
}

bool checkLive(){
    if(player[1].live == 0) return false;

    for(int i=2; i<=m; i++){
        if(player[i].live) return false;
    }
    return true;
}

void monopoly(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(board[i][j].first != 0){
                board[i][j].second--;
                if(board[i][j].second == 0) board[i][j] = {0, 0};
            }
        }
    }
}

void movePlayer(int idx){
    int x = player[idx].x, y = player[idx].y, dir = player_dir[idx] - 1;

    if(checkMove(idx, dir)){
        for(int i=0; i<4; i++){
            int nx = x + dx[moves[idx][dir][i]-1];
            int ny = y + dy[moves[idx][dir][i]-1];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(board[nx][ny].first == 0){
                player[idx] = {nx, ny, 1};
                player_dir[idx] = moves[idx][dir][i];
                break;
            }
        }
    } else{
        for(int i=0; i<4; i++){
            int nx = x + dx[moves[idx][dir][i]-1];
            int ny = y + dy[moves[idx][dir][i]-1];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(board[nx][ny].first == idx){
                player[idx] = {nx, ny, 1};
                player_dir[idx] = moves[idx][dir][i];
                break;
            }
        }
    }
}

int main(){
    cin >> n >> m >> k;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int num; cin >> num;
            if(num != 0){
                board[i][j] = {num, k};
                player[num] = {i, j, 1};
            }
            else board[i][j] = {0, 0};
        }
    }
    for(int i=1; i<=m; i++) cin >> player_dir[i];
    for(int i=1; i<=m; i++){
        for(int j=0; j<4; j++){
            for(int d = 0; d<4; d++) cin >> moves[i][j][d];
        }
    }
    
    while(1){
        if(ans > 1000) break;

        for(int i=1; i<=m; i++){
            if(player[i].live) movePlayer(i);
        }
        monopoly();
        for(int i=1; i<=m; i++){
            if(player[i].live == 0) continue;
            int x = player[i].x, y = player[i].y;
            if(board[x][y].first == 0 || board[x][y].first == i) board[x][y] = {i, k};
            else player[i].live = 0;
        }
        ans++;
        if(checkLive()) break;
    }

    if(ans > 1000) cout << -1;
    else cout << ans;

    return 0;
}