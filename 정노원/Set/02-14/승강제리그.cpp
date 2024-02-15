#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

void init(int N, int L, int mAbility[]);
int move();
int trade();

#define MAX_N 39990

#define CMD_INIT 100
#define CMD_MOVE 200
#define CMD_TRADE 300

static bool run()
{
    int query_num;
    scanf("%d", &query_num);

    int ans;
    bool ok = false;

    for (int q = 0; q < query_num; q++)
    {
        int query;
        scanf("%d", &query);
        if (query == CMD_INIT)
        {
            int N;
            int L;
            int mAbility[MAX_N];
            scanf("%d %d", &N, &L);
            for (int i = 0; i < N; i++) {
                scanf("%d", &mAbility[i]);
            }
            init(N, L, mAbility);
            ok = true;
        }
        else if (query == CMD_MOVE)
        {
            int ret = move();
            scanf("%d", &ans);
            if (ans != ret)
            {
                ok = false;
            }
        }
        else if (query == CMD_TRADE)
        {
            int ret = trade();
            scanf("%d", &ans);
            if (ans != ret)
            {
                ok = false;
            }
        }
    }
    return ok;
}

int main()
{
    setbuf(stdout, NULL);
    //freopen("sample_input.txt", "r", stdin);
    int T, MARK;
    scanf("%d %d", &T, &MARK);

    for (int tc = 1; tc <= T; tc++)
    {
        int score = run() ? MARK : 0;
        printf("#%d %d\n", tc, score);
    }
    return 0;
}
//////////////////////////////
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

struct player {
	int ID;
	int ability;
    bool operator<(const player &a)const {
        if (this->ability != a.ability) return this->ability < a.ability;
        return this->ID > a.ID;
    }
};

int n, l, playernum;
player playerpool[40000];
set<player> st1[10], st2[10];
player mid[10];


void balancing() {
    for (int i = 0; i < l; i++) {
        while (st1[i].size() != st2[i].size()) {
            if (st1[i].size() < st2[i].size()) {
                auto temp = st2[i].begin();
                st1[i].insert(mid[i]);
                mid[i] = *temp;
                st2[i].erase(*temp);
            }
            else {
                auto temp = --(st1[i].end());
                st2[i].insert(mid[i]);
                mid[i] = *temp;
                st1[i].erase(*temp);
            }
        }
    }
}

void init(int N, int L, int mAbility[])
{
	n = N;
	l = L;
    playernum = N / L;
    for (int i = 0; i < 10; i++) {
        st1[i].clear();
        st2[i].clear();
    }
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < playernum; j++) {
            int curindex = i * playernum + j;
            playerpool[curindex].ability = mAbility[curindex];
            playerpool[curindex].ID = curindex;
            if (j == 0) {
                mid[i] = playerpool[curindex];
            }
            else {
                if (playerpool[curindex].ability <= mid[i].ability) {
                    st1[i].insert(playerpool[curindex]);
                }
                else {
                    st2[i].insert(playerpool[curindex]);
                }
            }
        }
    }
    balancing();
}

int move()
{
    int cnt = 0;
    player temp1[10];
    player temp2[10];
    for (int i = 0; i < l-1; i++) {
        temp1[i] = *(st1[i].begin());
        temp2[i] = *(--st2[i + 1].end());
        cnt += temp1[i].ID + temp2[i].ID;
    }
    for (int i = 0; i < l-1; i++) {
        st1[i].erase(temp1[i]);
        st2[i+1].erase(temp2[i]);
        if (temp2[i] < mid[i]) {
            st1[i].insert(temp2[i]);
        }
        else {
            st2[i].insert(temp2[i]);
        }
        if (temp1[i] < mid[i+1]) {
            st1[i+1].insert(temp1[i]);
        }
        else {
            st2[i+1].insert(temp1[i]);
        }
    }
    balancing();
    return cnt;
}

int trade()
{
    int cnt = 0;
    player temp1[10];
    player temp2[10];
    for (int i = 0; i < l - 1; i++) {
        temp1[i] = mid[i];
        temp2[i] = *(--st2[i + 1].end());
        cnt += temp1[i].ID + temp2[i].ID;
    }
    for (int i = 0; i < l - 1; i++) {
        mid[i] = *st2[i].begin();
        st2[i].erase(mid[i]);
        st2[i + 1].erase(temp2[i]);
        if (temp2[i] < mid[i]) {
            st1[i].insert(temp2[i]);
        }
        else {
            st2[i].insert(temp2[i]);
        }
        if (temp1[i] < mid[i + 1]) {
            st1[i + 1].insert(temp1[i]);
        }
        else {
            st2[i + 1].insert(temp1[i]);
        }
    }
    balancing();
    return cnt;

}