#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define MAX_VERTEX_NUM 100

//구조체 선언
typedef struct {
    int vertexNum;  //정점의 개수
    int adjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];  //인접행렬 100X100크기
}Graph;


Graph* NewGraph(int vNum){
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertexNum = vNum;
    //memset(여기 주소부터 , 0 값으로 채워라, 해당 크기만큼) -> 0으로 초기화
    memset(graph->adjMatrix, 0, sizeof(int)*MAX_VERTEX_NUM*MAX_VERTEX_NUM);

    return graph;
}

//start 정점과 end 정점을 연결하는 간선 생성
void AddEdge(Graph *graph, int start, int end){
    graph->adjMatrix[start][end] = 1;
    graph->adjMatrix[end][start] = 1;
}

//graph를 출력하는 함수
void printGraph(Graph *graph)   {
    for(int i = 1; i <= graph->vertexNum; i++)    {
        for(int j =1; j <= graph->vertexNum; j++)
            printf("%d ", graph->adjMatrix[i][j]);
        
        printf("\n");
    }
}

int main(){
    //정점의 개수가 6개인 그래프 표현하기(인접행렬)
    Graph *g = NewGraph(6);

    AddEdge(g, 1, 2);
    AddEdge(g, 1, 3);
    AddEdge(g, 1, 4);
    AddEdge(g, 1, 6);
    AddEdge(g, 2, 3);
    AddEdge(g, 3, 5);
    AddEdge(g, 4, 6);
    AddEdge(g, 5, 6);
    
    printGraph(g);
}