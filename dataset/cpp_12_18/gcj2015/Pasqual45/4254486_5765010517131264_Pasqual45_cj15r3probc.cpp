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
 
 namespace
 {
 	int N;
 	ll Y;
 	ll p[500], s[500];
 
 	double t[501][501][2];
 	vector<pll> vl, vr;
 	int nl, nr;
 
 	ll abss(ll x) { return x < 0 ? -x : x; }
 
 	void parsevec(vector<pll>& v)
 	{
 		sort(v.begin(), v.end(), [](pll l, pll r)
 		{
 			return l.second > r.second || (l.second == r.second && l.first > r.first);
 		});
 
 		for (size_t i = 1; i < v.size();)
 		{
 			if (v[i].first <= v[i - 1].first)
 				v.erase(v.begin() + i);
 			else
 				++i;
 		}
 	}
 
 	double getLoc(const vector<pll>& v, size_t idx, double tCurr)
 	{
 		double dist = double(v[idx].first) + tCurr * v[idx].second;
 		return dist;
 	}
 
 	size_t getEffective(const vector<pll>& v, size_t i, double tCurr)
 	{
 		if (i == 0) return 0;
 		size_t ret = i;
 
 		double distBase = getLoc(v, i - 1, tCurr);
 		while (ret < v.size())
 		{
 			double distMe = getLoc(v, ret, tCurr);
 			if (distMe > distBase)
 				break;
 
 			++ret;
 		}
 		
 		return ret;
 	}
 
 }
 
 //int main15R3_C()
 int main()
 {
 	ifstream fin("C-small-attempt1.in");
 	ofstream fout("C-small-attempt1.out");
 	//ifstream fin("test.in");
 	//ofstream fout("test.out");
 
 	unsigned int numberOfCases;
 	fin >> numberOfCases;
 
 	fout << std::fixed << std::setprecision(6);
 
 	for (unsigned int zz = 1; zz <= numberOfCases; ++zz)
 	{
 		fin >> Y >> N;
 		for (int i = 0; i < N; ++i)
 		{
 			fin >> p[i];
 		}
 
 		for (int i = 0; i < N; ++i)
 		{
 			fin >> s[i];
 		}
 
 		vl.clear(); vr.clear();
 		for (int i = 0; i < N; ++i)
 		{
 			(p[i] < 0 ? vl : vr).push_back(make_pair(abss(p[i]), s[i]));
 		}
 
 		parsevec(vl);
 		parsevec(vr);
 		nl = vl.size(); nr = vr.size();
 
 		for (int il = 0; il <= nl; ++il)
 		{
 			for (int ir = 0; ir <= nr; ++ir)
 			{
 				t[il][ir][0] = t[il][ir][1] = 1e200;
 			}
 		}
 
 		t[0][0][0] = t[0][0][1] = 0.0;
 
 		double ret(1e200);
 		for (int il = 0; il <= nl; ++il)
 		{
 			for (int ir = 0; ir <= nr; ++ir)
 			{
 				for (int isRight = 0; isRight < 2; ++isRight)
 				{
 					double tCurr = t[il][ir][isRight];
 					if (tCurr == 1e200) continue;
 
 					if (isRight == 0 && ir < nr)
 					{
 						// Just caught left quail with index il - 1, now heading right
 						double myLoc = il == 0 ? 0.0 : getLoc(vl, il - 1, tCurr);
 
 						int effectiveIL = getEffective(vl, il, tCurr);
 						if (ir == nr && effectiveIL == nl)
 						{
 							ret = min(ret, tCurr);
 						}
 
 						double worstTime = tCurr;
 						for (int ir2 = ir + 1; ir2 <= nr; ++ir2)
 						{
 							double hisLoc = getLoc(vr, ir2 - 1, tCurr);
 							double dist = myLoc + hisLoc;
 							ll speedDiff = Y - vr[ir2 - 1].second;
 							double tExtra = dist / speedDiff;
 							double tNew = tCurr + tExtra;
 
 							if (tNew >= worstTime)
 							{
 								worstTime = tNew;
 								t[effectiveIL][ir2][1] = min(t[effectiveIL][ir2][1], tNew);
 							}
 						}
 
 						if (effectiveIL == nl)
 						{
 							ret = min(ret, worstTime);
 						}
 					}
 
 					if (isRight == 1 && il < nl)
 					{
 						// Just caught right quail with index ir - 1, now heading left
 						double myLoc = ir == 0 ? 0.0 : getLoc(vr, ir - 1, tCurr);
 
 						int effectiveIR = getEffective(vr, ir, tCurr);
 						if (il == nl && effectiveIR == nr)
 						{
 							ret = min(ret, tCurr);
 						}
 
 						double worstTime = tCurr;
 						for (int il2 = il + 1; il2 <= nl; ++il2)
 						{
 							double hisLoc = getLoc(vl, il2 - 1, tCurr);
 							double dist = myLoc + hisLoc;
 							ll speedDiff = Y - vl[il2 - 1].second;
 							double tExtra = dist / speedDiff;
 							double tNew = tCurr + tExtra;
 
 							if (tNew >= worstTime)
 							{
 								worstTime = tNew;
 								t[il2][effectiveIR][0] = min(t[il2][effectiveIR][0], tNew);
 							}
 						}
 
 						if (effectiveIR == nr)
 						{
 							ret = min(ret, worstTime);
 						}
 					}
 				}
 			}
 		}
 		
 		double result = ret;
 		fout << "Case #" << zz << ": " << result << endl;
 	}
 
 	return 0;
 }
