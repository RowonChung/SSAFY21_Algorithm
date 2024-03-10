#include <iostream>
#include <deque>
#include <vector>
using namespace std;



int JOKER;
deque<int> left_dq;
deque<int> right_dq;
int sum_left, sum_right;
int cnt_left, cnt_right;
deque<vector<int>> card;
deque<int> dq[31][20];

void calculate(int direction) {

    int value;
    int card_index;
    vector<int> v;
    if (direction == 0) {
        for (int i = 0; i < 4; i++) {
            v.push_back(left_dq[i]);
        }
        card.push_back(v);
        card_index = card.size() - 1;
        for (int i = 1; i <= 30; i++) {
            value = (sum_left + (cnt_left * i)) % 20;
            dq[i][value].push_front(card_index);
        }
    }
    else {
        for (int i = 0; i < 4; i++) {
            v.push_back(right_dq[i]);
        }
        card.push_back(v);
        card_index = card.size() - 1;
        for (int i = 1; i <= 30; i++) {
            value = (sum_right + (cnt_right * i)) % 20;
            dq[i][value].push_back(card_index);
        }
    }
}

void init(int mJoker, int mNumbers[5])
{
    left_dq.clear();
    right_dq.clear();
    sum_left = 0;
    sum_right = 0;
    cnt_left = 0;
    cnt_right = 0;
    JOKER = mJoker;
    int value;
    card.clear();
    for (int i = 1; i <= 30; i++) {
        for (int j = 0; j < 20; j++) {
            dq[i][j].clear();
        }
    }
    deque<int> dq;
    for (int i = 0; i < 4; i++) {
        left_dq.push_back(mNumbers[i]);
        if (mNumbers[i] == -1) {
            value = 0;
            cnt_left++;
        }
        else {
            value = mNumbers[i];
        }
        sum_left += value;
    }
    for (int i = 1; i < 5; i++) {
        right_dq.push_back(mNumbers[i]);
        if (mNumbers[i] == -1) {
            value = 0;
            cnt_right++;
        }
        else {
            value = mNumbers[i];
        }
        sum_right += value;
    }
    
    calculate(0);
    calculate(1);
}

void putCards(int mDir, int mNumbers[5])
{
    int value;
    if (mDir == 0) {
        for (int i = 4; 0<=i; i--) {
            left_dq.push_front(mNumbers[i]);
            if (mNumbers[i] == -1) {
                value = 0;
                cnt_left++;
            }
            else {
                value = mNumbers[i];
            }
            sum_left += value;
            if (left_dq.back() == -1) {
                cnt_left--;
                left_dq.pop_back();
            }
            else {
                sum_left -= left_dq.back();
                left_dq.pop_back();
            }
            calculate(0);
        }
    }
    else {
        for (int i = 0; i < 5; i++) {
            right_dq.push_back(mNumbers[i]);
            if (mNumbers[i] == -1) {
                value = 0;
                cnt_right++;
            }
            else {
                value = mNumbers[i];
            }
            sum_right += value;
            if (right_dq.front() == -1) {
                cnt_right--;
                right_dq.pop_front();
            }
            else {
                sum_right -= right_dq.front();
                right_dq.pop_front();
            }
            calculate(1);
        }
    }
}

int findNumber(int mNum, int mNth, int ret[4])
{
    if (dq[JOKER][mNum].size() < mNth) {
        return 0;
    }
    else {
        int card_index = dq[JOKER][mNum][mNth - 1];
        for (int i = 0; i < 4; i++) {
            ret[i] = card[card_index][i];
        }
        return 1;
    }
}

void changeJoker(int mValue)
{
    JOKER = mValue;
}
