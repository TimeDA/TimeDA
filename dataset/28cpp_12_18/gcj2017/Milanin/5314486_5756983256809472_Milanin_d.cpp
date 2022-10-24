#define _CRT_SECURE_NO_WARNINGS
 #pragma comment(linker, "/STACK:100000000")
 #include <stdio.h>
 #include <vector>
 #include <string>
 #include <set>
 #include <map>
 #include <queue>
 #include <algorithm>
 #include <string.h>
 #include <math.h>
 #include <fstream>
 #include <iostream>
 #include <ctime>
 #include <fstream>
 using namespace std;
 
 namespace Hng
 {
     const int N=110;
     const int M=2000000000;
     int n, m[N][N], a[N], b[N], pa[N], pb[N], ua[N], ub[N];
     bool dfs(int i)
     {
 	    int j;
 	    for(ua[i]=1, j=0; j<n; ub[j]|=m[i][j]==a[i]+b[j], j++);
 	    for(j=0; j<n; j++)
 		    if(m[i][j]==a[i]+b[j] && pb[j]==-1) { pa[i]=j; pb[j]=i; return 1; }
 	    for(j=0; j<n; j++)
 		    if(m[i][j]==a[i]+b[j] && !ua[pb[j]] && dfs(pb[j])) { pa[i]=j; pb[j]=i; return 1; }
 	    return 0;
     }
     int match()
     {
 	    int i, j, f;
 	    for(f=0; ; f+=j)
 	    {
 		    for(i=0; i<n; ua[i]=0, ub[i]=0, i++);
 		    for(j=0, i=0; i<n; j+=pa[i]==-1 && !ua[i] && dfs(i), i++);
 		    if(!j) break;
 	    }
 	    return f;
     }
     int hng()
     {
 	    int i, j, k, t;
 	    for(i=0; i<n; pa[i]=-1, pb[i]=-1, i++);
 	    for(i=0; i<n; a[i]=t, i++)
 		    for(t=M, j=0; j<n; t=m[i][j]<t?m[i][j]:t, j++);
 	    for(j=0; j<n; b[j]=t, j++)
 		    for(t=M, i=0; i<n; t=m[i][j]-a[i]<t?m[i][j]-a[i]:t, i++);
 	    for(k=match(); k<n; k+=match())
 	    {
 		    for(t=M, i=0; i<n; i++)
 			    if(ua[i])
 				    for(j=0; j<n; j++)
 					    if(!ub[j] && m[i][j]-a[i]-b[j]<t) t=m[i][j]-a[i]-b[j];
 		    for(i=0; i<n; a[i]+=ua[i]*t, b[i]-=ub[i]*t, i++);
 	    }
         j=0;
         for(i=0; i<n; j+=m[i][pa[i]], i++);
         return j;
     }
 }
 
 const int N=110;
 int r, c, l;
 char m[N][N];
 int sn, tn, si[N], sj[N], ti[N], tj[N];
 int id[N][N];
 int di[]={-1, 1, 0, 0}, dj[]={0, 0, -1, 1};
 int g[N][N], z[N][N], u[N][N];
 bool in(int i, int j)
 {
     return i>=0 && i<r && j>=0 && j<c;
 }
 vector <int> findWay(int ms)
 {
     for(int i=0; i<r; i++)
         for(int j=0; j<c; g[i][j]=0, j++);
     for(int t=0; t<tn; t++)
         if(!((ms>>t)&1))
             for(int k=0; k<4; k++)
                 for(int l=1; ; l++)
                 {
                     int i=ti[t]+di[k]*l, j=tj[t]+dj[k]*l;
                     if(!in(i, j)) break;
                     if(m[i][j]=='#') break;
                     g[i][j]=1;
                 }
     Hng::n=max(sn, tn);
     for(int i=0; i<Hng::n; i++)
         for(int j=0; j<Hng::n; Hng::m[i][j]=0, j++);
     for(int i=0; i<Hng::n; i++)
         for(int j=0; j<tn; j++)
             if((ms>>j)&1) Hng::m[i][j]=100000;
     for(int s=0; s<sn; s++)
     {
         for(int i=0; i<r; i++)
             for(int j=0; j<c; u[i][j]=0, j++);
         queue <int> q;
         q.push(si[s]); q.push(sj[s]);
         u[si[s]][sj[s]]=1;
         for(; !q.empty(); )
         {
             int i=q.front(); q.pop();
             int j=q.front(); q.pop();
             for(int t=0; t<tn; t++)
                 if(((ms>>t)&1) && ((z[i][j]>>t)&1)) Hng::m[s][t]=min(Hng::m[s][t], u[i][j]-1);
             if(g[i][j]) continue;
             if(u[i][j]>l) continue;
             for(int k=0; k<4; k++)
                 if(in(i+di[k], j+dj[k]) && m[i+di[k]][j+dj[k]]!='#' && !u[i+di[k]][j+dj[k]])
                 {
                     q.push(i+di[k]); q.push(j+dj[k]);
                     u[i+di[k]][j+dj[k]]=u[i][j]+1;
                 }
         }
     }
     if(Hng::hng()>=100000) return vector <int>();
     int p[N], d[N];
     for(int i=0; i<sn; i++)
         if(Hng::pa[i]<tn && ((ms>>Hng::pa[i])&1)) p[i]=Hng::pa[i];
         else p[i]=-1;
     for(int i=0; i<tn; d[i]=0, i++);
     vector <int> ans;
     int cnt=0;
     for(; ; )
     {
         int bs=-1;
         for(int s=0; s<sn; s++)
         {
             if(p[s]==-1) continue;
             for(int i=0; i<r; i++)
                 for(int j=0; j<c; u[i][j]=0, j++);
             queue <int> q;
             q.push(si[s]); q.push(sj[s]);
             u[si[s]][sj[s]]=1;
             for(; !q.empty(); )
             {
                 int i=q.front(); q.pop();
                 int j=q.front(); q.pop();
                 if((z[i][j]>>p[s])&1) { bs=s; break; }
                 if(g[i][j]) continue;
                 if(u[i][j]>l) continue;
                 bool killed=0;
                 for(int t=0; t<tn; t++)
                     if(!d[t] && ((z[i][j]>>t)&1)) killed=1;
                 if(killed) continue;
                 for(int k=0; k<4; k++)
                     if(in(i+di[k], j+dj[k]) && m[i+di[k]][j+dj[k]]!='#' && !u[i+di[k]][j+dj[k]])
                     {
                         q.push(i+di[k]); q.push(j+dj[k]);
                         u[i+di[k]][j+dj[k]]=u[i][j]+1;
                     }
             }
             if(bs!=-1) break;
         }
         if(bs==-1) break;
         ans.push_back(bs);
         ans.push_back(p[bs]);
         d[p[bs]]=1;
         p[bs]=-1;
         cnt++;
     }
     for(int i=0; i<tn; i++)
         if((ms>>i)&1) cnt--;
     if(cnt) 
         throw;
     return ans;
 }
 void solve()
 {
     scanf("%d%d%d", &c, &r, &l);
     for(int i=0; i<r; scanf("%s", m[i]), i++);
     sn=0;
     tn=0;
     for(int i=0; i<r; i++)
         for(int j=0; j<c; j++)
             if(m[i][j]=='S') { id[i][j]=sn, si[sn]=i; sj[sn]=j; sn++; }
             else if(m[i][j]=='T') { id[i][j]=tn; ti[tn]=i; tj[tn]=j; tn++; }
     for(int i=0; i<r; i++)
         for(int j=0; j<c; z[i][j]=0, j++);
     for(int t=0; t<tn; t++)
         for(int k=0; k<4; k++)
             for(int l=1; ; l++)
             {
                 int i=ti[t]+di[k]*l, j=tj[t]+dj[k]*l;
                 if(!in(i, j)) break;
                 if(m[i][j]=='#') break;
                 z[i][j]|=1<<t;
             }
     vector <int> ans;
     for(int ms=1; ms<(1<<tn); ms++)
     {
         vector <int> v=findWay(ms);
         if(v.size()>ans.size()) ans=v;
     }
     printf("%d\n", ans.size()/2);
     for(int i=0; i<ans.size(); printf("%d %d\n", ans[i]+1, ans[i+1]+1), i+=2);
 }
 int main()
 {
     int ts;
     scanf("%d", &ts);
     for(int t=1; t<=ts; t++)
     {
         fprintf(stderr, "%d\n", t);
         printf("Case #%d: ", t);
         solve();
     }
 	return 0;
 }
 /*
 1 
 18 18 61 
 ................#. 
 ................#. 
 ..........#.#...#. 
 ..........T##...## 
 ..........#T#...#. 
 ..........T##...#. 
 .##.#.....#T#...#. 
 .####.#.#.T##...#. 
 .##..###..#T#SSS#. 
 .##.#.#.#.T##SSS#. 
 .##..#.#..#T#####. 
 .##.##.##.T##..... 
 .##.S.S...#T...... 
 .##.##.###.#.#.#.. 
 .##..#.#....###... 
 .##.....#..#.#.#.. 
 .##........S...... 
 #................. 
 */