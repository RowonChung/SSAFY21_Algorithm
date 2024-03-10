#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, N, M;
int A[1001], B[1001];

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> T >> N;
	for (int i = 0; i < N; i++) 
        cin >> A[i];
	cin >> M;
	for (int i = 0; i < M; i++) 
        cin >> B[i];

	vector<int> aSum, bSum;
	
	for (int i = 0; i < N; i++) {
		int sum = A[i];
		aSum.push_back(sum);
		for (int j = i + 1; j < N; j++) {
			sum += A[j];
			aSum.push_back(sum);
		}
	}

	for (int i = 0; i < M; i++) {
		int sum = B[i];
		bSum.push_back(sum);
		for (int j = i + 1; j < M; j++) {
			sum += B[j];
			bSum.push_back(sum);
		}
	}

	sort(bSum.begin(), bSum.end());
	long long ans = 0;
	for (int i = 0; i < aSum.size(); i++) {
		int target = T - aSum[i];
		int lo = lower_bound(bSum.begin(), bSum.end(), target) - bSum.begin();
		int hi = upper_bound(bSum.begin(), bSum.end(), target) - bSum.begin();
		ans += (hi - lo);
	}

	cout << ans;

	return 0;
}