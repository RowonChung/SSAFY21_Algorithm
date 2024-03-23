from sys import stdin
input = stdin.readline

n, m = map(int, input().split())

graph = []
for i in range(n):
    tmp = list(map(int, input().split()))
    graph.append(tmp)
    
memo = [[0 for i in range(n+1)] for j in range(n+1)]

for i in range(1, n+1):
    for j in range(1, n+1):
        memo[i][j] = memo[i][j-1]+memo[i-1][j]-memo[i-1][j-1]+graph[i-1][j-1]
        
for i in range(m):
    x1, y1, x2, y2 = map(int,input().split())
    ans = memo[x2][y2]-memo[x2][y1-1]-memo[x1-1][y2]+memo[x1-1][y1-1]
    print(ans)
  
