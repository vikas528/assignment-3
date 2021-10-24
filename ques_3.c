#include <stdio.h>
#define N 50000

void sieveOfErastosthenes(long long int arr[], long long int brr[], long long int n){
    for(long long int i=2; i<n; i++){
        if(arr[i]!=i){
            brr[i]=0;
            continue;
        }
        for(long long int j=i; j<=n; j+=i)
            if(arr[j]==j){
                arr[j]=i;
                int k=j+i;
                if(k<=n)
                    brr[k]=0;
            }
    }
}

int main()
{
    long long int arr[N], brr[N];
    for(long long int i=0; i<N; i++){
        arr[i]=i;
        brr[i]=i;
    }
    printf("Enter the number:\n");
    sieveOfErastosthenes(arr, brr, N);
    long long int n;
    scanf("%lld", &n);
    
    for(int i=2; i<=n; i++)
        if(brr[i])
            printf("%d ", brr[i]);
    return 0;
}
