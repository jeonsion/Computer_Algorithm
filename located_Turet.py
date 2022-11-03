import sys
input = sys.stdin.readline

INSTALLED = 2   #터렛 설치됨
DEFFENDED = 1   #터렛 설치하지 않았지만, 하위노드 중 1개 설치되어 있어 방어됨
NOT_DEFFENDED = 0   #방어되지 않음

#전역변수로 노드개수, 간선개수, 시작노드, 끝노드 선언
N=M=S=E=0

#터렛 개수를 카운트 하는 변수 선언
numTuret = 0

A_list = [] #가변 배열 생성할 프레임 만들기
visited = [] #방문여부 확인한느 배열 만들기

#인접 배열 생상하는 함수
def AddEdge(s, e):
    A_list[s].append(e)
    A_list[e].append(s)

#그래프 출력하는 함수, 서로 연결된 노드들을 가변배열 형태로 출력함
def print_Graph():
    for i in range(N+1):
        print(i, end = ': ')
        for j in range(len(A_list[i])):
            print(A_list[i][j], end = ' ')
        #줄바꿈
        print()   


def aDFS(v):
    global numTuret
    ret = 0
    #print("aDFS에서 처음 visited : ", visited)         test1번
    #print("visited[v]에 {} 넣기".format(v))           test 2번
     #방문했다고 표시
    visited[int(v)] = 1
    #print("visited[v] 넣은 결과: ", visited )
    print(v, end = ' ')
    for i in range(len(A_list[v])):
        x = A_list[v][i]
        if(visited[x] == 0):
            ret = aDFS(x)
    
    if(len(A_list[v]) != 1 and ret == NOT_DEFFENDED):
        numTuret +=1
        return INSTALLED   
    elif (len(A_list[v])!= 0 and ret == INSTALLED):
        return DEFFENDED
    else:
        return NOT_DEFFENDED
    
    
def DFS():
    global numTuret
    global visited  #함수안에서 전역변수 리스트 값을 바꾸기 위함
    global ret
    #아무곳도 방문하지 않은 상태 초기화
    visited = [0 for i in range(N+1)]
    #print("visited 초기화한 결과 : ", visited)         test 3번
    
    #순차적으로 방문하지 않은 곳을 시작으로 aDFS 실행
    for v in range(1, N+1):
        if(visited[v] ==0 ):
            ret = aDFS(v)
            if(ret == NOT_DEFFENDED):
                numTuret+=1
            
            
            
            
            

T = int(input())
#테스트 케이스 만큼 for문 돌기
for i in range(T):
    numTuret = 0
    # N: 노드개수, M: 엣지 개수 입력받기
    N, M = map(int, input().split())
    #2차원 배열을 만드는데, 노드의 개수만큼 세로(노드 열) 생상
    A_list = [[] for i in range(N+1)]
    #리스트 잘 만들어 졌는지 확인
    print(A_list)
    #엣지 개수만큼 가변배열 만들기
    for j in range(M):
        # S : 시작노드, E : 끝 노드
        S, E = map(int, input().split())
        AddEdge(S, E)
    
    
    #그래프를 출력하는 함수
    print_Graph()
    
    #깊이우선탐색 시작
    DFS()
    print("터렛 설치 개수 :", numTuret)