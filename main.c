#include"data_struct.h"
int main(int argc, char **argv){
    int *N, *M, *array, *BSarray, i, N_size, M_size;
    struct node *head = NULL;
    struct node *root = NULL;
    struct node **HTable;
    struct timeval start;
	struct timeval end;
	unsigned long diff;//diff用微秒表示
    N_size = atoi(argv[2]);
    M_size = atoi(argv[4]);

    N = (int*)malloc(sizeof(int) * N_size);
    M = (int*)malloc(sizeof(int) * M_size);
    //產生插入的N筆資料
    for(i = 0; i < N_size; i++){
        N[i] = rand();
    }
    //產生搜尋用的M筆資料
    for(i = 0; i < M_size; i++){
        M[i] = rand();
    }
    for(i = 5; i < argc; i++){
        if(strcmp(argv[i], "-arr") == 0){
            printf("arr:\n");
            //計算建立的時間
            gettimeofday(&start, NULL);
            array = array_building(N, array, N_size);
            gettimeofday(&end, NULL);
            diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;//tv_sec :秒, tv_usec:微秒
            printf("building time: %f sec\n", (float)diff/1000000);

            gettimeofday(&start, NULL);
            array_finding(M, array, N_size, M_size);
            gettimeofday(&end, NULL);
            diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;//tv_sec :秒, tv_usec:微秒
            printf("query time: %f sec\n", (float)diff/1000000);
        }
        else if(strcmp(argv[i], "-ll") == 0){
            printf("ll:\n");
            //計算建立的時間
            gettimeofday(&start, NULL);
            head = ll_insert(N, head, N_size);
            gettimeofday(&end, NULL);
            diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;//tv_sec :秒, tv_usec:微秒
            printf("building time: %f sec\n", (float)diff/1000000);

            gettimeofday(&start, NULL);
            ll_find(M, head, M_size);
            gettimeofday(&end, NULL);
            diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;//tv_sec :秒, tv_usec:微秒
            printf("query time: %f sec\n", (float)diff/1000000);
        }
        else if((strcmp(argv[i], "-bst")) == 0){
            printf("bst:\n");
            //計算建立的時間
            gettimeofday(&start, NULL);
            root = bst_insert(N, root, N_size);
            gettimeofday(&end, NULL);
            diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;//tv_sec :秒, tv_usec:微秒
            printf("building time: %f sec\n", (float)diff/1000000);

            gettimeofday(&start, NULL);
            bst_find(M, M_size, root);
            gettimeofday(&end, NULL);
            diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;//tv_sec :秒, tv_usec:微秒
            printf("query time: %f sec\n", (float)diff/1000000);
        }
        else if(strcmp(argv[i], "-bs") == 0){
            printf("bs:\n");
            //計算建立的時間
            gettimeofday(&start, NULL);
            BSarray = BS_array_building(N, BSarray, N_size);
            gettimeofday(&end, NULL);
            diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;//tv_sec :秒, tv_usec:微秒
            printf("building time: %f sec\n", (float)diff/1000000);
            
            gettimeofday(&start, NULL);
            BS_array_finding(M, BSarray, M_size, N_size);
            gettimeofday(&end, NULL);
            diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;//tv_sec :秒, tv_usec:微秒
            printf("query time: %f sec\n", (float)diff/1000000);
            
        }
        else if(strcmp(argv[i], "-hash") == 0){
            printf("hash:\n");
            //計算建立的時間
            gettimeofday(&start, NULL);
            HTable = buildHash(N, N_size);
            gettimeofday(&end, NULL);
            diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;//tv_sec :秒, tv_usec:微秒
            printf("building time: %f sec\n", (float)diff/1000000);
            
            gettimeofday(&start, NULL);
            hash_find(M, M_size, HTable);
            gettimeofday(&end, NULL);
            diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;//tv_sec :秒, tv_usec:微秒
            printf("query time: %f sec\n", (float)diff/1000000);
        }
        else{
            printf("The %dth is illegal parameter\n", i+1);
        }
        printf("\n");
    }

    free(N);
    free(M);
    free(array);
    free(BSarray);
}
