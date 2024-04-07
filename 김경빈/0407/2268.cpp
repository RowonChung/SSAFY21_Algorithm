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
#include <stdio.h>
using namespace std;

long long N, M, arr[2000001], comm, a, b;

void update(long long loc, long long val) {
    for (arr[loc += N] = val; loc > 1; loc >>= 1) arr[loc >> 1] = arr[loc] + arr[loc ^ 1];
}

long long query(long long l, long long r) {
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

    cin >> N >> M;
    for (long long i = 0; i < M; i++) {
        cin >> comm >> a >> b;
        if (comm == 0) {
            if (a > b) {
                long long temp = a;
                a = b;
                b = temp;
            }
            cout << query(a - 1, b) << '\n';
        }
        else if (comm == 1) {
            update(a - 1, b);
        }
    }
}