#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m, n, k;
int board[11][11];
vector<int> copy_board[11][11];

struct Player{
    int x, y, gone;

    bool operator < (const Player &a) const{
        if(x == a.x) return y < a.y;
        return x < a.x;
    }
};
Player players[11];

pair<int, int> gate;

int move_cnt;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void player_move(int idx){
    int x = players[idx].x, y = players[idx].y;
    int dist = abs(x - gate.first) + abs(y - gate.second);
    int dir = -1;
    for(int i=0; i<4; i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 0 || nx >=n || ny < 0 || ny >= n) continue;
        if(board[nx][ny] != 0) continue;

        if(nx == gate.first && ny == gate.second){
            players[idx].gone = 1;
            move_cnt++;
            return;
        }

        int ndist = abs(nx - gate.first) + abs(ny - gate.second);
        if(ndist < dist){
            dist = ndist;
            dir = i;
        }
    }

    if(dir != -1){
        players[idx].x += dx[dir]; players[idx].y += dy[dir];
        move_cnt++;
    }
}

void wall_move(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) copy_board[i][j].clear();
    }

    int MIN = 100;
    for(int i=1; i<=m; i++){
        if(players[i].gone) continue;

        int dist = 0;
        if(abs(players[i].x - gate.first) != 0) dist = abs(players[i].x - gate.first);
        if(abs(players[i].y - gate.second) != 0) dist = max(dist, abs(players[i].y - gate.second));

        MIN = min(MIN, dist);
    }
    if(MIN == 100) return;

    int sx = -1, sy = -1;
    for(int i=0; i<(n-MIN); i++){
        for(int j=0; j<(n-MIN); j++){
            if(i <= gate.first && gate.first <= (i + MIN)){
                if(j <= gate.second && gate.second <= (j + MIN)){
                    for(int k=1; k<=m; k++){
                        if(players[k].gone) continue;
                        
                        if(i <= players[k].x && players[k].x <= (i + MIN)){
                            if(j <= players[k].y && players[k].y <= (j + MIN)){
                                sx = i; sy = j; break;
                            }
                        }
                    }
                    if(sx != -1) break; 
                }
            }
        }
        if(sx != -1) break;
    }

    // 회전 부분 복사 ... player 위치 idx * 100;
    for(int i=0; i<=MIN; i++){
        for(int j=0; j<=MIN; j++){
            if(board[i + sx][j + sy] > 0) copy_board[i + sx][j + sy].push_back(board[i + sx][j + sy]);
        }
    }
    for(int i=1; i<=m; i++){
        if(players[i].gone) continue;
        if(sx <= players[i].x && players[i].x <= (sx + MIN)){
            if(sy <= players[i].y && players[i].y <= (sy + MIN)) copy_board[players[i].x][players[i].y].push_back(i * 100);
        }
    }
    copy_board[gate.first][gate.second].push_back(-1);

    for(int i=0; i<=MIN; i++){
        for(int j=0; j<=MIN; j++){
            if(copy_board[MIN - j + sx][i + sy].size() == 0) board[i + sx][j + sy] = 0;
            else if(0 < copy_board[MIN - j + sx][i + sy][0] && copy_board[MIN - j + sx][i + sy][0] < 10) board[i + sx][j + sy] = copy_board[MIN - j + sx][i + sy][0] - 1;
            else if(copy_board[MIN - j + sx][i + sy][0] == -1){ board[i + sx][j + sy] = 0; gate = {i + sx, j + sy}; }
            else{
                board[i + sx][j + sy] = 0;
                for(int idx : copy_board[MIN - j + sx][i + sy]){
                    players[idx/100].x = (i + sx);
                    players[idx/100].y = (j + sy);
                }
            }
        }
    }
}

int main() {
    cin >> n >> m >> k;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cin >> board[i][j];
    }
    for(int i=1; i<=m; i++){
        int x, y; cin >> x >> y;
        players[i] = {x-1, y-1, 0};
    }
    int gx, gy; cin >> gx >> gy;
    gate = {gx-1, gy-1};

    for(int tc=0; tc<k; tc++){
        for(int i=1; i<=m; i++){
            if(players[i].gone) continue;
            player_move(i);
        }

        int cnt = 0;
        for(int i=1; i<m; i++) cnt += players[i].gone;
        if(cnt == m) break;

        wall_move();
    }

    cout << move_cnt << '\n';
    cout << gate.first + 1 << ' ' << gate.second + 1;

    return 0;
}