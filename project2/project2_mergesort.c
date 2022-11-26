

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

//퀵 정렬 이용 Date 오름 차순으로 정렬
//분할 정복법 사용
//분할(partition) : 데이터가 저장된 배열을 pivot에 따라 두 부분으로 나눔
//정복 : 각 부분을 순환적으로 정렬
//취합은 필요 없음

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
            if(A[j].efficiency>A[j+1].efficiency){
                Fitbit_Daily_Info temp = A[j+1];
                A[j+1] = A[j];
                A[j] = temp;
            }
        }
    }
}

void insertionsort(Fitbit_Daily_Info A[], int p, int r){
    
    int i, j;
    //인덱스 1은 이미 정렬된 것으로 간주한다. 2부터 시작
    for(i = p+1; i<=r; i++) {  
        //후에 삽입 될 숫자인 i 번째 정수를 key값 변수로 복사
        Fitbit_Daily_Info key = A[i];

        //현재 정렬된 배열은 i-1까지 이므로, 여기서 부터 역순으로 조사한다.
        //j는 음수가 아니어야한다.(배열의 시작 인덱스는 1), key값보다 앞에 배열이 크면 레코드를 앞으로 땡겨줘야함
        for(j = i-1; j>=1 && A[j].date<key.date; j--){
            A[j+1] = A[j];  //레코드 오른쪽으로 이동
        }
        A[j+1] = key;
    }

}


//취합
void merge(Fitbit_Daily_Info A[], int p, int q, int r){
    //A[p..q]와 A[q+1..r]을 병합하여 A[p..r]을 정렬된 형태로 만든다.
    //A[p..q]와 A[q+1..r]은 이미 정렬되어 있다.

    int i = p, j = q+1, t = 1;
    Fitbit_Daily_Info temp[DAY+1];

    while(i<=q && j<=r){
        if(A[i].efficiency>=A[j].efficiency){
            temp[t++] = A[i++];
        }
        else{
            temp[t++] = A[j++];
        }   
    }
    //왼쪽 부분 배열이 남은경우
    while(i<=q){
        temp[t++] = A[i++];
    }
    //오른쪽 부분 배열이 남은경우
    while(j<=r){
        temp[t++] = A[j++];
    }
    i = p; t=1;
    while(i<=r)
        A[i++]=temp[t++];
}
//분할, 정복
void mergesort(Fitbit_Daily_Info A[], int p, int r){
    int q = 0;
    if(p<r){
        q = (p+r)/2;
        mergesort(A, p, q);
        mergesort(A, q+1, r);
        merge(A, p, q, r);
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
    //insertionsort(monthly_info, 1, DAY);
    mergesort(monthly_info, 1, DAY);    //mergesort로 efficiency 내림차순 정렬
    printf("병합정렬로 efficiency 내림차순정렬\n");

    printData();
}