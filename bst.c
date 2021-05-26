#include"data_struct.h"

struct node* insert(struct node* root, int num){
    struct node* newnode;
    if(root == NULL){
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->left = newnode->right = NULL;
        newnode->data = num;
        root = newnode;
    }
    else if(root->data > num){
        root->right = insert(root->right, num);
    }
    else if(root->data < num){
        root->left = insert(root->left, num);
    }
    return root;
}
struct node* bst_insert(int *N, struct node* root, int size){
    int i;
    for(i = 0; i < size; i++){
        root = insert(root, N[i]);
    }
    return root;
}

void bst_find(int *M, int M_size,  struct node* root){
    int i;
    struct node* tmp;
    for(i = 0; i < M_size; i++){
        tmp = root;
        while(tmp != NULL && tmp->data != M[i]){
            if(tmp->data > M[i]){
                tmp = tmp->left;
            }
            else{
                tmp = tmp->right;
            }
        }
    }
}