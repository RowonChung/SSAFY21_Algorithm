from sys import stdin
input = stdin.readline

from bisect import bisect_left

n, q = map(int, input().split())
numbers = list(map(int, input().split()))
numbers.sort()

for i in range(q):
    query = int(input())
    index = bisect_left(numbers, query)
    if index!=n and query==numbers[index]:
        print(index*(n-1-index))
    else:
        print(0)
