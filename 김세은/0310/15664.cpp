#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> nums;
vector<int> result;

void backtracking(int N, int M, int index) {
    if (result.size() == M) {
        for (int i = 0; i < M; ++i) {
            cout << result[i] << " ";
        }
        cout << "\n";
        return;
    }

    int prev = -1;
    for (int i = index; i < N; ++i) {
        if (nums[i] != prev) {
            result.push_back(nums[i]);
            backtracking(N, M, i + 1);
            result.pop_back();
            prev = nums[i];
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    nums.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    backtracking(N, M, 0);

    return 0;
}
