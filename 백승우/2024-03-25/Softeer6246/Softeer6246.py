from sys import stdin
input = stdin.readline
from copy import deepcopy

n, m = map(int, input().split())

graph = []
for y in range(n):
    graph.append(list(map(int, input().split())))

m_spots = []
for i in range(m):
    y, x = map(int, input().split())
    m_spots.append([y-1, x-1])

global ans
ans = 0

def view(graph):
    print("=======")
    for y in range(n):
        print(graph[y])
    print("=======")



visited = [[0 for i in range(n)]for i in range(n)]
visited[m_spots[0][0]][m_spots[0][1]] = 1

dy = [-1,1,0,0]
dx = [0,0,-1,1]
# 분기점이 있는 DFS
def dfs(y, x, level):
    global ans
    #print(level)
    #view(visited)
    if level==m:
        ans+=1
        return
    for i in range(4):
        ny = y+dy[i]
        nx = x+dx[i]
        if ny>=n or ny<0 or nx>=n or nx<0: continue
        if graph[ny][nx]==1 or visited[ny][nx]==1: continue

        visited[ny][nx]=1
        if ny==m_spots[level][0] and nx==m_spots[level][1]:
            dfs(ny, nx, level+1)
        else:
            dfs(ny, nx, level)
        visited[ny][nx]=0

dfs(m_spots[0][0], m_spots[0][1], 1)

print(ans)
