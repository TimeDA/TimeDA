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
 	int W, H, B;
 	int x[11], xx[11], y[11], yy[11];
 	int m[501];
 	bool blocked[501][501];
 
 
 
 	const static int max_nodes = 100005; // CHANGE TO SOMETHING SENSIBLE, INCLUDING E.G. * 2 + 1!!!
 	const static int inf = 0x1f1f1f1f;
 
 	struct MaxFlow {
 		//int c[max_nodes][max_nodes], f[max_nodes][max_nodes], p[max_nodes];
 		int p[max_nodes];
 		vector<pii> children[max_nodes];
 		vector<int> parents[max_nodes];
 		int N, A, Z, totalFlow;
 		queue<pair<int, int> > q;
 
 		explicit MaxFlow(int source, int sink) : A(source), Z(sink), N(max(source, sink) + 1)
 		{
 			if (N>max_nodes) cout << "N too big!"; if (A == Z) cout << "Error"; reset();
 		}
 
 		void reset() {totalFlow = 0; }
 		void set(int a, int z, int capacity = 1) { N = max(max(a, z) + 1, N); children[a].push_back({ z, 0 }); parents[z].push_back(a); }
 
 		int getFlow(int i, int j)
 		{
 			vector<pii>& v = children[i];
 			for (int k = 0; k < v.size(); ++k)
 			{
 				if (v[k].first == j)
 				{
 					return v[k].second;
 				}
 			}
 
 			return 0;
 		}
 
 		void addFlow(int i, int j, int amount)
 		{
 			vector<pii>& v = children[i];
 			for (int k = 0; k < v.size(); ++k)
 			{
 				if (v[k].first == j)
 				{
 					v[k].second += amount;
 					if (v[k].second > 1)
 						throw "Bad capacity";
 
 					return;
 				}
 			}
 
 			addFlow(j, i, -amount);
 		}
 
 		bool augment()
 		{
 			memset(p, -1, sizeof(p)); p[A] = A;
 			q.push(make_pair(inf, A));
 			while (!q.empty())
 			{
 				int i = q.front().second, flow_in = q.front().first;
 
 				if (i == Z)
 				{	// add a path and quit
 					int j = i;
 					i = p[i];
 					while (i != j)
 					{
 						addFlow(i, j, flow_in);
 						j = i; i = p[j];
 					}
 					totalFlow += 1;
 					while (!q.empty()) q.pop();
 					return true;
 				}
 
 
 				const vector<pii>& v = children[i];
 				for (int z = 0; z < v.size(); ++z)
 				{
 					int j = v[z].first;
 					if (p[j] >= 0) continue;
 
 					int existingFlow = v[z].second;
 					if (existingFlow == 0)
 					{
 						p[j] = i;
 						q.push(make_pair(1, j));
 					}
 				}
 
 				const vector<int>& vv = parents[i];
 				for (int z = 0; z < vv.size(); ++z)
 				{
 					int j = vv[z];
 					if (p[j] >= 0) continue;
 
 					if (getFlow(j, i) > 0)
 					{
 						p[j] = i;
 						q.push(make_pair(1, j));
 					}
 				}
 
 				q.pop();
 			}
 			return false;
 		}
 
 		int max_flow() //g and N should be set
 		{
 			while (augment()) {}
 			return totalFlow;
 		}
 	}; // end of MaxFlow
 }
 
 //int main14R2_C()
 int main()
 {
 	ifstream fin("C-small-attempt2.in");
 	ofstream fout("C-small-attempt2.out");
 	//ifstream fin("test.in");
 	//ofstream fout("test.out");
 
 	unsigned int numberOfCases;
 	fin >> numberOfCases;
 
 	for (unsigned int zz = 1; zz <= numberOfCases; ++zz)
 	{
 		
 		fin >> W >> H >> B;
 
 		for (int i = 0; i < B; ++i)
 			fin >> x[i] >> y[i] >> xx[i] >> yy[i];
 
 
 		memset(blocked, 0, sizeof(blocked));
 		for (int k = 0; k < B; ++k)
 		{
 			for (int i = x[k]; i <= xx[k]; ++i)
 			{
 				for (int j = y[k]; j <= yy[k]; ++j)
 				{
 					blocked[i][j] = true;
 				}
 			}
 		}
 
 		int source = 2 * H*W, sink = source + 1;
 		MaxFlow f(source, sink);
 		cout << source << " " << sink << endl;
 		for (int i = 0; i < W; ++i)
 		{
 			for (int j = 0; j < H; ++j)
 			{
 				int idxIn = j*W + i;
 				int idxOut = H*W + j*W + i;
 
 				if (j == 0)
 				{
 					f.set(source, idxIn);
 				}
 
 				if (j == H - 1)
 				{
 					f.set(idxOut, sink);
 				}
 
 				if (!blocked[i][j])
 				{
 					f.set(idxIn, idxOut);
 				}
 
 				if (i > 0)
 				{
 					f.set(idxOut, idxIn - 1);
 				}
 
 				if (i+1 < W)
 				{
 					f.set(idxOut, idxIn + 1);
 				}
 
 				if (j > 0)
 				{
 					f.set(idxOut, idxIn - W);
 				}
 
 				if (j + 1 < H)
 				{
 					f.set(idxOut, idxIn + W);
 				}
 			}
 		}
 
 		int result = f.max_flow();
 		fout << "Case #" << zz << ": " << result << endl;
 	}
 
 	return 0;
 }
