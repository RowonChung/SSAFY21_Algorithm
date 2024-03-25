#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> cmp[32010];
vector<int> inDegree;

void topologySort(int n) {
    int ans[32010];
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) q.push(i);
    }
    int idx = 1; 
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        ans[idx++] = x; 
        for (int j = 0; j < cmp[x].size(); j++) {
            int y = cmp[x][j]; 
            if (--inDegree[y] == 0) {
                q.push(y);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    inDegree.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int str, dst;
        cin >> str >> dst;
        inDegree[dst]++;
        cmp[str].push_back(dst);
    }

    topologySort(n);
    return 0;
}
