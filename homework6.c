//Programming By Sion.J
#include <stdio.h>
#define DATA_SIZE 5


//정렬된 배열을 출력하는 함수
void printsort(int A[], int n){
    for(int i = 0; i<n; i++)
        printf("%d ", A[i]);
}


//난이도 : ★★☆
//선택정렬 : 전체 입력 배열에 대해서 차례대로 최대값을 "선택"하여 마지막 원소와 자리를 교환하여 정렬
void selectionsort(int A[], int n){
    int select = 0;
    int temp = 0;

    //최대값을 선택하여 마지막 인덱스인 n-1위치에 삽입할 것이다.
    for(int i = n-1; i>1; i--)    {
        //0부터 i 번째 위치까지 최대값 찾기
        for(int j = 0; j<=i; j++)    {
            //가장 큰 배열의 인덱스를 반환한다.
            if(A[select]<=A[j]) 
                select = j;
        }
        //만약 자리를 바꿀 필요가 없다면 swap하지 않아도 됨.
        //가장 큰 인덱스를 i 위치와 swap 한 후 고정
        if(select!=i){
            temp = A[i];
            A[i] = A[select];
            A[select] = temp;
        }
        //select 초기화
        select = 0;

    }
}


//난이도 : ★☆☆
//버블정렬 : 이웃하는 숫자를 비교하여 큰 수를 뒤쪽으로 이동시키는 과정을 반복하여 정렬 
void bubblesort(int A[], int n){

    int large = 0;
    int temp;
    //총 n번의 확인단계를 거친다.
    for(int i = 0; i<n; i++){
        //가장 큰 값을 n-i자리에 고정한다음 다음 단계에서는 고정한 자리 앞까지 '버블'정렬로 정렬한다.
        for (int j = 0; j<n-i; j++ )    {
            //이웃한 배열의 수가 클 때 swap.
            if(A[j]>A[j+1]){
                temp = A[j+1];
                A[j+1] = A[j];
                A[j]= temp;
            }
        }
    }
}
//난이도 : ★★★
//삽입정렬 : 배열을 정렬된 왼쪽 자료들과 비교하여 삽입할 위치를 지정한후 레코드를 옮겨 지정한 자리에 데이터를 삽입하는 정렬
void insertionsort(int A[], int n){
    int i, j, key;
    //인덱스 0 은 이미 정렬된 것으로 본다.
    for(i = 1; i<=n; i++)    {
        key = A[i]; //현재 삽입될 숫자인 i 번째 정수를 key 변수로 복사
        
        //현재 정렬된 배열은 i-1까지 이므로, 여기서 부터 역순으로 조사한다.
        //j는 음수가 아니어야함 (배열의 시작 인덱스는 0), key값보다 앞에 배열이 크면 앞으로 떙겨줘야 함
        for(j = i-1; j  >= 0 && A[j]>key; j--)  {
            A[j+1] = A[j];  //레코드 오른쪽으로 이동
        }
        A[j+1] = key;   //A[j]가 아니고 A[j+1]이다. for문 j-- for문 실행 후 증감연산.
    }

}




int main()  {
    int input[] = {7, 9, 4, 8, 6, 3};
    printf("변경 전 : 7, 9, 4, 8, 6, 3 \n");
    for(int i = 1; i<=6; i++){}
    //사용법 : 주석을 번갈아 제거하면서 사용하세요.
    //selectionsort(input, DATA_SIZE);
    //bubblesort(input, DATA_SIZE);
    insertionsort(input, DATA_SIZE);

    printsort(input, DATA_SIZE);
    return 0;
}