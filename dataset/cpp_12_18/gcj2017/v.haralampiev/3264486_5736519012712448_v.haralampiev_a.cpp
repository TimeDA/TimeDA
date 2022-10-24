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
 
 int n, k;
 char in[MAX];
 
 int CASE = 0;
 void Doit(){
   ++CASE;
   cerr << "Case: " << CASE << endl;
 
   scanf("%s%d", in, &k);
   n = strlen(in);
 
   int tot = 0;
   for(int i = 0;i + k <= n;++i)
     if(in[i] == '-'){
       ++tot;
       for(int j = 0;j < k;++j)
         if(in[i + j] == '-') in[i + j] = '+';
         else in[i + j] = '-';
     }
 
   printf("Case #%d: ", CASE);
   if(count(in, in + n, '-') > 0)
     printf("IMPOSSIBLE\n");
   else
     printf("%d\n", tot);
 }
 
 int main(){
   int q;
   scanf("%d", &q);
   while(q-- > 0) Doit();
 
   return 0;
 }
