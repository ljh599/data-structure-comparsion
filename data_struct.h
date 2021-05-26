#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/time.h>
#define MAXhash  (1 << 20)
struct node{
    struct node* left;
    struct node* right;
    struct node* next;
    int data;
};

int* array_building(int *N, int *array, int size);
void array_finding(int *M, int *array, int a_size, int M_size);
struct node* ll_insert(int *N, struct node* head, int size);
void ll_find(int *M, struct node* head, int M_size);
struct node* bst_insert(int *N, struct node* root, int size);
void bst_find(int *M, int M_size, struct node *root);
int *BS_array_building(int *N, int *BSarray, int size);
void BS_array_finding(int *M, int *BSarray, int M_size, int size);
struct node **buildHash(int *data, int size);
void hash_find(int *M, int M_size, struct node **HTable);