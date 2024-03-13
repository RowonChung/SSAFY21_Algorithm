#include <iostream>
#include <cstring>
using namespace std;

int N, M;
int alis[101][101];
int dist[101][101];
int INF = 2134567890;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        if (alis[from][to] == 0) alis[from][to] = cost;
        else alis[from][to] = min(alis[from][to], cost);
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) dist[i][j] = 0;
            else if (alis[i][j]) dist[i][j] = alis[i][j];
            else dist[i][j] = INF;
        }
    }
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                int a = dist[i][k];
                int b = dist[k][j];
                int c;
                if (a == INF || b == INF) c = INF;
                else c = a + b;
                dist[i][j] = min(dist[i][j], c);
            }
        }
    }
    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= N; x++) {
            if (dist[y][x] == INF) cout << 0 << " ";
            else cout << dist[y][x] << " ";
        }
        cout << "\n";
    }

    return 0;
}