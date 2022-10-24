#include <cstdio>
 #include <vector>
 #include <cstring>
 #include <algorithm>
 #include <stack>
 #include <map>
 
 using namespace std;
 
 #define MAXM 5000
 #define MAXN 2*MAXM
 
 int N;
 vector<int> graph[MAXN];
 
 int sn;
 int sccgroup[MAXN];
 
 int dfsno;
 int check[MAXN];
 int back[MAXN];
 char onstack[MAXN];
 stack<int> st;
 
 void searchc(int a) {
 	check[a] = back[a] = ++dfsno;
 	onstack[a] = 1;
 	st.push(a);
 
 	for (int i = 0; i < graph[a].size(); i++) {
 		int b = graph[a][i];
 
 		if (check[b]) {
 			if (check[b] < check[a] && onstack[b] && back[a] > check[b])
 				back[a] = check[b];
 		}
 		else {
 			searchc(b);
 			if (back[a] > back[b])
 				back[a] = back[b];
 		}
 	}
 
 	if (check[a] == back[a]) {
 		int v = -1;
 		while (v != a) {
 			v = st.top();
 			st.pop();
 			onstack[v] = 0;
 			sccgroup[v] = sn;
 		}
 		sn++;
 	}
 }
 
 void scc() {
 	memset(check, 0, N * sizeof(int));
 	memset(back, 0, N * sizeof(int));
 	memset(onstack, 0, N);
 	memset(sccgroup, -1, N * sizeof(int));
 	while (!st.empty()) st.pop();
 	dfsno = sn = 0;
 
 	for (int i = 0; i < N; i++) {
 		if (!check[i])
 			searchc(i);
 	}
 }
 
 struct SAT {
 	int a, b;
 	char nota, notb;
 };
 
 int M;
 vector<SAT> sat;
 
 bool twoSat() {
 	N = 2 * M;
 	for (int i = 0; i < N; i++)
 		graph[i].clear();
 
 	for (int i = 0; i < sat.size(); i++) {
 		graph[2 * sat[i].a + 1 - sat[i].nota].push_back(2 * sat[i].b + sat[i].notb);
 		graph[2 * sat[i].b + 1 - sat[i].notb].push_back(2 * sat[i].a + sat[i].nota);
 	}
 
 	// Erase Duplicated edges
 	for (int i = 0; i < N; i++) {
 		sort(graph[i].begin(), graph[i].end());
 		graph[i].erase(unique(graph[i].begin(), graph[i].end()), graph[i].end());
 	}
 
 	scc();
 	for (int i = 0; i < M; i++) {
 		if (sccgroup[2 * i] == sccgroup[2 * i + 1])
 			return false;
 	}
 
 	return true;
 }
 
 char table[55][55];
 int beamno[55][55];
 int emptyno[55][55];
 
 int dx[4] = { -1, 0, 1, 0 };
 int dy[4] = { 0, 1, 0, -1 };
 int R, C;
 
 bool shoot(int x, int y, int dir, vector<int>* ret)
 {
 	while (true)
 	{
 		if (x < 0 || y < 0 || x >= R || y >= C) break;
 		if (table[x][y] == '#') break;
 		if (table[x][y] == '.') ret->push_back(emptyno[x][y]);
 		if (table[x][y] == '|' || table[x][y] == '-')
 			return false;
 		if (table[x][y] == '/')
 		{
 			dir = dir ^ 1;
 		}
 		if (table[x][y] == '\\')
 		{
 			dir = 3 - dir;
 		}
 		x = x + dx[dir];
 		y = y + dy[dir];
 	}
 	return true;
 }
 
 int main()
 {
 	freopen("C-small-attempt0.in", "r", stdin);
 	freopen("C-small-attempt0.out", "w", stdout);
 
 	int T;
 	scanf("%d", &T);
 	for (int cn = 1; cn <= T; ++cn)
 	{
 		scanf("%d%d", &R, &C);
 
 		int bindex = 0, eindex = 0;
 		map<int, pair<int, int>> bmap;
 
 		memset(table, 0, sizeof(table));
 
 		for (int i = 0; i < R; ++i)
 			for (int j = 0; j < C; ++j)
 			{
 				scanf(" %c", &table[i][j]);
 				if (table[i][j] == '|' || table[i][j] == '-')
 				{
 					beamno[i][j] = bindex;
 					bmap[bindex] = make_pair(i, j);
 					bindex++;
 				}
 				else
 				{
 					beamno[i][j] = -1;
 				}
 				if (table[i][j] == '.')
 				{
 					emptyno[i][j] = eindex;
 					eindex++;
 				}
 				else
 				{
 					emptyno[i][j] = -1;
 				}
 			}
 
 		printf("Case #%d: ", cn);
 		bool ispos = true;
 		vector<vector<int>> epass(eindex, vector<int>());
 
 		M = eindex;
 		sat.clear();
 
 		for (int i = 0; i < R; ++i)
 			for (int j = 0; j < C; ++j)
 				if (beamno[i][j] != -1)
 				{
 					vector<int> v1, v2;
 					if (shoot(i, j + 1, 1, &v1) && shoot(i, j - 1, 3, &v2))
 					{
 						for (auto ei : v1) { epass[ei].push_back(beamno[i][j]); epass[ei].push_back(0); }
 						for (auto ei : v2) { epass[ei].push_back(beamno[i][j]); epass[ei].push_back(0); }
 					}
 					else
 					{
 						table[i][j] = '|';
 					}
 
 					v1.clear();
 					v2.clear();
 
 					if (shoot(i - 1, j, 0, &v1) && shoot(i + 1, j, 2, &v2))
 					{
 						for (auto ei : v1) { epass[ei].push_back(beamno[i][j]); epass[ei].push_back(1); }
 						for (auto ei : v2) { epass[ei].push_back(beamno[i][j]); epass[ei].push_back(1); }
 					}
 					else
 					{
 						table[i][j] = '-';
 					}
 				}
 
 		SAT temp;
 		for (auto ep : epass)
 		{
 			if (ep.size() == 0)
 			{
 				ispos = false;
 			}
 			else if (ep.size() == 2)
 			{
 				temp.a = ep[0]; temp.nota = ep[1];
 				temp.b = ep[0]; temp.notb = ep[1];
 				sat.push_back(temp);
 			}
 			else if (ep.size() == 4)
 			{
 				temp.a = ep[0]; temp.nota = ep[1];
 				temp.b = ep[2]; temp.notb = ep[3];
 				sat.push_back(temp);
 			}
 			else
 			{
 				printf("error!!!\n");
 				continue;
 			}
 		}
 
 		if (ispos)
 		{
 			ispos = twoSat();
 		}
 
 		if (ispos)
 		{
 			printf("POSSIBLE\n");
 			for (int i = 0; i < M; ++i)
 			{
 				if (sccgroup[2 * i] > sccgroup[2 * i + 1])
 				{
 					int x = bmap[sat[i].a].first;
 					int y = bmap[sat[i].a].second;
 					if (sat[i].nota == 0) table[x][y] = '-'; else table[x][y] = '|';
 				}
 				else
 				{
 					int x = bmap[sat[i].b].first;
 					int y = bmap[sat[i].b].second;
 					if (sat[i].nota == 0) table[x][y] = '-'; else table[x][y] = '|';
 				}
 			}
 			for (int i = 0; i < R; ++i)
 				printf("%s\n", table[i]);
 		}
 		else
 		{
 			printf("IMPOSSIBLE\n");
 		}
 	}
 }