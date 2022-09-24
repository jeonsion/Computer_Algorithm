
MAX_N = 15

weight=[0 for i in range(MAX_N+1)]
result = 0
N = 0

def countTeams(h, wA,  wB, wC) :
    global result
    if(h==N):
        if(wA==wB and wB==wC and wA==wC):
            result += 1
    else:
        countTeams(h+1, wA + weight[h+1], wB, wC)
        countTeams(h+1, wA , wB+ weight[h+1], wC)
        countTeams(h+1, wA , wB, wC+ weight[h+1])
        countTeams(h+1, wA , wB, wC)
        

T = int(input())
for i in range(int(T)):
    
    N = int(input())
    weight[1:N+1] = list(map(int, input().split()))
    ##print(weight)
    countTeams(0,0,0,0)
    print(result)
    result = 0    
