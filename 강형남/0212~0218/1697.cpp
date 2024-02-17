#include <iostream>
#include <queue>
using namespace std;
int n, k;
bool visited[100001];
struct node {
    int x;
    int cnt;
};
void fun(int a) {
    queue<node> q;
    q.push({ a,0 });
    while (!q.empty()) {
        node next = q.front();
        q.pop();
        if (next.x == k) {
            cout << next.cnt;
            break;
        }
        if (next.x + 1 >= 0 && next.x + 1 < 100001) {
            if (!visited[next.x + 1]) {
                visited[next.x + 1] = 1;
                q.push({next.x+1,next.cnt+1});
            }
        }
        if (next.x - 1 >= 0 && next.x - 1 < 100001) {
            if (!visited[next.x - 1]) {
                visited[next.x - 1] = 1;
                q.push({ next.x - 1,next.cnt + 1 });
            }
        }
        if (2 * next.x >= 0 && 2 * next.x < 100001) {
            if (!visited[2 * next.x]) {
                visited[2 * next.x] = 1;
                q.push({ next.x*2 ,next.cnt + 1 });
            }
        }
    }
}
int main() {
    cin >> n >> k;
    visited[n] = 1;
    fun(n);
    return 0;
}