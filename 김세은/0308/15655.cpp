#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> nums;
vector<int> result;
int visited[9] = { 0, };

void run(int M, int start) {
   
    if (result.size() == M) {
        for (int num : result) {
            cout << num << " ";
        }
        cout << "\n";
        return;
    }

   
    for (int i = start; i < nums.size(); ++i) {
        
        if (visited[i] != 0) continue;
        result.push_back(nums[i]);
        visited[i] = 1;
        run(M, i); // i번째 이후의 숫자들만을 고려하여 순열을 생성하도록 수정
       
        result.pop_back();
        visited[i] = 0;
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

    run(M, 0); // 시작 인덱스를 0으로 설정

    return 0;
}

