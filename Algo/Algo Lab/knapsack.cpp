ll dp[n][100001];
			dp[0][0]=0;
			dp[0][w[0]]=v[0];
			flp(i,1,n)
			{
				dp[i][0]=0;
				flp(j,1,c+1)
				{
					dp[i][j]=dp[i-1][j];
					if(j>=w[i])
						dp[i][j]=max(dp[i][j],v[i]+dp[i-1][j-w[i]]);
				}
			}
			ll ans=-1e18;
			flp(i,0,c+1)
			ans=max(ans,dp[n-1][i]);
			cout<<ans;

			
				}