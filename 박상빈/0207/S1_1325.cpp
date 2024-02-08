#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Node
{
    int cnt;
    int num;
    bool operator<(Node right) const
    {
        // 같은 cnt 를 가진다면 num 기준 오름차순으로 뽑아내야함
        if (cnt == right.cnt) return num > right.num;
        return cnt < right.cnt;
    }
};

int n, m;
vector<int> alis[10001];
priority_queue<Node> pq;

void BFS(int num)
{
    // bfs로 갈 수 있는 곳 까지 진행
    int size = 0;
    queue<int> que;

    bool visited[10001] = { false, };

    que.push(num);
    visited[num] = true;

    while(!que.empty())
    {
        int now = que.front();
        que.pop();

        size++;

        for(int i=0;i<alis[now].size();i++)
        {
            if (!visited[alis[now][i]])
            {

                visited[alis[now][i]] = true;

                que.push(alis[now][i]);
            }
        }
    }

    // 최종적으로 num, size를 가지고 pq 삽입
    pq.push({ size, num });
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);


    // graph
    // 시작 번호를 기준으로 얼마나 많은 컴퓨터까지 들어갈 수 있는가 ?

    // a 가 b 를 신뢰하는 경우 b 를 해킹하면 a 도 해킹 가능하다
    // b -> a 로만 진행가능
    // 단방향이네

    cin >> n >> m;

    for(int i=0;i<m;i++)
    {
        int a, b;
        cin >> a >> b;

        alis[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) BFS(i);

    int MAX = pq.top().cnt;

    while(!pq.empty())
    {
        if (pq.top().cnt == MAX)
        {
            cout << pq.top().num << " ";
        }
        else break;
        pq.pop();
    }


    return 0;
}