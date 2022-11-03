//터렛설치하기
//BFS? DFS? -> 최적의 답이 나오려면 BFS사용 하면 안됨.
//힌트 : 두 지역을 연결하는 단순경로는 정확히 하나만 존재한다 -> DFS를 이용
//리프노드에서 방어 가능 여부를 부모노드에게 알려준다 -> 부모노드 : 터렛 설치 여부를 해당 부모에게 알려준다.
//결론 : 자기 자식중에 한명이라도 방어가 안되는 노드가 있으면 그 부모노드는 터렛을 설치해야한다.

//코드 바뀌는 점 : aDFS -> return 값 생김
//ret = aDFS(), 자식이 없으면 NOT_DEFFEND 리턴, 중요!! : DFS()에서 ret == NOT_DEF이면 numTurret++

#pragma warnging(dsiable : 4996)
#include <iostream>
#include <vector>
using namespace std;

const int INSTALLED = 2;    //해당 노드에 터렛 설치됨(따라서 방어됨)
const int DEFFENDED = 1;    //헤당 노드에 터렛을 설치하지 않았지만 하위 노드 중 1개에 설치되어 있어 방어됨.
const int NOT_DEFFENDED = 0;    //해당 노드는 방어되지 않음

int n, m;   //n: 노드의 개수, m: 엣지의 개수
int s, e;   //s: start, 시작노드, e: end. 끝 노드

vector<vector<int> > adjArray;
vector<int> visited;

int numTuret = 0;
//트리 생성
void AddEdge(int start, int end){
    adjArray[start].push_back(end);
    adjArray[end].push_back(start);
}

// aDFS()함수는 INSTALLED, DEFFENDED, NOT_DEFFENDED 값을 리턴
int aDFS(int v){
    //return값 담을 변수 ret 선언
    int ret=0;
    visited[v] = 1;
    //cout << v << " ";
    //인접노드 방문
    
    for (int i = 0; i<adjArray[v].size(); i++){
        int x = adjArray[v][i];
        //인접노드 방문하지 않았으면 방문
        if(visited[x]==0){
            //함수호출 뒤 리턴값 할당
            ret = aDFS(x);
        }
    }
    //알고리즘 짜야할 코드 부분
    //마지막 노드에서부터 역으로 올라오는 알고리즘, 마지막 노드는 40번째 포문을 거치지 않고 바로 이곳으로 옴 -> 자연스레 NOT_DEFFENDED 리턴

    //하위노드가 존재하며, 리턴값이 NOT_DEFFENDED일 경우 -> 경우를 막론하고 즉 하나라도 NOT_DEFFENDED있으면 여기에 걸려서 numTuret++ 하게됨
    if(adjArray[v].size() != 0 && ret == NOT_DEFFENDED){
        numTuret+=1;
        return INSTALLED;
    }
    //하위노드가 존재하며, 리턴값이 INSTALLED인 경우
    else if(adjArray[v].size() != 0 && ret == INSTALLED){
        return DEFFENDED;
    }
    else
        return NOT_DEFFENDED;
        
}

//깊이우선 탐색 시작!
void DFS(){
    int ret;
    //모든 노드를 방문하지 않았다고 초기화
    for(int v = 1; v<=n; v++)
        visited[v] = 0;

    //첫번째 노드부터 방문 시작!
    for (int v = 1; v<=n; v++){
        if(visited[v]==0){
            //1번 노드부터 시작
            ret = aDFS(v);
            if(ret == NOT_DEFFENDED)
                numTuret+=1;
        }
        
    }
}

void printGraph(){
    for (int i = 1; i<=n; i++)  {
        cout << i << ": ";
        for(int j = 0; j<adjArray[i].size(); j++)
            cout << adjArray[i][j] << " ";
        
        cout << endl;
    }
}


int main(){
    freopen("input.txt", "r", stdin);
    int T;
    cin >> T;

    for(int i = 0; i < T; i++){
        numTuret = 0;
        adjArray.clear();
        visited.clear();

        cin >> n >> m;

        adjArray.resize(n+1);
        visited.resize(n+1);

        for(int j = 0; j< m; j++){
            cin >> s >> e;
            AddEdge(s,e);
        }

        printGraph();
        printf("\n");
        //깊이우선 탐색 시작!
        DFS();

        printf("%d\n", numTuret);
    }
}
