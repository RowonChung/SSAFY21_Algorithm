#include <iostream>
#include <map>
using namespace std;

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test_case;
	int T;
	
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		map<string, int> map;
		int n, m;
		int cnt = 0;
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			string s;
			cin >> s;
			map.insert({ s,i });
		}
		for (int i = 1; i <= m; i++) {
			string s;
			cin >> s;
			if (map.find(s) != map.end()) {
				cnt++;
			}
		}
		cout << "#" << test_case << " " << cnt << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
