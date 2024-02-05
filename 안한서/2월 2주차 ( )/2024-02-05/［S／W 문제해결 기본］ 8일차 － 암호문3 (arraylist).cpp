#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    for (int test_case = 1; test_case < 11; test_case++) {
        int n; cin >> n;
 
        vector<int> list;
        for (int i = 0; i < n; i++) {
            int pw; cin >> pw;
            list.push_back(pw);
        }
        int m; cin >> m;
        for (int i = 0; i < m; i++) {
            char command; cin >> command;
            int x, y, s;
            if (command == 'I') {
                cin >> x >> y;
                for (int idx = 0; idx < y; idx++) {
                    cin >> s;
                    list.insert(list.begin() + x + idx, s);
                }
            }
            else if (command == 'A') {
                cin >> y;
                for (int idx = 0; idx < y; idx++) {
                    cin >> s;
                    list.push_back(s);
                }
            }
            else {
                cin >> x >> y;
                for (int idx = 0; idx < y; idx++) list.erase(list.begin() + x);
            }
        }
        cout << "#" << test_case << ' ';
        for (int i = 0; i < 10; i++) cout << list[i] << ' ';
        cout << '\n';
    }
    return 0;
}
