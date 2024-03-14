#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b)
{
    return a.first < b.first;
}

int n, k;
long long answer = 0;
int bags[300001];
pair<int, int> jewels[300001];
priority_queue<int> pq;

int main()
{
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> jewels[i].first >> jewels[i].second;
    }

    for (int i = 0; i < k; i++)
    {
        cin >> bags[i];
    }

    sort(jewels, jewels + n, compare);
    sort(bags, bags + k);

    int idx = 0;
    for (int i = 0; i < k; i++)
    {
        while (idx < n && bags[i] >= jewels[idx].first)
        {
            pq.push(jewels[idx].second);
            idx++;
        }
        if (!pq.empty())
        {
            answer += pq.top();
            pq.pop();
        }
    }


    cout << answer;


    return 0;
}