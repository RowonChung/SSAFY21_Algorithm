#include <iostream>
using namespace std;

int arr[3][3];
int emptyNum, sum;
bool notFound;

int findSum() {
  for (int i = 0; i < 3; i++) {
    if (arr[i][0] && arr[i][1] && arr[i][2])
      return arr[i][0] + arr[i][1] + arr[i][2];
    if (arr[0][i] && arr[1][i] && arr[2][i])
      return arr[0][i] + arr[1][i] + arr[2][i];
  }
  if (arr[0][0] && arr[1][1] && arr[2][2])
    return arr[0][0] + arr[1][1] + arr[2][2];
  if (arr[0][2] && arr[1][1] && arr[2][0])
    return arr[0][2] + arr[1][1] + arr[2][0];

  int maxSum = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      maxSum += arr[i][j];
    }
  }
  return maxSum / 2;
}

int findNumber(int x, int y) {
  int emptyRowCount = 0;
  int tmpSum = 0;

  for (int i = 0; i < 3; i++) {
    if (!arr[x][i]) emptyRowCount++;
    tmpSum += arr[x][i];
  }
  if (emptyRowCount == 1) return sum - tmpSum;

  emptyRowCount = 0;
  tmpSum = 0;
  for (int i = 0; i < 3; i++) {
    if (!arr[i][y]) emptyRowCount++;
    tmpSum += arr[i][y];
  }
  if (emptyRowCount == 1) return sum - tmpSum;

  if ((x + y) % 2 == 0) {
    emptyRowCount = 0;
    tmpSum = 0;
    for (int i = 0; i < 3; i++) {
      if (!arr[i][i]) emptyRowCount++;
      tmpSum += arr[i][i];
    }
    if (emptyRowCount == 1) return sum - tmpSum;

    emptyRowCount = 0;
    tmpSum = 0;
    for (int i = 0; i < 3; i++) {
      if (!arr[i][2 - i]) emptyRowCount++;
      tmpSum += arr[i][2 - i];
    }
    if (emptyRowCount == 1) return sum - tmpSum;
  }

  return -1;
}

void backtracking(int emptyCells) {
  if (notFound) return;
  if (emptyCells == 0) {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        cout << arr[i][j] << ' ';
      }
      cout << '\n';
    }
    notFound = true;
    return;
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (arr[i][j]) continue;
      int number = findNumber(i, j);
      if (number == -1) continue;
      arr[i][j] = number;
      backtracking(emptyCells - 1);
    }
  }
}

int main() {
  emptyNum = 0;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> arr[i][j];
      if (arr[i][j] == 0) emptyNum++;
    }
  }

  sum = findSum();
  backtracking(emptyNum);
}