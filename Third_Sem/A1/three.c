//question 3
#include<stdio.h>
int main()
{
  long long a,b;
  char c;
  scanf("%lli",&a);
  getchar();
  scanf("%s",&c);
  scanf("%lli",&b);
  if(c=='+')
  printf("%lli",a+b);
  else printf("%lli",a-b);
  return 0;
}
