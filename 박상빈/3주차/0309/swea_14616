#include <iostream>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

struct Player {
    int ability;
    int id;
    bool operator<(Player right) const {
        if (ability == right.ability) return id > right.id;
        return ability < right.ability;
    }
};

bool Compare(const Player& left, const Player& right)
{
    if (left.ability == right.ability) return left.id > right.id;
    return left.ability < right.ability;
}

// 0이면 오른쪽 한칸
// 1이면 왼쪽 한칸
// 2이면 오른쪽 두칸
// 3이면 왼쪽 두칸
int movelr[11] = { 0, };
set<Player> st[11];
queue<Player> tmp[11];
Player middle[11];
int n, l, s;

void init(int N, int L, int mAbility[])
{
    for (int i = 0; i < 11; i++)
    {
        st[i].clear();
    }

    n = N;
    l = L;
    s = (n / l);

    int lidx = -1;
    for (int i = 0; i < n; i++)
    {
        if (i % s == 0) lidx++;
        st[lidx].insert({ mAbility[i], i });
    }

    // 제일 처음 middle 값을 가지고 있어야겠다
    for (int i = 0; i < l; i++)
    {
        int cnt = 0;
        for (auto iter = st[i].begin(); iter != st[i].end(); iter++)
        {
            if (cnt == ((s / 2)))
            {
                middle[i] = *iter;
                break;
            }
            cnt++;
        }
    }
}

int move()
{
    for (int i = 0; i < l; i++)
    {
        auto first = st[i].begin();
        auto last = --st[i].end();
        auto mid = st[i].find(middle[i]);

        // 마찬가지로 middle값 갱신해줘야함
        if (i == 0)
        {
            if (Compare(*mid, *(--st[i + 1].end()))) movelr[i] = 0;
            else movelr[i] = -1;

            tmp[i + 1].push(*first);
        }
        else if (i == l - 1)
        {
            if (Compare(*mid, *(st[i - 1].begin()))) movelr[i] = -1;
            else movelr[i] = 1;

            tmp[i - 1].push(*last);
        }
        else
        {
            auto leftlast = st[i - 1].begin();
            auto rightfirst = --st[i + 1].end();

            if (Compare(*mid, *leftlast))
            {
                if (Compare(*mid, *rightfirst)) movelr[i] = 0;
                else movelr[i] = -1;
            }
            else
            {
                if (Compare(*mid, *rightfirst)) movelr[i] = -1;
                else movelr[i] = 1;
            }

            tmp[i - 1].push(*last);
            tmp[i + 1].push(*first);
        }
    }

    int sum = 0;
    for (int i = 0; i < l; i++)
    {
        // move는 꼬이니까 넣기전에 빼자
        if (i == 0) st[i].erase(*(st[i].begin()));
        else if (i == l - 1) st[i].erase(*(--st[i].end()));
        else
        {
            st[i].erase(*st[i].begin());
            st[i].erase(*(--st[i].end()));
        }

        while (!tmp[i].empty())
        {
            sum += tmp[i].front().id;
            st[i].insert(tmp[i].front());
            tmp[i].pop();
        }

        auto mid = st[i].find(middle[i]);

        if (movelr[i] == 0) middle[i] = *(++mid);
        else if (movelr[i] == 1) middle[i] = *(--mid);
    }

    return sum;
}

int trade()
{
    for (int i = 0; i < l; i++)
    {
        auto first = --st[i].end();
        auto mid = st[i].find(middle[i]);

        if (i == 0)
        {
            auto rightfirst = --st[i + 1].end();

            if (Compare(*mid, *rightfirst)) movelr[i] = 0;
            else movelr[i] = 1;

            tmp[i + 1].push(*mid);
        }
        else if (i == l - 1)
        {
            auto leftmid = st[i - 1].find(middle[i - 1]);

            if (Compare(*mid, *leftmid)) movelr[i] = -1;
            else movelr[i] = 1;

            tmp[i - 1].push(*first);
        }
        else
        {
            auto leftmid = st[i - 1].find(middle[i - 1]);
            auto rightfirst = --st[i + 1].end();

            if (Compare(*mid, *leftmid))
            {
                if (Compare(*mid, *rightfirst)) movelr[i] = 0;
                else movelr[i] = 1;
            }
            else
            {
                if (Compare(*mid, *rightfirst)) movelr[i] = 1;
                else movelr[i] = 3;
            }

            tmp[i - 1].push(*first);
            tmp[i + 1].push(*mid);
        }
    }

    int sum = 0;
    for (int i = 0; i < l; i++)
    {
        // 앞은 먼저 빼야함
        if (i != 0) st[i].erase(*(--st[i].end()));

        while (!tmp[i].empty())
        {
            sum += tmp[i].front().id;

            st[i].insert(tmp[i].front());
            tmp[i].pop();
        }

        // 일단 다 넣고
        // 기존 middle을 기준으로 movelr 가지고 middle 업데이트
        // 기존 middle 삭제
        auto mid = st[i].find(middle[i]);
        Player ptmp = *mid;

        if (movelr[i] == 0) middle[i] = *(++mid);
        else if (movelr[i] == 1) middle[i] = *(--mid);
        else if (movelr[i] == 2)
        {
            ++mid;
            middle[i] = *(++mid);
        }
        else if (movelr[i] == 3)
        {
            --mid;
            middle[i] = *(--mid);
        }
        else continue;

        if (i != l - 1) st[i].erase(ptmp);
    }

    return sum;
}