//Aditya Badayalya, 510819056, Question-1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
  int n;
  scanf("%d",&n);
  int a[n][n];
  for(int i=0;i<n;i++)
  for(int j=0;j<n;j++)
  scanf("%d",&a[i][j]);
  int count=0;
  while(count<2*n-1)
  {
    int space=abs(n-count-1);
    for(int i=0;i<space;i++)
    printf(" ");
    int array[n*n];
    space=0;
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        if(i+j==count)
        {
          array[space]=a[i][j];
          space++;
        }
      }
    }
    for(int i=space-1;i>=0;i--)
    printf("%d ",array[i]);
    printf("\n");
    count++;
  }
  return 0;
}
