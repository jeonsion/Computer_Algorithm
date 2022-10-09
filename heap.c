#include <stdio.h>
#define arr_size 5




void heapify(int A[], int k, int n){
    //마지막 노드: n, 부모노드 : k, 왼쪽 자식(left) = 2*k+1, 오른쪽 자식(right) = 2*(k+1)
    //자식 노드 중 작은 노드의 인덱스를 할당할 변수 smaller 선언
    //여기서 부모노드는 2, 자식노드는 5
    int smaller = 0;
    int left = 2*k + 1, right = 2*(k+1);
    //두명의 자식을 가지고 있을 경우
    if(right<=n){
        if(A[left] < A[right])
            smaller = left;
        else
            smaller = right;
    }
    else if(left<=n)
        smaller = left;
    else
        return ;

    //부모노드의 자식노드 중 작은 노드가 부모모다 작으면 swap해주기
    if(A[smaller] < A[k]){
        int temp = A[k];
        A[k] = A[smaller];
        A[smaller] = temp;
        //교체를 후 heapify함수를 통해 자식노드를 루트로 재귀적으로 실행 노드와 비교
        heapify(A, smaller, n);
    }
}

//힙을 구성하기
void buildheap(int A[], int n){
    //마지막 노드 인덱스 = n
    for(int i = (n-1)/2; i>=0; i--){
        heapify(A, i, n); //heapify(A, 2(부모노드 인덱스), 5(자식노드 인덱스))
    }
}

void heapsort(int A[], int n){
    //힙 만들기 A[0...n-1]
    buildheap(A, n);
    for(int i = n; i>=0; i--){
        int temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        //힙 재구성 배열 A[0...i-1]
        heapify(A, 0, i-1);
    }
}



int main()  {
    
    int input[] = {7, 9, 4, 8, 6, 3};
    heapsort(input, arr_size);

    for(int i = 0; i<=arr_size; i++) {
        printf("%d ", input[i]);
    }


}

