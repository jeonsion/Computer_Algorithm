#include <stdio.h>
#define DATA_SIZE 10


//정렬된 배열을 출력하는 함수
void printsort(int A[], int n){
    for(int i = 0; i<n; i++)
        printf("%d ", A[i]);
}

//선택정렬 : 전체 입력 배열에 대해서 차례대로 최대값을 "선택"하여 마지막 원소와 자리를 교환하여 정렬
void selectionsort(int A[], int n){
    int select = 0;
    int temp = 0;
    for(int i = n-1; i>1; i--)    {
        for(int j = 0; j<=i; j++)    {
            //printf("for문이 0부터 %d 까지 돌아갑니다\n", j);
            if(A[select]<=A[j])
                select = j;
        }
        //printf("가장큰 수 : %d, i의 값 : %d\n", A[select], i);
        if(select!=i){
            temp = A[i];
            A[i] = A[select];
            A[select] = temp;
        }
        select = 0;

    }
}


//버블정렬 : 이웃하는 숫자를 비교하여 큰 수를 뒤쪽으로 이동시키는 과정을 반복하여 정렬
void bubblesort(int A[], int n){
    int large = 0;
    int temp;
    for(int i = 0; i<n; i++){
        for (int j = 0; j<n-i; j++ )    {
            if(A[j]>A[j+1]){
                temp = A[j+1];
                A[j+1] = A[j];
                A[j]= temp;
            }
        }
    }
}

int main()  {
    int input[] = {3, 31, 48, 73, 8, 11, 20, 29, 65, 15};
    printf("변경 전 : 3, 31, 48, 73, 8, 11, 20, 29, 65, 15 \n");
    //selectionsort(input, DATA_SIZE);
    //bubblesort(input, DATA_SIZE);
    printsort(input, DATA_SIZE);
    return 0;
}