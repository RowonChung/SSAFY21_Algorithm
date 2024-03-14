#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;


int n, m, k, ans;
string arr[55];
unordered_map<string, int> cnt;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        cnt[arr[i]]++;
    }

    cin >> k;

    for (int i = 0; i < n; ++i) {
        int zeroCnt = 0;
        for (char c : arr[i]) {
            if (c == '0') zeroCnt++;
        }

        if (zeroCnt <= k && zeroCnt % 2 == k % 2) {
            ans = max(ans, cnt[arr[i]]);
        }
    }

    cout << ans;
}
