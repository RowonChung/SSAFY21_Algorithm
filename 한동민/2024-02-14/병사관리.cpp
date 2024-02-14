#include <iostream>
using namespace std;

#define MAXNODE 100010

struct NODE {
    int mID = 0;
    int mTeam = 0;
    int mScore = 0;
    NODE* prev = nullptr;
    NODE* next = nullptr;
};

NODE head[6][6];
NODE tail[6][6];

NODE nodepool[MAXNODE];

void init()
{
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            head[i][j].next = &tail[i][j];
            tail[i][j].prev = &head[i][j];
        }
    }
}

void hire(int mID, int mTeam, int mScore)
{
    nodepool[mID].mID = mID;
    nodepool[mID].mTeam = mTeam;
    nodepool[mID].mScore = mScore;

    nodepool[mID].prev = tail[mTeam][mScore].prev;
    nodepool[mID].next = &tail[mTeam][mScore];

    nodepool[mID].prev->next = &nodepool[mID];
    nodepool[mID].next->prev = &nodepool[mID];

}

void fire(int mID)
{
    nodepool[mID].prev->next = nodepool[mID].next;
    nodepool[mID].next->prev = nodepool[mID].prev;
}

void updateSoldier(int mID, int mScore)
{
    fire(mID);
    hire(mID, nodepool[mID].mTeam, mScore);
}

void updateTeam(int mTeam, int mChangeScore)
{
    if (mChangeScore < 0) {
        for (int i = 2; i <= 5; i++) {
            int dif = (i + mChangeScore) < 1 ? 1 : (i + mChangeScore);
            if (head[mTeam][i].next != &tail[mTeam][i]) {
                NODE* frontNode = head[mTeam][i].next;
                NODE* lastNode = tail[mTeam][i].prev;
                head[mTeam][i].next = &tail[mTeam][i];
                tail[mTeam][i].prev = &head[mTeam][i];

                frontNode->prev = tail[mTeam][dif].prev;
                lastNode->next = &tail[mTeam][dif];

                frontNode->prev->next = frontNode;
                lastNode->next->prev = lastNode;
            }
        }
    }
    else {
        for (int i = 4; 1 <= i; i--) {
            int dif =  5 < (i + mChangeScore) ? 5 : (i + mChangeScore);
            if (head[mTeam][i].next != &tail[mTeam][i]) {
                NODE* frontNode = head[mTeam][i].next;
                NODE* lastNode = tail[mTeam][i].prev;
                head[mTeam][i].next = &tail[mTeam][i];
                tail[mTeam][i].prev = &head[mTeam][i];
                frontNode->prev = tail[mTeam][dif].prev;
                lastNode->next = &tail[mTeam][dif];

                frontNode->prev->next = frontNode;
                lastNode->next->prev = lastNode;
            }
        }
    }
}

int bestSoldier(int mTeam)
{
    for (int i = 5; 1 <= i; i--) {
        NODE* currentNode = head[mTeam][i].next;
        if (currentNode != &tail[mTeam][i]) {
            int number = 0;
            while (currentNode != &tail[mTeam][i]) {
                number = max(number, currentNode->mID);
                currentNode = currentNode->next;
            }
            return number;
        }
    }
}
