#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct candidate {
    int Ascore;
    int Bscore;
    bool operator<(candidate right) const {
        return Ascore < right.Ascore;
    }
};

int t, n;
vector<candidate> vec;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    for(int idx = 0; idx < t; idx++)
    {
        cin >> n;
        vec.clear();

        for(int i=0;i<n;i++)
        {
            int a, b;

            cin >> a >> b;

            vec.push_back({a, b});
        }

        sort(vec.begin(), vec.end());

        // 차례대로 앞을 다 비교하면 늦는다
        // 스택에 쌓으면 어떨까 ? top 보다 작은 경우에만 뽑을 수 있는거지

        stack<int> answer;

        for(int i=0;i<n;i++)
        {
            if (answer.empty()) answer.push(vec[i].Bscore);
            else{
                if (answer.top() > vec[i].Bscore) answer.push(vec[i].Bscore);
            }
        }

        cout << answer.size() << "\n";
    }
    
    

    return 0;
}