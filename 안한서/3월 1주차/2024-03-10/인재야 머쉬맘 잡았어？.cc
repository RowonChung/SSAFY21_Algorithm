#include <iostream>
#include <algorithm>
using namespace std;

int ans;
int A, B, X, Y;

void hunt(int a, int b, int x, int turn) {
	// 버프 결과 공격력이 100000 이상 되는 지점 -> 상한선
	// 상한선 만큼 반격을 시도한 체력 초과 -> 상한선
	if (a > 22875475) return;
	// 몬스터 죽였으면 횟수 갱신
	if (x <= 0) { ans = min(ans, turn); return; }

	int hp = a, atk = b, buff = 0;
	while (1) {
		// 현재 공격력으로 공격만 했을 때 걸리는 횟수
		int cnt = (x + atk - 1) / atk; 
		// 현재 공격력으로 안죽고 죽일 수 있으면 갱신 (버프 + 공격 횟수 더해서)
		if (hp - (Y * (cnt - 1)) > 0) ans = min(ans, turn + cnt + buff);

		// 상한선 넘거나, 버프 결과가 같으면 종료
		if (atk == (atk + (atk / 5)) || atk > 100000) break;

		// 버프 진행
		atk += (atk / 5); hp -= (3 * Y); buff++;
		// 인재가 죽으면 종료
		if (hp <= 0) break;
	}
	// 반격 진행
	hunt(a + a / 10, b, x - Y, turn + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> A >> B >> X >> Y;
	// 반격만 진행하는 경우 -> 최대
	ans = (X + Y - 1) / Y;
	// 사냥 진행
	hunt(A, B, X, 0);
	cout << ans;
	return 0;
}
