#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int n, gNum, mid;
int board[30][30];
int visited[30][30];
int newBoard[30][30];
vector<pair<int, int>> group[850];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int make_group(){
    memset(visited, 0, sizeof(visited));
    for(int i=0; i<gNum; i++) group[i].clear();

    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visited[i][j]) continue;

            queue<pair<int, int>> q;
            q.push({i, j});
            visited[i][j] = 1;

            while(!q.empty()){
                int x = q.front().first, y = q.front().second;
                int color = board[x][y];
                q.pop();

                group[cnt].push_back({x, y});

                for(int d=0; d<4; d++){
                    int nx = x + dx[d], ny = y + dy[d];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(visited[nx][ny] || board[nx][ny] != color) continue;
                    q.push({nx, ny});
                    visited[nx][ny] = 1;
                }
            }

            cnt++;
        }
    }

    return cnt;
}

int harmony(int g1, int g2){
    int len1 = group[g1].size(), len2 = group[g2].size();
    int val1 = board[group[g1][0].first][group[g1][0].second];
    int val2 = board[group[g2][0].first][group[g2][0].second];

    int same = 0;
    for(int i=0; i<len1; i++){
        for(int j=0; j<len2; j++){
            int dist = abs(group[g1][i].first - group[g2][j].first) + abs(group[g1][i].second - group[g2][j].second);
            if(dist == 1) same++;
        }
    }

    return (len1 + len2) * same * val1 * val2;
}

void rotate(){
    newBoard[n/2][n/2] = board[n/2][n/2];
    for(int i=0; i<n/2; i++){
        newBoard[n/2][i] = board[i][n/2];
        newBoard[n - 1 -i][n/2] = board[n/2][i];
    }
    for(int i=(n/2 + 1); i<n; i++){
        newBoard[n/2][i] = board[i][n/2];
        newBoard[n - 1 - i][n/2] = board[n/2][i];
    }

    for(int i=0; i<n/2; i++){
        for(int j=0; j<n/2; j++) newBoard[i][j] = board[n/2 - 1 - j][i];
        for(int j=(n/2 + 1); j<n; j++) newBoard[i][j] = board[n - 1 - j][i + n/2 + 1];
    }

    for(int i=(n/2 + 1); i<n; i++){
        for(int j=0; j<n/2; j++) newBoard[i][j] = board[n - 1 - j][i - n/2 - 1];
        for(int j=(n/2 + 1); j<n; j++) newBoard[i][j] = board[n - j + n/2][i];
    }
}

int main() {
    cin >> n;
    mid = (n + 1)/2;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cin >> board[i][j];
    }

    int ans = 0;
    for(int t=0; t<4; t++){
        gNum = make_group();

        for(int i=0; i<(gNum - 1); i++){
            for(int j=(i + 1); j<gNum; j++) ans += harmony(i, j);
        }

        rotate();

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++) board[i][j] = newBoard[i][j];
        }
    }
    cout << ans;
    return 0;
}