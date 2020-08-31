//question 1
#include<stdio.h>
int main()
{
	int n,k=0,k1=0,k2=0;
	printf("Enter the size of the array:\n");
	scanf("%d",&n);
	int a[n];
	printf("Enter the elements of the array:\n");
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
	printf("The third largest number in the array is: ");
	printf("%d\n",k2);
	return 0;


}
