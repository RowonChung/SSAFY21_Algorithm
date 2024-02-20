#include <iostream>
using namespace std;

const int MAX_N = 100100;

int arr[MAX_N], n, k, m;
int cases, each_case = 1;

int find(int tar) {
  if (tar == arr[tar])
    return tar;
  int ret = find(arr[tar]);
  arr[tar] = ret;
  return ret;
}

void setUnion(int a, int b) {
  int t1 = find(a);
  int t2 = find(b);
  if (t1 == t2)
    return;
  if (t1 < t2)
    arr[t2] = t1;
  else if (t1 > t2)
    arr[t1] = t2;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> cases;
  while (each_case <= cases) {
    cout << "Scenario " << each_case << ":\n";
    cin >> n;
    for (int i = 1; i <= n; i++)
      arr[i] = i;
    cin >> k;
    for (int i = 0; i < k; i++) {
      int n1, n2;
      cin >> n1 >> n2;
      setUnion(n1, n2);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
      int in1, in2;
      cin >> in1 >> in2;
      if (find(in1) == find(in2))
        cout << "1\n";
      else
        cout << "0\n";
    }
    each_case++;
    cout << "\n";
  }

  return 0;
}
