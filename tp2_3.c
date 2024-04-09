#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 5
#define M 7

int main()
{
int i,j;

srand(time(NULL));
int mt[N][M];
int *punt_m = &mt[0][0];

for(i = 0;i<N; i++)
{
    for(j = 0;j<M; j++)
    {
    *(punt_m + i * M + j)= 1 + rand()% 100;
    printf("%d ", *(punt_m + i * M + j));
    }
    printf("\n");
}


}

