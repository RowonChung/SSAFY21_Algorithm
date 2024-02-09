#include <cmath>
#include <iostream>
using namespace std;
typedef long long ll;

ll first[10010], second[10010];
ll total;
int n;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> first[i] >> second[i];
  }

  first[n] = first[0];
  second[n] = second[0];

  for (int i = 0; i < n; i++) {
    total += first[i] * second[i + 1];
    total -= second[i] * first[i + 1];
  }

  total = abs(total);

  cout.precision(1);
  cout << fixed << round(total * 10) / 20.0;
  return 0;
}
