#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define MAX_VERTEX_NUM 100

typedef struct {
    int vertexNum;
    int adjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
}Graph;

int visited[MAX_VERTEX_NUM];

#define MAX_QUEUE_SIZE 20

typedef int element;

typedef struct {
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
}QueuType;

void error(char* message){
    fprintf(stderr, "%s\n", message);
}

void init_queue(QueuType* q){
    q->rear = 0;
    q->front = 0;
}

int is_full(QueuType* q){
    return (q->front ==(q->rear +1) % MAX_QUEUE_SIZE);
}

int is_empty(QueuType* q){
    return (q->front == q->rear);   // 비어있으면 1 아니면 0반환
}

void enqueue(QueuType* q, element item){
    if(is_full(q)){
        error("큐가 포화상탱칩니다.");
        return;
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

element dequeue(QueuType* q){
    if(is_empty(q)) {
        error("큐가 공백상태입니다.");
        return -1;
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}
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

void BFS_Mat(Graph* g, int s){
    QueuType q;
    init_queue(&q);

    for(int i = 1; i<= g->vertexNum; i++)   //visited 배열 초기화
        visited[i] = 0;                     // 0: 방문하지 않음, 1: 방문했음

    visited[s] = 1;
    printf("%d ", s);
    enqueue(&q, s);
    while(!is_empty(&q)){
        int u = dequeue(&q);
        for(int v = 1; v<= g->vertexNum; v++){
            if(g->adjMatrix[u][v] == 1 && visited[v]==0){
                visited[v] = 1;
                printf("%d ", v);
                enqueue(&q, v);
            }
        }

    }
}

int main(){
    Graph *g = NewGraph(8);

    AddEdge(g, 1, 2);
    AddEdge(g, 1, 3);
    AddEdge(g, 2, 4);
    AddEdge(g, 2, 5);
    AddEdge(g, 3, 5);
    AddEdge(g, 3, 7);
    AddEdge(g, 3, 8);
    AddEdge(g, 4, 5);
    AddEdge(g, 5, 6);
    AddEdge(g, 7, 8);

    printGraph(g);
    printf("\nBFS: ");
    BFS_Mat(g, 1);
}