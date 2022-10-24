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
 
 const int MAX = 100;
 
 int r, c;
 char in[MAX][MAX];
 char buf[MAX];
 
 int CASE = 0;
 void Doit(){
   ++CASE;
   cerr << "Case: " << CASE << endl;
 
   scanf("%d%d", &r, &c);
   for(int i = 0;i < r;++i)
     scanf("%s", in[i]);
 
   while(true){
     int bq = 0;
     for(int i = 0;i < r;++i)
       for(int j = 0;j < c;++j)
         if(in[i][j] == '?') ++bq;
     if(bq == 0) break;
 
     fill(buf, buf + MAX, '?');
     for(int i = 0;i < r;++i)
       for(int j = 0;j < c;++j)
         if(in[i][j] == '?') in[i][j] = buf[j];
         else buf[j] = in[i][j];
 
     fill(buf, buf + MAX, '?');
     for(int i = r - 1;i >= 0;--i)
       for(int j = 0;j < c;++j)
         if(in[i][j] == '?') in[i][j] = buf[j];
         else buf[j] = in[i][j];
 
     fill(buf, buf + MAX, '?');
     for(int j = 0;j < c;++j)
       for(int i = 0;i < r;++i)
         if(in[i][j] == '?') in[i][j] = buf[i];
         else buf[i] = in[i][j];
 
     fill(buf, buf + MAX, '?');
     for(int j = c - 1;j >= 0;--j)
       for(int i = 0;i < r;++i)
         if(in[i][j] == '?') in[i][j] = buf[i];
         else buf[i] = in[i][j];
   }
 
   printf("Case #%d:\n", CASE);
   for(int i = 0;i < r;++i){
     for(int j = 0;j < c;++j)
       printf("%c", in[i][j]);
     printf("\n");
   }
 }
 
 int main(){
   int q;
   scanf("%d", &q);
   while(q-- > 0) Doit();
 
   return 0;
 }
