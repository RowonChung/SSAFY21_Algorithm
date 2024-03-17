#include <iostream>
#include <queue>
using namespace std;

struct NODE {
    int number;
    int Time;
    bool operator <(const NODE& n) const {
        return Time > n.Time;
    }
};

int n, m;
int stick[101];
int snake[101];
bool visit[101];


bool isRange(int number) {
    if (1 <= number && number <= 100) {
        return true;
    }
    return false;
}

int bfs() {
    priority_queue<NODE> pq;
    visit[1] = true;
    pq.push({ 1,0 });
    while (!pq.empty()) {
        NODE current = pq.top();
        if (current.number == 100) {
            return current.Time;
        }
        pq.pop();
        int next;
        for (int i = 1; i <= 6; i++) {
            next = current.number + i;
            if (isRange(next) && visit[next] == 0) {
                if (stick[next] != 0) {
                    visit[next] = true;
                    visit[stick[next]] = true;
                    pq.push({ stick[next], current.Time + 1 });
                }
                else if(snake[next] != 0) {
                    visit[next] = true;
                    visit[snake[next]] = true;
                    pq.push({ snake[next], current.Time + 1 });
                }
                else {
                    pq.push({ next, current.Time + 1 });
                    visit[next] = true;
                }

            }
        }
    }
    return -1;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        stick[a] = b;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        snake[a] = b;
    }
    cout << bfs();
}
