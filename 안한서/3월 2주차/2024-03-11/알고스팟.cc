#include <iostream>
#include <queue>
#include <string>
using namespace std;

int Map[101][101];
int dist[101][101];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

struct Node{
    int x, y, cnt;
    bool operator < (const Node &a) const{
        return cnt > a.cnt;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int m, n; cin >> m >> n;
    for(int i=0; i<n; i++){
        string s; cin >> s;
        for(int j=0; j<m; j++){
            Map[i][j] = (s[j] - '0');
            dist[i][j] = -1;
        }
    }

    priority_queue<Node> pq;
    pq.push({0, 0, 0});
    dist[0][0] = 0;

    while(!pq.empty()){
        int x = pq.top().x, y = pq.top().y, cnt = pq.top().cnt;
        pq.pop();

        if(x == (n-1) && y == (m-1)){
            cout << cnt;
            return 0;
        }

        if(dist[x][y] != -1 && dist[x][y] < cnt) continue;

        for(int i=0; i<4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if(Map[nx][ny] == 0){
                if(dist[nx][ny] != -1 && dist[nx][ny] <= cnt) continue;
                dist[nx][ny] = cnt;
                pq.push({nx, ny, cnt});
            } else{
                if(dist[nx][ny] != -1 && dist[nx][ny] <= (cnt + 1)) continue;
                dist[nx][ny] = cnt + 1;
                pq.push({nx, ny, cnt + 1});
            }
        }
    }
    return 0;
}