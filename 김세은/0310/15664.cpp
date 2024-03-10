#include <iostream>
#include <vector>

using namespace std;

vector<int> nums;
vector<int> result;

void backtracking(int N, int M, int index) {
    if (result.size() == M) {
        for (int num : result) {
            cout << num << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = index; i < N; ++i) {
        result.push_back(nums[i]);
        backtracking(N, M, i);
        result.pop_back();
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    sort(nums.begin(), nums.end());

    backtracking(N, M, 0);

    return 0;
}
