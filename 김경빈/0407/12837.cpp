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

long long N, Q, comm, p, q, arr[2000001];

void update(int loc, int val) {
    for (arr[loc += N] += val; loc > 1; loc >>= 1) arr[loc >> 1] = arr[loc] + arr[loc ^ 1];
}

long long query(int l, int r) {
    long long sum = 0;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l & 1) sum += arr[l++];
        if (r & 1) sum += arr[--r];
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> comm >> p >> q;
        if (comm == 1) {
            update(p - 1, q);
        }
        else if (comm == 2) {
            cout << query(p - 1, q) << '\n';
        }
    }
}