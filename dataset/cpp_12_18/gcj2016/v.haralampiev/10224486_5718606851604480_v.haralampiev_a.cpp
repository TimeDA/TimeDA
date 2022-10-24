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
 
 char Win(char a, char b){
   if(a > b) swap(a, b);
   if(a == 'P' && b == 'R')
     return 'P';
   if(a == 'P' && b == 'S')
     return 'S';
   if(a == 'R' && b == 'S')
     return 'R';
   return '?';
 }
 
 bool IsWin(string w){
   while(sz(w) > 1){
     string tmp = "";
     for(int i = 0;i < sz(w);i += 2){
       char l = Win(w[i], w[i + 1]);
       if(l == '?') return false;
       tmp += l;
     }
     w = tmp;
   }
   return true;
 }
 
 string ans;
 void Build(string t, int P, int R, int S){
   if(P + R + S == 0){
     if(IsWin(t)) ans = t;
     return;
   }
   if(sz(ans) > 0) return;
 
   if(P > 0) Build(t + 'P', P - 1, R, S);
   if(R > 0) Build(t + 'R', P, R - 1, S);
   if(S > 0) Build(t + 'S', P, R, S - 1);
 }
 
 int CASE = 0;
 void Doit(){
   ++CASE;
   cerr << "Case: " << CASE << endl;
   int N, R, P, S;
   scanf("%d%d%d%d", &N, &R, &P, &S);
   ans = "";
   Build("", P, R, S);
   if(ans == "") printf("Case #%d: IMPOSSIBLE\n", CASE);
   else{
     printf("Case #%d: %s\n", CASE, ans.c_str());
   }
 }
 
 int main(){
   int Q;
   scanf("%d", &Q);
   while(Q-- > 0) Doit();
   return 0;
 }
