#크루스칼 알고리즘 파이썬으로 구현하기

from collections import deque

# 노드 x를 유일한 원소로 하는 집합 생성
def Make_Set(x):
    p[x] = x
    ranks[x] = 0

# 노드 x가 속한 집합을 알아낸다, 노드 x가 속한 트리의 루트 노드를 리턴한다.
def Find_Set(x):
    if(p[x] != x):
        p[x] = Find_Set(p[x])   #경로압축 : Find_Set을 수행하는 과정에서 만나는 모든 노드들이 직접 루트 노드를 가리키도록 변경
    
    return p[x]

#노드 x가 속한 집합과 노드 y가 속한 집합을 합친다.
def Union(x, y):
    x1 = Find_Set(x)    #x의 루트 노드 찾기
    y1 = Find_Set(y)    #y의 루트 노드 찾기
    
    if(ranks[x1] > ranks[y1]):  #x가 속해있는 집합의 높이(ranks)가 더 크면 y를 연결
        p[y1] = x1
    else:                       #그 반대의 경우 x를 연결한다음 두개가 같은 경우에는 y의 랭크를 증가시켜준다.
        p[x1] = y1
        if(ranks[x1]==ranks[y1]):   
            ranks[y1] = ranks[y1] + 1
    
    
def Kruskal():
    
    for i in range(1, n+1):     #집합생성
        Make_Set(i)
    
    #n-1개가 선택될 때 까지 반복문 실행
    while(len(result) < n - 1):
        start = Node_list[0][0]
        end = Node_list[0][1]
        
        if(Find_Set(start) != Find_Set(end)):
            Union(start, end)
            result.append(Node_list[0])
        
        Node_list.popleft()


n, m = map(int, input().split())
p = [0 for i in range(n+1)]    #배열을 이용한 집합의 표현 -> 부모노드를 가리킴 p[x] = x라면 자기자신을 가리키며 루트이다.
ranks = [0 for i in range(n+1)]    #랭크 노드 개수 결정
result = [] #선택된 엣지의 정보를 저장할 배열
Node_list = []

#엣지 입력받기
for i in range(m):
    Node_list.append(list(map(int, input().split())))

#가중치를 기준으로 오름차순 정렬하기
Node_list.sort(key = lambda x:x[2])
Node_list = deque(Node_list)

# 크루스칼 알고리즘 시작
Kruskal()

cost = 0
for i in result:
    print("{},{}({})".format(i[0],i[1],i[2]))
    cost +=i[2]

print("Total Cost : ", cost)