# 2961 with Bitmask
- make each case(1 as Use & 0 as UnUsed) by Bitmask
  - MAKE LOOP
  - SELECT EACH INDEX
  - CHECK IS IT USED 
```cpp
#include <iostream>
#include <algorithm>
using namespace std;

struct food {
	int sin;
	int ssen;
};

int n;
food foods[11];

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> foods[i].sin >> foods[i].ssen;
	}

	int ans = 1e9;
	/* MAKE LOOP : 1(00...001) ~2 ^ n - 1(11...111) */
	for (int i = 1; i < (1 << n); i++) {
		int sumSin = 1, sumSsen = 0;
		/* SELECT EACH INDEX */
		for (int index = 0; index <= n; index++) {
			/* CHECK IS IT USED: 1 for used & 0 for unused */
			if (i & (1 << index)) {
				int foodIndex = index + 1;
				sumSin *= foods[foodIndex].sin;
				sumSsen += foods[foodIndex].ssen;
			}
		}
		ans = min(ans, abs(sumSin - sumSsen));
	}
	cout << ans;

	return 0;
}
```
