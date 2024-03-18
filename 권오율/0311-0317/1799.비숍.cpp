#include <iostream>
#include <algorithm>
using namespace std;

int N;
int maxi[2];
int arr[11][11];
int l[20];
int r[20];

void dfs(int row, int col, int cnt, int board) {
    if (col >= N) {
        row++;
        if (col % 2 == 0) col = 1;
        else col = 0;
    }
    if (row >= N) {
        maxi[board] = max(maxi[board], cnt);
        return;
    }

    if (arr[row][col] && !l[col - row + N - 1] && !r[row + col]) {
        l[col - row + N - 1] = r[row + col] = 1;
        dfs(row, col + 2, cnt + 1, board);
        l[col - row + N - 1] = r[row + col] = 0;
    }
    dfs(row, col + 2, cnt, board);
}

int main(void) {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    dfs(0, 0, 0, 0);
    dfs(0, 1, 0, 1);

    cout << maxi[0] + maxi[1];
}
