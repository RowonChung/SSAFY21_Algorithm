#include <iostream>
#include <vector>
#include <map>
#include <deque>
using namespace std;


int arr[101][101];
int dr[4] = { 0,1,0,-1 };
int dc[4] = { -1,0,1,0 };

int n, k, l;
int times, flag, dir = 1;

struct Snake { int row, col; };

deque <Snake> snake;
map <int, char> inst;

int main() {
    snake.push_back({ 1,1 });
    cin >> n >> k;

    for(int i = 0; i < k; i++){
        int row, col;
        cin >> row >> col;
        arr[row][col] = 1;
    }

    cin >> l;

    for(int i = 0; i < l; i++) {
        int row;
        char dir;
        cin >> row >> dir;
        inst[row] = dir;
    }

    while (true) {
        times++;
        int row = snake.front().row;
        int col = snake.front().col;
        int nextR = row + dc[dir];
        int nextC = col + dr[dir];
        for (auto& body : snake)
            if (body.row == nextR && body.col == nextC){
                flag = 1; 
                break;
            }
        if (1 > nextR || nextR > n || 1 > nextC || nextC > n || flag) { 
            flag = 1; break; 
        }
        snake.push_front({ nextR,nextC });

        if (arr[nextR][nextC] == 0) { 
            snake.pop_back(); 
        }
        else arr[nextR][nextC] = 0;

        if (inst[times] == 'D') {
            dir = (dir + 1) % 4; 
        }
        else if (inst[times] == 'L') { 
            dir = (dir + 3) % 4;
        }
    }

    cout << times << '\n';
}
