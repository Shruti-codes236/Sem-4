#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
using namespace std;
int calculate(int p[], int n)
{

	int m[n][n];

	int i, j, k, L, cst;

	/* m[i, j] = Minimum number of scalar
	multiplications needed to compute the
	matrix A[i]A[i+1]...A[j] = A[i..j] where
	dimension of A[i] is p[i-1] x p[i] */
	for (i = 1; i < n; i++)
		m[i][i] = 0;

	// L is chain length.
	for (L = 2; L < n; L++) 
	{
		for (i = 1; i < n - L + 1; i++) 
		{
			j = i + L - 1;
			m[i][j] = 1e9;
			for (k = i; k <= j - 1; k++) 
			{
				// q = cost/scalar multiplications
				cst = m[i][k] + m[k + 1][j]
					+ p[i - 1] * p[k] * p[j];
				if (cst< m[i][j])
					m[i][j] = cst;
			}
		}
	}

	return m[1][n - 1];//minimum number of operations stored here
}
int main()
{
	int n;
	cin>>n;
	int p[n],i;
	for(i=0;i<n;i++) cin>>p[i];

	cout << "Minimum number of multiplications is "<< calculate(p,n)<<"\n";

	
	return 0;
}
