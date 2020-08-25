#include<stdio.h>
int main()
{
	int n,k=0,k1=0,k2=0;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>k)
		{
			k=a[i];
		}
	}
	for(int i=0;i<n;i++)
        {
             if(a[i]>k1&&a[i]!=k)
                {
                        k1=a[i];
                }
        }
	for(int i=0;i<n;i++)
        {
                
                if(a[i]>k2&&a[i]<k1)
                {
                        k2=a[i];
                }
        }
	printf("%d",k2);
	return 0;


}
