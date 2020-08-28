#include<stdio.h>
int main()
{
  FILE *fp;
  char a,c;
  printf("Enter the character whose frequency is to be checked from the file:\n");
  scanf("%c",&a);
  int k=0;
  fp=fopen("test.txt","r");
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
    printf("%d",k);
  }
  return 0;
}
