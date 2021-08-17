#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

void heap(int array[],int n,int index,int k)
{
  int childArray[k+1];
	for(int i=1;i<=k;i++)
	childArray[i]=((k*index+i)<n?(k*index+i):-1);
	int maxChildVal=-1,maxChildInd;
	for(int i=1;i<=k;i++)
	{
		if(childArray[i]!=-1&&array[childArray[i]]>maxChildVal)
		{
			maxChildVal=array[childArray[i]];
			maxChildInd=childArray[i];
		}
	}
	if(maxChildVal!=-1)
  {
    if(array[index]<array[maxChildInd])
    {
      int s=array[index];
      array[index]=array[maxChildInd];
      array[maxChildInd]=k;
    }
    index=maxChildInd;
    heap(array,n,index,k);
  }
}

void reset(int array[],int index,int k)
{
  int parentInd=(index-1)/k;
  if(array[index]>array[parentInd]&&(parentInd>=0))
  {
    int s=array[index];
    array[index]=array[parentInd];
    array[parentInd]=s;
    reset(array,parentInd,k);
  }
}

void heapify(int array[],int n,int k)
{
  for(int i=(n-1)/k;i>=0;i--)
  heap(array,n,i,k);
}

void insertNew(int array[],int *n, int k,int e)
{
  array[*n]=e;
  (*n)++;
  reset(array,*n-1,k);
}

void extractMax(int array[],int *n,int k)
{
  int max=array[0];
  if((*n)==0)
  {
    printf("!!! ERROR NO DATA FOUND !!!\n");
    return;
  }
  array[0]=array[(*n)-1];
  (*n)--;
  printf("The extracted Maximum number is : %d\n",max);
  heap(array,*n,0,k);
}

int main()
{
  int kary,z;
  printf("Enter the number of children a node can possess:\n");
  scanf("%d",&kary);
  int n=1;
  int array[1000],size=0;
  while(n!=0)
  {
    printf("Press 1 to add a new element to the %d-Ary tree and heapify:\n",kary);
    printf("Press 2 to display the Max Heap:\n");
    printf("Press 3 to extract the maximum in the heap:\n");
    printf("Press 0 to exit:\n");
    scanf("%d",&n);
    switch(n)
    {
      case 1: printf("Enter the value of the element:\n");
              scanf("%d",&z);
              insertNew(array,&size,kary,z);
              heapify(array,size,kary);
              break;
      case 2: if(size==0)
              {
                printf("!!! ERROR NO DATA FOUND !!!\n");
                break;
              }
              for(int i=0;i<size;i++)
              printf("%d ",array[i]);
              printf("\n");
              break;
      case 3: extractMax(array,&size,kary);
              break;
    }
  }
  return 0;
}
