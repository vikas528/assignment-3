#include <stdio.h>
#define N 1000000

int arr[N] = {0};

void insertAtLast(int arr[], int n, int key){
    arr[n] = key;
}

void insertAtHead(int arr[], int n, int key){
    for(int i=n; i>0; i--)
        arr[i]=arr[i-1];
    arr[0]=key;
}

void insertAtI(int arr[], int n, int key, int i){
    for(int p=n; p>i; p--)
        arr[p]=arr[p-1];
    arr[i]=key;
}

void delFromLast(int arr[], int *n){
    --*n;
}

void delFromFirst(int arr[], int n){
    for(int p=1; p<n; p++)
        arr[p-1]=arr[p];
}

void delFromI(int arr[], int n, int i){
    for(int p=i; p<n-1; p++)
        arr[p] = arr[p+1];
}

int unsortedAscending(int arr[], int n){
    for(int i=0; i<n-1; i++)
        if(arr[i+1]<arr[i])
            return i+1;
    return -1;
}

int unsortedDescending(int arr[], int n){
    for(int i=0; i<n; i++)
        if(arr[i+1]>arr[i])
            return i+1;
    return -1;
}

int sortedAscending(int arr[], int n){
    for(int i=0; i<n-1; i++)
        if(arr[i]<arr[i+1])
            return i;
    return -1;
}

int sortedDescending(int arr[], int n){
    for(int i=0; i<n; i++)
        if(arr[i]>arr[i+1])
            return i;
    return -1;
}

