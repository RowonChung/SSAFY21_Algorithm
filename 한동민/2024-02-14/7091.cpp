#include<iostream>
using namespace std;

#define HASH_SIZE (1 << 31)
#define DIV (HASH_SIZE - 1)

int H, W, N, M;
int calRow, calCol;

int student[2000][2000];
int teacher[2000][2000];
int hash_map[2000][2000];
int tmp[2000][2000];

void calculate() {
    unsigned long long mul = 1;
    for (int i = 0; i < W - 1; i++) {
        mul = (mul << 4) + mul;
    }
    calCol = (int)(mul & DIV);
    mul = 1;
    for (int i = 0; i < H - 1; i++) {
        mul = (mul << 5) + mul;
    }
    calRow = (int)(mul & DIV);
}

int make_student_hash(int row, int col, int direction) {
    // 가로: 2, 세로:3
    unsigned long long hash = 0;
    if (direction == 0) {
        // 가로
        for (int i = col; i < col + W; i++) {
            hash = (hash << 4) + hash + student[row][i];
        }
        return (int)(hash & DIV);
    }
    else {
        // 세로
        for (int i = row; i < row + H; i++) {
            hash = (hash << 5) + hash + student[i][col];
        }
        return (int)(hash & DIV);
    }
}


int make_teacher_hash(int row, int col, int direction) {
    // 가로: 2, 세로:3
    unsigned long long hash = 0;
    if (direction == 0) {
        // 가로
        for (int i = col; i < col + W; i++) {
            hash = (hash << 4) + hash + teacher[row][i];
        }
        return (int)(hash & DIV);
    }
    else {
        // 세로
        for (int i = row; i < row + H; i++) {
            hash = (hash << 5) + hash + teacher[i][col];
        }
        return (int)(hash & DIV);
    }
}

int make_hash(int row, int col, int direction) {
    // 가로: 2, 세로:3
    unsigned long long hash = 0;
    if (direction == 0) {
        // 가로
        for (int i = col; i < col + W; i++) {
            hash = (hash << 4) + hash + tmp[row][i];
        }
        return (int)(hash & DIV);
    }
    else {
        // 세로
        for (int i = row; i < row + H; i++) {
            hash = (hash << 5) + hash + tmp[i][col];
        }
        return (int)(hash & DIV);
    }
}

int next_hash(int prev, int rmv, int add, int direction) {
    if (direction == 0) {
        unsigned long long hash = prev - (rmv * calCol);
        hash = (hash << 4) + hash + add;
        return (int)(hash & DIV);
    }
    else {
        unsigned long long hash = prev - (rmv * calRow);
        hash = (hash << 5) + hash + add;
        return (int)(hash & DIV);
    }
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test_case;
    int T;
    //freopen("input.txt", "r", stdin);
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> H >> W >> N >> M;
        calculate();
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                char c;
                cin >> c;
                if (c == 'x') {
                    student[i][j] = 1;
                }
                else {
                    student[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < N; i++) {
            int k = 1;
            for (int j = 0; j < M; j++) {
                char c;
                cin >> c;
                if (c == 'x') {
                    teacher[i][j] = 1;
                }
                else {
                    teacher[i][j] = 0;
                }
            }
        }
        int studentKey;
        for (int i = 0; i < H; i++) {
            tmp[i][0] = make_student_hash(i, 0, 0);
        }
        studentKey = make_hash(0, 0, 1);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M - W + 1; j++) {
                if (j == 0) {
                    tmp[i][j] = make_teacher_hash(i, j, 0);
                }
                else {
                    tmp[i][j] = next_hash(tmp[i][j - 1], teacher[i][j - 1], teacher[i][j + W - 1], 0);
                }
            }
        }
        for (int j = 0; j < M - W + 1; j++) {
            for (int i = 0; i < N - H + 1; i++) {
                if (i == 0) {
                    hash_map[i][j] = make_hash(i, j, 1);
                }
                else {
                    hash_map[i][j] = next_hash(hash_map[i - 1][j], tmp[i - 1][j], tmp[i + H - 1][j], 1);
                }
            }
        }
        int res = 0;
        for (int i = 0; i < N - H + 1; i++) {
            for (int j = 0; j < M - W + 1; j++) {
                /*cout << "row = " << i << " col = " << j << endl;
                cout << "studentKey = " << studentKey << endl;
                cout << "hash = " << hash_map[i][j] << endl;*/
                if (hash_map[i][j] == studentKey) {
                    res++;
                }
            }
        }
        cout << "#" << test_case << " ";
        cout << res << endl;
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
