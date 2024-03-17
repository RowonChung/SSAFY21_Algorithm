#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> histogram(n);
    for (int i = 0; i < n; ++i) {
        cin >> histogram[i];
    }

    vector<int> left(n), right(n);
    stack<int> s;

    for (int i = 0; i < n; ++i) {
        while (!s.empty() && histogram[s.top()] >= histogram[i]) {
            s.pop();
        }
        left[i] = s.empty() ? 0 : s.top() + 1;
        s.push(i);
    }

    while (!s.empty()) s.pop();

    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && histogram[s.top()] >= histogram[i]) {
            s.pop();
        }
        right[i] = s.empty() ? n - 1 : s.top() - 1;
        s.push(i);
    }

    int maxArea = 0;
    for (int i = 0; i < n; ++i) {
        maxArea = max(maxArea, histogram[i] * (right[i] - left[i] + 1));
    }

    cout << maxArea << endl;

    return 0;
}