void sortArray(int arr[], int n){
    for(int i=1; i<n; i++)
        for(int j=0; j<n-1; j++)
            if(arr[j]>arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
}

void extractSubset(int arr[], int n, int i, int j){
    for(int p=i; p<=j; p++)
        printf("%d ", arr[p]);
    printf("\n");
}

void deleteSubset(int arr[], int n, int i, int j){
    for(int p=i; p<n; p++){
        if(p+j>=n)
            break;
        arr[p]=arr[p+j];
    }
}

void splitArray(int arr[], int n){
    printArray(arr, n);
}

void cloneArray(int arr[], int n, int brr[]){
    for(int i=n; i<2*n; i++)
        arr[i]=brr[i-n];
}

void shiftLeft(int arr[], int n){
    int current = arr[0];
    for(int i=1; i<n; i++)
        arr[i-1] = arr[i];
    arr[n-1]=current;
}

void shiftRight(int arr[], int n){
    int current = arr[n-1];
    for(int i=n-1; i>0; i--)
        arr[i]=arr[i-1];
    arr[0]=current;
}

void rotateArrayClockwise(int arr[],int n,int r){
    for(int i=1; i<=r; i++)
        shiftRight(arr,n);
}

void rotateArrayAntiClockwise(int a[],int n,int r){
    for(int i=1; i<=r; i++)
        shiftLeft(a,n);
}

int minim(int arr[],int n){
    int ans=0;
    for (int i=0;i<n;i++)
        if(arr[i]<arr[ans])
            ans=i;
    return ans;
}

int maxim(int arr[],int n){
    int ans=0;
    for(int i=1;i<n;i++)
        if(arr[i]>arr[ans])
            ans=i;
    return ans;
}

void fillPseudoRandom(int arr[],int n){
    for(int i=0; i<n; i++)
        arr[i]=rand();
}

void fillTrueRandom(int arr[],int n){
    srand(time(0));
    for(int i=0; i<n; i++)
        arr[i]=rand();
}

void setToZero(int arr[],int n){
    for(int i=0; i<n; i++)
        arr[i]=0;
}

void deletion(int arr[],int n){
    for(int i=0; i<n; i++)
        free(arr[i]);
}

void printArray(int arr[],int n){
    for(int i=0; i<n; i++)
        printf("%d ",arr[i]);
    printf("\n");
}

int main(){
    int n, m;
    printf("Enter the initial no. of elements in Array\n");
    scanf("%d", &n);
    printf("Enter the elements\n");
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    int key, i, j, r;
    int brr[100000];
    printf("Hello\n");
    printf("Enter choice:\n0. All Operations Completed\n1. Insert item at last\n2. Insert Item At First\n3. Insert Item At Index\n4. DeleteItemFromLast\n5. Delete Item from First\n6. DeleteItemFromIndex\n7. Find Item Unsorted\n8. Find Item sorted\n9. Sort Array\n10. ExtractSubset\n11. DeleteSubset\n12. Split Into two Array\n13. m. CloneArray\n14. ShiftLeftArray\n15. ShiftRightArray\n 16. RotateArrayClockwise\n 17. RotateArrayAntiClockwise\n 18. FindMin\n20. FillArrayPseudoRandom\n21. FillArrayTrueRandom\n22. IncreaseArraySize\n23. SetArrayToZero\n24. DeleteAllItemOfArray\n25. DeleteArray\n26. AllocateArray\n27. PrintArray\n");
    int choice;
    do {
        printf("\nEnter choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            printf("Operations have been performed successfully");
            break;
        case 1:
            printf("Enter the number to be inserted\n");
            scanf("%d", &key);
            insertAtLast(arr, n, key);
            n++;
            printf("Array has been updated");
            break;
        case 2:
            printf("Enter the number to be inserted\n");
            scanf("%d", &key);
            insertAtHead(arr, n, key);
            n++;
            printf("Array has been updated\n");
            break;
        case 3:
            printf("Enter the number to be inserted and enter the index respectively\n");
            scanf("%d %d", &key, &i);
            insertAtI(arr, n, i, key);
            n++;
            printf("Array has been updated\n");
            break;
        case 4:
            delFromLast(arr, &n);
            printf("Array has been updated\n");
            break;
        case 5:
            delFromFirst(arr, n);
            n--;
            printf("Array has been updated\n");
            break;
        case 6:
            printf("Enter the index to be deleted from\n");
            scanf("%d", &i);
            delFromI(arr, n, i);
            n--;
            break;
        case 7:
            printf("Considering the array to be a ascending array, the Unsorted element is: ");
            printf("%d\n", unsortedAscending(arr, n));
            printf("Considering the array to be a descending array, the Unsorted element is: ");
            printf("%d\n", unsortedDescending(arr, n));
            break;
        case 8:
            printf("For ascending: ");
            printf("%d\n",sortedAscending(arr,n));
            printf("For descending: ");
            printf("%d\n",sortedDescending(arr,n));
            break;
        case 9:
            sortArray(arr,n);
            printf("Array has been Sorted\n");
            break;
        case 10:
            printf("Enter the starting and ending indexes of the subarray in the given array\n");
            scanf("%d %d",&i,&j);
            extractSubset(arr,n,i,j);
            break;
        case 11:
            printf("Enter the the starting and ending indexed of the subset to be deleted\n");
            scanf("%d %d",&i,&j);
            deleteSubset(arr,n,i,j);
            printf("Required subset has been deleted\n");
            n=n-j+i-1;
            break;
        case 12:
            printf("Array after splitting:\n");
            n=n/2+1;
            splitArray(arr,n);
            break;
        case 13:
            printf("Enter %d elements for 2nd array\n",n);
            for(int i=0;i<n;i++)
                scanf("%d",&brr[i]);
            cloneArray(arr,n,brr);
            n*=2;
            printf("Cloning has been done\n");
            break;
        case 14:
            shiftLeft(arr,n);
            printf("Array has been shifted left\n");
            break;
        case 15:
            shiftRight(arr,n);
            printf("Array has been shifted right\n");
            break;
        case 16:
            printf("Enter no of rotations\n");
            scanf("%d",&r);
            r=r%n;
            rotateArrayClockwise(arr,n,r);
            printf("Array has been rotated\n");
            break;
        case 17:
            printf("Enter no of rotations\n");
            scanf("%d",&r);
            r=r%n;
            rotateArrayAntiClockwise(arr,n,r);
            printf("Array has been rotated\n");
            break;
        case 18:
            printf("The index containing the minimum element is :%d\n", minim(arr,n));
            break;
        case 19:
            printf("The index containing the maximum element is :%d\n", maxim(arr,n));
            break;
        case 20:
            fillPseudoRandom(arr,n);
            printf("Array has been filled with pseudo random numbers\n");
            break;
        case 21:
            fillTrueRandom(arr,n);
            printf("Array has been filled with true random numbers\n");
            break;
        case 22:
            printf("Enter the new size of Array\n");
            scanf("%d",&m);
            printf("Size of Array has been changed from %d to %d\n",n,m);
            if(m>n)
                printf("%d elements are filled with garbage values\n",m-n);
        case 23:
            setToZero(arr,n);
            break;
        case 24:
            n=0;
            printf("Elements Of array has been deleted");
            break;
        case 25:
            deletion(arr,n);
            free(arr);
            n=0;
            break;
        case 26:
            printf("Enter the new size of array\n");
            scanf("%d",&m);
            printf("The address of newly allocated array is: %p\n",&brr[0]);
            break;
        case 27:
            printArray(arr,n);
            break;
        default:
            printf("Wrong Case");
            break;
        }
    }while(choice>=1 && choice<=27);
    return 0;
}