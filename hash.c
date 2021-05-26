#include"data_struct.h"


struct node* Hash_insert(struct node *n, int data){
    struct node *newN = (struct node*)malloc(sizeof(struct node));
    struct node *tmp;
    newN->data = data;
    newN->next = NULL;
    if(n->next == NULL){
        return newN;
    }
    tmp = n;
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = newN;
    return n;
}

struct node **buildHash(int *N, int size){
    int  i, hv;
    struct node **HTable;
    HTable = (struct node**)malloc(MAXhash * sizeof(struct node*));
    for(i = 0; i < MAXhash; i++){
        HTable[i] = (struct node*)malloc(sizeof(struct node));
    }
    for(i = 0; i < MAXhash; i++){
        HTable[i]->next = NULL;
    }
    for(i = 0 ; i <= size ; i++){
        struct node *dptr;
        hv = N[i] % MAXhash;
        dptr = HTable[hv];
        HTable[hv] = Hash_insert(dptr,N[i]);
    }
    return HTable;
}

void list_find(struct node *n, int data){
    while(n){
        if(n->data == data)
            break;
        else
            n = n -> next;
    }
}

void hash_find(int *M, int M_size, struct node **HTable){
    int i, hv;
    for(i = 0 ;  i <= M_size ; i++){
        hv = M[i] % MAXhash;
        struct node  *dqtr = HTable[hv];
        list_find(dqtr,M[i]);
    }
}