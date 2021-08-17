//510819056 Aditya Badayalya, assignment 2 question 2.
#include <stdio.h>

int main ()
{
	int n , i , j , x = 0 , y = 0 , k ;
	printf ( "Enter the size of the number of rows or columns of the Matrix : \n" ) ;
	scanf ( "%d" , &n ) ;
	int s1 = 0 , arr1[n][n] , arr2[n][n] , s2 = 0 ;
	printf ( "Enter the elements of the first Matrix : \n" ) ;
	for ( i = 0 ; i < n ; i++ )
	{
		for ( j = 0 ; j < n ; j++ )
		{
			scanf ( "%d" , &arr1[i][j] ) ;
			if ( arr1[i][j] != 0 )
				s1++ ;
		}
	}
	printf ( "Enter the elements of the second Matrix :\n " ) ;
	for ( i = 0 ; i < n ; i++ )
	{
		for ( j = 0 ; j < n ; j++ )
		{
			scanf ( "%d" , &arr2[i][j] ) ;
			if ( arr2[i][j] != 0 )
				s2++ ;
		}
	}
	int a[3][s1] , b[3][s2] , c[3][s1+s2] , d[3][s1+s2] ;
	for ( i = 0 ; i < n ; i++ )
	{
		for ( j = 0 ; j < n ; j++ )
		{
			if ( arr1[i][j] != 0 )
			{
				a[0][x] = i ;
				a[1][x] = j ;
				a[2][x] = arr1[i][j] ;
				x++ ;
			}
			if ( arr2[i][j] != 0 )
			{
				b[0][y] = i ;
				b[1][y] = j ;
				b[2][y] = arr2[i][j] ;
				y++ ;
			}
		}
	}
	i = 0 , j = 0 , k = 0 ;
	while ( i < s1 || j < s2 )
	{
		if ( a[0][i] == b[0][j] && a[1][i] == b[1][j] )
		{
			c[0][k] = a[0][i] ;
			c[1][k] = a[1][i] ;
			d[0][k] = a[0][i] ;
			d[1][k] = a[1][i] ;
			c[2][k] = a[2][i] + b[2][j] ;
			d[2][k] = a[2][i] - b[2][j] ;
			i++ ;
			j++ ;
			k++ ;
		}
		else
		{
			if ( a[0][i] == b[0][j] )
			{
				if ( a[1][i] < b[1][j] )
				{
					c[0][k] = a[0][i] ;
					c[1][k] = a[1][i] ;
					d[0][k] = a[0][i] ;
					d[1][k] = a[1][i] ;
					c[2][k] = a[2][i] ;
					d[2][k] = a[2][i] ;
					i++ ;
					k++ ;
				}
				else
				{
					c[0][k] = b[0][j] ;
					c[1][k] = b[1][j] ;
					d[0][k] = b[0][j] ;
					d[1][k] = b[1][j] ;
					c[2][k] = b[2][j] ;
					d[2][k] = -b[2][j] ;
					j++ ;
					k++ ;
				}
			}
			else if ( a[0][i] < b[0][j] )
			{
				c[0][k] = a[0][i] ;
				c[1][k] = a[1][i] ;
				d[0][k] = a[0][i] ;
				d[1][k] = a[1][i] ;
				c[2][k] = a[2][i] ;
				d[2][k] = a[2][i] ;
				i++ ;
				k++ ;
			}
			else if ( a[0][i] > b[0][j] )
			{
				c[0][k] = b[0][j] ;
				c[1][k] = b[1][j] ;
				d[0][k] = b[0][j] ;
				d[1][k] = b[1][j] ;
				c[2][k] = b[2][j] ;
				d[2][k] = -b[2][j] ;
				j++ ;
				k++ ;
			}
		}
	}
	printf ( "The sum of 2 Sparse Matrix is as follows : \n" ) ;
	for ( i = 0 ; i < 3 ; i++ )
	{
		for ( j = 0 ; j < k ; j++ )
		{
			printf ( "%d  " , c[i][j] ) ;
		}
		printf ( "\n" ) ;
	}
	printf ( "The difference of 2 Sparse Matrix is as follows : \n" ) ;
	for ( i = 0 ; i < 3 ; i++ )
	{
		for ( j = 0 ; j < k ; j++ )
		{
			printf ( "%d  " , d[i][j] ) ;
		}
		printf ( "\n" ) ;
	}
	return 0 ;
}
