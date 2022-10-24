#include <vector>
 #include <list>
 #include <map>
 #include <set>
 #include <deque>
 #include <queue>
 #include <stack>
 #include <bitset>
 #include <algorithm>
 #include <functional>
 #include <numeric>
 #include <utility>
 #include <sstream>
 #include <iostream>
 #include <iomanip>
 #include <string>
 #include <complex>
 #include <cstdio>
 #include <cmath>
 #include <cstdlib>
 #include <cctype>
 #include <cstring>
 #include <climits>
 #include <ctime>
 
 #include<unordered_map>
 #include<unordered_set>
 using namespace std;
 
 int _SKIP = -1, _START = -1;
 void __aa(int a, char **ag)
 {
 	if (a > 1 )
 	{
 		_SKIP = atoi(ag[2]);
 		_START = atoi(ag[1]);
 	}
 }
 
 
 
 long long rev(long long n)
 {
 	long long ans = 0;
 	while(n)
 	{
 		ans*=10;
 		ans+= n%10;
 		n/=10;
 	}
 	return ans;
 }
 
 long long lar(long long n)
 {
 	long long ans = 10;
 
 	while (ans < n)
 		ans*=10;
 
 	return ans/10;
 }
 
 
 long long n;
 map<long long,long long>vis;
 long long bans;
 struct AA
 {
 bool operator()(const pair<long long,long long>& a , const pair<long long,long long>&b)
 {
 	return a.second != b.second ? a.second > b.second : a.first > b.first; 
 }
 };
 void dfs(long long cur, long long lv)
 {
 	//queue< pair<long long,long long> > q;
 	priority_queue< pair<long long,long long> ,vector<pair<long long,long long> >, AA > q;
 	q.push( make_pair(cur,lv) );
 
 	while (!q.empty())
 	{
 		auto as = q.top(); q.pop();
 		if (as.first == n)
 		{
 			bans = min(as.second, bans);
 			continue;
 		}
 		if (as.second >= bans) continue;
 		if (vis.find(as.first) == vis.end() || vis.find(as.first)->second > as.second )
 		{
 			vis.insert(as);
 			cur = as.first;
 			lv = as.second+1;
 			q.push( make_pair(cur+1,lv) );
 			q.push( make_pair(rev(cur),lv) );
 		}
 	}
 
 }
 
 int main(int a, char **ag)
 {	
 	int Case, cases = 0;
 	scanf("%d" , &Case);
 	
 	__aa(a,ag);
 	///////////////
 
 
 	while (Case--)	
 	//for (n = 1 ; n < 100; ++n)
 	{
 		
 
 		cin >> n;
 		long long ans = 0;
 
 
 		if( n <= 10 )
 			ans = n;
 		else
 		{
 			long long rec = rev(n);
 			long long tar = min(n,rec);
 			if (n%10 == 0)
 				tar = n;
 			long long largest = lar(tar);
 			long long cur10 = 10;
 
 			ans += 10;
 			while (largest > cur10)
 			{
 				ans += 9; //10 -> 19  ,109 , 
 				ans++; //19 -> 91 , 901 99
 				ans += cur10-1;
 
 				cur10 *=10;
 			}
 
 			long long realTar = tar;
 			if (tar%10 == 0)			
 				--realTar;
 
 			long long left = realTar/largest;
 			if (left != 1)
 				ans += left+1;
 			ans += realTar%largest;
 			
 
 			if (tar%10 == 0)
 				++ans;
 
 			if ( tar != n)
 				++ans;
 		}
 		bans = n;
 		vis.clear();
 		dfs(1,1);
 
 		printf("Case #%d: " , ++cases );
 	//	if ( bans != ans )
 	//		cout << "!!!!!! " << n << " ";
 		cout << bans << endl;
 	//	cout << ans << endl;
 
 	}
 
 	return 0;
 }
 
