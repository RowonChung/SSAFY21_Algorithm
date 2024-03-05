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

long long N, A, a[1001], B, b[1001], ans;
unordered_map<long long, long long> um1, um2;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    cin >> A;
    for (int i = 1; i <= A; i++) {
        cin >> a[i];
        if (i > 0) a[i] += a[i - 1];
    }
    cin >> B;
    for (int i = 1; i <= B; i++) {
        cin >> b[i];
        if (i > 0) b[i] += b[i - 1];
    }
    for (int i = 0; i < A; i++) {
        for (int j = i + 1; j <= A; j++) {
            um1[a[j] - a[i]]++;
        }
    }
    for (int i = 0; i < B; i++) {
        for (int j = i + 1; j <= B; j++) {
            um2[b[j] - b[i]]++;
        }
    }

    for (auto iter : um1) {
        if (um2.count(N-iter.first) == 0) continue;
        ans += iter.second * um2[N-iter.first];
    }
    cout << ans;
}