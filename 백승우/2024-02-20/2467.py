from sys import stdin
input = stdin.readline

n = int(input())
data = list(map(int, input().split()))

min_sum = 1e9

start = 0
end = n-1
flag = True
if data[start]>=0:
    flag = False
    case = [data[start], data[start+1]]
if data[end]<=0:
    flag = False
    case = [data[end-1], data[end]]
    
while start<end and flag:
    if abs(data[start]+data[end])<min_sum:
        min_sum = abs(data[start]+data[end])
        case = [data[start], data[end]]
    if -1*data[start]>data[end]:
        start+=1
    else:
        end-=1
        
print(*case)
