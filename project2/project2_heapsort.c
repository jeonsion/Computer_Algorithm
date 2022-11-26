

#include <stdio.h>
#pragma warning(disable : 4996)

#define DAY 30

typedef struct 
{
    int date;
    int duration;
    int efficiency;
    char level[10];
}Fitbit_Daily_Info;

//구조체 배열 선언
Fitbit_Daily_Info monthly_info[DAY +1];

//j의 원소가 pivot보다 크면 j = j+1, j의 원소가 pivot보다 작으면 i = i+1하고 i와 j의 인덱스 바꾸기 그 다음 j = j+1
int partition(Fitbit_Daily_Info A[], int p, int r){
    //피봇
    Fitbit_Daily_Info x = A[r];
    //i는 0부터 시작
    int i = p - 1;

    //j의 원소가 pivot보다 크면 defaut로 j의 값을 증가시켜준다.
    for(int j = p; j<r; j++)    {
        //j의 원소가 pivot보다 작은 경우
        if(A[j].date <x.date){
            i++;
            Fitbit_Daily_Info temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    //i+1과 pivot 위치 바꾸기
    Fitbit_Daily_Info temp1 = A[i+1];
    A[i+1] = A[r];
    A[r] = temp1;

    //pivot의 인덱스 리턴
    return i+1;
}

void quicksort(Fitbit_Daily_Info A[], int p, int r){
    if(p<r){
        int q = partition(A, p, r);
        quicksort(A, p, q-1);
        quicksort(A, q+1, r);
    }
}

void printData()    {
    for(int i = 1; i<=DAY; i++) {
        printf("[%d] Date : %d  Duration:%d     Efficiency : %d     Level : %s\n", i, monthly_info[i].date, monthly_info[i].duration,
        monthly_info[i].efficiency, monthly_info[i].level);    
    }
}

void selectionsort(Fitbit_Daily_Info A[], int p, int r){
    int select = 0;
    
    //최대값을 선택하여 마지막 인덱스 r위치에 삽입 & 고정
    for(int i = r; i>p; i--){
        //0부터 i번째 위치까지 최대값 찾기
        for(int j = 0; j<=i; j++){
            if(A[select].duration <=A[j].duration){
                select = j;
            }
        }
        //자리를 바꿀 필요가 없다면 swap 하지 않아도 됨.
        //가장 큰 인덱스를 i 위치와 swap 한 후 고정
        if(select!=i){
            Fitbit_Daily_Info temp = A[i];
            A[i] = A[select];
            A[select] = temp;
        }

        select = 0;
    }
}

void bubblesort(Fitbit_Daily_Info A[], int p, int r){
    int large = 0;
    //배열의 크기만큼 확인단계를 거친다.
    for(int i = p; i<=DAY; i++){
        //가장 큰 값을 r-i에 고정한 다음 다음단계에서는 고정한 자리 앞까지 버블정렬한다.
        for(int j = 1; j<=r-i; j++)  {
            if(A[j].date<A[j+1].date){
                Fitbit_Daily_Info temp = A[j+1];
                A[j+1] = A[j];
                A[j] = temp;
            }
        }
    }
}



//힙 재구성
void heapifty(Fitbit_Daily_Info A[], int k, int r){
    //자식 노드 중 작은 노드으 인덱스를 할당할 변수 smaller 선언
    int smaller = 0;
    //마지막 노드 : r, 부모노드 : k, 왼쪽 자식(left) : 2*k, 오른쪽 자식(right) : 2*k +1
    int left = 2*k, right = 2*k +1;

    //두명의 자식을 가지고 있을경우 
    if(right <= r){
        //두 자식 노드 중 작은 노드의 인덱스를 smaller에 할당해준다.
        if(A[left].efficiency <= A[right].efficiency)
            smaller = left;
        else
            smaller = right;
    }
    //한명의 자식
    else if(left <= r)
        smaller = left;
    //자식이 없을 때
    else
        return ;

    //자식노드 중 작은 노드가 부모모다 작으면 swap해주기.
    if(A[smaller].efficiency < A[k].efficiency){
        Fitbit_Daily_Info temp = A[k];
        A[k] = A[smaller];
        A[smaller] = temp;
        //swap한다음 자식노드를 루트로 재귀적으로 구성
        heapifty(A, smaller, r);


    }
}


//힙만들기
void buildheap(Fitbit_Daily_Info A[], int p, int r){
    //마지막 노드의 부모노드 부터 체크한다.
    for(int i = r/2; i>0; i--)
        //힙 재구성
        heapifty(A, i, r);
}


//힙정렬
//주어진 입력 데이터를 힙으로 만든 다음, 하나씩 힙에서 제거하면서 정렬
//최악의 경우에도 O(nlogn)
//A[p...r] -> A[1...30]
void heapsort(Fitbit_Daily_Info A[], int p, int r){
    //힙만들기
    buildheap(A, p, r);
    for(int i = r; i>=p; i--){
        Fitbit_Daily_Info temp = A[1];
        A[1] = A[i];
        A[i] = temp;
        heapifty(A,1, i-1);
    }


}


int main()  {
    freopen("Fitbit_Data.txt", "r", stdin);

    for(int i = 1; i<= DAY; i++)   {
        scanf("%d", &monthly_info[i].date);
        scanf("%d", &monthly_info[i].duration);
        scanf("%d", &monthly_info[i].efficiency);
        scanf("%s", monthly_info[i].level);        
    }

    //quicksort(monthly_info, 1, DAY);
    //selectionsort(monthly_info, 1, DAY);
    //bubblesort(monthly_info, 1, DAY);
    heapsort(monthly_info, 1, DAY);
    printf("<<<힙정렬로 date 내림차순정렬>>>\n");
    printData();
} 