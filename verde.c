#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
  int idade;
  int tempo;
  struct fila *prox;
} Fila;
//Pasa cabeca e cauda
void insere_aux(Fila **h, Fila **t, int idade, int tempo) {
  Fila *novo = malloc(sizeof(Fila)), *aux, *aux_anterior;
  novo->idade = idade;
  novo->tempo = tempo;

  if (*h == NULL) {
    *h = novo;
    *t = novo;
    (*h)->prox = NULL;
    return;
  } //Compara tempo e idade se for idoso
  if (novo->tempo < (*h)->tempo || (novo->tempo == (*h)->tempo && novo->idade > 59 && novo->idade > (*h)->idade)) {
    novo->prox = *h;
    *h = novo;
    return;
  }
//se nao for idoso, so compara o tempo
  if (novo->tempo > (*t)->tempo) {
    novo->prox = NULL;
    (*t)->prox = novo;
    *t = novo;
    return;
  }

  aux = (*h)->prox;
  aux_anterior = *h;
  while (aux != NULL) {
    if (novo->tempo < aux->tempo || (novo->tempo == aux->tempo && novo->idade > 59 && novo->idade > aux->idade)) {
      aux_anterior->prox = novo;
      novo->prox = aux;
      return;
    }
    aux_anterior = aux;
    aux = aux->prox;
  }

  if (novo->tempo == (*h)->tempo && ((*h)->prox == NULL || (*h)->prox->tempo != novo->tempo)) {
    novo->prox = (*h)->prox;
    (*h)->prox = novo;
    return;
  }

  aux = (*h)->prox;
  while (aux != NULL) {
    if (novo->tempo == aux->tempo && (aux->prox == NULL || aux->prox->tempo != novo->tempo)) {
      novo->prox = aux->prox;
      aux->prox = novo;
      if (novo->prox == NULL) 
        *t = novo;
      return;
    }
    aux = aux->prox;
  }
}

void insere(Fila **h, Fila **t, int idade, int tempo) {
  Fila *novo = malloc(sizeof(Fila));//Alocando espaco
  novo->idade = idade;
  novo->tempo = tempo;
  Fila *aux, *aux_anterior;
  if (*h == NULL) {
    *h = novo;
    *t = novo;
    (novo)->prox = NULL;
    return;
  }//insere com prioridade
  if ((novo)->idade > 59) {
    if ((novo)->idade > (*h)->idade) {
      (novo)->prox = *h;
      *h = novo;
      return;
    }
    aux = (*h)->prox;
    aux_anterior = (*h);
    while (aux != NULL) {
      if ((novo)->idade > aux->idade) {
        aux_anterior->prox = novo;
        (novo)->prox = aux;
        return;
      }
      aux_anterior = aux;
      aux = aux->prox;
    }
  }
  (*t)->prox = novo;
  (novo)->prox = NULL;
  *t = novo;
}

void remover(Fila **h, Fila **t) {
  if (*h == NULL) return;
  if ((*h)->prox == NULL) {
    free(*h);
    *h = NULL;
    *t = NULL;
    return;
  }
  if ((*h)->prox == *t) {
    free(*h);
    *h = *t;
    return;
  }
  Fila *aux = *h;
  *h = (*h)->prox;
  free(aux);
}

void imprime(Fila *h) {
  while (h != NULL) {
    printf("%d ", h->idade);
    h = h->prox;
  }
  printf("\n");
}

int main() {
  int i, N, idade, tempo, tempoTotal, tempo_atual = 3, idade_atual;
  Fila *head_aux = NULL, *tail_aux = NULL, *head = NULL, *tail = NULL;
  scanf("%d", &N);
  for (i = 0; i < N; i++) {
    scanf("%d %d", &idade, &tempo);
    insere_aux(&head_aux, &tail_aux, idade, tempo);
  }
  tempoTotal = head_aux->tempo;
  idade_atual = head_aux->idade;
  insere(&head, &tail, head_aux->idade, head_aux->tempo);
  remover(&head_aux, &tail_aux);
  int inseriu = 1;
  while (!(head_aux == NULL && head == NULL)) {
    if (tempo_atual >= 3) {
      tempo_atual = 0;
      if (head == NULL) {
        insere(&head, &tail, head_aux->idade, head_aux->tempo);
        tempoTotal = head_aux->tempo;
        remover(&head_aux, &tail_aux);
        inseriu = 1;
      }
      idade_atual = head->idade;
      remover(&head, &tail);
    }
    while (head_aux != NULL && tempoTotal >= head_aux->tempo) {
      insere(&head, &tail, head_aux->idade, head_aux->tempo);
      remover(&head_aux, &tail_aux);
      inseriu = 1;
    }
    if (inseriu) {
      printf("%d ", idade_atual);
      imprime(head);
    }
    tempo_atual++;
    tempoTotal++;
    inseriu = 0;
  }

  return 0;
}