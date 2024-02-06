#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> arr;
vector<int> check;

int findMax(int a, int b)
{
    while(b)
    {
        int n = a % b;
        a = b;
        b = n;
    }

    return a;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);


    // arr[1] - arr[0]
    // arr[2] - arr[0]
    // ,,,

    cin >> n;

    for(int i=0;i<n;i++)
    {
        int input;

        cin >> input;

        arr.push_back(input);
    }

    sort(arr.begin(), arr.end());

    for(int i = 1;i<n;i++)
    {
        check.push_back(arr[i] - arr[i - 1]);
    }

    int answer = check[0];

    for(int i=1;i<check.size();i++)
    {
        answer = findMax(answer, check[i]);
    }


    cout << answer;



    return 0;
}