#include <stdio.h>
#include <stdlib.h>

typedef struct list {
  int tempo;
  int carga;
  struct list *prox;
} Lista;

Lista *transforma() {
  Lista *aux = malloc(sizeof(Lista));
  scanf("%d", &aux->tempo);
  scanf("%d", &aux->carga);
  aux->prox = NULL;
  return aux;
}

Lista *inserir(Lista *h, Lista *p) {
  Lista *aux, *anterior;
  if (h == NULL)
    return p;

  aux = anterior = h;

  while (aux->prox && p->tempo > aux->tempo) {
    anterior = aux;
    aux = aux->prox;
  }

  if (aux == h) {
    if (p->tempo > aux->tempo) {
      p->prox = h->prox;
      h->prox = p;
      return h;
    } else {
      p->prox = h;
      return p;
    }
  }

  if (p->tempo > aux->tempo) {
    p->prox = aux->prox;
    aux->prox = p;
  } else {
    p->prox = aux;
    anterior->prox = p;
  }
  return h;
}

void retiraitem(Lista **h, int carga) {
  Lista *aux = *h, *anterior;
  if (aux != NULL && aux->carga == carga) {
    *h = aux->prox;
    free(aux);
    return;
  }
  while (aux != NULL && aux->carga != carga) {
    anterior = aux;
    aux = aux->prox;
  }
  if (aux == NULL)
    return;
  anterior->prox = aux->prox;
  free(aux);
}

int busca(Lista *h, int inicio) {
  Lista *aux = h;
  int maior = 0;
  while (aux && aux->tempo <= inicio) {
    if (aux->carga > maior) {
      maior = aux->carga;
    }
    aux = aux->prox;
  }
  return maior;
}
int main() {
  int N, i, inicio = 10001, maior, *resp; //Esse maximo no inicio é definido no exer
  Lista *lista = NULL, *new; //inicia a lista vazia
  scanf("%d", &N);

  resp = malloc(N * sizeof(int));

  for (i = 0; i < N; i++) 
  {
    new = transforma();
    if (new->tempo < inicio)
      inicio = new->tempo;
    lista = inserir(lista, new);
  }

  i = 0;

  while (lista) {
    maior = busca(lista, inicio);
    if (maior == 0) {
      inicio = lista->tempo;
      maior = busca(lista, inicio);
    }
    retiraitem(&lista, maior);
    resp[i] = maior;
    i++;
    inicio += maior;
  }

  for (i = 0; i < N; i++) {
    printf("%d ", resp[i]);
  }
  printf("\n");

  return 0;
}