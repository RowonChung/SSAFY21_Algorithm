from sys import stdin
input = stdin.readline

n, s = map(int, input().split())
data = list(map(int, input().split()))

start, end = 0, 0
temp_sum = 0
min_length = 1e9

while True:
    if temp_sum >= s:
        min_length = min(min_length, end-start)
        temp_sum-=data[start]
        start+=1
    elif end == n:
        break
    else:
        temp_sum+=data[end]
        end+=1

if min_length == 1e9:
    print(0)
else:
    print(min_length)
