#include <iostream>
#include <string>
using namespace std;

int arr[10001] = { 0, };
int remember = 0;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n, m; cin >> n >> m;
	// 26개의 1로 만듬
	for (int i = 0; i < 26; i++) remember |= (1 << i);

	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		// 배열에 순서대로 알파벳 순서에 1 저장
		// 알파벳 순서만큼 1 밀고 or(|)
		for (int j = 0; j < s.length(); j++) {
			arr[i] |= (1 << (s[j] - 'a'));
		}
	}

	for (int i = 0; i < m; i++) {
		int o;
		char x;
		cin >> o >> x;

		// 알파벳 순서만큼 1 밀고
		// 1은 잊어버리니 not(~)과 and(&)
		// 2는 다시 기억하니 or(|)
		if (o == 1) remember &= ~(1 << (x - 'a'));
		else remember |= (1 << (x - 'a'));

		int cnt = 0;
		for (int j = 0; j < n; j++) {
			// 기억하는 알파벳과 arr[j]를 and(&)
			// 결과가 arr[j]와 같으면 기억 O -> 개수++
			if ((arr[j] & remember) == arr[j]) cnt++;
		}
		cout << cnt << '\n';
	}
	return 0;
}