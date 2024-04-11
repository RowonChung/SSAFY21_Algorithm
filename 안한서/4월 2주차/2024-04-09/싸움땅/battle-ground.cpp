#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k;
vector<int> board[21][21];

struct Player {
    int x, y, d, atk, gun, score;
};
Player players[31];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool isRange(int x, int y) { return (x < 0 || x >= n || y < 0 || y >= n); }

int search(int st, int x, int y) {
    for (int i = 1; i <= m; i++) {
        if (i == st) continue;
        if (players[i].x == x && players[i].y == y) return i;
    }
    return 0;
}

void getGun(int idx, int x, int y) {
    if (board[x][y][0] != 0) {
        sort(board[x][y].rbegin(), board[x][y].rend());
        if (players[idx].gun < board[x][y][0]) {
            if (players[idx].gun != 0) board[x][y].push_back(players[idx].gun);
            players[idx].gun = board[x][y][0];
            board[x][y].erase(board[x][y].begin());
            if (board[x][y].size() == 0) board[x][y].push_back(0);
        }
    }
}

void fight(int p1, int p2) {
    int atk1 = players[p1].atk + players[p1].gun;
    int atk2 = players[p2].atk + players[p2].gun;

    if (atk1 > atk2) players[p1].score += (atk1 - atk2);
    else if(atk2 > atk1 ){
        players[p2].score += (atk2 - atk1);
        swap(p1, p2);
    } else {
        if (players[p1].atk < players[p2].atk) swap(p1, p2);
    }
    
    // p1 : 이긴 사람, p2 : 진 사람
    int x = players[p2].x, y = players[p2].y;
    if (board[x][y][0] != 0) {
        if (players[p2].gun != 0) board[x][y].push_back(players[p2].gun);
    } else board[x][y][0] = players[p2].gun;
    players[p2].gun = 0;

    int nx, ny, dir = players[p2].d;
    while (1) {
        nx = x + dx[dir], ny = y + dy[dir];
        if (isRange(nx, ny)) { dir = (dir + 1) % 4; continue; }
        if (search(p2, nx, ny) != 0) { dir = (dir + 1) % 4; continue; }
        break;
    }

    players[p2].x = nx; players[p2].y = ny; players[p2].d = dir;
    getGun(p2, nx, ny);
    getGun(p1, players[p1].x, players[p1].y);
}

void moving(int idx) {
    int x = players[idx].x, y = players[idx].y, dir = players[idx].d;
    int nx, ny;
    while (1) {
        nx = x + dx[dir], ny = y + dy[dir];
        if (isRange(nx, ny)) { dir = (dir + 2) % 4; continue; }
        break;
    }
    players[idx].x = nx; players[idx].y = ny; players[idx].d = dir;

    int info = search(idx, nx, ny);
    if (info != 0) fight(idx, info);
    else getGun(idx, nx, ny);
}

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int num; cin >> num;
            board[i][j].push_back(num);
        }
    }

    for (int i = 1; i <= m; i++) {
        int x, y, d, s; cin >> x >> y >> d >> s;
        players[i] = { x - 1, y - 1, d, s, 0, 0 };
    }

    for (int i = 0; i < k; i++) {
        for (int j = 1; j <= m; j++) moving(j);
    }

    for (int i = 1; i <= m; i++) cout << players[i].score << " ";
    return 0;
}