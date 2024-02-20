n = int(input())
data = list(map(int, input().split()))
end = max(data)

memo = {}
for num in data:
    memo[num] = 0

for num in data:
    for next_num in range(num*2, end+1, num):
        if next_num in memo:
            memo[num] += 1
            memo[next_num] -= 1

for num in data:
    print(memo[num], end=" ")
