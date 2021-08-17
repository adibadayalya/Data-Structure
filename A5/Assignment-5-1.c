#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct LinkedText
{
  int frequency,size;
  char word[50];
  struct LinkedText* address;
}LT;

void append(LT **H,char c[])
{
  //printf("%s\n",c);
  c[0]=tolower(c[0]);
  int l=strlen(c);
  if(*H==NULL)
  {
    LT* temp=(LT*)malloc(sizeof(LT));
    temp->frequency=1;
    temp->size=l;
    strcpy(temp->word,c);
    *H=temp;
    temp->address=NULL;
  }
  else
  {
    LT *current= *H;
    while((current->address!=NULL)&&(strcmp(current->word,c)!=0))
    current=current->address;
    if(current->address==NULL)
    {
      if(strcmp(current->word,c)==0)
      {
        current->frequency=current->frequency+1;
      }
      else
      {
        current->address=(LT*)malloc(sizeof(LT));
        current=current->address;
        current->frequency=1;
        current->size=l;
        strcpy(current->word,c);
        current->address=NULL;
      }
    }
    else
    {
      current->frequency=current->frequency+1;
    }
  }
}

void display(LT *node)
{
  if(node==NULL)
  printf("!!!!NO LIST FOUND!!!!\n");
  else
  {
    printf("THe data is as follows:\n");
    while(node!=NULL)
    {
      printf("| FOR THE WORD :%s ----> THE FREQUENCY IS : %d ---> THE SIZE(LENGHT) OF THE WORD IS: %d |\n",node->word,node->frequency,node->size);
      printf("---------------------------------\n");
      node=node->address;
    }
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");
  }
}

void displayLength(LT * node, int l)
{
  if(node==NULL)
  printf("!!!!NO LIST FOUND!!!!\n");
  else
  {
    int k=0;
    while(node!=NULL)
    {
      if(node->size==l)
      {
        k++;
        printf("| FOR THE WORD :%s ----> THE FREQUENCY IS : %d ---> THE SIZE(LENGHT) OF THE WORD IS: %d |\n",node->word,node->frequency,node->size);
        printf("---------------------------------\n");
      }
      node=node->address;
    }
    if(k==0)
    printf("!!! NO WORD OF THIS LENGTH FOUND !!!\n");
    else
    printf("---------------------------------------------------------------------------------------------------------------------------------\n");
  }
}

int main()
{
  LT *head=NULL;
  FILE *fp;
  fp=fopen("input.txt","r");
  if(fp==NULL)
  {
    printf("!!! FILE NOT FOUND !!!\n");
    return 0;
  }
  char c[50],m;
  while(!feof(fp))
  {
    fscanf(fp,"%s",&c);
    m=getc(fp);
    if(m==EOF)
    break;
    append(&head,c);
  }
  fclose(fp);
  display(head);
  int n=1;
  while(n!=0)
  {
    printf("To search a word of given length press 1:\n");
    printf("To exit press 0:\n");
    scanf("%d",&n);
    if(n==1)
    {
      int z;
      printf("Enter the size/length of the word:\n");
      scanf("%d",&z);
      displayLength(head,z);
    }
  }
  return 0;
}
