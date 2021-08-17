#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

void heap(int array[],int n, int index)
{
  int smallest=index;
  int l=index+1;
  if((l<n)&&(array[l]<array[smallest]))
  smallest=l;
  if(smallest!=index)
  {
    int k=array[smallest];
    array[smallest]=array[index];
    array[index]=k;
    heap(array,n,smallest);
  }
}

void reset(int array[],int index)
{
  int parentInd=(index-1);
  if(array[parentInd]>array[index])
  {
    int k=array[parentInd];
    array[parentInd]=array[index];
    array[index]=k;
    reset(array,parentInd);
  }
}

void heapify(int array[],int n)
{
  for(int i=(n-1);i>=0;i--)
  heap(array,n,i);
}

void insertNew(int array[], int*n,int e)
{
  array[(*n)]=e;
  (*n)++;
  reset(array,(*n)-1);
}

int main()
{
  int n,k;
  printf("Enter the total number of elements in a single array:\n");
  scanf("%d",&n);
  printf("Enter the total number of arrays:\n");
  scanf("%d",&k);
  int totalElements=n*k,size=0;
  int a[k][n],array[totalElements+1];
  for(int i=0;i<k;i++)
  {
    printf("Enter the elements of Array %d(sorted order):\n",i+1);
    for(int j=0;j<n;j++)
    {
      scanf("%d",&a[i][j]);
      insertNew(array,&size,a[i][j]);
      heapify(array,size-1);
    }
  }
  printf("The combined sorted array is:\n");
  for(int i=0;i<totalElements;i++)
  printf("%d ",array[i]);
  printf("\n");
}
