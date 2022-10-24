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
 
 typedef pair<double, int> pdi;
 #define mp make_pair
 
 namespace
 {
 	const static int max_nodes = 102;
 	const static ll inf = 0x1f1f1f1f1f1f1f1fLL;
 
 	struct Shortest {
 		explicit Shortest(int n) : N(n) { if (n>max_nodes) cout << "N too big!"; reset(); }
 		ll g[max_nodes][max_nodes], e[max_nodes][max_nodes], p[max_nodes][max_nodes];
 		int N;
 
 		inline void reset() { memset(g, inf, sizeof(g)); }
 		inline void set(int a, int z, ll weight = 1, bool both_ways = false) { g[a][z] = weight; if (both_ways) g[z][a] = weight; }
 		void run() {
 			memset(p, -1, sizeof(p)); memcpy(e, g, sizeof(g));
 			for (int i = 0; i<N; ++i)
 				for (int j = 0; j<N; ++j)
 					if (g[i][j] < inf) p[i][j] = i; else if (i == j) p[i][j] = i, e[i][j] = 0;
 			for (int k = 0; k<N; ++k)
 				for (int i = 0; i<N; ++i)
 					for (int j = 0; j<N; ++j)
 						if (e[i][k] + e[k][j] < e[i][j])
 							e[i][j] = e[i][k] + e[k][j], p[i][j] = p[k][j];
 		}
 		inline ll finish_time(int start_idx, int end_idx) { return e[start_idx][end_idx]; }
 	};
 
 
 	struct Dijkstra {
 		explicit Dijkstra(int n) : N(n) { if (n>max_nodes) cout << "N too big!"; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) graph[i][j] = 1e200; }
 		double graph[max_nodes][max_nodes], end_time[max_nodes];
 		int predecessor[max_nodes], N;
 
 		inline void set(int a, int z, double w, bool both_ways = false) { graph[a][z] = w; if (both_ways) graph[z][a] = w; }
 		void run(int start) //graph and N should be set
 		{
 			for (int i = 0; i < N; ++i)
 				end_time[i] = 1e200;
 
 			memset(predecessor, -1, sizeof(predecessor));
 			priority_queue<pdi, vector<pdi>, greater<pdi>> q;
 			q.push(make_pair(0.0, start));
 			while (!q.empty())
 			{
 				int i = q.top().second;
 				double time = q.top().first;
 				q.pop();
 				if (time < end_time[i])
 				{
 					/* CAREFUL - PREDECESSOR IS WRONG */
 					end_time[i] = time;
 					for (int j = 0; j<N; ++j)
 						if (time + graph[i][j] < end_time[j])
 							q.push(make_pair(time + graph[i][j], j)), predecessor[j] = i;
 				}
 			}
 		}
 		inline double finish_time(int end_idx) { return end_time[end_idx]; }
 	};
 }
 
 //int main17R1B_C()
 int main()
 {
 	ifstream fin("C-small-attempt0.in");
 	ofstream fout("C-small-attempt0.out");
 	//ifstream fin("test.in");
 	//ofstream fout("test.out");
 
 	fout << fixed << setprecision(9);
 
 	unsigned int numberOfCases;
 	fin >> numberOfCases;
 
 	Shortest g(0);
 	for (unsigned int zz = 1; zz <= numberOfCases; ++zz)
 	{
 		int N, Q;
 		fin >> N >> Q;
 
 		g.N = N;
 		g.reset();
 
 		vector<int> E(N), S(N);
 		for (int i = 0; i < N; ++i)
 		{
 			fin >> E[i] >> S[i];
 		}
 
 		for (int i = 0; i < N; ++i)
 		{
 			for (int j = 0; j < N; ++j)
 			{
 				int d;
 				fin >> d;
 				if (d > 0)
 				{
 					g.set(i, j, d);
 				}
 			}
 		}
 
 		g.run();
 
 		g.N = N;
 		g.reset();
 
 		vector<int> U(Q), V(Q);
 		for (int i = 0; i < Q; ++i)
 		{
 			fin >> U[i] >> V[i];
 			--U[i];
 			--V[i];
 		}
 		
 		Dijkstra d(N);
 		for (int i = 0; i < N; ++i)
 		{
 			ll maxDist = E[i], speed = S[i];
 
 			for (int j = 0; j < N; ++j)
 			{
 				ll dist = g.finish_time(i, j);
 				if (i != j && dist <= maxDist)
 				{
 					double t = double(dist) / speed;
 					d.set(i, j, t);
 				}
 			}
 		}
 
 		fout << "Case #" << zz << ":";
 		for (int i = 0; i < Q; ++i)
 		{
 			d.run(U[i]);
 			double thisVal = d.finish_time(V[i]);
 
 			fout << " " << thisVal;
 		}
 		fout << endl;
 	}
 
 	return 0;
 }
