#include"data_struct.h"
struct node* ll_insert(int *N, struct node* head, int size){
    int i, j;
    struct node *newnode, *tmp;
    
    for(i = 0; i < size; i++){
        if(i == 0){
            newnode = (struct node*)malloc(sizeof(struct node));
            newnode->data = N[i];
            newnode->next = NULL;
            head = newnode;
        }
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = N[i];
        newnode->next = NULL;
        tmp = head;
        head = newnode;
        head->next = tmp;
    }
    return head;
}

void ll_find(int *M, struct node* head, int M_size){
    int i, j;
    struct node* tmp;
    for(i = 0; i < M_size; i++){
        tmp = head;
        while(tmp){
            if(tmp->data == M[i]){
                break;
            }
            tmp = tmp->next;
        }
    }
}
