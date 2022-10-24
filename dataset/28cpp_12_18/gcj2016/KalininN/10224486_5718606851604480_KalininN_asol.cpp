#include <bits/stdc++.h>
 
 using namespace std;
 
 using ll = long long;
 using ld = long double;
 using D = double;
 using uint = unsigned int;
 
 #ifdef WIN32
     #define LLD "%I64d"
 #else
     #define LLD "%lld"
 #endif
 
 #define pb push_back
 #define mp make_pair
 #define all(x) x.begin(),x.end()
 #define fi first
 #define se second
 
 int P, R, S;
 int n;
 string Ps, Rs, Ss, Psn, Rsn, Ssn;
 
 int main()
 {
     int NT = 0;
     scanf("%d", &NT);
     for (int T = 1; T <= NT; T++)
     {
         printf("Case #%d:", T);
         scanf("%d%d%d%d", &n, &R, &P, &S);
 		Rs = "R";
 		Ps = "P";
 		Ss = "S";
 		bool ok = true;
 		for (int i = 0; i < n; i++)
 		{
 			int a = P + R - S;
 			if (a % 2 != 0)
 			{
 				ok = false;
 				break;
 			}
 			a /= 2;
 			int nP = a;
 			int nR = R - a;
 			int nS = P - a;
 			if (nP < 0 || nR < 0 || nS < 0)
 			{
 				ok = false;
 				break;
 			}
 			P = nP;
 			R = nR;
 			S = nS;
 			Psn = min(Ps + Rs, Rs + Ps);
 			Rsn = min(Ss + Rs, Rs + Ss);
 			Ssn = min(Ss + Ps, Ps + Ss);
 			Ps = Psn;
 			Rs = Rsn;
 			Ss = Ssn;
 		}
 		if (!ok) printf(" IMPOSSIBLE\n");
 		else if (P > 0) printf(" %s\n", Ps.c_str());
 		else if (R > 0) printf(" %s\n", Rs.c_str());
 		else if (S > 0) printf(" %s\n", Ss.c_str());
 		fprintf(stderr, "%d/%d cases done!\n", T, NT);
     }
     return 0;
 }
