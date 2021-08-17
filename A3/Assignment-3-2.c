//Aditya Badayalya, 510819056, Assignment-3-2
#include<stdio.h>
int sz;
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

int pp(int *s, int *t)
{
  return s[(*t)];
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

void sort(int *p,int *a,int *q,int*b)
{
  int temp=pop(p,a);
  push(q,b,temp);
  temp=pop(p,a);
  while(*a>=-1)
  {
    if(temp>pp(q,b))
    {
      push(q,b,temp);
      temp=pop(p,a);
    }
    else
    {
      while(pp(q,b)>temp&&(*b!=-1))
      {
        push(p,a,pop(q,b));
      }
      push(q,b,temp);
      temp=pop(p,a);
    }
  }
  printf("The combined sorted stack is:\n");
  display(q,*b);
}

int main()
{
  int sz1,sz2,sz3;
  printf("Enter the size of stacks 1, 2 and 3 respectively:\n");
  scanf("%d%d%d",&sz1,&sz2,&sz3);
  sz=sz1+sz2+sz3;
  int stack[sz],stack1[sz1],stack2[sz2],stack3[sz3],stackk[sz],t=-1,n=1,k,p=-1,q=-1,r=-1,zzz=-1;
  while(n!=11)
  {
    printf("Press 1 to push an element is stack 1\n");
    printf("Press 2 to push an element is stack 2\n");
    printf("Press 3 to push an element is stack 3\n");
    printf("Press 4 to pop an element is stack 1\n");
    printf("Press 5 to pop an element is stack 2\n");
    printf("Press 6 to pop an element is stack 3\n");
    printf("Press 7 to display stack 1\n");
    printf("Press 8 to display stack 2\n");
    printf("Press 9 to display stack 3\n");
    printf("Press 0 to display the sorted stack\n");
    printf("Press 11 to exit\n");
    scanf("%d",&n);
        switch(n)
        {
          case 1 : if(p==sz1-1)
                  {
                      printf("Error!!!!!\nSTACK IS FULL!!!\n");
                  }
                  else
                  {
                    printf("Enter an element:\n");
                    scanf("%d",&k);
                    push(stack1,&p,k);
                  }
                  break;
          case 2 : if(q==sz2-1)
                  {
                    printf("Error!!!!!\nSTACK IS FULL!!!\n");
                  }
                  else
                  {
                    printf("Enter an element:\n");
                    scanf("%d",&k);
                    push(stack2,&q,k);
                  }
                  break;
         case 3 : if(r==sz3-1)
                  {
                    printf("Error!!!!!\nSTACK IS FULL!!!\n");
                  }
                  else
                  {
                    printf("Enter an element:\n");
                    scanf("%d",&k);
                    push(stack3,&r,k);
                  }
                  break;

      case 4 :  if(p==-1)
                {
                  printf("Error!!!!!\nSTACK IS EMPTY!!!\n");
                }
                else
                {
                  int xad=pop(stack1,&p);
                  printf("Popped element is: %d\n",xad);
                }
                break;
      case 5 :  if(q==-1)
                {
                  printf("Error!!!!!\nSTACK IS EMPTY!!!\n");
                }
                else
                {
                  int xad=pop(stack2,&q);
                  printf("Popped element is: %d\n",xad);
                }
                break;
      case 6 :  if(r==-1)
                {
                  printf("Error!!!!!\nSTACK IS EMPTY!!!\n");
                }
                else
                {
                  int xad=pop(stack3,&r);
                  printf("Popped element is: %d\n",xad);
                }
                break;
      case 7 :  printf("The first stack is:\n");
                display(stack1,p);
                break;
      case 8 :  printf("The second stack is:\n");
                display(stack2,q);
                break;
      case 9 :  printf("The third stack is:\n");
                display(stack3,r);
                break;
      case 0 :  goto oo;
                break;
      case 11:  return 0;
                break;
      default:  printf("Choose a valid option:\n");
                break;
      }
  }
oo:
  while(p!=-1)
  {
    push(stackk,&t,pop(stack1,&p));
  }
  while(q!=-1)
  {
    push(stackk,&t,pop(stack2,&q));
  }
  while(r!=-1)
  {
    push(stackk,&t,pop(stack3,&r));
  }
  sort(stackk,&t,stack,&zzz);
  return 0;
}
