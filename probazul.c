#include <stdio.h>

int main()
{
    int N,i,j;
    int val_partidas[1000][2],soma;

    scanf("%d",&N);
    for(i=0;i<N;i++)
    {   soma=0;
        for(j=0;j<2;j++)
     {   
        scanf("%d",&val_partidas[i][j]);
        soma=soma+val_partidas[i][j];   
     }
     if(soma%2==0)
          printf("A\n");
        else
            printf("B\n"); 
    }

 return 0;   
}