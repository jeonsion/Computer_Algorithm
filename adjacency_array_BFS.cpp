#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int s, e;

//vector<int>는 노드의 인접한 정점들을 추가(가로), vecotr<vector<int>>는 세로의 노드를 표현
vector<vector<int> > adjArray;
vector<int> visited;

queue<int> q;

//가변길이의 배열 구현
void AddEdge(int start, int end){
    adjArray[start].push_back(end);
    adjArray[end].push_back(start);
}

void printGraph(){
    for (int i = 1; i<=n; i++)  {
        cout << i << ": ";
        for(int j = 0; j<adjArray[i].size(); j++)
            cout << adjArray[i][j] << " ";
        
        cout << endl;
    }
}


void aDFS(int v){
    visited[v] = 1;
    cout << v << " ";
    for(int i = 0; i < adjArray[v].size(); i++){
        int x = adjArray[v][i];
        if(visited[x]==0){
            aDFS(x);
        }
    }
}


void DFS(){
    for(int v = 1; v <=n; v++)
        visited[v]= 0;
    
    for(int v = 1; v<=n; v++){
        if(visited[v]==0){
            aDFS(v);
        }
    }
}


void BFS(int s){
    for(int i = 1; i<=n; i++)
        visited[i] = 0;
    
    visited[s] = 1;
    cout << s << " ";
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int j = 0; j<adjArray[u].size(); j++){
            if(visited[adjArray[u][j]] == 0){
                visited[adjArray[u][j]] = 1;
                cout << adjArray[u][j] << " ";
                q.push(adjArray[u][j]);
            }
        }
    

    }

}





int main(){
    cin >> n >> m;
    adjArray.resize(n + 1);
    visited.resize(n + 1);

    for(int i = 0; i<m; i++){
        cin >> s >> e;
        AddEdge(s, e);
    }

    printGraph();
    //DFS();
    BFS(1);
}