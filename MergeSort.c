#include <stdio.h>
#include <stdlib.h>
void Merge(int A[],int p,int q,int r)
{
    int n1 = q-p+1;  // 2-1+1
    int n2 = r-q;     //4-2
    int L[n1];
    int R[n2];
    int i,j,k;
    for(i=1;i<n1;i++)
    {
        L[i]=A[p+i];          // Copying the elements of the first subarray 
    }
    for(j=1;j<n2;j++)
    {
        R[j]=A[q+1+j];
    }
    i=0;
    j=0;
    k=1;
    while(i < n1 && j < n2 )
    {
        if(L[i]<=R[j])
        {
            A[k]=L[i];
            i++;
        }
        else 
        {
            A[k]=R[j];
            j++;
        }
        k++;
    }
     while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }
     while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }
}
void MergeSort(int A[], int p, int r) // First index and r is the last position or index 
{
    if(p<r)
    {
        int q= p + (r-1) / 2;       // Divides into two parts
        MergeSort(A, p, q); 
        MergeSort(A, q+1, r);
        Merge(A, p, q, r);
    }
}
void display(int A[],int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        printf("%d ",A[i]);    
    }
    printf("\n");
}
int main()
{
    int A[]={33,12,34,64};
    int size = sizeof(A) / sizeof(A[0]);
    printf("The given array is \n");
    display(A,size);

    MergeSort(A,0,size-1);

    printf("Sorted array is \n");
    display(A,size);
    return 0;
}