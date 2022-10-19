#include <stdio.h>
#include <math.h>

double distMRU(double,double);
double velMRU(double,double);
double tempoMRU(double,double);
double distMRUV(double,double,double);    //Declaração de funções
double VelFinalMRUV(double,double,double);
double VelInicialMRUV(double,double,double);
double TempoMRUV(double,double,double);

int main(){
    int N, O, i;
    double V,T,S,A;

    scanf("%d",&N); //Número de operações a ser realizada

for(i=0;i<N;i++)
{
    
    scanf("%d",&O); //opção
    switch (O)
    {
        case 1: {
            scanf("%lf",&V);
            scanf("%lf",&T);            //Calcular a distância
            printf("%.2lf\n",distMRU(V,T));
            break;
        }
        case 2: {
            scanf("%lf",&S);
            scanf("%lf",&T);        //Calcular a velocidade
            printf("%.2lf\n",velMRU(S,T));
            break;
        }    
        case 3:{
             scanf("%lf",&S);
             scanf("%lf",&V); //Calcular o tempo
             printf("%.2lf\n",tempoMRU(S,V));
             break;
        }
        case 4:{
             scanf("%lf",&V);
             scanf("%lf",&A);
             scanf("%lf",&S);  //Calcular a distância percorrida com aceleração
             printf("%.2lf\n",distMRUV(V,A,S));
             break;
        }
        case 5:{
            scanf("%lf",&V);
            scanf("%lf",&A);    //Calcular a velocidade final
            scanf("%lf",&T);
            printf("%.2lf\n",VelFinalMRUV(V,A,T));
            break;
        }
        case 6:{
            scanf("%lf",&S);
            scanf("%lf",&A);    //Calcular a velocidade inicial
            scanf("%lf",&T);
            printf("%.2lf\n",VelInicialMRUV(S,A,T));
            break;
        }
        case 7:{
            scanf("%lf",&S);
            scanf("%lf",&V);    //Calcular o tempo total
            scanf("%lf",&A);
            printf("%.2lf\n",TempoMRUV(S,V,A));
             break;
        }
    }

}
return 0;
}

double distMRU(double vel,double tempo){ //Opção 1
    double resultado;
    resultado = vel*tempo;
  return resultado;  
}

double velMRU(double espaco, double tempo){ //Opção 2
    double velocidade;
    velocidade = espaco/tempo;
 return velocidade;    
}

double tempoMRU(double espaco, double velocidade){ //Opção 3
    double tempo;
    tempo = espaco/velocidade;
 return tempo;
}

double distMRUV(double velocidade, double aceleracao,double tempo){ //Opção 4
    double distancia;
    distancia = (velocidade*tempo) + (aceleracao*tempo*tempo)/2;
 return distancia;
}

double VelFinalMRUV(double velocidade, double aceleracao, double tempo){ //Opção 5
    double velFinal;
    velFinal = velocidade + (aceleracao*tempo);
 return velFinal;
}

double VelInicialMRUV(double espaco,double aceleracao,double tempo){ //Opção 6
    double velInicial;
    velInicial = (espaco - (aceleracao*tempo*tempo)/2)/tempo;
 return velInicial;
}

double TempoMRUV(double espaco, double velocidade, double aceleracao){ //Opção 7
    double Tempo;
    Tempo = (sqrt((velocidade*velocidade) + (2*aceleracao*espaco))- velocidade)/aceleracao; //Raiz para achar a velocidade final Calculei a variação de velocidade dividido pela aceleracao pra achar o tempo
 return Tempo;   
}