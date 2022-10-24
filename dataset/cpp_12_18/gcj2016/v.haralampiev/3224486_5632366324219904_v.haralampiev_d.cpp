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
 
 const int MAX = 500;
 char buf[MAX];
 int n, l;
 
 int CASE = 0;
 void Doit(){
   ++CASE;
   cerr << "Case: " << CASE << endl;
 
   scanf("%d%d", &n, &l);
   int max1 = 0;
   for(int i = 0;i < n;++i){
     scanf("%s", buf);
     int b1 = count(buf, buf + l, '1');
     relaxMax(max1, b1);
   }
 
   scanf("%s", buf);
 
   if(max1 == l) {
     printf("Case #%d: IMPOSSIBLE\n", CASE);
     return;
   }
 
   string a = "", b = "";
   if(max1 > 0){
     for(int i = 0;i < max1;++i) b += '1';
     for(int i = 0;i < l;++i) a += '0', a += '?';
   } else {
     for(int i = 0;i < l;++i) b += '0';
     for(int i = 0;i < l;++i) a += '?';
   }
 
   printf("Case #%d: %s %s\n", CASE, a.c_str(), b.c_str());
 }
 
 int main(){
   int q;
   scanf("%d", &q);
   while(q-- > 0) Doit();
   return 0;
 }
