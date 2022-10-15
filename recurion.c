#include <stdio.h>


//팩토리얼 재귀함수 구현하기
int factorial(int n)    {
    if(n<=1)
        return 1;
    else
        return n * factorial(n-1);
}

//x의 n승 구하기
double power(double x, int n){
    if(n==0)
        return 1;
    else
        return x * power(x, n-1);
}

//피보나치 수열 구하기
int fibonacci(int n){
    if(n<2)
        return n;
    else 
        return fibonacci(n-1) + fibonacci(n-2);
}
//최대 공약수 구하기 유클리도 호제
int gcd(int a, int b){
    //전제 : a가 b보다 커야한다.
    if( b==0)
        return a;
    else
        return gcd(b, a%b);
}
//문자열 길이 계산하기
int length(char *str)   {
    if(*str == '\0')
        return 0;
    else    
        return 1 + length(str +1);
}

//문자열 출력하기
void printChars(char * str) {
    if(*str == '\0')
        return;
    else {
        printf("%c", *str);
        printChars(str+1);
    }
}

//문자열 거꾸로 출력하기
void printCharsReverse(char *str){
    if(*str == '\0')
        return ;
    else
        printCharsReverse(str+1);
        printf("%c", *str);
}
//순차 탐색하기, 존재하면 배열의 인덱스 아니면 -1 반환
//n은 배열의 길이 따라서 n-1로 접근한다.
int search(int data[], int n, int target)   {
    if(n <= 0)
        return -1;
    else if (target == data[n-1])
        return n-1;
    else 
        return search(data, n-1, target);
}

int MAX(int a, int b){
    if(a>b)
        return a;
    else 
        return b;
}

//최대값 찾기
int findMax(int n, int data[])  {
    if (n==1)// 배열의 길이가 1이라면 첫째 값 리턴
        return data[0];
    else   
        return MAX(data[n-1], findMax(n-1, data));
}
//이진수 출력하기
void printInBinary(int n){
    if(n<2)
        print("%d", n);
    else{
        printInBinary(n/2);
        printf("%d", n%2);
    }
}