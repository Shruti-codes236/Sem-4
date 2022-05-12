#include <bits/stdc++.h>
using namespace std;
int Graph_edit_Distance(vector<int> str1, vector<int> str2, int m, int n)
{
	int dp[m + 1][n + 1];

	// Fill d[][] in bottom up manner
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			// If first graph is empty, only option is to
			// insert all characters of second graph
			if (i == 0)
				dp[i][j] = j; // Min. operations = j

			// If second graph is empty, only option is to
			// remove all characters of second graph
			else if (j == 0)
				dp[i][j] = i; // Min. operations = i

			// If last values are same, ignore last value
			// and recur for remaining graph
			else if (str1[i - 1] == str2[j - 1])
				dp[i][j] = dp[i - 1][j - 1];

			// If the last graph vale is different, consider
			// all possibilities and find the minimum
			else
				dp[i][j]
					= 1
					+ min(dp[i][j - 1], // Insert
							dp[i - 1][j], // Remove
							dp[i - 1][j - 1]); // Replace
		}
	}

	return dp[m][n];
}
int main()
{
	vector<int> g1,g2;
	int n,m;
	cout<<"Enter total elements of first graph\n";
	cin>>n;
	int i,x;
	for(i=0;i<n;i++)
	{
		cin>>x;
		g1.push_back(x);
	}
	cout<<"Enter total elements of second graph\n";
	cin>>m;
	for(i=0;i<m;i++)
	{
		cin>>x;
		g2.push_back(x);
	}

	cout << Graph_edit_Distance(g1, g2, n,m);

	return 0;
}
