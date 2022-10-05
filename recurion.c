#include <stdio.h>

int factorial(int n)    {
    if(n<=1)
        return 1;
    else
        return n * factorial(n-1);
}


double power(double x, int n){
    if(n==0)
        return 1;
    else
        return x * power(x, n-1);
}

int fibonacci(int n){
    if(n<2)
        return n;
    else 
        return fibonacci(n-1) + fibonacci(n-2);
}

int gcd(int a, int b){
    //전제 : a가 b보다 커야한다.

    if( b==0)
        return a;
    else
        return gcd(b, a%b);
}

int length(char *str)   {
    if(*str == '\0')
        return 0;
    else    
        return 1 + length(str +1);
}

void printChars(char * str) {
    if(*str == '\0')
        return;
    else {
        printf("%c", *str);
        printChars(str+1);
    }
}


void printCharsReverse(char *str){
    if(*str == '\0')
        return ;
    else
        printCharsReverse(str+1);
        printf("%c", *str);
}

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

int findMax(int n, int data[])  {
    if (n==1)
        return data[0];
    else   
        return MAX(data[n-1], findMax(n-1, data));
}

void printInBinary(int n){
    if(n<2)
        print("%d", n);
    else{
        printInBinary(n/2);
        printf("%d", n%2);
    }
}