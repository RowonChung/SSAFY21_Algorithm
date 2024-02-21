#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> nums;
vector<int> result;
int visited[9] = { 0, };

void run(int M) {
   
    if (result.size() == M) {
        for (int num : result) {
            cout << num << " ";
        }
        cout << "\n";
        return;
    }

   
    for (int i = 0; i < nums.size(); ++i) {
        
        if (visited[i] != 0) continue;
        result.push_back(nums[i]);
        visited[i] = 1;
        run(M);

       
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

    run(M);

    return 0;
}
