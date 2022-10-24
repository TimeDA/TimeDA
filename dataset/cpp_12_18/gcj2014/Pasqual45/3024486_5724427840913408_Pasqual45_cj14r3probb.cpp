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
 	int P, Q, N;
 	ll dp[101][12000], H[101], G[101];
 	int shotsMe[101], shotsTower[101], shotsTowerOnly[101];
 
 	int minShots(int hp, int& maxTower)
 	{
 		int ret = 1;
 		while (hp > 0)
 		{
 			int towerShots = (hp - 1) / Q;
 			int newHP = hp - towerShots * Q;
 			
 			if (P >= newHP)
 			{
 				maxTower = towerShots;
 				return ret;
 			}
 
 			++ret;
 			hp -= P;
 		}
 	}
 
 	ll solve(int loc, int extraShots)
 	{
 		if (loc == N) return 0;
 		ll& ret = dp[loc][extraShots];
 		if (ret >= 0)
 			return ret;
 
 		ret = solve(loc + 1, extraShots + shotsTowerOnly[loc]);
 
 		int extraShotsAfter = extraShots + shotsTower[loc] - shotsMe[loc];
 		if (extraShotsAfter >= 0)
 		{
 			ll next = solve(loc + 1, extraShotsAfter);
 			ret = max(ret, next + G[loc]);
 		}
 
 		return ret;
 	}
 }
 
 //int main14R3_B()
 int main()
 {
 	ifstream fin("B-small-attempt0.in");
 	ofstream fout("B-small-attempt0.out");
 	//ifstream fin("test.in");
 	//ofstream fout("test.out");
 
 	unsigned int numberOfCases;
 	fin >> numberOfCases;
 
 	for (unsigned int zz = 1; zz <= numberOfCases; ++zz)
 	{
 		fin >> P >> Q >> N;
 		for (int i = 0; i < N; ++i)
 		{
 			fin >> H[i] >> G[i];
 			shotsMe[i] = minShots(H[i], shotsTower[i]);
 			shotsTowerOnly[i] = (H[i] + Q - 1) / Q;
 		}
 
 		memset(dp, -1, sizeof(dp));
 		ll ret = solve(0, 1);
 		fout << "Case #" << zz << ": " << ret << endl;
 	}
 
 	return 0;
 }
