//question 3
#include<stdio.h>
int main()
{
  long long a,b;
  char c;
  printf("Enter the first number:\n");
  scanf("%lli",&a);
  getchar();
  printf("Enter '+' or '-' :\n");
  scanf("%c",&c);
  printf("Enter the second number:\n");
  scanf("%lli",&b);
  printf("%lli %c %lli is : ",a,c,b);
  if(c=='+')
  printf("%lli\n",a+b);
  else printf("%lli\n",a-b);
  return 0;
}
