#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct LinkedList
{
  int data;
  struct LinkedList *address;
//  struct LinkedList *nested;
}LL;

void append(LL **H,int k)
{
  if(*H==NULL)
  {
    LL *temp=(LL*)malloc(sizeof(LL));
    temp->data=k;
    temp->address=NULL;
    *H=temp;
  }
  else
  {
    LL *Current=*H;
    while(Current->address!=NULL)
    Current=Current->address;
    Current->address=(LL*)malloc(sizeof(LL));
    Current=Current->address;
    Current->data=k;
    Current->address=NULL;
  }
}

void display(LL *Node)
{
  if(Node==NULL)
  printf("No linked list!!!\n");
  else
  {
    while(Node!=NULL)
    {
      printf("%d ",Node->data);
      Node=Node->address;
    }
    printf("\n");
  }
}

int main()
{
  char c;
  LL *Head=NULL;
  int a,k=0;
  FILE *fp;
  fp=fopen("input.txt","r");
  if(fp==NULL)
  printf("!!!Error file not found!!!\n");
  else
  {
    fscanf(fp,"%d",&a);
    while(fscanf(fp,"%d",&a)!=EOF)
    {
      append(&Head,a);
    }
    fclose(fp);
    printf("The combined linked list is:\n");
    display(Head);
  }
  return 0;
}
