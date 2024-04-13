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

long long A, B, C;

long long div_num(long long b) {
    if (b == 0) return 1;
    if (b == 1) return A % C;

    long long ret = div_num(b / 2);

    if (b % 2) return ret * ret * A % C;
    else return ret * ret % C;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> B >> C;
    A %= C;
    cout << div_num(B);
}