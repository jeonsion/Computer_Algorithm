

MAX_N = 15
weight = [0 for i in range(MAX_N +1)]
T = int(input())
for i in range(T):
    N = int(input())
    weight[1:N+1] = list(map(int, input().split()))
    print(weight)
