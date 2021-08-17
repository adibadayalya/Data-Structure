//question 5
#include<stdio.h>
int main()
{	
	int n,k=0;
	printf("Enter the number of rows/colums in the sparse square matrix:\n");
	scanf("%d",&n);
	int a[n][n];
	printf("Enter the elements of the matrix:\n");
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j]!=0)
				k++;
		}
	int b[3][k],t=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			if(a[i][j]!=0)
			{
				b[0][t]=i;
				b[1][t]=j;
				b[2][t]=a[i][j];
				t++;
			}
		}
	printf("The representation of given sparse matrix is as follows:\n");
	for(int i=0;i<3;i++)
		{
			for(int j=0;j<k;j++)
				printf("%d ",b[i][j]);
			printf("\n");
		}
	return 0;
}
