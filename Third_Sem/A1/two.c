//question 2
#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=0,j=n-1;j>0,i<n;j--,i++)
	{	
		if(j==i||j<i)
		{
			break;
		}
		else
		{
			int k=a[i];
			a[i]=a[j];
			a[j]=k;
		}
	}
	for(int i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
	return 0;


}
