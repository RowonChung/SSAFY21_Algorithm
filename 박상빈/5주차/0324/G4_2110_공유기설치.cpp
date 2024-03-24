#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

int n, c;
set<int> homes;

// 앞에서부터 놓아보면서 체크
int check(int gap)
{
    int before = *homes.begin();
    int cnt = 1;
    int mini = 21e8;

    auto iter = homes.begin();
    iter++;

    while(iter != homes.end())
    {
        if (*iter - before >= gap)
        {
            if (mini > *iter - before) mini = *iter - before;
            before = *iter;
            cnt++;
        }

        iter++;
    }

    if (cnt >= c) return mini;
    else return -1;
}

int bs(int start, int end)
{
    int mid;
    int result = 0;

    while (start <= end)
    {
        mid = (start + end) / 2;

        int res = check(mid);

        if (res == -1)
        {
            end = mid - 1;
        }
        else
        {
            result = res;
            start = mid + 1;
        }
    }

    return result;
}

int main()
{
    cin >> n >> c;

    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;

        homes.insert(input);
    }

    cout << bs(0, 1000000000);


    return 0;
}