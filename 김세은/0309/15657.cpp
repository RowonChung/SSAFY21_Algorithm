#include <iostream>
#include <algorithm>
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
        backtracking(N, M, i); // 현재 인덱스부터 시작하여 조합을 생성하도록 수정
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

    backtracking(N, M, 0); // 시작 인덱스를 0으로 설정

    return 0;
}

