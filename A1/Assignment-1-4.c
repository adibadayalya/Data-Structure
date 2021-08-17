//question 4
#include<stdio.h>
int main()
{
  FILE *fp;
  char a,c;
  printf("Enter the character whose frequency is to be checked from the file:\n");
  scanf("%c",&a);
  int k=0;
  fp=fopen("/home/aadi/Desktop/Third_Sem/A1/test.txt","r");
  if(fp==NULL)
  printf("File does not exist\n");
  else
  {
    while(c!=EOF)
    {
      c=getc(fp);
      if(c==a)
      k++;
    }
    fclose(fp);
    printf("The frequency of the character '%c' in the given file is : %d\n",a,k);
  }
  return 0;
}
