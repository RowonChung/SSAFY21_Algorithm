#include <iostream>
using namespace std;

int score;
int board[10][10];

void block(int x, int y, int tp){
    int right = y, down = x;
    if(tp == 1){
        while(right < 10){
            if(board[x][right + 1] || right == 9){
                board[x][right] = 1;
                break;
            }
            right++;
        }

        while(down < 10){
            if(board[down + 1][y] || down == 9){
                board[down][y] = 1;
                break;
            }
            down++;
        }
    } else if(tp == 2){
        while(right < 10){
            if(board[x][right + 2] || right == 8){
                board[x][right] = 1; board[x][right+1] = 1;
                break;
            }
            right++;
        }

        while(down < 10){
            if((board[down + 1][y] || board[down + 1][y + 1]) || down == 9){
                board[down][y] = 1; board[down][y + 1] = 1;
                break;
            }
            down++;
        }
    } else{
        while(right < 10){
            if((board[x][right + 1] || board[x + 1][right + 1]) || right == 9){
                board[x][right] = 1; board[x + 1][right] = 1;
                break;
            }
            right++;
        }

        while(down < 10){
            if(board[down + 2][y] || down == 8){
                board[down][y] = 1; board[down + 1][y] = 1;
                break;
            }
            down++;
        }
    }
}

void addScore(){
    for(int i=6; i<10; i++){
        int red = 0, yellow = 0;
        for(int j=0; j<4; j++){
            red += board[j][i];
            yellow += board[i][j];
        }

        if(yellow == 4){
            score++;
            int temp[4];
            for(int j=0; j<4; j++){
                for(int up = i; up > 4; up --) board[up][j] = board[up-1][j];
            }
        }

        if(red == 4){
            score++;
            int temp[4];
            for(int j=0; j<4; j++){
                for(int up = i; up > 4; up --) board[j][up] = board[j][up-1];
            }
        }
    }
}

void limitMove(){
    int red_st, yellow_st;
    for(red_st=4; red_st < 6; red_st++){
        int flag = 0;
        for(int i=0; i<4; i++){
            if(board[i][red_st]){ flag = 1; break; }
        }
        if(flag) break;
    }

    for(yellow_st=4; yellow_st < 6; yellow_st++){
        int flag = 0;
        for(int i=0; i<4; i++){
            if(board[yellow_st][i]){ flag = 1; break; }
        }
        if(flag) break;
    }

    for(int i= 9; i>5; i--){
        for(int j=0; j<4; j++){
            board[j][i] = board[j][i - (6 - red_st)];
            board[i][j] = board[i-(6 - yellow_st)][j];
        }
    }

    for(int i=0; i<4; i++){
        board[4][i] = board[5][i] = 0;
        board[i][4] = board[i][5] = 0;
    }
}

int main(){
    int k; cin >> k;
    for(int tc=0; tc<k; tc++){
        int t, x, y; cin >> t >> x >> y;
        block(x, y, t);
        addScore();
        limitMove();
    }

    int cnt = 0;
    for(int i=6; i<10; i++){
        for(int j=0; j<4; j++) cnt += (board[i][j] + board[j][i]);
    }
    cout << score << '\n' << cnt;
    return 0;
}