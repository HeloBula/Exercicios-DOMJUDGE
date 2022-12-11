#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct letras
{
  char pal[50]; // numero de letra de cada palavra máximo
  struct letras *prox;
} palavra;

palavra *alocar(char *novapalavra)
{
  palavra *nova;
  nova = malloc(sizeof(palavra)); // Eu estou alocando um espaço pra minha struct que será apontada pelo ponteiro
  strcpy(nova->pal, novapalavra);
  nova->prox = NULL;
  return (nova); // Retornando o ponteiro
}

palavra *inserepalavra(palavra *h, palavra *p);
void printarlista(palavra *head);
void tiraritem(palavra **h,char *novapalavra);

int main()
{
  int i, op;
  int N, M; // N é numero inicial de palavras e M é o número de operações
  scanf("%d", &N);
  scanf("%d", &M);
  char novapalavra[50];
  palavra *aux;

  palavra *head;
  head = NULL;

  for (i = 0; i < N; i++)
  {
    scanf(" %s", novapalavra);
    aux = alocar(novapalavra); // Crio a nova struct com a palavra
    head = inserepalavra(head, aux);
  }
  for (i = 0; i < M; i++)
  {
    scanf("%d %s", &op, novapalavra);
    if (op == 1) // Insere a palavra
    {
      aux = alocar(novapalavra);
      head = inserepalavra(head, aux);
    }
    else if(op == 0)
    {
      tiraritem(&head,novapalavra);//Como é um pnteiro de ponteiro eu passo o endereço
      if(head==NULL)
        printf("NULL\n");
      else{  
      printarlista(head);
      }
    }
  }

  return 0;
}

palavra *inserepalavra(palavra *h, palavra *p)
{
  palavra *anterior, *aux;
  if (!h) // Cabeça nula
    return p;
  aux = anterior = h;
  while (aux->prox && strcmp(p->pal, aux->pal) > 0)
  {
    anterior = aux;
    aux = aux->prox;
  }
  if (aux == h) // Se for igual a cabeça
  {
    if (strcmp(p->pal, h->pal) < 0)
    {
      p->prox = h;
      return p;
    }
    else if (strcmp(p->pal, h->pal) > 0)
    {
      p->prox = h->prox;
      h->prox = p;
      return h;
    }
    else
    { // Se forem o mesmo
      return h;
    }
  }
  // Quando for diferente da cabeça
  if (strcmp(p->pal, aux->pal) < 0)
  {
    anterior->prox = p;
    p->prox = aux;
    return h;
  }
  else if (strcmp(p->pal, aux->pal) > 0)
  {
    p->prox = aux->prox;
    aux->prox = p;
    return h;
  }
  else
  {
    return h;
  }
}

void printarlista(palavra *head)
{
  palavra *aux = head;

  while (aux != NULL)
  {
    printf("%s ", aux->pal);
    aux = aux->prox;
  }
  printf("\n");
}

void tiraritem(palavra **h,char *novapalavra){
  palavra *aux;
  aux = *h;
  palavra *anterior;
 
    // If head node itself holds the key to be deleted
    if (aux != NULL && strcmp(aux->pal,novapalavra)==0) {
        *h = aux->prox; // Changed head
        free(aux); // free old head
        return;
    }
 
    
    // previous node as we need to change 'prev->next'
    while (aux != NULL && strcmp(aux->pal,novapalavra)!=0) { //Elemento no meio da lista, roda até achar um igual
        anterior = aux;
        aux = aux->prox;
    }
 
    // If key was not present in linked list
    if (aux == NULL)
        return;
 
    // Retira o do meio e linka os outros dois
    anterior->prox = aux->prox;
 
    free(aux); // Free memory
}
 