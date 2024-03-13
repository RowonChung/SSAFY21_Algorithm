#include <iostream>
using namespace std;

int n, ans = 1, curr, before, cnt = 1;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> n >> before;

    while (--n) {
        cin >> curr;

        if (curr < before) {
            ++cnt;
        }
        else {
            ans = max(ans, cnt);
            cnt = 1;
            before = curr;
        }
    }

    cout << max(ans, cnt);
}
