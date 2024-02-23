from sys import stdin
input = stdin.readline

n = int(input())
data = input().split()

# Manacher's Algorithm
mana_string = [0] * (2 * n + 1)
length = len(mana_string)

for i in range(1, length, 2):
	mana_string[i] = data[(i-1)//2]

memo = [0] * length
r, p = 0, 0

for i in range(length):
    if i <= r:
        memo[i] = min(memo[2 * p - i], r - i)
    while i + memo[i] + 1 < length and mana_string[i - memo[i] - 1] == mana_string[i + memo[i] + 1]:
        memo[i] += 1
    if i + memo[i] > r:
        r, p = i + memo[i], i


m = int(input().strip())
for i in range(m):
    s, e = map(int, input().split())
    if memo[s + e - 1] >= e - s: print(1)
    else: print(0)
