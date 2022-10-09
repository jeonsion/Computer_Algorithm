

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

int main()  {
    freopen("Fitbit_Data.txt", "r", stdin);

    for(int i = 1; i<= DAY; i++)   {
        scanf("%d", &monthly_info[i].date);
        scanf("%d", &monthly_info[i].duration);
        scanf("%d", &monthly_info[i].efficiency);
        scanf("%s", monthly_info[i].level);        
    }

    quicksort(monthly_info, 1, DAY);    //퀵정렬로 date 오름차순 정렬
    printf("<<<퀵정렬로 date 오름차순 정렬>>>\n");
    printData();
}