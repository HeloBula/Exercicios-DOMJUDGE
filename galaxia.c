#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{ 
    int N, M, i, j;
    int op, ind,ind2;
    char Complan1[21], Complan2[21];
    
    int X1, Y1, Z1;
    int X2, Y2, Z2;
    double distancia;

    scanf("%d", &N);
    typedef struct dados{
        char nome[21];
        double peso;
        double x, y, z;
    }Dados;

    Dados planetas[N];

    scanf("%d", &M);
    for (i = 0; i < N; i++)
    {
        scanf("%s", planetas[i].nome);
        scanf("%lf", &planetas[i].peso);
        scanf("%lf", &planetas[i].x);
        scanf("%lf", &planetas[i].y);
        scanf("%lf", &planetas[i].z);
    }

    for (j = 0; j < M; j++)
    {
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            scanf("%s", Complan1);
            scanf(" %s", Complan2);
             for(i=0;i<N;i++)
                {
                    if(strcmp(Complan1,planetas[i].nome)==0)
                   {
                    ind=i;
                   }
                }
                 for(i=0;i<N;i++)
                {
                    if(strcmp(Complan2,planetas[i].nome)==0)
                   {
                    ind2=i;
                   }
                }
                X1 = planetas[ind].x;
                Y1 = planetas[ind].y;
                Z1 = planetas[ind].z;

                X2 = planetas[ind2].x;
                Y2 = planetas[ind2].y;
                Z2 = planetas[ind2].z;
            
            distancia = sqrt(pow((X2 - X1), 2) + pow((Y2 - Y1), 2) + pow((Z2 - Z1), 2));
            printf("%.2lf\n", distancia);
            break;
        case 2:
            scanf("%s", Complan1);
            for (i = 0; i < N; i++)
            {
                if (strcmp(Complan1, planetas[i].nome) == 0)
                {
                    ind = i;
                }
            }
            printf("%.0lf %.0lf %.0lf\n", planetas[ind].x, planetas[ind].y, planetas[ind].z);
            break;
        case 3:
            scanf("%s", Complan1);
            for (i = 0; i < N; i++)
            {
                if (strcmp(Complan1, planetas[i].nome) == 0)
                {
                    ind = i;
                }
            }

            printf("%.2lf\n", planetas[ind].peso);
            break;
        }
    }
    return 0;
}