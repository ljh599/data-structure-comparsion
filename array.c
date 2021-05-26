#include"data_struct.h"

int * array_building(int *N, int *array, int size){
    int i;
    array = (int*)malloc(sizeof(int) * size);
    for(i = 0; i < size; i++){
        array[i] = N[i];
    }
    return array;
}

void array_finding(int *M, int *array, int a_size, int M_size){
    int i, j;
    for(i = 0; i < M_size; i++){
        for(j = 0; j < a_size; j++){
            if(array[j] == M[i]){
                break;
            }
        }
    }
}