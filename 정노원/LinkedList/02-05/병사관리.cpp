#include<iostream>
#include<algorithm>
#include <stdio.h>

#define CMD_INIT 1
#define CMD_HIRE 2
#define CMD_FIRE 3
#define CMD_UPDATE_SOLDIER 4
#define CMD_UPDATE_TEAM 5
#define CMD_BEST_SOLDIER 6
using namespace std;

struct Node{
    Node * pre;
    int mID, mTeam, mScore;
    Node * next;
};

Node Nodepool[100010];
Node * head[6][6];
Node * tail[6][6];

Node * NewNode(int x){
    Nodepool[x].pre =nullptr;
    Nodepool[x].mID = x;
    Nodepool[x].next = nullptr;
    return &Nodepool[x];
}

void init()
{
    printf("1");
    for(int i = 0; i <= 100000; i++){
        Nodepool[i].pre = nullptr;
        Nodepool[i].mID = i;
        Nodepool[i].mTeam = 0;
        Nodepool[i].mScore = 0;
        Nodepool[i].next = nullptr;
    }
    for(int i =1 ; i <= 5; i++){
        for(int j =1 ; j <= 5; j++){
            head[i][j] = nullptr;
            tail[i][j] = head[i][j];
        }
    }
}

void hire(int mID, int mTeam, int mScore){
    printf("2");
    if(head[mTeam][mScore]==nullptr){
        head[mTeam][mScore] = & Nodepool[mID];
    }else{
        tail[mTeam][mScore]->next = &Nodepool[mID];
        Nodepool[mID].pre = tail[mTeam][mScore];
        Nodepool[mID].next = nullptr;
        tail[mTeam][mScore] = &Nodepool[mID];
    }
}

void fire(int mID)
{
    printf("3");
    int curteam = Nodepool[mID].mTeam;
    int curScore = Nodepool[mID].mScore;
    if( Nodepool[mID].pre == nullptr && Nodepool[mID].next == nullptr){
        head[curteam][curScore] = nullptr;
        tail[curteam][curScore] = head[curteam][curScore];
    }else if ( Nodepool[mID].pre == nullptr){
        head[curteam][curScore] = Nodepool[mID].next;
        Nodepool[mID].next = nullptr;
        Nodepool[mID].pre = nullptr;
    }else if ( Nodepool[mID].next == nullptr){
        tail[curteam][curScore] = Nodepool[mID].pre;
        Nodepool[mID].next = nullptr;
        Nodepool[mID].pre = nullptr;
    }else{
        Nodepool[mID].next->pre = Nodepool[mID].pre;
        Nodepool[mID].pre->next = Nodepool[mID].next;
        Nodepool[mID].next = nullptr;
        Nodepool[mID].pre = nullptr;
    }
}

void updateSoldier(int mID, int mScore)
{
    printf("4");
    fire(mID);
    hire(mID, Nodepool[mID].mTeam ,mScore);
}

void updateTeam(int mTeam, int mChangeScore)
{
    printf("5");
    if( mChangeScore > 0){
        for(int i = 4; i >= 1; i--){
            int curScore = i + mChangeScore;
            if(curScore >= 5) curScore = 5;
            if(head[mTeam][i] == nullptr) continue;
            tail[mTeam][curScore] -> next = head[mTeam][i];
            head[mTeam][i] = nullptr;
            tail[mTeam][curScore] = tail[mTeam][i];
            tail[mTeam][i] = head[mTeam][i];
        }
    }else{
        for(int i = 2; i <= 5; i++){
            int curScore = i + mChangeScore;
            if(curScore <= 1) curScore = 1;
            if(head[mTeam][i] == nullptr) continue;
            tail[mTeam][curScore] -> next = head[mTeam][i];
            head[mTeam][i] = nullptr;
            tail[mTeam][curScore] = tail[mTeam][i];
            tail[mTeam][i] = head[mTeam][i];
        }
    }
}

int bestSoldier(int mTeam)
{
    printf("6");
    int MM = 0;
    for(int i = 5; i >= 1 ; i--){
        if( head[mTeam][i] == nullptr) continue;
        Node * cur = head[mTeam][i];
        while(cur->next != nullptr){
            MM = max(MM , cur->mID);
            cur = cur->next;
        }

    }
    return MM;
}


static bool run()
{
    int numQuery;

    int mID, mTeam, mScore, mChangeScore;

    int userAns, ans;

    bool isCorrect = false;

    scanf("%d", &numQuery);

    for (int i = 0; i < numQuery; ++i)
    {
        int cmd;
        scanf("%d", &cmd);
        switch (cmd)
        {
        case CMD_INIT:
            init();
            isCorrect = true;
            break;
        case CMD_HIRE:
            scanf("%d %d %d", &mID, &mTeam, &mScore);
            hire(mID, mTeam, mScore);
            break;
        case CMD_FIRE:
            scanf("%d", &mID);
            fire(mID);
            break;
        case CMD_UPDATE_SOLDIER:
            scanf("%d %d", &mID, &mScore);
            updateSoldier(mID, mScore);
            break;
        case CMD_UPDATE_TEAM:
            scanf("%d %d", &mTeam, &mChangeScore);
            updateTeam(mTeam, mChangeScore);
            break;
        case CMD_BEST_SOLDIER:
            scanf("%d", &mTeam);
            userAns = bestSoldier(mTeam);
            scanf("%d", &ans);
            if (userAns != ans)
            {
                isCorrect = false;
            }
            break;
        default:
            isCorrect = false;
            break;
        }
    }

    return isCorrect;
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