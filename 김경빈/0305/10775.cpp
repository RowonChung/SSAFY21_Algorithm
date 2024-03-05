#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <climits>
#include <unordered_map>
using namespace std;

int G, P, p, cnt, g[100001];
queue<int> plane;

int find_parent(int a) {
    if (a == 0) return g[a] = - 1;
    if (a == g[a]) return g[a] = a-1;
    return g[a] = find_parent(g[a]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> G;
    cin >> P;
    for (int i = 0; i <= G; i++) {
        g[i] = i;
    }
    for (int i = 0; i < P; i++) {
        cin >> p;
        plane.push(p);
    }
    while (!plane.empty()) {
        int pp = plane.front();
        plane.pop();

        if (find_parent(pp) == -1) break;
        cnt++;
    }
    cout << cnt;
}