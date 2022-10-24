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
 	int N;
 	int C[90], g[90];
 	int how[90][90];
 	vector<pii> v[90]; // (where, roadIndex)
 
 	bool touches(int loc, int road)
 	{
 		return road >= 0 && (loc == road || loc == g[road]);
 	}
 
 	void spread(int i, int num, int cur, int last)
 	{
 		how[i][cur] = num;
 
 		for (pii p : v[cur])
 		{
 			int where = p.first, road = p.second;
 			if (where != last)
 			{
 				spread(i, num, where, cur);
 			}
 		}
 	}
 
 
 	int playSolo(int loc, int lastUsed, int bad1, int bad2)
 	{
 		int ret = 0;
 
 		for (pii p : v[loc])
 		{
 			int j = p.first, road = p.second;
 			if (road == lastUsed || road == bad1 || road == bad2) continue;
 
 			int next = playSolo(j, road, bad1, bad2);
 			if (!touches(j, bad1) && !touches(j, bad2))
 				next += C[j];
 
 			ret = max(ret, next);
 		}
 
 		return ret;
 	}
 
 	int playTwo(int loc1, int loc2, int lastUsed1, int lastUsed2)
 	{
 		int ret = -1000000000;
 
 		for (pii p : v[loc1])
 		{
 			int j = p.first, road = p.second;
 			if (road == lastUsed1) continue;
 
 			int cur = 0;
 			if (j == loc2)
 			{
 				// Touch opponent, dont' collect coins bad roads are road and lastUsed2
 				vector<int> choices(2, 0);
 				for (pii q : v[j])
 				{
 					int j2 = q.first, road2 = q.second;
 					if (road2 == road || road2 == lastUsed2) continue;
 
 					choices.push_back(C[j2] + playSolo(j2, road2, -1, -1));
 				}
 
 				sort(choices.begin(), choices.end(), greater<int>());
 				cur = choices[1] - choices[0];
 			}
 			else if (road == how[loc1][loc2])
 			{
 				// Towards opponent
 				cur = C[j];
 				cur -= playTwo(loc2, j, lastUsed2, road);
 			}
 			else
 			{
 				// Away from opponent
 				cur = C[j];
 				cur += playSolo(j, road, -1, -1);
 				cur -= playSolo(loc2, lastUsed2, lastUsed1, road);
 			}
 
 			ret = max(ret, cur);
 		}
 
 		return ret;
 	}
 
 	int play(int x, int y)
 	{
 		if (x == y)
 		{
 			int best = -1000000000;
 			for (pii p : v[x])
 			{
 				int cur = C[x]; // I get first move
 				int j = p.first, road = p.second;
 
 				cur += C[j] + playSolo(j, road, -1, -1);
 				cur -= playSolo(x, road, -1, -1);
 				best = max(best, cur);
 			}
 
 			return best;
 		}
 
 		int balance = C[x] - C[y];
 		return balance + playTwo(x, y, -1, -1);
 	}
 }
 
 //int main14R3_D()
 int main()
 {
 	ifstream fin("D-small-attempt2.in");
 	ofstream fout("D-small-attempt2.out");
 	//ifstream fin("test.in");
 	//ofstream fout("test.out");
 
 	unsigned int numberOfCases;
 	fin >> numberOfCases;
 
 	for (unsigned int zz = 1; zz <= numberOfCases; ++zz)
 	{
 		memset(how, -1, sizeof(how));
 		fill(v, v + 90, vector<pii>());
 
 		fin >> N;
 		for (int i = 0; i < N; ++i)
 			fin >> C[i];
 
 		for (int i = 0; i + 1 < N; ++i)
 		{
 			fin >> g[i];
 			--g[i];
 		}
 
 		for (int i = 0; i+1 < N; ++i)
 		{
 			int j = g[i];
 			v[i].push_back({ j, i });
 			v[j].push_back({ i, i });
 		}
 
 		for (int i = 0; i < N; ++i)
 		{
 			for (pii p : v[i])
 			{
 				int j = p.first, road = p.second;
 				spread(i, road, j, i);
 			}
 		}
 
 		int result = -1000000000;
 		for (int i = 0; i < N; ++i)
 		{
 			int worst = 1000000000;
 			for (int j = 0; j < N; ++j)
 			{
 				int next = play(i, j);
 				worst = min(worst, next);
 			}
 
 			result = max(result, worst);
 		}
 
 
 		
 		fout << "Case #" << zz << ": " << result << endl;
 	}
 
 	return 0;
 }
