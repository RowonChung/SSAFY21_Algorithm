#include <iostream>
#include <deque>
#include <queue>

using namespace std;

int N, K, L;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

struct Node {
    int apple = 0;
    int ex = 0;
};
Node arr[101][101];
queue<pair<int, char>> dir;

int main() {
    deque <pair<int, int>> q;//뱀의 좌표들 모두 저장

    cin >> N >> K;

    for (int i = 0; i < K; i++) {
        int x, y;
        cin >> y >> x;
        arr[y][x].apple = 1;
    }

    cin >> L;


    for (int i = 0; i < L; i++) {
        int time;
        char d;
        cin >> time >> d;
        dir.push({ time,d });
    }

    int T = 0;
    int di = 1; // 기본 방향
    q.push_front({ 1,1 });
    arr[1][1].ex = 1;


    while (1) {
        //1. 방향 먼저 바꾸기


        if (dir.size() > 0 && dir.front().first == T) {
            if (dir.front().second == 'L') {
                if (di == 0) di = 3;
                else di -= 1;
                dir.pop();
            }
            else {
                if (di == 3) di = 0;
                else di += 1;
                dir.pop();
            }
        }
        //2. 머리 움직이기
        int hi = q.front().first;
        int hj = q.front().second;

        hi += dy[di];
        hj += dx[di];

        q.push_front({ hi,hj });

        //4. 머리 판별
        if (hi < 1 || hi > N || hj < 1 || hj > N) break;
        if (arr[hi][hj].ex == 1) break;

        //3. 사과 여부 확인 후 꼬리뺄지 말지
        if (arr[hi][hj].apple == 1) {
            arr[hi][hj].apple = 0;
        }
        else {
            arr[q.back().first][q.back().second].ex = 0;
            q.pop_back();
        }


        //4. 시간 증가 
        arr[hi][hj].ex = 1;
        T++;
    }

    cout << T + 1;
}