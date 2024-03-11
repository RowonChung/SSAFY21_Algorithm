#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;


string wheel[5];
bool canMoved[5][5] = { false, };

void update() {
    memset(canMoved, false, sizeof(canMoved));
    for (int i = 1; i <= 4; i++) {
        int left = i - 1, right = i + 1;
        if (left >= 1 && wheel[left][2] != wheel[i][6])
            canMoved[i][left] = true;
        if (right <= 4 && wheel[right][6] != wheel[i][2])
            canMoved[i][right] = true;
    }
}

void rotate(int pos, int dir) {
    if (pos <= 0 || pos > 4)
        return;

    if (dir == 1) {
        char tmp = wheel[pos][8 - 1];
        for (int i = 8 - 2; i >= 0; i--) {
            wheel[pos][i + 1] = wheel[pos][i];
        }
        wheel[pos][0] = tmp;
    }
    else {
        char tmp = wheel[pos][0];
        for (int i = 1; i < 8; i++) {
            wheel[pos][i - 1] = wheel[pos][i];
        }
        wheel[pos][8 - 1] = tmp;
    }
    for (int i = 1; i <= 4; i++) {
        if (canMoved[pos][i]) {
            canMoved[pos][i] = false;
            canMoved[i][pos] = false;
            rotate(i, -1 * dir);
        }
    }
}

int main(void) {
    for (int i = 1; i <= 4; i++)
        cin >> wheel[i];

    int k;
    cin >> k;
    while (k--) {
        int to_move, direction;
        cin >> to_move >> direction;
        update();
        rotate(to_move, direction);
    }

    int answer = 0;
    for (int i = 1; i <= 4; i++) {
        if (wheel[i][0] == '1')
            answer += pow(2, i - 1);
    }
    cout << answer;
}
