#include <stdio.h>
#include <string.h>

 void RomanoDecimal(char*,int*); //Declarando funcoes
 void DecimalRomano(int);

int main(){
   int N,C,i;
   int nDecimal,ConvDecimal,soma=0;
   char nRomano[50];

    scanf("%d",&N);//O número de linhas que serão impressas

    for(i=0;i<N;i++)
    {
        scanf("%d",&C);
    if(C==1) //Se o C for 1 pega um numero romano
    {   nDecimal=0;
        scanf("%s",nRomano);
        RomanoDecimal(nRomano,&nDecimal); //Chama a função para converter
        soma += nDecimal; //Contador para ver quanto foi convertido
        printf("%d\n",nDecimal);
    }
    else if(C==2) //Se for 2 pega numero decimal
    {
        scanf("%d",&nDecimal);
        DecimalRomano(nDecimal); //decimal vira romano
    }
    }
    printf("%d",soma);//Quanto de numeros romanos foi convertido


  return 0;  
}

void RomanoDecimal(char* romanos,int* decimal) //Transformando romano em decimal
{
 int i, tamanho, valor;
 tamanho=strlen(romanos); //Verifica quantas letras tem
 for(i=0;i<tamanho;i++)
 { switch(romanos[i]){
    case 'M':
    valor = 1000;
    break;

    case 'D':
    valor = 500;
    break;

    case 'C':
        if(romanos[i+1]=='D'){
            valor=400;
            i++;
        }
        else if(romanos[i+1]=='M'){
            valor=900;
            i++;
        }
        else{
            valor=100;
        } break;

    case 'L':
        valor=50;
        break;   

    case'X':
        if(romanos[i+1]=='C')
        {
            valor=90;
            i++;
        }  
        else if(romanos[i+1]=='L')
        {
            valor=40;
            i++;
        }  
        else{
            valor=10;
        }break;

    case'V':
        valor = 5;
        break;

    case 'I':
        if(romanos[i+1]=='X')
        {
            valor=9;
            i++;
        }
        else if(romanos[i+1]=='V')
        {
            valor=4;
            i++;
        } else{
            valor=1;
        }
        break;
    }    
    *decimal = *decimal + valor;
 }
 }

void DecimalRomano(int numero)
{
    while(numero>0)
    {
        if(numero>=1000)
        {
            printf("M");
            numero -= 1000;//Retira do numero a quantidade mil
        }
        else if(numero>=900)
        {
            printf("CM");
            numero -= 900; //Se um menor vem antes do maior, ele se subtrai o valor anterior do posterior
        }
        else if(numero>=500)
        {
            printf("D");
            numero -= 500;
        }
        else if(numero>=400)
        {
            printf("CD");
            numero -= 400;
        }
        else if(numero>=100)
        {
            printf("C");
            numero -= 100;
        }
        else if(numero>=90)
        {
            printf("XC");
            numero -= 90;
        }
        else if(numero>=50)
        {
            printf("L");
            numero -= 50;
        
        }
        else if(numero>=40)
        {
            printf("XL");
            numero -= 40;
        }
        else if(numero>=10)
        {
            printf("X");
            numero -= 10;
        }
        else if(numero>=9)
        {
            printf("IX");
            numero -= 9;
        }
        else if(numero>=5)
        {
            printf("V");
            numero -= 5;
        }
        else if(numero>=4)
        {
            printf("IV");
            numero -= 4;
        }
        else if(numero>=1)
        {
            printf("I");
            numero -= 1;
        }
    }
  printf("\n");

}