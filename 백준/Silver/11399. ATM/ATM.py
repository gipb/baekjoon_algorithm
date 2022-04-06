N = int(input())
P = list(map(int,input().split()))
P.sort()
i = 0
answer = 0

while N:
    answer += N*P[i]
    i += 1
    N -= 1

print(answer)