#include"data_struct.h"

int BinarySearch(int a[], int item,int low, int high){
    if (high <= low){
        return (item > a[low]) ?(low + 1) : low;
    }
    int mid = (low + high) / 2;
 
    if (item == a[mid]){
        return (mid + 1);
    }
    if (item > a[mid]){
        return BinarySearch(a, item, mid + 1, high);
    }
    return BinarySearch(a, item, low, mid - 1);
}
//insertion sort 用binary search 比較
int *BS_array_building(int *N, int *BSarray, int size){
    int i, j, pos, key;
    BSarray = (int*)malloc(sizeof(int) * size);
    //先建立binary search 的資料庫
    for(i = 0; i < size; i++){
        BSarray[i] = N[i];
    }
    for (i = 1; i < size; i++){
        j = i - 1;
        key = BSarray[i];
        //找到key應該放的位置
        pos = BinarySearch(BSarray, key, 0, j);
        while(j >= pos){
            BSarray[j + 1] = BSarray[j];
            j--;
        }
        BSarray[j + 1] = key;
    }
    return BSarray;
}

void binarysearch(int a[], int item, int low, int high){
    //找到底還沒找到直接return
    if(high <= low)return;
    int mid = (low + high) / 2;
    //如果有找到也直接return
    if(item == a[mid])return;

    if(item > a[mid]){
        binarysearch(a, item, mid + 1, high);
    }
    else{
        binarysearch(a, item, low, mid - 1);
    }
}

void BS_array_finding(int *M, int *BSarray, int M_size, int size){
    int i;
    for(i = 0; i < M_size; i ++){
        binarysearch(BSarray, M[i], 0, size - 1);
    }
}