#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define N 50000

void insertSort(int arr[], int n){
    for(int i=1; i<n; i++){
        int key = arr[i];
        int j = i-1;

        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main() {
    int arr1[N], arr2[N], arr3[N];
    clock_t start1, start2, start3;
    clock_t end1, end2, end3;
    double t1, t2, t3;
    //1. Best case
    for(int i=0; i<N; i++)
        arr1[i]=i;
    start1 = clock();
    insertSort(arr1, N);
    end1 = clock();
    t1 = end1-start1;
    //time consumed check
    printf("Time elapsed: %f\n", (double)t1/(double)CLOCKS_PER_SEC);

    //2. Average case
    for(int i=0; i<N; i++)
        arr2[i]=rand()%1000;
    start2 = clock();
    insertSort(arr2, N);
    end2 = clock();
    t2 = end2-start2;
    //time consumed check
    printf("Time elapsed: %f\n", (double)t2/(double)CLOCKS_PER_SEC);

    //3. Worst case
    for(int i=0; i<N; i++)
        arr3[i]=N-i-1;
    start3 = clock();
    insertSort(arr3, N);
    end3 = clock();
    t3 = end3-start3;
    //time consumed check
    printf("Time elapsed: %f\n", (double)t3/(double)CLOCKS_PER_SEC);
    return 0;
}