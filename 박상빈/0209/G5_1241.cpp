#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int students[100001];
int cnt[1000001];
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 1000000 까지의 cnt 배열
    // 들어온 입력에 값 cnt ++

    // 입력된 수의 약수들 sum += cnt

    cin >> n;

    for(int i=0;i<n;i++)
    {
        cin >> students[i];
        
        cnt[students[i]]++;
    }

    for(int i=0;i<n;i++)
    {
        int sum = 0;
        // students[i] 최대 1000000 너무 큰데 ?
        for(int j=1;j*j<=students[i];j++)
        {
            if (students[i] % j == 0)
            {
                if (students[i]/j != j) sum += cnt[j] + cnt[students[i]/j];
                else sum += cnt[j];
            }
        }
        sum--;
        
        cout << sum << "\n";
    }
    

    return 0;
}