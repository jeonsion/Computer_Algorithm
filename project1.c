#include <stdio.h>
#define MAX_N 15
#pragma warning(disable:4996)


int weight[MAX_N +1];
int result = 0;
int N = 0;

void countTeams(int h, int wA, int wB, int wC) {


    if(h==N)    {
            //모든 학생들을 팀에 넣은 후 모뭄게가 같은 경우 result +1
        if(wA==wB && wB==wC && wA==wC)
            result +=1;
    }
    else{
        countTeams(h+1, wA + weight[h+1], wB, wC);
        countTeams(h+1, wA, wB +weight[h+1], wC);
        countTeams(h+1, wA, wB, wC + weight[h+1]);
        countTeams(h+1, wA, wB,wC);
    }
    

}
int main()  {
    int T;
    freopen("input.txt", "r", stdin);

    scanf("%d", &T);

    for(int i = 0; i< T; i++)   {
        scanf("%d", &N);

        for(int j = 1; j<=N; j++)   {
            scanf("%d", &weight[j]);
        }
        countTeams(0,0,0,0);

        printf("%d\n", result);
        result = 0;
    }
}