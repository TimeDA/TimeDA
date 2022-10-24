#include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <cmath>
 #include <vector>
 #include <algorithm>
 #include <string>
 #include <map>
 #define SZ(x) ((int)(x).size())
 #define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
 using namespace std;
 typedef long long LL;
 
 int cs;
 map<string, int> id;
 
 int getid(string x) {
   if(id.count(x) == 0) {
     int c = (int)id.size();
     id[x] = c;
   }
   return id[x];
 }
 
 char s[1000005];
 char tok[1000005];
 void solve() {
   int n;
   id.clear();
   vector<int> a[20];
   scanf("%d", &n);
   for(int i=0;i<n;i++) a[i] = vector<int>();
   gets(s);
   for(int i=0;i<n;i++) {
     gets(s);
     int pos=0, offset=0;
     while(sscanf(s+offset, "%s%n", tok, &pos)>0) {
       a[i].push_back(getid(string(tok)));
       offset += pos;
     }
   }
 
   int m = (int)id.size();
   int ans = m;
   for(int i=0;i<(1<<n);i++) {
     if(i%4!=2) continue;
     int u[100005]={};
     for(int j=0;j<n;j++) {
       if(i&(1<<j)) { //franch
         FOR(it, a[j]) u[*it] |= 2;
       } else { //english
         FOR(it, a[j]) u[*it] |= 1;
       }
     }
     
     int cnt=0;
     for(int j=0;j<m;j++) cnt += (u[j]==3);
     ans = min(ans, cnt);
   }
   
   printf("Case #%d: %d\n", cs, ans);
   fprintf(stderr, "Case #%d: %d\n", cs, ans);
 }
 
 int main(void) {
   int T;
   scanf("%d", &T);
   for(cs=1;cs<=T;cs++) solve();
   return 0;
 }
