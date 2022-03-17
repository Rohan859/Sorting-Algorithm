#include <iostream>
using namespace std;
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int A[],int lb,int ub)
{
    int pivot=A[lb];
    int start=lb;
    int end=ub;
    while(start<end)
    {
        while(A[start]<=pivot)
        {
            start++;
        }
        while(A[end]>pivot)
        {
            end--;
        }
        if(start<end)
        {
            swap(&A[start],&A[end]);
        }
    }
    swap(&A[lb],&A[end]);
    return end;
}

void quicksort(int A[],int lb,int ub)
{
    if(lb<ub)
    {
        int loc=partition(A,lb,ub);
        quicksort(A,lb,loc-1);
        quicksort(A,loc+1,ub);
    }
}

void display(int A[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<A[i]<<"\t";
    }
}


int main() 
{
    int a[]={7,6,10,5,9,2,1,15,7};
    int n=sizeof(a)/sizeof(a[0]);
    quicksort(a,0,n-1);
    display(a,n);

    return 0;
}
