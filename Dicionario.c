#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct lista
{ // Simplesmente encadeada
    char palavra[100];
    struct lista *prox;
} pal;

pal *alocar(char *p);
void insere(pal **h, pal *s);
void imprime(pal *h, char *s);
void remover(pal **h, char *palavrinha);

int main()
{
    pal *h = NULL, *s;
    char p[100], palavrinha[70];
    int N, M, i;
    int op;

    scanf("%d %d", &N, &M);

    for (i = 0; i < N; i++)
    {
        scanf(" %s", p);
        s = alocar(p);
        insere(&h, s);
    }

    for (i = 0; i < M; i++)
    {
        scanf("%d %s", &op, palavrinha);

        if (op == 0)
        {
            remover(&h, palavrinha);
        }
        else if (op == 1)
        {
            s = alocar(palavrinha);
            insere(&h, s);
        }
        else if (op == 2)
        {
            imprime(h, palavrinha);
        }
    }
    return 0;
}

pal *alocar(char *p)
{
    pal *aux;
    aux = malloc(sizeof(pal));
    strcpy(aux->palavra, p);
    aux->prox = NULL;
    return aux;
}

void insere(pal **h, pal *s)
{
    pal *anterior, *aux;
    if (!(*h))// Cabeça nula
       { *h = s;
        return;}
    aux = anterior = (*h);
    while (aux->prox && strcmp(s->palavra, aux->palavra) > 0)
    {
        anterior = aux;
        aux = aux->prox;
    }
    if (aux == (*h)) // Se for igual a cabeça
    {
        if (strcmp(s->palavra, (*h)->palavra) < 0)
        {
            s->prox = (*h);
            (*h)=s;
            return;
        }
        else if (strcmp(s->palavra, (*h)->palavra) > 0)
        {
            (*h)->prox = s;
            return;
        }
        else
        { // Se forem o mesmo
            return;
        }
    }
    // Quando for diferente da cabeça
   if(strcmp(s->palavra,aux->palavra)>0){ 
    aux->prox = s; //último da lista
      }
   else if(strcmp(s->palavra,aux->palavra)<0){ //Parar no meio da lista
    s->prox = aux;
    anterior->prox = s;
  }
    return;
}

void imprime(pal *h, char *s)
{
    pal *aux = h;

    while (aux != NULL && strcmp(aux->palavra, s) < 0) // Enquanto não achar o lugar
    {
        aux = aux->prox;
    }
    if (aux == NULL) // Se não tiver nada na Lista, imprime NULL
    {
        printf("NULL");
        printf("\n");
        return;
    }

    while (aux != NULL)
    {
        printf("%s ", aux->palavra); // Imprimir as palavras restantes a partir da que eu quero
        aux = aux->prox;
    }
    printf("\n");
    return;
}

void remover(pal **h, char *palavrinha)
{
    pal *aux = (*h), *anterior;

    while (aux != NULL && strcmp(aux->palavra, palavrinha) != 0) // Enquanto não for o fim da lista e não tiver achado
    {
        anterior = aux;
        aux = aux->prox;
    }
    if(aux == NULL)
     return;

    if (strcmp(aux->palavra, palavrinha) == 0) // é igual
    {   if(aux==*h) //Se eu quero tirar a cabeça
        {
            *h = aux->prox;
            free(aux);
            return;
        }
        anterior->prox = aux->prox;
        free(aux);
        return;
    }
    return;
}
