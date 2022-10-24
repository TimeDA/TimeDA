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
 	int bits(unsigned int x)
 	{
 		return bitset<32>(x).count();
 	}
 
 	int vdx[] = { 1, -1, 0, 0 };
 	int vdy[] = { 0, 0, 1, -1};
 
 	int C, R, M;
 	vector<string> grid;
 	vector<pii> S, T;
 	int ns, nt;
 	unsigned int vHits[32][32];
 
 	int resultTotal;
 	pii bestResult;
 
 	const static int inf = 0x1f1f1f1f;
 	pii lastMove[1024][1024];
 	
 
 	struct St
 	{
 		St() { memset(v, 0, sizeof(v)); }
 		void set(int i, int j)
 		{
 			v[i] |= (1 << j);
 		}
 
 		bool get(int i, int j) const
 		{
 			return (v[i] & (1 << j)) != 0;
 		}
 
 		unsigned int v[32];
 	};
 
 	St badCells[1024];
 
 	St combine(const St& a, const St& b)
 	{
 		St ret(a);
 		for (int i = 0; i < 32; ++i)
 		{
 			ret.v[i] |= b.v[i];
 		}
 
 		return ret;
 	}
 
 	void fillTurret(int i, int j, int t, St& s)
 	{
 		vHits[i][j] |= (1 << t);
 		s.set(i, j);
 		for (int k = 0; k < 4; ++k)
 		{
 			int dx = vdx[k], dy = vdy[k];
 			int ii(i+dx), jj(j+dy);
 			while (grid[ii][jj] == '.')
 			{
 				vHits[ii][jj] |= (1 << t);
 				s.set(ii, jj);
 				ii += dx; jj += dy;
 			}
 		}
 	}
 
 	void go(int sol, int tur, int lastSol, int lastTur)
 	{
 		pii& result = lastMove[sol][tur];
 		if (result.first != inf)
 			return;
 
 		result = make_pair(lastSol, lastTur);
 
 		int thisCount = bits(sol);
 		if (thisCount > resultTotal)
 		{
 			resultTotal = thisCount;
 			bestResult = make_pair(sol, tur);
 		}
 
 		const St& bad = badCells[((1 << nt) - 1) ^ tur];
 		for (int s = 0; s < ns; ++s)
 		{
 			if ((1 << s) & sol)
 				continue;
 
 			St seen;
 			queue<pair<pii, int> > q;
 			q.push(make_pair(S[s], M));
 			while (!q.empty())
 			{
 				pii loc = q.front().first;
 				int i = loc.first, j = loc.second;
 				int movesLeft = q.front().second;
 				q.pop();
 
 				if (grid[i][j] == '#') continue;
 
 				if (!seen.get(i, j))
 				{
 					seen.set(i, j);
 
 					if (bad.get(i, j))
 					{
 						// Have to stop and shoot something
 						unsigned int who = vHits[i][j];
 						for (int t = 0; t < nt; ++t)
 						{
 							if (tur & (1<<t)) continue; // ALready shot this one
 							if ((1<<t) & who)
 							{
 								go(sol | (1 << s), tur | (1 << t), s, t);
 							}
 						}
 
 					}
 					else if (movesLeft > 0)
 					{
 						q.push(make_pair(make_pair(i + 1, j), movesLeft - 1));
 						q.push(make_pair(make_pair(i - 1, j), movesLeft - 1));
 						q.push(make_pair(make_pair(i, j + 1), movesLeft - 1));
 						q.push(make_pair(make_pair(i, j - 1), movesLeft - 1));
 					}
 				}
 			}
 		}
 	}
 }
 
 //int main17R2_D()
 int main()
 {
 	ifstream fin("D-small-attempt0.in");
 	ofstream fout("D-small-attempt0.out");
 	//ifstream fin("test.in");
 	//ofstream fout("test.out");
 
 	unsigned int numberOfCases;
 	fin >> numberOfCases;
 
 	for (unsigned int zz = 1; zz <= numberOfCases; ++zz)
 	{
 		fin >> C >> R >> M;
 
 		resultTotal = 0;
 		S.clear(); T.clear();
 		memset(vHits, 0, sizeof(vHits));
 		memset(lastMove, inf, sizeof(lastMove));
 		memset(badCells, 0, sizeof(badCells));
 
 		grid.resize(R + 2);
 		grid[0] = grid[R + 1] = string(C + 2, '#');
 
 		for (int i = 1; i <= R; ++i)
 		{
 			fin >> grid[i];
 			grid[i] = '#' + grid[i] + '#';
 
 			for (int j = 1; j <= C; ++j)
 			{
 				if (grid[i][j] == 'S')
 				{
 					S.emplace_back(i, j);
 					grid[i][j] = '.';
 				}
 				else if (grid[i][j] == 'T')
 				{
 					T.emplace_back(i, j);
 					grid[i][j] = '.';
 				}
 			}
 		}
 
 		ns = S.size();
 		nt = T.size();
 		for (int t = 0; t < nt; ++t)
 		{
 			fillTurret(T[t].first, T[t].second, t, badCells[1<<t]);
 		}
 
 		for (int mask = 1; mask < (1 << nt); ++mask)
 		{
 			if (mask & (mask - 1))
 			{
 				int p = 1;
 				while ((mask&p) == 0)
 					p <<= 1;
 
 				badCells[mask] = combine(badCells[p], badCells[mask - p]);
 			}
 		}
 			
 
 		go(0, 0, -1, -1);
 		fout << "Case #" << zz << ": " << resultTotal << endl;
 
 		vector<pii> vRes(resultTotal);
 
 		pii curResult = bestResult;
 		for (int i = 0; i < resultTotal; ++i)
 		{
 			vRes[i] = lastMove[curResult.first][curResult.second];
 
 			curResult.first -= (1 << vRes[i].first);
 			curResult.second -= (1 << vRes[i].second);
 		}
 
 		reverse(vRes.begin(), vRes.end());
 		for (int i = 0; i < resultTotal; ++i)
 		{
 			fout << vRes[i].first + 1 << " " << vRes[i].second + 1<< endl;;
 		}
 
 	}
 
 	return 0;
 }
