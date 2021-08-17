#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char na[50];
typedef struct EmployeeData
{
  int task,time;
  char name[50];
  struct EmployeeData *address;
}ED;

void append(ED **H,int ta,int ti, char na[])
{
  if(*H==NULL)
  {
  //  printf("test1\n");
    ED* temp=(ED*)malloc(sizeof(ED));
    temp->task=ta;
    temp->time=ti;
    strcpy(temp->name,na);
    temp->address=NULL;
    *H=temp;
  }
  else
  {
    ED *current=*H;
    while((current->task<ta)&&(current->address!=NULL))
    {
      current=current->address;
    }
    if(current->address==NULL)
    {
      if(current->task<ta)
      {
      //  printf("test3\n");
        current->address=(ED*)malloc(sizeof(ED));
        current=current->address;
        current->task=ta;
        current->time=ti;
        strcpy(current->name,na);
        current->address=NULL;
      }
      else
      {
      //  printf("test2\n");
        int x,y;
        char z[50];
        x=current->task;
        y=current->time;
        strcpy(z,current->name);
        current->task=ta;
        current->time=ti;
        strcpy(current->name,na);
        current->address=(ED*)malloc(sizeof(ED));
        current=current->address;
        current->task=x;
        current->time=y;
        strcpy(current->name,z);
        current->address=NULL;
      }
    }
    else
    {
      int x,y,g,h;
      char z[50],i[50];
      x=current->task;
      y=current->time;
      strcpy(z,current->name);
      current->task=ta;
      current->time=ti;
      strcpy(current->name,na);
      current=current->address;
      if(current->address==NULL)
      {
      //  printf("test4\n");
        g=current->task;
        h=current->time;
        strcpy(i,current->name);
        current->task=x;
        current->time=y;
        strcpy(current->name,z);
        current->address=(ED*)malloc(sizeof(ED));
        current=current->address;
        current->task=g;
        current->time=h;
        strcpy(current->name,i);
        current->address=NULL;
      }
      else
      {
        //printf("test5\n");
        while(current->address!=NULL)
        {
          int p,q;
          char r[50];
          p=current->task;
          q=current->time;
          strcpy(r,current->name);
          current->task=x;
          current->time=y;
          strcpy(current->name,z);
          current=current->address;
          x=p;
          y=q;
          strcpy(z,r);
        }
        int p,q;
        char r[50];
        p=current->task;
        q=current->time;
        strcpy(r,current->name);
        current->task=x;
        current->time=y;
        strcpy(current->name,z);
        x=p;
        y=q;
        strcpy(z,r);
        current->address=(ED*)malloc(sizeof(ED));
        current=current->address;
        current->task=x;
        current->time=y;
        strcpy(current->name,z);
        current->address=NULL;
      }
    }
  }
}

void displayTime(ED **reset)
{
  ED *temp=*reset;
  int t=0,k=0;
  while(temp->address!=NULL)
  {
    t+=temp->time;
    temp=temp->address;
  }
  temp=*reset;
  while(1)
  {
    while(temp!=NULL)
    {
      printf("Employee Name : %s || Task Number : %d || ",temp->name,temp->task);
      if(temp->time>0)
      {
        if(temp->time==1)
        {
          printf("Time Stamp: %d to %d\n",k,k+1);
          k+=1;
          t-=1;
          temp->time-=1;
        }
        else
        {
          printf("Time Stamp: %d to %d\n",k,k+2);
          k+=2;
          t-=2;
          temp->time-=2;
        }
      }
      else
      {
        printf("TASK COMPLETED!\n");
      }
      temp=temp->address;
    }
    if(t>0)
    {
      temp=*reset;
    }
    else if(t==0)
    {
      temp=*reset;
      t=-1;
    }
    else
    {
      printf("ALL TASKS COMPLETED!!!!\n");
      return;
    }
  }
}

int main()
{
  int k=7;
  ED*Head=NULL;
  printf("Enter the number of Employees:\n");
  scanf("%d",&k);
  printf("Enter the data of the Employees one by one respectively:\n");
  while(k--)
  {
    int x,y;
    char n[50];
    printf("Enter the Employee Name:\n");
    scanf("%s",&n);
    strcpy(na,n);
    printf("Enter the task number:\n");
    scanf("%d",&x);
    printf("Enter the time required:\n");
    scanf("%d",&y);
    append(&Head,x,y,na);
  }
  printf("\nThe employee data and time is as follows:\n\n");
  displayTime(&Head);
  return 0;
}
