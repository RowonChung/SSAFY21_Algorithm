/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;



	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		cin >> n;
		int flag = (1 << 10);
		int index = 1;
		while (1) {
			int temp = n * index;
			bool start = false;
			for (int mul = 1000000; 1 <= mul; mul /= 10) {
				if (temp / mul != 0) {
					start = true;
				}
				if (start) {
					flag |= (1 << (temp / mul));
					temp %= mul;
				}
			}
			if ((flag & ((1 << 10) - 1)) == (1 << 10) - 1) {
				cout << "#" << test_case << " " << n * index << endl;
				break;
			}
			index++;
		}
	}
	return 0;
}
