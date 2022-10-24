#include <stdio.h>
 #include <iostream>
 #include <vector>
 #include <string>
 #include <algorithm>
 #include <cmath>
 #include <memory.h>
 #include <map>
 
 using namespace std;
 
 #define mp make_pair
 #define pb push_back
 
 typedef long long li;
 typedef double ld;
 #define FILE "change me!"
 void solve();
 int main ()
 {
 #ifdef _DEBUG
 	freopen ("in.txt", "r", stdin);
 	freopen ("out.txt", "w", stdout);
 #else
 	//freopen (FILE ".in", "r", stdin);
 	//freopen (FILE ".out", "w", stdout);
 #endif
 	int z=1;
 	//ios_base::sync_with_stdio(false);
 	cin>>z;
 	while (z--)
 		solve();
 	return 0;
 }
 int timer=0;
 //#define int li
 
 int n;
 int dp[200][200];
 int s, p;
 int t[200];
 
 void solve()
 {
 	timer++;
 	cin>>n>>s>>p;
 	for (int i=0; i<n; i++)
 		cin>>t[i];
 	memset (dp, 0, sizeof dp);
 	for (int i=0; i<n; i++)
 		for (int j=0; j<=i; j++)
 		{
 			if (t[i]>=3*p-2)
 				dp[i+1][j]=max(dp[i+1][j], dp[i][j]+1);
 			else
 				dp[i+1][j]=max(dp[i+1][j], dp[i][j]);
 
 			if (t[i]>=2 && t[i]<=28)
 			{
 				if (t[i]>=3*p-4)
 					dp[i+1][j+1]=max(dp[i+1][j+1], dp[i][j]+1);
 				else
 					dp[i+1][j+1]=max(dp[i+1][j+1], dp[i][j]);
 			}
 			
 		}
 	/*for (int i=1; i<=n; i++)
 	{
 		for (int j=0; j<=i; j++)
 			cout<<dp[i][j]<<' ';
 		cout<<endl;
 	}*/
 	cout<<"Case #"<<timer<<": "<<dp[n][s]<<endl;
 }
 
 
