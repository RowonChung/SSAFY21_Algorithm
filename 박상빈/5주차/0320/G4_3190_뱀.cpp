#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

struct Position {
    int y;
    int x;
};

int N, K, L;
int board[101][101] = { 0, };
unordered_map<int, char> inform;

int dirx[4] = { 0, 0, 1, -1 };
int diry[4] = { 1, -1, 0, 0 };

// 동의 오른쪽은 남 왼쪽은 북 0 -> 2, 3
// 서의 오른쪽은 북 왼쪽은 남 1 -> 3, 2
// 남의 오른쪽은 서 왼쪽은 동 2 -> 1, 0
// 북의 오른쪽은 동 왼쪽은 서 3 -> 0, 1
int ddir[4] = { 2,3,1,0 };
int ldir[4] = { 3,2,0,1 };

int solution()
{
    // 0 길, 1 사과

    // 뱀 좌표 저장
    vector<Position> position;

    position.push_back({ 0, 0 });

    int seconds = 0;
    int dir = 0;
    bool game = true;

    while (game)
    {
        seconds++;

        Position last = position[0];

        position[0].y += diry[dir];
        position[0].x += dirx[dir];

        // 이동한 위치가 벽이거나 자기자신이라면 게임 종료
        if (position[0].y < 0 || position[0].x < 0 || position[0].y >= N || position[0].x >= N)
        {
            game = false;
            break;
        }

        if (!game) break;

        for (int j = 1; j < position.size(); j++)
        {
            if (position[0].y == position[j].y && position[0].x == position[j].x)
            {
                game = false;
                break;
            }
        }

        if (!game) break;

        // 사과 먹으면 몸길이 추가
        if (board[position[0].y][position[0].x] == 1)
        {
            board[position[0].y][position[0].x] = 0;
            position.push_back(last);
        }


        for (int i = (int)position.size() - 1; i >= 1; i--)
        {
            // 머리를 제외하고 앞에 있는 몸의 위치로 이동
            if (i == 1) position[i] = last;
            else position[i] = position[i - 1];
        }

        // 회전
        if (inform.count(seconds))
        {
            // 오른쪽
            if (inform[seconds] == 'D')
            {
                dir = ddir[dir];
            }
            // 왼쪽
            else if (inform[seconds] == 'L')
            {
                dir = ldir[dir];
            }
        }

    }


    return seconds;
}

int main()
{
    cin >> N >> K;

    for (int i = 0; i < K; i++)
    {
        int a, b;
        cin >> a >> b;

        board[b - 1][a - 1] = 1;
    }

    cin >> L;

    for (int i = 0; i < L; i++)
    {
        int t;
        char d;
        cin >> t >> d;

        inform[t] = d;
    }

    cout << solution() << endl;

    return 0;
}