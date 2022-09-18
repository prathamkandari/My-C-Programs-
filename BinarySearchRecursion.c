#include<stdio.h>
int BS(int a[],int i, int j, int element)
{
    int mid=0;
    mid=(i+j)/2;
    if(a[mid]== element)
        return mid;
    else if(a[mid]>element)
        return BS(a,i,mid-1,element);
    else 
        return BS(a,mid+1,j,element);
}

int main()
{
    int n,element;
    printf("Enter the size of the array \n");
    scanf("%d",&n);
    printf("Enter the element to be found \n");
    scanf("%d",&element);
    printf("Enter the elements in the array \n");
    int a[n],i=0,j=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int result = BS(a,0,n-1,element);
    printf("Element found at %d position",(result+1));
    return 0;
}