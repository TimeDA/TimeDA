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
 #define mp make_pair
 
 namespace
 {
 	ll v[1000001], w[1000001];
 }
 
 //int main14R3_A()
 int main()
 {
 	ifstream fin("A-small-attempt0.in");
 	ofstream fout("A-small-attempt0.out");
 	//ifstream fin("test.in");
 	//ofstream fout("test.out");
 
 	unsigned int numberOfCases;
 	fin >> numberOfCases;
 
 	fout << std::setprecision(12);
 
 	for (unsigned int zz = 1; zz <= numberOfCases; ++zz)
 	{
 		ll N, p, q, r, s;
 		fin >> N >> p >> q >> r >> s;
 
 		ll ip = 0;
 		w[0] = 0;
 		for (int i = 0; i < N; ++i)
 		{
 			v[i] = ((ip + q) % r) + s;
 			ip = (ip + p) % r;
 			w[i+1] = v[i] + w[i];
 		}
 
 		ll tot = w[N];
 		double result = 0.0;
 
 		for (int i = 0; i < N; ++i)
 		{
 			ll x1 = w[i];
 			ll target = ((tot - x1) / 2) + x1;
 
 			int loc = lower_bound(w + i, w + N + 1, target) - w;
 			for (int j = loc - 2; j <= loc + 2; ++j)
 			{
 				if (j >= i && j < N)
 				{
 					ll x2 = w[j + 1] - x1;
 					ll x3 = tot - x1 - x2;
 					ll next = tot - max(x1, max(x2, x3));
 					double dn = double(next) / tot;
 					result = max(result, dn);
 				}
 			}
 		}
 		
 		fout << "Case #" << zz << ": " << result << endl;
 	}
 
 	return 0;
 }
