#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
vector<int> ip;
string ans1, ans2;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;

        int idx1 = input.find(".", 0);
        int idx2 = input.find(".", idx1 + 1);
        int idx3 = input.find(".", idx2 + 1);

        string num1 = input.substr(0, idx1);
        string num2 = input.substr(idx1 + 1, idx2 - (idx1 + 1));
        string num3 = input.substr(idx2 + 1, idx3 - (idx2 + 1));
        string num4 = input.substr(idx3 + 1, input.size() - (idx3 + 1));

        int this_num = (stoi(num1) << 24) + (stoi(num2) << 16) + (stoi(num3) << 8) + stoi(num4);

        ip.push_back(this_num);
    }

    int diff = -1;

    for (int i = 31; i >= 0; i--) {
        for (int j = 1; j < n; j++) {
            int left = ip[j - 1];
            int right = ip[j];

            if ((left & (1 << i)) != (right & (1 << i))) {
                diff = i;
                break;
            }
        }

        if (diff != -1)
            break;
    }

    int network = 0;
    int subnetMask = 0;

    if (diff == -1) {
        subnetMask = (1U << 32) - 1;
        network = subnetMask & ip[0];
    }
    else {
        for (int i = 31; i > diff; i--) {
            subnetMask |= (1U << i);
        }

        network = subnetMask & ip[0];
    }


    for (int i = 0; i < 4; i++) {
        int check = (1U << 8) - 1;

        int ans1_number = (network & check);
        int ans2_number = (subnetMask & check);

        ans1 = to_string(ans1_number) + "." + ans1;
        ans2 = to_string(ans2_number) + "." + ans2;

        network = (network >> 8);
        subnetMask = (subnetMask >> 8);
    }

    ans1.pop_back();
    ans2.pop_back();

    cout << ans1 << "\n" << ans2;
}
