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

#define div 1000000007
int N, M, K, input, a, b, c;
long long tree[2000001];

void init() {
    for (int i = N - 1; i > 0; --i) tree[i] = tree[i << 1] * tree[i << 1 | 1] % div;
}

void update(int loc, long long val) {
    for (tree[loc += N] = val; loc > 1; loc >>= 1) tree[loc >> 1] = tree[loc] * tree[loc ^ 1] % div;
}

long long query(int l, int r) {
    long long temp = 1;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l & 1) temp = temp * tree[l++] % div;
        if (r & 1) temp = temp * tree[--r] % div;
    }
    return temp;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    for (int i = N; i < 2 * N; i++) {
        cin >> tree[i];
    }
    init();


    for (int i = 0; i < M + K; i++) {
        cin >> a >> b >> c;

        if (a == 1) update(b - 1, c);
        else if (a == 2) cout << query(b - 1, c) << '\n';
    }
}