#include <stdio.h>
#define N 500000

void sieveOfErastosthenes(long long int arr[], long long int n){
    for(long long int i=2; i<n; i++){
        if(arr[i]!=i)
            continue;
        for(long long int j=i; j<=n; j+=i)
            if(arr[j]==j)
                arr[j]=i;
    }
}

int main()
{
    long long int arr[N];
    for(long long int i=0; i<N; i++)
        arr[i]=i;
    printf("Enter the number:\n");
    sieveOfErastosthenes(arr, N);
    // for(int i=0; i<N; i++)
    //     printf("%d ", arr[i]);
    long long int n;
    scanf("%lld", &n);
    printf("Prime factors of %lld will be:\n", n);
    
    while(n>1){
        printf("%lld ", arr[n]);
        n/=arr[n];
        if(n==1)
            break;
    }
    return 0;
}
