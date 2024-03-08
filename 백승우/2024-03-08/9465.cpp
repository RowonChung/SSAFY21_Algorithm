#include <iostream>
#include <algorithm>
using namespace std;

int T;
int n;
int arr[2][100000];
int memo[2][100000];

void init(int n)
{
    for (int y = 0; y < 2; y++) {
        for (int x = 0; x < n; x++) memo[y][x] = 0;
    }
}

int getAnswer(int n)
{
    int ans = 0;
    for (int y = 0; y < 2; y++) {
        for (int x = 0; x < n; x++) ans = max(ans, memo[y][x]);
    }
    return ans;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> T;
    for (int testCase = 1; testCase <= T; testCase++) {
        cin >> n;
        init(n);
        for (int y = 0; y < 2; y++) {
            for (int x = 0; x < n; x++) cin >> arr[y][x];
        }

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < 2; y++) {
                int otherY = 0;
                if (y == 0) otherY = 1;

                int temp = 0;
                if (x - 2 >= 0) {
                    temp = max(temp, memo[y][x - 2]);
                    temp = max(temp, memo[otherY][x - 2]);
                }
                if (x - 1 >= 0) {
                    temp = max(temp, memo[otherY][x - 1]);
                }
                memo[y][x] = temp + arr[y][x];
            }
        }
        cout << getAnswer(n) << '\n';
    }
    return 0;
}
