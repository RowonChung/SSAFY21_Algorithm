#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node { int y, x; };
int N, M;
int cityOriginal[50][50];
int dist[13][100];
vector<Node> houses;
vector<Node> chickens;

int getDist(Node from, Node to) {
    int dy = abs(from.y - to.y);
    int dx = abs(from.x - to.x);
    return dy + dx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> cityOriginal[y][x];
            if (cityOriginal[y][x] == 1) {
                houses.push_back({ y,x });
            }
            if (cityOriginal[y][x] == 2) {
                chickens.push_back({ y,x });
                cityOriginal[y][x] == 0;
            }
        }
    }
    for (int y = 0; y < chickens.size(); y++) {
        for (int x = 0; x < houses.size(); x++) {
            dist[y][x] = getDist(chickens[y], houses[x]);
        }
    }
    
    vector<int> n;
    for (int i = 0; i < chickens.size(); i++) {
        n.push_back(i);
    }

    vector<int> ind;

    for (int i = 0; i < n.size() - M; i++) {
        ind.push_back(0);
    }
    for (int i = 0; i < M; i++) {
        ind.push_back(1);
    }
    int minDist = 2134567890;
    do {
        vector<int> idx;
        for (int i = 0; i < n.size(); i++) {
            if (ind[i] == 1) {
                idx.push_back(i);
            }
        }
        int de = -1;
        int sumHouse = 0;
        for (int x = 0; x < houses.size(); x++) {
            int minHouse = 2134567890;
            for (int i : idx) {
                minHouse = min(minHouse, dist[i][x]);
            }
            sumHouse += minHouse;
        }
        minDist = min(minDist, sumHouse);
    } while (next_permutation(ind.begin(), ind.end()));

    cout << minDist;

    return 0;
}