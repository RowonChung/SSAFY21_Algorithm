from sys import stdin
input = stdin.readline
from collections import deque

def bfs(n, m, ladder, snake):
  visited = set()
  q = deque([(0, 1)])

  while q:
    level, pos = q.popleft()
    visited.add(pos)

    if pos == 100:
      return level

    for dice_roll in range(6, 0, -1):
      next_pos = pos + dice_roll
      if next_pos > 100:
        continue

      if next_pos not in visited:
        if next_pos in ladder:
          next_pos = ladder[next_pos]
        elif next_pos in snake:
          next_pos = snake[next_pos]
        q.append((level + 1, next_pos))

  return -1


n, m = map(int, input().split())
ladder = {}
for _ in range(n):
  x, y = map(int, input().split())
  ladder[x] = y

snake = {}
for _ in range(m):
  u, v = map(int, input().split())
  snake[u] = v

min_moves = bfs(n, m, ladder, snake)

print(min_moves)
