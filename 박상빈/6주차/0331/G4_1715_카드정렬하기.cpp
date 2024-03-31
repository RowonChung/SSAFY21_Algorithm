#include <iostream>
#include <queue>

using namespace std;

struct Card
{
    int num;
    bool operator<(Card right) const
    {
        return num > right.num;
    }
};

priority_queue<Card> pq;

int main() {

    int n;

    cin >> n;

    for(int i=0;i<n;i++)
    {
        int input;
        cin >> input;

        pq.push({ input });
    }

    int answer = 0;

    while(!pq.empty())
    {
        if (pq.size() == 1) break;

        int a = pq.top().num;
        pq.pop();
        int b = pq.top().num;
        pq.pop();

        answer += (a + b);
        pq.push({ a + b });
    }

    cout << answer;


    return 0;
}
