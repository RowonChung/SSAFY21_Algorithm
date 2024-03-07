#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str1, str2;
int arr[1001][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> str1 >> str2;
    for (int y = 0; y < str1.length(); y++) {
        for (int x = 0; x < str2.length(); x++) {
            if (str1[y] == str2[x]) {
                arr[y + 1][x + 1] = arr[y][x] + 1;
            }
            else {
                arr[y + 1][x + 1] = max(arr[y][x + 1], arr[y + 1][x]);
            }
        }
    }
    int ans = 0;
    for (int y = 1; y <= str1.length(); y++) {
        for (int x = 1; x <= str2.length(); x++) {
            ans = max(ans, arr[y][x]);
        }
    }
    cout << ans;

    return 0;
}