#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

ll t;
int n, m;

ll a[1010], b[1010];
vector<ll> aSub, bSub;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	

	cin >> t >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}

	for (int i = 0; i < n; i++) {
		int sum = a[i];
		aSub.push_back(sum);
		for (int j = i + 1; j < n; j++) {
			sum += a[j];
			aSub.push_back(sum);
		}
	}
	for (int i = 0; i < m; i++) {
		int sum = b[i];
		bSub.push_back(sum);
		for (int j = i + 1; j < m; j++) {
			sum += b[j];
			bSub.push_back(sum);
		}
	}

	sort(bSub.begin(), bSub.end());

	ll ans = 0;
	for (int i = 0; i < aSub.size(); i++) {
		ll tar = t - aSub[i];
		ll lowerBound = lower_bound(bSub.begin(), bSub.end(), tar) - bSub.begin();
		ll upperBound = upper_bound(bSub.begin(), bSub.end(), tar) - bSub.begin();
		ans += (upperBound - lowerBound);
	}
	cout << ans;

}
