from itertools import combinations_with_replacement

n, m = map(int, input().split())
data = set(list(map(int, input().split())))

ans = []
for each in combinations_with_replacement(data, m):
    ans.append(sorted(each))

ans.sort()
for each in ans:
    print(*each)
