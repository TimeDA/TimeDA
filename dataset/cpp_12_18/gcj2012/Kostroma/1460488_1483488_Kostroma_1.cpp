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
 
 int num[20];
 bool good (int q, int w)
 {
 	//cout<<q<<' '<<w<<endl;
 	vector <int> cur1, cur2;
 	while (q)
 		cur1.push_back(q%10), q/=10;
 	while (w)
 		cur2.push_back(w%10), w/=10;
 	int n=cur1.size();
 	if (cur2.size()!=n)
 		return false;
 	for (int i=0; i<10; i++)
 		num[i]=0;
 	for (int i=0; i<n; i++)
 		num[cur1[i]]++, num[cur2[i]]--;
 	for (int i=0; i<9; i++)
 		if (num[i]!=0)
 			return false;
 	//cout<<n<<endl;
 	for (int i=0; i<n; i++)
 	{
 		bool f=true;
 		for (int j=0; j<n; j++)
 			if ( cur1[(i+j)%n]!=cur2[j] )
 			{
 				f=false;
 				break;
 			}
 		if (f)
 			return true;
 	}
 	return false;
 }
 bool best[2000][2000];
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
 	for (int i=1; i<=1000; i++)
 		for (int j=i+1; j<=1000; j++)
 			best[i][j]=good(i, j);
 	cin>>z;
 	while (z--)
 		solve();
 	return 0;
 }
 int timer=0;
 //#define int li
 
 
 void solve()
 {
 	timer++;
 	int ans=0;
 	int a, b;
 	cin>>a>>b;
 	//cout<<a<<' '<<b<<endl;
 	for (int i=a; i<=b; i++)
 		for (int j=i+1; j<=b; j++)
 			if (best[i][j])
 				ans++;
 	cout<<"Case #"<<timer<<": "<<ans<<endl;
 }
 
 
