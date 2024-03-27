#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

string a, b;
int dp[1010][1010];
vector<char> v;
int val;

int main() {
    cin >> a >> b;

    for (int i = 0; i < a.length(); i++) {
        for (int j = 0; j < b.length(); j++) {
            if (a[i] == b[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }
            else {
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }
    cout << dp[a.length()][b.length()] << "\n";

    val = dp[a.length()][b.length()];
    for (int i = a.length(), j = b.length(); i > 0 && j > 0;) {
        if (a[i - 1] == b[j - 1] && dp[i][j] == val) {
            v.push_back(a[i - 1]);
            val--, i--, j--;
        }
        else {
            if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            }
            else {
                j--;
            }
        }
    }
    for (int i = v.size() - 1; i >= 0; i--) {
        cout << v[i];
    }
}
