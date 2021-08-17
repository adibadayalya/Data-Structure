//Assignment-4-1, 510819056, Aditya Badayalya
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

typedef struct LinkedList
{
  int data;
  struct LinkedList *address;
} LS;

void append(LS **H,int k)
{
  if(*H==NULL)
  {
    LS *temp = (LS*)malloc(sizeof(LS));
    temp->data=k;
    temp->address=NULL;
    *H=temp;
  }
  else
  {
    LS *List= *H;
    while((List->data<k)&&(List->address!=NULL))
    {
      List=List->address;
      //printf("test\n");
    }
    if(List->address==NULL)
    {
      if(List->data<k)
      {
        List->address=(LS*)malloc(sizeof(LS));
        List=List->address;
        List->data=k;
        List->address=NULL;
      }
      else
      {
        int y=List->data;
        List->data=k;
        List->address=(LS*)malloc(sizeof(LS));
        List=List->address;
        List->data=y;
        List->address=NULL;
      }
    }
    else
    {
      int x=List->data,y;
      List->data=k;
      List=List->address;
      if(List->address==NULL)
      {
        y=List->data;
        List->data=x;
        List->address=(LS*)malloc(sizeof(LS));
        List=List->address;
        List->data=y;
        List->address=NULL;
      }
      else
      {
        while(List->address!=NULL)
        {
          //printf("%d\n",x);
          int m=List->data;
          List->data=x;
          List=List->address;
          x=m;
        }
        List->address=(LS*)malloc(sizeof(LS));
        List=List->address;
        List->data=x;
        List->address=NULL;
      }
    }
  }
}

void deleteList(LS *Node)
{
  LS *Current=Node;
  LS *temp;
  while(Current!=NULL)
  {
    temp=Current->address;
    free(Current);
    Current=temp;
  }
  Node=NULL;
}
void display(LS *Node)
{
    if(Node==NULL)
    {
      printf("Linked lidt does not exist!!!\n");
      return;
    }
    while(Node!=NULL)
    {
      printf("%d ",Node->data);
      Node=Node->address;
    }
    printf("\n");
}

void arrayAppend(int a[],int k,int z)
{
  if(z==1)
  a[z-1]=k,z++;
  else if(a[z-2]<k)
  {
    a[z-1]=k;
  }
  else
  {
    int x;
    for(int i=0;i<z-1;i++)
    if(a[i]>k)
    {
      x=i;
      break;
    }
    for(int i=z-1;i>x;i--)
    a[i]=a[i-1];
    a[x]=k;
  }
}

int main(int argc, char *argv[])
{
  int cases=6,N;
  N=atoi(argv[1]);
  float totalLinkedListTime=0,totalArrayTime=0;
  //printf("Enter the number of numbers to be generated:\n");
  //scanf("%d",&N);
  printf("The given value of N: %d\n",N);
  for(int iter=0;iter<cases;iter++)
  {
    LS *Head=NULL;
    float linkedListTime=0,arrayTime=0;
    int n=0,a[N];
    memset(a,0,sizeof(a));
    //srand(0);
    while(n<N)
    {
      n++;
      int num = rand()%10001;
      num=abs(num);
      clock_t begin = clock();
      append(&Head,num);
      clock_t end = clock();
      linkedListTime+=(float)(end-begin)*1000/CLOCKS_PER_SEC;
      begin = clock();
      arrayAppend(a,num,n);
      end = clock();
      arrayTime+=(float)(end-begin)*1000/CLOCKS_PER_SEC;
    }
    totalLinkedListTime+=linkedListTime;
    totalArrayTime+=arrayTime;
    printf("The linked list structure is as follows:\n");
    display(Head);
    deleteList(Head);
    printf("\nThe time required by linked list in this cycle is %f milliseconds.\n",linkedListTime);
    printf("\n\nThe array is as follows:\n");
    for(int i=0;i<N;i++)
    printf("%d ",a[i]);
    printf("\n");
    printf("\nThe time required by array in this cycle is %f milliseconds.\n\n\n",arrayTime);
    printf("------------------------------------------------------------------------------------------------\n");
  }
  printf("\n\n\nTotal time required by linked list is %f milliseconds.\n",totalLinkedListTime);
  printf("Total time required using array is %f milliseconds.\n",totalArrayTime);
  printf("\nAverage time required by linked list is %f milliseconds.\n",totalLinkedListTime/6);
  printf("Average time required by array is %f milliseconds.\n",totalArrayTime/6);
  printf("------------------------------------------------------------------------------------------------\n");
  return 0;
}
