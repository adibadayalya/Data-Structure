//510819056 Aditya Badayalya, assignment 2 question 1.
#include<stdio.h>
#include<string.h>
#include<ctype.h>
char s[100000];
int x,originallenght,lenghtnew,a[10000],nl,cnt;
void alphaln()
{
  for(int i=1;i<=10000;i++)
  if(a[i]!=0)
  nl++;
}
void alpha()
{
  memset(a,0,sizeof(a));
  char c;
  int i=0,k=0;
  FILE *fp;
  fp=fopen("output.txt","r");
  if(fp==NULL)
  printf("File does not exist\n");
  else
  {
    while(c!=EOF)
    {
      c=getc(fp);
      if(isxdigit(c))
      {
        k++;
      }
      else
      {
        a[i]=k;
        k=0;
        i++;
      }
    }
    fclose(fp);
  }
}
void fun()
{
  char a,c;
  int n,lenghtold;
  //printf("Enter the number of conseecutive zeros that are allowed:\n");
  //scanf("%d",&n);
  int i=0;
  //lenghtold=func();
  FILE *f;
  f=fopen("output.txt","r");
  if(f==NULL)
  printf("File does not exist\n");
  else
  {
    while(c!=EOF)
    {
      c=getc(f);
      s[i]=c;
      i++;
    }
    fclose(f);
    lenghtnew=strlen(s)-2;
    //printf("%d\n",lenghtnew);
  }
  x= lenghtnew+2;
  s[x-1]='\0';
}
void func()
{
  FILE *fp;
  char a,c,ss[100000];
  int k=0,i=0;
  fp=fopen("input.txt","r");
  if(fp==NULL)
  printf("File does not exist!\n");
  else
  {
    while(c!=EOF)
    {
      c=getc(fp);
      ss[i]=c;
      i++;
    }
    k=strlen(ss)-2;
    originallenght=k;
  }
}
void frequency()
{
  alpha();
  alphaln();
  FILE *fp;
  fp=fopen("output.txt","w");
  fprintf(fp,"The original length of the string is: %d\n",originallenght);
  fprintf(fp,"The value of n given is: %d\n",cnt);
  fprintf(fp,"The substrings are as follows:\n");
    int count = 0, c = 0, i, j = 0, k, space = 0;

    char  p[50][100], str1[20], ptr1[50][100];

  //  char *ptr;

    for (i = 0;i<x;i++)
    {
        if ((s[i] == ' '))
        {
            space++;
        }
    }

    for (i = 0, j = 0, k = 0;j < x;j++)
    {
        if ((s[j] == ' '))
        {
            p[i][k] = '\0';
            i++;
            k = 0;
        }
        else
             p[i][k++] = s[j];
    }

    k = 0;

    for (i = 0;i <= space;i++)
    {
        for (j = 0;j <= space;j++)
        {
            if (i == j)
            {
                strcpy(ptr1[k], p[i]);
                k++;
                count++;

                break;
            }
            else
            {
                if (strcmp(ptr1[j], p[i]) != 0)
                    continue;
                else
                    break;
            }
        }
    }
    int lnt=0;
    for(int i=0;i<=space;i++)
    fprintf(fp,"%s ",p[i]);
    fprintf(fp, "\n" );
    for (i = 0;i < count;i++)
    {
        for (j = 0;j <= space;j++)
        {
            if (strcmp(ptr1[i], p[j]) == 0)
                c++;
        }
        lnt+=(c*(strlen(ptr1[i])));
        fprintf(fp,"The Frequency of the substring '%s' is %d\n", ptr1[i], c);
        c = 0;
    }
    fprintf(fp,"Length using frequency is: %d\n",lnt);
    fprintf(fp,"Difference between the length is: %d\n",lnt-originallenght);
    fprintf(fp,"The string after replacement is:\n");
    fprintf(fp,"'");
    for(int i=0;i<10000;i++)
    {
      if(a[i]!=0)
      {
        char xx=64+a[i];
        fprintf(fp,"%c",xx);
      }
    }
    fprintf(fp,"'\n");
    fprintf(fp,"The length of the string after replacement is: %d\n",nl);
    fprintf(fp,"The difference in the length of the string is: %d\n",originallenght-nl);
    float ffff=originallenght,yyyy=nl;
    float difff=ffff-yyyy;
    difff/=ffff;
    fprintf(fp,"The percentage change in length is: %f%\n",difff*100);
    fclose(fp);
}
int main()
{
  FILE *fp;
  char a,c,ss[100000];
  int n;
  printf("Enter the number of consecutive zeros or ones that are allowed:\n");
  scanf("%d",&n);
  cnt=n;
  int i=0;
  fp=fopen("input.txt","r");
  if(fp==NULL)
  printf("File does not exist\n");
  else
  {
    while(c!=EOF)
    {
      c=getc(fp);
      ss[i]=c;
      i++;
    }
    fclose(fp);
    FILE *fp;
    fp =fopen("output.txt","w");
    //fprintf(fp,"%d\n",strlen(s)-2);
    int z=0,o=0,k=0;
    for(int i=0;i<strlen(ss)-1;i++)
    {
      if(ss[i]=='0')
      {
        for(int j=i;j<strlen(ss)-1;j++)
        {
          if(ss[j]!='0')
          {break;}
          z++;
        }
        if(z>=n)
        {
          z=0;
          for(int j=0;j<n;j++)
          {fprintf(fp,"0");}
          fprintf(fp," ");
          i+=(n-1);
        }
        else
        {
          if((i+z)>=strlen(ss)-2)
          {
            z=0;
            if(k==0)
            {
              for(int j=0;j<n;j++)
              fprintf(fp,"0");
              k++;
            }
          }
          else
          {for(int j=0;j<z;j++)
          {fprintf(fp,"0");}
          fprintf(fp,"1 ");
          i+=(z);
          z=0;}
        }
      }
      else if(ss[i]=='1')
      {
        o=0;
        for(int j=i;j<strlen(ss)-1;j++)
        {
          if(ss[j]=='0')
          {break;}
          o++;
        }
        if(o>=n)
        {
          for(int j=0;j<n;j++)
          {fprintf(fp,"1");}
          fprintf(fp," ");
          o=0;
          i+=(n-1);
        }
        else
        {
          for(int j=0;j<o;j++)
          {fprintf(fp,"1 ");}
          i+=(o-1);
          o=0;
        }
      }
    }
    fclose(fp);
  }
  fun();
  func();
  frequency();
  return 0;
}
