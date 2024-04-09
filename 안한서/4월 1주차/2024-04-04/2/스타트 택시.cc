#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

#define INF 1e9

int n, m, c;
int car_x, car_y;
int board[21][21];
int dist[21][21];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

struct Human{
    int sx, sy, ex, ey, state;
};
Human humans[401];

void bfs(int x, int y){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) dist[i][j] = INF;
    }

    queue<pair<int, int>> q;
    q.push({x, y});
    dist[x][y] = 0;

    while(!q.empty()){
        int cx = q.front().first, cy = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = cx + dx[i], ny = cy + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n || board[nx][ny]) continue;
            if(dist[nx][ny] != -1 && dist[nx][ny] <= (dist[cx][cy] + 1)) continue;

            dist[nx][ny] = dist[cx][cy] + 1;
            q.push({nx, ny});
        }
    }
}

int main(){
    cin >> n >> m >> c;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cin >> board[i][j];
    }
    cin >> car_x >> car_y;
    for(int i=0; i<m; i++){
        int sx, sy, ex, ey; cin >> sx >> sy >> ex >> ey;
        humans[i] = {sx, sy, ex, ey, 1};
    }

    while(1){
        int flag = 0;
        for(int i=0; i<m; i++) flag += humans[i].state;
        if(flag == 0) break;

        bfs(car_x-1, car_y-1);

        int idx = 0, charge = 1e9;
        for(int i=0; i<m; i++){
            if(humans[i].state == 0) continue;

            if(charge > dist[humans[i].sx - 1][humans[i].sy - 1]){
                idx = i;
                charge = dist[humans[i].sx - 1][humans[i].sy - 1];
            } else if(charge == dist[humans[i].sx - 1][humans[i].sy - 1]){
                if(humans[idx].sx == humans[i].sx){
                    if(humans[idx].sy > humans[i].sy) idx = i;
                } else{
                    if(humans[idx].sx > humans[i].sx) idx = i;
                }
            }
        }

        c -= charge;
        if(c < 0) break;
        else{
            car_x = humans[idx].sx; car_y = humans[idx].sy;
            bfs(car_x-1, car_y-1);
            c -= dist[humans[idx].ex-1][humans[idx].ey-1];
            if(c < 0) break;
            humans[idx].state = 0;
            c += dist[humans[idx].ex-1][humans[idx].ey-1] * 2;
            car_x = humans[idx].ex; car_y = humans[idx].ey;
        }
    }

    if(c < 0) cout << -1;
    else cout << c;

    return 0;
}