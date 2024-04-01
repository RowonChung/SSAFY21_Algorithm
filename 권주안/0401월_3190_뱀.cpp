#include <iostream>
#include <deque>
using namespace std;

struct Node {
    char status;
    int dir;
};
int N, K;
Node board[100][100];
int L;
deque<pair<int, char>> dirChanges;

int dr[] = { -1,0,1,0 };
int dc[] = { 0,1,0,-1 };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            board[y][x].status = '0';
        }
    }
    board[0][0] = { 'S', 1 };
    for (int i = 0; i < K; i++) {
        int row, col;
        cin >> row >> col;
        board[row - 1][col - 1].status = 'A';
    }
    cin >> L;
    for (int i = 0; i < L; i++) {
        int time; char dir;
        cin >> time >> dir;
        dirChanges.push_back({ time, dir });
    }
    int t = 0;
    int headY = 0;
    int headX = 0;
    int nowDir = 1;
    deque<pair<int, int>> snake; // 뱀의 몸통 좌표를 저장하는 deque
    snake.push_front({ headY, headX }); // 머리를 몸통 deque에 추가

    while (1) {
        t++;
        int ny = headY + dr[nowDir];
        int nx = headX + dc[nowDir];
        if (!dirChanges.empty() && t == dirChanges.front().first) {
            char changeDir = dirChanges.front().second;
            if (changeDir == 'L')
                nowDir = (nowDir + 3) % 4;
            else if (changeDir == 'D')
                nowDir = (nowDir + 1) % 4;
            dirChanges.pop_front(); // 사용된 방향전환 정보는 삭제
        }
        if (ny < 0 || ny >= N || nx < 0 || nx >= N || board[ny][nx].status == 'S') {
            break;
        }
        snake.push_front({ ny, nx }); // 머리를 몸통 deque에 추가
        if (board[ny][nx].status != 'A') {
            board[snake.back().first][snake.back().second].status = '0'; // 꼬리 지우기
            snake.pop_back(); // 꼬리를 몸통 deque에서 삭제
        }
        board[ny][nx] = { 'S', nowDir }; // 머리 이동
        headY = ny;
        headX = nx;
    }
    cout << t;
    return 0;
}
