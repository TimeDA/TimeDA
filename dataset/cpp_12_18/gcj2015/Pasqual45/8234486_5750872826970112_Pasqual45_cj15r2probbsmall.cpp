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
 	int n;
 	double V, X;
 	double r[101], c[101];
 
 	bool can(double t)
 	{
 		double target = V * X;
 		double vLo = 0.0, vxLo = 0.0, vHi = 0.0, vxHi = 0.0;
 		for (int i = 0; i < n; ++i)
 		{
 			double maxV = r[i] * t;
 			double neededV = V - vLo;
 			double usedV = min(maxV, neededV);
 
 			vLo += usedV;
 			vxLo += usedV * c[i];
 			if (usedV == neededV)
 				break;
 		}
 
 		for (int i = n-1; i >= 0; --i)
 		{
 			double maxV = r[i] * t;
 			double neededV = V - vHi;
 			double usedV = min(maxV, neededV);
 
 			vHi += usedV;
 			vxHi += usedV * c[i];
 			if (usedV == neededV)
 				break;
 		}
 
 		return (vxLo <= target + 1e-12 && vxHi >= target - 1e-12);
 	}
 }
 
 //int main15R2_B()
 int main()
 {
 	ifstream fin("B-small-attempt2.in");
 	ofstream fout("B-small-attempt2.out");
 	//ifstream fin("test.in");
 	//ofstream fout("test.out");
 
 	fout << std::fixed << std::setprecision(9);
 
 	unsigned int numberOfCases;
 	fin >> numberOfCases;
 
 	for (unsigned int zz = 1; zz <= numberOfCases; ++zz)
 	{
 		fin >> n >> V >> X;
 		vector<pair<double, double> >vp(n);
 		for (int i = 0; i < n; ++i)
 		{
 			fin >> vp[i].second >> vp[i].first;
 		}
 
 		sort(vp.begin(), vp.end());
 		for (int i = 0; i < n; ++i)
 		{
 			r[i] = vp[i].second;
 			c[i] = vp[i].first;
 		}
 
 		if (c[0] > X + 1e-10 || c[n - 1] < X - 1e-10)
 		{
 			fout << "Case #" << zz << ": " << "IMPOSSIBLE" << endl;
 		}
 		else
 		{
 			double t = 0.0;
 			
 			if (n==1 || (n==2 && c[0] == c[1]))
 			{
 				double sumR = accumulate(r, r + n, 0.0);
 				t = V / sumR;
 			}
 			else
 			{
 				double alpha = (X - c[0]) / (c[1] - c[0]);
 				double v1 = alpha * V, v0 = (1 - alpha) * V;
 
 				double t1 = v1 / r[1], t0 = v0 / r[0];
 				t = max(t0, t1);
 			}
 
 			fout << "Case #" << zz << ": " << t << endl;
 		}
 	}
 
 	return 0;
 }
