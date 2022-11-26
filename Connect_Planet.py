# 모든 행성을 연결하면서 플로우 관리 비용을 최소한으로 해라
# 행성의 개수 N
# 플로우 관리 비용이 N x N 행렬로 주어짐
# 크루스칼 알고리즘 이용


from collections import deque


#노드 x를 유일한 원소로 하는 집합 생성
def Make_Set(x):
    p[x] = x    #처음에는 
    ranks[x] = 0

# x의 루트노드를 찾는 함수
def Find_Set(x):
    if(p[x]!=x):
        p[x] = Find_Set(p[x])  #Find_Set함수를 수행하는 과정에서 만나는 노드들이 직접 루트노드르 가리키도록 변경
    return p[x]

def Union(x, y):
    x1 = Find_Set(x)    #x의 루트노드 찾기
    y1 = Find_Set(y)    #y의 루트노드 찾기
    
    if(x1>y1):      #x가 속해있는 집합의 랭크가 클 경우 y집합을 x에 연결
        p[y1] = x1
    else:
        p[x1] = y1  # 반대의 경우 x의 집합을 y에 연결, 같을 경우 랭크 + 1
        if(x1 == y1):
            ranks[y1] = ranks[y1] + 1
            
def Kruskal():
    for i in range(1, N+1):     #집합 생성
        Make_Set(i)
        
    while(len(result) < N-1):   #선정된 엣지의 개수가 n-1개가 될때까지 반복문 수행
        start = Edge_list[0][0]
        end = Edge_list[0][1]
        
        if(Find_Set(start) != Find_Set(end)):   #다른 집합인 경우(사이클 안생기는 경우) Union 수행
            Union(start, end)                   # 집합 합치기
            result.append(Edge_list[0])         #선정된 엣지 result 리스트에 추가
        
        Edge_list.popleft()     #pop 연산
        
        
        

#행성의 개수
N = int(input())

#그리드 만들기
flow_list = []
for i in range(N):
    flow_list.append(list(map(int, input().split())))

#s,e,w 쌍으로 엣지 정보 저장
# 스킬 : N x N 그리드의 반절의 엣지정보를 이용
Edge_list = []
for i in range(N):
    for j in range(i+1, N):
        Edge_list.append([i+1, j+1, flow_list[i][j]])

#엣지 정보들 가중치 순으로 정렬
Edge_list.sort(key = lambda x:x[2])
Edge_list = deque(Edge_list)    


p = [0 for i in range(N+1)]     #부모노드를 가리킬 리스트 p
ranks = [0 for i in range(N+1)]     #집합에서의 rank를 나타냄
result = []     #선택된 엣지들을 저장할 리스트 result

Kruskal()

#총합 계산
cost = 0
for i in result:
    #print("{},{}({})".format(i[0],i[1],i[2]))
    cost +=i[2]

print(cost)