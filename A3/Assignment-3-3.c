#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int SIZE;
int k1,k2;
#define SI 10000
struct QUEUE
{
  int Head;
  int Tail;
  int Count;
  char Queue[SI][50];
};
typedef struct QUEUE QU;

void intsort( QU *x,int z );

void enqueue(QU *x,char *p,int z)
{
  SIZE=z;
  strcpy(x->Queue[x->Tail],p);
  x->Tail=(x->Tail+1)%SIZE;
  (x->Count)++;
  intsort(x,z);
}

void display(QU *x, int z)
{
  SIZE=z;
  for(int i=x->Head,j=x->Count;j>0;i=(i+1)%SIZE,j-- )
  printf("| %s | ", x->Queue[i]);
  printf("\n");
}

void delete(QU *x, int xx)
{
      SIZE=xx;
      //printf("%d\n",x->Head);
      printf("DETETED = %s \n", x->Queue[x->Head]);
      x->Head = (x->Head + 1)%SIZE;
      (x->Count)--;
}

void del(QU *x, int xx)
{
      SIZE=xx;
      x->Head = (x->Head + 1)%SIZE;
      (x->Count)--;
}

void intsort( QU *x, int z)
{
    SIZE=z;
    int T, TP, H;
    char tempVAL[50],tempPrio[50];
    if(x->Count == 1)
        return;
    if(  x->Tail == 0 )
        T = SIZE-1;
    else
        T = (x->Tail)-1;
    if( T == 0 )
        TP = SIZE-1;
    else
        TP = T-1;
    H = x->Head;
    while( T != H )
    {
        if(strcmp(x->Queue[TP],x->Queue[T])>0)
        {
            strcpy(tempVAL,x->Queue[T]);
            strcpy(x->Queue[T],x->Queue[TP]);
            strcpy(x->Queue[TP],tempVAL);
        }
        else
            return;
        T = TP;
        if( T == 0 )
           TP = SIZE-1;
        else
           TP = T-1;
    }
}

void merge(QU *X, QU *Y,QU *Z)
{
  char s[50];
  int xx=k1+k2;
  int k=X->Count;
  while(X->Count!=0)
  {
    strcpy(s,X->Queue[X->Head]);
    enqueue(Z,s,xx);
    del(X,k1);
  }
  X->Count=k;
  X->Head=0;
  k=Y->Count;
  while(Y->Count!=0)
  {
    strcpy(s,Y->Queue[Y->Head]);
    enqueue(Z,s,xx);
    del(Y,k2);
  }
  Y->Head=0;
  Y->Count=k;
}

int main()
{
  printf("Enter the size of the first Queue:\n");
  scanf("%d",&k1);
  printf("Enter the size of the second Queue:\n");
  scanf("%d",&k2);
  QU Q;
  Q.Head=0;
  Q.Tail=0;
  Q.Count=0;
  QU D;
  D.Head=0;
  D.Tail=0;
  D.Count=0;
  QU UN;
  UN.Head=0;
  UN.Tail=0;
  UN.Count=0;
  int n=1;
  while(n!=0)
  {
    printf("Press 1 to insert an element in first queue:\n");
    printf("Press 2 to delete an element of highest priority in first queue:\n");
    printf("Press 3 to display first queue:\n");
    printf("Press 4 to insert an element in second queue:\n");
    printf("Press 5 to delete an element of highest priority in second queue:\n");
    printf("Press 6 to display second queue:\n");
    printf("Press 7 to combine both queues.\n");
    printf("Press 0 to exit.\n");
    scanf("%d",&n);
    switch(n)
    {
      case 1: if(Q.Count==k1)
              {
                printf("!!!The Queue is full!!!\n");
              }
              else
              {
                int p;
                char k[50];
                printf("Enter an element:\n");
                scanf("%s",&k);
                enqueue(&Q,k,k1);
              }
              break;
      case 2: if(Q.Count==0)
              {
                printf("!!!The Queue is Empty!!!\n");
              }
              else
              {
                delete(&Q,k1);
              }
              break;
      case 3: if(Q.Count==0)
              {
                printf("!!!The Queue is Empty!!!\n");
              }
              else
              {
                display(&Q,k1);
              }
              break;
     case 4: if(D.Count==k2)
              {
                printf("!!!The Queue is full!!!\n");
              }
              else
              {
                int p;
                char k[50];
                printf("Enter an element:\n");
                scanf("%s",&k);
                enqueue(&D,k,k2);
              }
              break;
      case 5: if(D.Count==0)
              {
                printf("!!!The Queue is Empty!!!\n");
              }
              else
              {
                delete(&D,k2);
              }
              break;
      case 6: if(D.Count==0)
              {
                printf("!!!The Queue is Empty!!!\n");
              }
              else
              {
                display(&D,k2);
              }
              break;
      case 7: goto takeoff;
    }
  }
  takeoff:
  merge(&Q,&D,&UN);
  int zzz=k1+k2;
while(n!=0)
{
  printf("Press 1 to display the union of the queues:\n");
  printf("Press 2 to delete an element of highest priority in the combined queue:\n");
  printf("Press 3 to display the original first queue:\n");
  printf("Press 4 to display the original second queue:\n");
  printf("Press 0 to exit.\n");
  scanf("%d",&n);
  switch(n)
  {
    case 1: if(UN.Count==0)
            {
              printf("!!!The Queue is Empty!!!");
            }
            else;
            display(&UN,zzz);
            break;
    case 2: if(UN.Count==0)
            {
              printf("!!!The Queue is Empty!!!");
            }
            else;
            delete(&UN,zzz);
            break;
    case 3: if(Q.Count==0)
            {
              printf("!!!The Queue is Empty!!!\n");
            }
            else
            {
              display(&Q,k1);
            }
            break;
    case 4: if(D.Count==0)
            {
              printf("!!!The Queue is Empty!!!\n");
            }
            else
            {
              display(&D,k2);
            }
            break;
  }
}
  return 0;
}
