//Aditya Badayalya, 510819056, Assignment-3-1
#include<stdio.h>

int SIZE;

void push(int *s,int *t,int k)
{
    (*t)++;
    s[*t]=k;
}

int pop(int *s,int *t)
{
    (*t)--;
    return s[(*t)+1];
}

void display(int *s,int t)
{
  if(t==-1)
  printf("Stack is empty!\n");
  else
  {
    for(int i=0;i<=t;i++)
    printf("%d ",s[i]);
    printf("\n");
  }
}

void duplicate(int *s,int*t,int *ss,int *tt)
{
  int p[SIZE],q[SIZE],r[SIZE],x=-1,y=-1,z=-1,w,fl=1;
  //dtermining the position where initially the element eppears and the order
  //accordingly
  //first the values in the stack are popped one by one and it is determined
  // whether it is appearing for the first time or not and are then pushed into
  //a tmep stack accordingly and then are later called back as last in first out
  // and the original and the duplicate(copied) stacks are obtained accordingly
  //elements are pushed in p when they are appearing for the first time and '1'
  //is pushed in the stack r to mark that an element is appearing for the first
  //time here and similary other elements are pushed into the stack q and '0' is
  //is pushed in the stack r to mark that the element has appeared before.
  for(int i=*t;i>=0;i--)
  {
    fl=1;
    w=pop(s,t);
    for(int j=0;j<i;j++)
    {
      if(s[j]==w)
      fl=0;
    }
    if(fl)
    {
      push(p,&x,w);
      push(r,&z,1);
    }
    else
    {
      push(q,&y,w);
      push(r,&z,0);
    }
  }
  //the original stack and the duplicate(copied) are obtained as follows
  //when the popped value from the stack r is '1',the poppedvalue from the stack
  // s is copied to the duplicate as well as the original stack as it is
  //appearing for the first time and if the popped value from the stack r is '0'
  // then the corresponding popped value from the stack q is copied only to the
  //original stack s.
  for(int i=0;i<SIZE;i++)
  {
    fl=pop(r,&z);
    if(fl)
    {
      w=pop(p,&x);
      push(s,t,w);
      push(ss,tt,w);
    }
    else
    {
      w=pop(q,&y);
      push(s,t,w);
    }
  }
}

int main(void)
{
  printf("Enter the size of the stack:\n");
  scanf("%d",&SIZE);
  int stack[SIZE],stackk[SIZE],t=-1,n=1,k,tt=-1;
  while(n!=0)
  {
    printf("Press 1 to push:\n");
    printf("Press 2 to pop:\n");
    printf("Press 3 to display:\n");
    printf("Press 4 to copy the stack:\n");
    printf("Press 0 to exit\n");
    scanf("%d",&n);
    switch(n)
    {
      case 1: if(t==SIZE-1)
              {
                  printf("Error!!!!!\nSTACK IS FULL!!!\n");
              }
              else
              {
                printf("Enter an element:\n");
                scanf("%d",&k);
                push(stack,&t,k);
              }
              break;
      case 2: if(t==-1)
              {
                printf("Error!!!!!\nSTACK IS EMPTY!!!\n");
              }
              else
              {
                int xad=pop(stack,&t);
                printf("Popped element is: %d\n",xad);
              }
              break;
      case 3: display(stack,t);
              break;
      case 4: duplicate(stack,&t,stackk,&tt);
              goto takeoff;
      case 0: return 0;
      default: printf("Choose a Valid option\n");
    }
  }
  takeoff:
  n=1;
  while(n!=0)
  {
    printf("Press 1 to print the original stack:\n");
    printf("Press 2 to print the duplicate(copied) stack:\n");
    printf("Press 0 to exit:\n");
    scanf("%d",&n);
    switch(n)
    {
      case 1: display(stack,t);
              break;
      case 2: display(stackk,tt);
              break;
      case 0: return 0;
      default: printf("Choose a Valid option\n");
    }
  }
}
