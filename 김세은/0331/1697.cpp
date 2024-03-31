#include <iostream>
#include <queue>
using namespace std;

int N, K;
int dist[100001] = { 0, };
int visited[100001] = { 0, };
int cnt = 0;
void init() {
    for (int i = 0; i <= 100000; i++) {
        visited[i] = 21e8;
    }
}
void bfs(int node) {
    queue<int> q;    q.push(node);
    visited[node] = 0;

    while (!q.empty()) {
        int now = q.front();
        //if (now == K) cnt++;
        q.pop();

        for (int i = 0; i < 3; i++) {
            int next;
            if (i == 0) {
                next = now - 1;
                
            }
            if (i == 1) {
                next = now + 1;
                
            }
            if (i == 2) {
                next = now * 2;
                
            }
            if (next < -1 || next > 100001)continue;
            //if (visited[next] != 21e8)continue;
            if (visited[next] < visited[now] + 1)continue;
            visited[next] = visited[now] + 1;
            if (next == K)cnt++;
            q.push(next);
        }
    }

    
}
int main() {
    cin >> N >> K;

    init();
    
    if (N == K) {
        cout << 0 << "\n";

    }
    else {
        bfs(N);

        cout << visited[K] << "\n";
    }

}
