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

int N, M, K, a, b;
long long c, tree[2000001];

void init() {
    for (int i = N - 1; i > 0; i--) {
        tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }
}

void update(int p, long long val) {
    for (tree[p += N] = val; p > 1; p >>= 1) {
        tree[p >> 1] = tree[p] + tree[p ^ 1];
    }
}

long long query(int l, int r) {
    long long sum = 0;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l & 1) sum += tree[l++];
        if (r & 1) sum += tree[--r];
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        cin >> tree[N + i];
    }
    init();
    for (int i = 0; i < M + K; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            update(b - 1, c);
        }
        else if (a == 2) {
            cout << query(b - 1, c) << '\n';
        }
    }
}