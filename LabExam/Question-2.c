//Aditya Badayalya, 510819056, Question-2
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  int a[n],b[m],c[m];
  for(int i=0;i<n;i++)
  scanf("%d",&a[i]);
  for(int i=0;i<m;i++)
  scanf("%d",&b[i]);
  for(int i=0;i<m;i++)
  scanf("%d",&c[i]);
  if(n!=m)
  {
    printf("NOT MIRROR TWIN\n");
    return 0;
  }
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n-1;j++)
    {
      if(a[j]>a[j+1])
      {
        int k=a[j];
        a[j]=a[j+1];
        a[j+1]=k;
      }
    }
  }
  for(int i=0,j=n-1;i<n,j>=0;i++,j--)
  {
    if(a[i]!=b[j])
    {
      printf("NOT MIRROR TWIN\n");
      return 0;
    }
  }
  printf("MIRROR TWIN\n");
  return 0;
}
