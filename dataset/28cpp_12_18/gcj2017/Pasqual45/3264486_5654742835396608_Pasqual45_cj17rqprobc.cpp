#include<fstream>
 #include<iostream>
 #include<sstream>
 #include<iomanip>
 #include<string>
 #include<vector>
 #include<list>
 #include<set>
 #include<map>
 #include<queue>
 #include<algorithm>
 #include<functional>
 #include<numeric>
 #include<bitset>
 using namespace std;
 typedef pair<int, int> pii;
 typedef long long ll;
 typedef pair<ll, ll> pll;
 #define mp make_pair
 
 //int main17RQ_C()
 int main()
 {
 	ifstream fin("C-small-1-attempt0.in");
 	ofstream fout("C-small-1-attempt0.out");
 	//ifstream fin("test.in");
 	//ofstream fout("test.out");
 
 	unsigned int numberOfCases;
 	fin >> numberOfCases;
 
 	for (unsigned int zz = 1; zz <= numberOfCases; ++zz)
 	{
 		ll k;
 		queue<pll> q;
 		q.push(make_pair(0, 1));
 		fin >> q.front().first >> k;
 
 		while (k > 1)
 		{
 			pll front = q.front();
 			ll num = min(k - 1, front.second);
 
 			ll a = front.first / 2, b = (front.first - 1) / 2;
 
 			if (q.back().first == a)
 			{
 				q.back().second += num;
 			}
 			else
 			{
 				q.emplace(a, num);
 			}
 
 			if (q.back().first == b)
 			{
 				q.back().second += num;
 			}
 			else
 			{
 				q.emplace(b, num);
 			}
 
 			k -= num;
 			if (num == front.second)
 				q.pop();
 		}
 
 
 		pll front = q.front();
 		ll a = front.first / 2, b = (front.first - 1) / 2;
 
 		fout << "Case #" << zz << ": " << a << " " << b << endl;
 	}
 
 	return 0;
 }
