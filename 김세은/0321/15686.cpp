#include <iostream>
#include <queue>
using namespace std;

int N, M;
int path[14];
int visited[14] = { 0, };
vector <pair<int, int>> chicken;
queue <pair<int, int>> q1;
int ans = 21e8;
int dst(queue <pair<int, int>> q) {
    int dis = 0;
    int mdis = 21e8;
    //path 받으면 가장 가까운 거
    int dsum = 0;

    while (!q.empty()) {
        int r2 = q.front().first;
        int c2 = q.front().second;
        q.pop();
        mdis = 21e8;
        for (int i = 0; i < M; i++) {
            int r1 = chicken[path[i]].first;
            int c1 = chicken[path[i]].second;

            dis = abs(r1 - r2) + abs(c1 - c2);
            mdis = min(dis, mdis);

        }
        dsum += mdis;
    }
    return dsum;
}
void run(int level, int num) {


    if (level == M) {
        //for (int i = 0; i < M; i++) {
            //cout << path[i];
        //}
        //cout << dst(q1)<<" "<< "\n";
        ans = min(ans, dst(q1));
        return;
    }

    for (int i = num; i <= chicken.size() - 1; i++) {
        path[level] = i;
        run(level + 1, i + 1);
    }

}

int main() {

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int num;
            cin >> num;
            if (num == 1) q1.push({ i,j });
            if (num == 2) chicken.push_back({ i,j });
        }
    }

    run(0, 0);

    cout << ans;
}