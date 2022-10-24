#include <bits/stdc++.h>
 using namespace std;
 #define null NULL
 #define mp make_pair
 #define pb(a) push_back(a)
 #define sz(a) ((int)(a).size())
 #define all(a) a.begin() , a.end()
 #define fi first
 #define se second
 #define relaxMin(a , b) (a) = min((a),(b))
 #define relaxMax(a , b) (a) = max((a),(b))
 #define SQR(a) ((a)*(a))
 #define PI 3.14159265358979323846
 typedef vector<int> vi;
 typedef pair<int,int> pii;
 typedef long long ll;
 
 const int MAX = 1010;
 
 int par[MAX];
 
 int Get(int vr){
   return par[vr] == vr ? vr : par[vr] = Get(par[vr]);
 }
 
 void Merge(int a, int b){
   a = Get(a);
   b = Get(b);
   par[a] = b;
 }
 
 int n, m;
 int x[MAX], y[MAX], z[MAX];
 int dx[MAX], dy[MAX], dz[MAX];
 
 int CASE = 0;
 void Doit(){
   ++CASE;
   cerr << "Case: " << CASE << endl;
 
   scanf("%d%d", &n, &m);
   for(int i = 0;i < n;++i){
     scanf("%d%d%d", &x[i], &y[i], &z[i]);
     scanf("%d%d%d", &dx[i], &dy[i], &dz[i]);
   }
 
   vector< pair<int, pii> > edj;
   for(int i = 0;i < n;++i)
     for(int j = i + 1;j < n;++j){
       int dist = SQR(x[i] - x[j]) +
                  SQR(y[i] - y[j]) +
                  SQR(z[i] - z[j]);
       edj.pb(mp(dist, mp(i, j)));
     }
 
   sort(all(edj));
 
   int ans = 0;
   for(int i = 0; i < n;++i) par[i] = i;
 
   for(auto have : edj){
     int a = have.se.fi;
     int b = have.se.se;
     Merge(a, b);
     if(Get(0) == Get(1)){
       ans = have.fi;
       break;
     }
   }
 
   printf("Case #%d: %.12f\n", CASE, sqrt(ans));
 }
 
 int main(){
   int q;
   scanf("%d", &q);
   while(q-- > 0) Doit();
   return 0;
 }
