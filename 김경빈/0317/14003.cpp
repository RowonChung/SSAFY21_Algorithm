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

int N, input, nums[1000001], dp[1000001], temp_dp, idx;
vector<int> v, ans;
vector<int>::iterator iter;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> input;
        nums[i] = input;
        if (v.size() == 0) {
            v.push_back(input);
            dp[i] = 1;
        }
        else {
            if (v[v.size() - 1] < input) {
                v.push_back(input);
                dp[i] = v.size();
            }
            else {
                iter = lower_bound(v.begin(), v.end(), input);
                *(iter) = input;
                dp[i] = iter - v.begin() + 1;
            }
        }
        if (dp[i] > temp_dp) {
            idx = i;
            temp_dp = dp[i];
        }
    }

    cout << v.size() << '\n';
    ans.push_back(nums[idx]);
    for (int i = idx - 1; i >= 0; i--) {
        if (nums[i] < nums[idx] && dp[i] + 1 == dp[idx]) {
            idx = i;
            ans.push_back(nums[i]);
        }
    }
    while (!ans.empty()) {
        cout << ans.back() << " ";
        ans.pop_back();
    }
}