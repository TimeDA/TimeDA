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
 using namespace std;
 typedef pair<int, int> pii;
 typedef long long ll;
 #define mp make_pair
 
 //int main12R2A()
 int main()
 {
 	ifstream fin("A-small-attempt0.in");
 	ofstream fout("A-small-attempt0.out");
 	//ifstream fin("test.in");
 	//ofstream fout("test.out");	
 
 	unsigned int numberOfCases;
 	fin >> numberOfCases;
 
 	int N,D;
 	for (unsigned int zz=1; zz<=numberOfCases; ++zz)
 	{
 		fin >> N;
 		vector<ll> d(N+1), l(N+1);
 		for (int i=0; i<N; ++i)
 			fin >> d[i] >> l[i];
 
 		fin >> D;
 		d[N]=D; l[N]=0;
 
 		vector<ll> best(N+1, -1);
 		best[0] = d[0];
 
 		for (int i=0; i<N; ++i)
 		{
 			for (int j=i+1; j<=N; ++j)
 			{
 				if (d[j] > d[i] + best[i]) break;
 				best[j] = max(best[j], min(l[j], d[j]-d[i]));
 			}
 		}
 
 		fout << "Case #" << zz << ": " << (best[N] >= 0 ? "YES" : "NO") << endl;
 	}
 
 	return 0;
 }