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
 	int N, S;
 	double t[1001];
 
 	const static double inf = 1.0e50;
 	struct P
 	{
 		P(int _x = 0, int _y = 0, int _z = 0) : x(_x), y(_y), z(_z) {}
 		int x, y, z;
 	};
 
 	double sqr(double x) { return x*x;  }
 	double dist(const P& a, const P& b)
 	{
 		double ret = sqr(a.x - b.x) + sqr(a.y - b.y) + sqr(a.z - b.z);
 		return sqrt(ret);
 	}
 }
 
 //int main16R3_C()
 int main()
 {
 	ifstream fin("C-small-attempt0.in");
 	ofstream fout("C-small-attempt0.out");
 	//ifstream fin("test.in");
 	//ofstream fout("test.out");
 
 	fout << fixed << setprecision(9);
 
 	unsigned int numberOfCases;
 	fin >> numberOfCases;
 
 	for (unsigned int zz = 1; zz <= numberOfCases; ++zz)
 	{
 		fin >> N >> S;
 		vector<P> x(N), v(N);
 		for (int i = 0; i < N; ++i)
 		{
 			fin >> x[i].x >> x[i].y >> x[i].z >> v[i].x >> v[i].y >> v[i].z;
 		}
 		
 		fill(t, t + 1001, inf);
 
 		priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int> > > q;
 		q.emplace(0.0, 0);
 		while (!q.empty())
 		{
 			double thisDist = q.top().first;
 			int thisLoc = q.top().second;
 			q.pop();
 
 			if (thisDist < t[thisLoc])
 			{
 				t[thisLoc] = thisDist;
 
 				for (int i = 0; i < N; ++i)
 				{
 					if (i == thisLoc) continue;
 
 					double d = dist(x[thisLoc], x[i]);
 					q.emplace(max(thisDist, d), i);
 				}
 			}
 		}
 
 		fout << "Case #" << zz << ": " << t[1] << endl;
 	}
 
 	return 0;
 }
