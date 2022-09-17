//과제3
#include <stdio.h>
#define N 8

int cols[N+1];

int abs(int n)  {
    if(n>0)
        return n;
    else
        return -n;
}

int promissing(int h)   {
    for(int i =1; i<h; i++) {
        if(cols[i]==cols[h])
            return 0;
        else if(h-i == abs(cols[h]-cols[i]))
            return 0;
    }
    return 1;
}

int queens(int h)   {
    if(!promissing(h))
        return 0;
    if (h==N)   {
        for(int i = 1; i<=N;i++)    {
            printf("(%d, %d)\n",i, cols[i]);
        }
        return 1;
    }
    for(int i = 1; i<=N ; i++)  {
        cols[h+1] = i;
        if(queens(h+1))
            return 1;
    }
    return 0;
}

int main()  {
    if(queens(0) == 1)
        printf("Success\n");
   
}