#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int arr[100001];
int sums[100001];
int n;

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];

        sums[i] = sums[i - 1] + arr[i];
    }

    int answer = -21e8;

    for (int i = 2; i < n; i++) {
        // 벌 벌 통
        // 벌하나 왼쪽 고정
        // 통 오른쪽 고정
                        // 왼쪽 고정 벌              // 움직이는 벌
        int now = (sums[n] - sums[1] - arr[i]) + (sums[n] - sums[i]);
        answer = max(answer, now);

        // 벌 통 벌
        // 벌이 양 끝 고정
            // 왼쪽 고정 벌            // 오른쪽 고정 벌
        now = (sums[i] - sums[1]) + (sums[n - 1] - sums[i - 1]);
        answer = max(answer, now);

        // 통 벌 벌
        // 벌하나 오른쪽 고정
        // 통 왼쪽 고정
                    // 오른쪽 고정 벌       // 움직이는 벌
        now = (sums[n - 1] - arr[i]) + sums[i - 1];
        answer = max(answer, now);
    }

    cout << answer;

    return 0;
}