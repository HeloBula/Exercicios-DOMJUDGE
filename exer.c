#include <stdio.h>
#include <string.h>

int palindromo(char *palavra, int ind, int tamanho);
int palindromeio(char *palavra,int tamanho);

int main(){
    char palavra[2001];
    int tam=0,i;

    scanf("%s",palavra);
    tam=strlen(palavra);

    printf("%d",palindromeio(palavra, tam));

return 0;
}

int palindromo(char *palavra, int ind, int tamanho){ //Ver se é palindromo total
    if (ind > tamanho/2)
        return 1;
    else
    {   if (palavra[ind] != palavra[tamanho-1-ind])
            return 0;
        else
            return palindromo(palavra, ++ind, tamanho);        
    }
}

int palindromeio(char *palavra,int tamanho){
    int i,j,k,count;
    char nome[tamanho];

    for(i=tamanho;i>0;i--)
    {
      for(j=0;j<tamanho-i+1;j++) //Pega o tamanho total, tira o i e acrescenta 1.
      { count=0;
        for(k=j;k<i+j;k++) //Para escrever a substring no nome
        {
          nome[count]=palavra[k];
          count++;
        } 
        nome[count]='\0';
        if(palindromo(nome, 0, i)==1)
        {
         return i; //Como está indo do maior pro menor, o i vai ser o maior palindromo dentro da palavra
        }
      }
    }
return 0;
}