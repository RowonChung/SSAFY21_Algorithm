n = int(input())

graph = []
for i in range(n):
    graph.append(list(map(int, input().split())))

memo = [[0 for i in range(n)] for j in range(n)]

memo[0][0] = graph[0][0]


dy = [-1,-1]
dx = [-1, 0]
for y in range(1, n):
    for x in range(y+1):
        for i in range(2):
            py = y+dy[i]
            px = x+dx[i]
            if px<0:
                continue
            memo[y][x] = max(memo[y][x], memo[py][px]+graph[y][x])

print(max(memo[n-1]))
