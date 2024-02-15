#include<iostream>
#include<queue>
#include<unordered_map>
#include<unordered_set>

using namespace std;

#define MAX_USER 500
#define MAX_CHANNEL 500
#define MAX_NEWS 30000

struct News {
    int newsId;
    int channelId;
    int time;
    bool isDeleted;

    News() {};

    News(int _newsId, int _channelId, int _time) {
        newsId = _newsId;
        channelId = _channelId;
        time = _time;
        isDeleted = false;
    }
}newsPool[MAX_NEWS];
int newsIndex;

struct cmp {
    // time이 낮을수록, newId가 낮을수록 우선순위 큼
    bool operator()(const News* a, const News* b) {
        if (a->time != b->time) return !(a->time < b->time);
        return !(a->newsId < b->newsId);
    }
};

vector< int > channelArr[MAX_CHANNEL + 1];
vector< News*>  userArr[MAX_USER + 1];
News* newsArr[MAX_NEWS + 1];                
priority_queue< News*, vector< News*>, cmp > notiPQ; 
unordered_map< int, int > cMapper;
unordered_map< int, int > uMapper;
unordered_map< int, int > nMapper;
int cIndex;
int uIndex;
int nIndex;

void init(int N, int K) {
    newsIndex = 0;
    cIndex = uIndex = nIndex = 0;

    cMapper.clear();
    uMapper.clear();
    nMapper.clear();

    for (int i = 0; i < MAX_USER; i++)
    {
        channelArr[i].clear();
        userArr[i].clear();
    }

    notiPQ = {};
}


void sendNews(int time) {
    while (!notiPQ.empty()) {
        if (notiPQ.top()->time > time) return;
        News* news = notiPQ.top(); notiPQ.pop();
        if (news->isDeleted) continue;
        vector< int >* userList = &channelArr[news->channelId];
        for (int i : *userList) {
            userArr[i].push_back(news);
        }
    }
}

void registerUser(int mTime, int mUID, int mNum, int mChannelIDs[]) {
    sendNews(mTime);

    int userID = uMapper[mUID];
    if (userID == 0)
        userID = uMapper[mUID] = ++uIndex;

    for (int i = 0; i < mNum; i++) {
        int channelId = cMapper[mChannelIDs[i]];
        if (channelId == 0)
            channelId = cMapper[mChannelIDs[i]] = ++cIndex;

        channelArr[channelId].push_back(userID);
    }
}

int offerNews(int mTime, int mNewsID, int mDelay, int mChannelID) {
    int nID = nMapper[mNewsID] = ++nIndex;
    int channelID = cMapper[mChannelID];

    News* newNews = &newsPool[newsIndex++];
    newNews->newsId = mNewsID;
    newNews->channelId = channelID;
    newNews->time = mTime + mDelay;
    newNews->isDeleted = false;

    notiPQ.emplace(newNews);
    newsArr[nID] = newNews;

    return channelArr[channelID].size();
}

void cancelNews(int mTime, int mNewsID) {
    sendNews(mTime);
    int nID = nMapper[mNewsID];
    newsArr[nID]->isDeleted = true;
}


int checkUser(int mTime, int mUID, int mRetIDs[]) {
    sendNews(mTime);

    int uID = uMapper[mUID];
    vector< News*>* newsList = &userArr[uID];

    int total = newsList->size();
    int cnt = 0;

    while (total > 0) {
        News* news = newsList->at(total - 1);
        if (news->isDeleted) {
            total--;
            continue;
        }
        if (cnt < 3) mRetIDs[cnt] = news->newsId;

        total--;
        cnt++;
    }
    newsList->clear();
    return cnt;
}
