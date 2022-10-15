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

//0부터 들어감  -> 1 들어감 1에 놓을 수 있는지 없는지 확인, 이상 없음
int queens(int h)   {
    if(!promissing(h))  //->h가 2일 때 안됨 return
        return 0;
    if (h==N)   {
        for(int i = 1; i<=N;i++)    {
            printf("(%d, %d)\n",i, cols[i]);
        }
        return 1;
    }
    for(int i = 1; i<=N ; i++)  {
        cols[h+1] = i;  //cols[1]에 1할당   ->cols[2]에 1 할당  ->cols[2]에 1들어갈 수 없음 2확인
        if(queens(h+1)) //quuen(1)체크      ->quuen(2)체크 ->
            return 1;
    }
    return 0;
}

int main()  {
    if(queens(0) == 1)
        printf("Success\n");
   
}
