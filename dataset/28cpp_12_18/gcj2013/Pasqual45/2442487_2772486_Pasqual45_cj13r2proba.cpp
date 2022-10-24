#include<fstream>
 #include<iostream>
 #include<sstream>
 #include<iomanip>
 #include<string>
 #include<vector>
 #include<list>
 #include<set>
 #include<map>
 #include<stack>
 #include<queue>
 #include<algorithm>
 #include<functional>
 #include<numeric>
 using namespace std;
 typedef long long ll;
 
 typedef pair<ll, ll> pii;
 typedef pair<ll, pii> tii;
 #define mp make_pair
 
 //int main13R2A()
 int main()
 {
 	ifstream fin("A-small-attempt1.in");
 	ofstream fout("A-small-attempt1.out");
 	//ifstream fin("test.in");
 	//ofstream fout("test.out");
 
 	unsigned int numberOfCases;
 	fin >> numberOfCases;
 
 	for (unsigned int zz=1; zz<=numberOfCases; ++zz)
 	{
 		ll N,M;
 		fin >> N >> M;
 
 		vector<tii> vt(M);
 		for (int i=0; i<M; ++i)
 			fin >> vt[i].first >> vt[i].second.first >> vt[i].second.second;
 
 		sort(vt.begin(), vt.end());
 
 		ll result(0);
 		stack<tii> s;
 		priority_queue<pii, vector<pii>, greater<pii>> q;
 		for (int i=0; i<=M; ++i)
 		{
 			ll a,b,c;
 			if (i<M)
 			{
 				a = vt[i].first, b = vt[i].second.first, c = vt[i].second.second;
 			}
 			else
 			{
 				a = 1LL << 62;
 			}
 			
 			while (!q.empty() && q.top().first < a)
 			{
 				ll nPeople = min(q.top().second, s.top().first);
 				ll whereFrom = s.top().second.first;
 				ll originalDest = s.top().second.second;
 				ll newDest = q.top().first;
 
 				q.top().second -= nPeople;
 				s.top().first -= nPeople;
 
 				if (q.top().second == 0) q.pop();
 				if (s.top().first == 0) s.pop();
 
 				ll x = min(originalDest - whereFrom, newDest - whereFrom), y = max(originalDest - whereFrom, newDest - whereFrom);
 
 				ll c1 = x * N - (x * (x-1))/2;
 				ll c2 = y * N - (y * (y-1))/2;
 
 				if (originalDest > newDest)
 					result += nPeople * (c2-c1);
 				else
 					result += nPeople * (c1-c2);
 			}
 
 			if (i<M)
 			{
 				s.push(mp(c, mp(a,b)));
 				q.push(mp(b, c));
 			}
 		}
 
 		fout << "Case #" << zz << ": " << result << endl;
 	}
 
 	return 0;
 }