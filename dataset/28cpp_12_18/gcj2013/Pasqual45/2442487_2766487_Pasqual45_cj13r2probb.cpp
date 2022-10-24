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
 
 namespace
 {
 	ll N,P;
 	bool v[100];
 
 	bool canWin(int round, ll better, ll worse)
 	{
 		if (round == N) return true;
 
 		bool needWin = v[round];
 		if (needWin)
 		{
 			if (worse == 0) return false;
 			--worse;
 
 			ll left = (better + worse) / 2;
 			ll mostWorst = worse / 2;
 			return canWin(round+1, left - mostWorst, mostWorst);
 		}
 		else
 		{
 			if (better == 0 || worse > 0) return true;
 			--better;
 
 			ll left = (better + worse) / 2;
 			ll mostWorst = min(worse, left);
 			return canWin(round+1, left - mostWorst, mostWorst);
 		}
 	}
 
 	bool canFinishLower(int round, ll better, ll worse)
 	{
 		if (better == 0) return false;
 
 		bool needLoss = !v[round];
 		if (needLoss)
 		{
 			if (better == 0) return false;
 			--better;
 
 			ll left = (better + worse) / 2;
 			ll maxBetterLosers = better / 2;
 			return canFinishLower(round+1, maxBetterLosers, left - maxBetterLosers);
 		}
 		else
 		{
 			if (better > 0) return true;
 			--worse;
 
 			ll left = (better + worse) / 2;
 			ll mostBetter = min(left, better);
 			return canFinishLower(round+1, mostBetter, left - mostBetter);
 		}
 	}
 }
 
 //int main13R2B()
 int main()
 {
 	ifstream fin("B-small-attempt1.in");
 	ofstream fout("B-small-attempt1.out");
 	//ifstream fin("test.in");
 	//ofstream fout("test.out");	
 
 	unsigned int numberOfCases;
 	fin >> numberOfCases;
 
 	for (unsigned int zz=1; zz<=numberOfCases; ++zz)
 	{
 		fin >> N >> P; // 2^N teams, P prizes
 
 		--P;
 		memset(v,0,sizeof(v));
 		for (int i=0; i<N; ++i)
 			if ((P & (1LL << (N-1-i))) == 0)
 				v[i] = true;
 
 		ll nTeams = (1LL) << N;
 		ll lo = 0, hi = nTeams;
 		while (hi - lo > 1)
 		{
 			ll mid = (hi+lo)/2;
 			bool can = canWin(0, mid, nTeams - mid - 1);
 			if (can)
 				lo = mid;
 			else
 				hi = mid;
 		}
 
 		ll worstWinner = lo;
 
 		lo = -1, hi = nTeams;
 		while (hi - lo > 1)
 		{
 			ll mid = (hi+lo)/2;
 			bool can = canFinishLower(0, mid, nTeams - mid - 1);
 			if (can)
 				hi = mid;
 			else
 				lo = mid;
 		}
 
 		ll bestLoser = hi;
 
 		fout << "Case #" << zz << ": " << (bestLoser-1) << " " << worstWinner << endl;
 	}
 
 	return 0;
 }