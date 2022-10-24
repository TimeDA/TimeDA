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
 
 const int maxn = 30;
 
 int gr[maxn][maxn];
 queue<pair<int, int>> q;
 char s[maxn];
 int n;
 int cnt1, cnt2;
 bool was1[maxn], was2[maxn];
 int answer, curans;
 
 vector<pair<int, int>> groups;
 
 void go1(int cur);
 void go2(int cur)
 {
 	if (was2[cur]) return;
 	was2[cur] = true;
 	cnt2++;
 	for (int i = 0; i < n; i++) if (gr[i][cur]) go1(i);
 }
 
 void go1(int cur)
 {
 	if (was1[cur]) return;
 	was1[cur] = true;
 	cnt1++;
 	for (int i = 0; i < n; i++) if (gr[cur][i]) go2(i);
 }
 
 void go()
 {
 	if (groups.size() == 0)
 	{
 		answer = min(answer, curans);
 		return;
 	}
 	if (curans >= answer) return;
 	auto waslast = groups.back();
 	groups.pop_back();
 	for (int i = 0; i < (int)groups.size(); i++)
 	{
 		swap(groups[i], groups.back());
 		auto nowlast = groups.back();
 		groups.pop_back();
 		curans += nowlast.fi * waslast.se + nowlast.se * waslast.fi;
 		if (nowlast.fi + waslast.fi != nowlast.se + waslast.se) groups.pb({nowlast.fi + waslast.fi, nowlast.se + waslast.se});
 		go();
 		if (nowlast.fi + waslast.fi != nowlast.se + waslast.se) groups.pop_back();
 		curans -= nowlast.fi * waslast.se + nowlast.se * waslast.fi;
 		groups.push_back(nowlast);
 		swap(groups[i], groups.back());
 	}
 	groups.push_back(waslast);
 }
 
 int main()
 {
     int NT = 0;
     scanf("%d", &NT);
     for (int T = 1; T <= NT; T++)
     {
         printf("Case #%d:", T);
         scanf("%d", &n);
 		while (!q.empty()) q.pop();
 		int ans = 0;
 		for (int i = 0; i < n; i++)
 		{
 			scanf("%s", s);
 			for (int j = 0; j < n; j++) if (s[j] == '1')
 			{
 				q.push({i, j});
 				ans--;
 			}
 		}
 		for (int i = 0; i < n; i++)
 		{
 			for (int j = 0; j < n; j++) gr[i][j] = 0;
 		}
 		while (!q.empty())
 		{
 			int a = q.front().fi;
 			int b = q.front().se;
 			q.pop();
 			if (gr[a][b] == 1) continue;
 			gr[a][b] = 1;
 // 			cout << "add " << a << ' ' << b << endl;
 			ans++;
 			for (int i = 0; i < n; i++) if (i != b && gr[a][i])
 			{
 				for (int j = 0; j < n; j++) if (j != a)
 				{
 					if (gr[j][i]) q.push({j, b});
 				}
 			}
 
 			for (int i = 0; i < n; i++) if (i != b && gr[a][i])
 			{
 				for (int j = 0; j < n; j++) if (j != a)
 				{
 					if (gr[j][b]) q.push({j, i});
 				}
 			}
 
 			for (int i = 0; i < n; i++) if (i != a && gr[i][b])
 			{
 				for (int j = 0; j < n; j++) if (j != b)
 				{
 					if (gr[i][j]) q.push({a, j});
 				}
 			}
 		}
 // 		cout << ans << endl;
 		for (int i = 0; i < n; i++) was1[i] = false, was2[i] = false;
 		groups.clear();
 		for (int i = 0; i < n; i++) if (!was1[i])
 		{
 			cnt1 = 0;
 			cnt2 = 0;
 			go1(i);
 // 			cout << "from " << i << ' ' << cnt1 << ' ' << cnt2 << endl;
 			if (cnt1 != cnt2) groups.pb({cnt1, cnt2});
 		}
 		for (int i = 0; i < n; i++) if (!was2[i])
 		{
 			groups.pb({0, 1});
 		}
 		answer = n * n;
 		curans = 0;
 // 		for (auto t : groups) printf("%d %d\n", t.fi, t.se);
 		go();
 		printf(" %d\n", ans + answer);
         fprintf(stderr, "%d/%d cases done!\n", T, NT);
     }
     return 0;
 }
