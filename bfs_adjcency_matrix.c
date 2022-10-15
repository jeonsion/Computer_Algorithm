#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define MAX_VERTEX_NUM 100

typedef struct {
    int vertexNum;
    int adjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
}Graph;

//방문 유무를 확인하는 배열
int visited[MAX_VERTEX_NUM];

//큐의 최대 크기
#define MAX_QUEUE_SIZE 20

typedef int element;       //큐의 원소 자료형을 int로 정의

// 큐 구조체
typedef struct {
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
}QueuType;

void error(char* message){
    fprintf(stderr, "%s\n", message);
}

//큐 시작 rear, front 초기화
void init_queue(QueuType* q){
    q->rear = 0;
    q->front = 0;
}

//원형 큐의 포화상태 (front가 rear보다 한칸 앞에 위치하면 포화상태이다. )
int is_full(QueuType* q){
    return (q->front ==(q->rear +1) % MAX_QUEUE_SIZE);
}
//원형 큐의 공백 상태
int is_empty(QueuType* q){
    return (q->front == q->rear);   // 비어있으면 1 아니면 0반환
}

//큐 insert
void enqueue(QueuType* q, element item){
    if(is_full(q)){
        error("큐가 포화상태입니다.");
        return;
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;   //rear = rear + 1 
    q->data[q->rear] = item;    //큐 삽입
}

//큐 pop
element dequeue(QueuType* q){
    if(is_empty(q)) {
        error("큐가 공백상태입니다.");
        return -1;
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE; //front = front + 1
    return q->data[q->front];   //큐 front 값 리턴
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

//BFS 너비 우선 탐색
//출발 노드로부터 가까운 정점을 먼저 방문하고 멀리 떨어져 있는 정점을 나중에 방문하는 순회방법
void BFS_Mat(Graph* g, int s){  //

    //큐 선언
    QueuType q;
    //큐 초기화
    init_queue(&q);

    
    for(int i = 1; i<= g->vertexNum; i++)   //visited 배열 초기화
        visited[i] = 0;                     // 0: 방문하지 않음, 1: 방문했음

    // 첫번째 노드 방문
    visited[s] = 1;
    //방문했으면 출력 후 큐에 넣는다.
    printf("%d ", s);
    enqueue(&q, s);
    //큐가 비어있지 않다면 반복문 실행
    while(!is_empty(&q)){
        //큐에 들어있는 노드를 꺼내 그 이웃노드들을 방문하고 큐에 저장할 것이다.
        int u = dequeue(&q);
        for(int v = 1; v<= g->vertexNum; v++){
            if(g->adjMatrix[u][v] == 1 && visited[v]==0){       //인접노드 이면서 방문하지 않은 노드일 때
                visited[v] = 1; //방문하고
                printf("%d ", v);   //출력하고
                enqueue(&q, v); //큐에 집어넣는다
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