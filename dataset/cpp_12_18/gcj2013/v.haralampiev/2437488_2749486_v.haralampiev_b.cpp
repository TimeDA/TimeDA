#ifdef _WIN32
 #  define LL "%I64d"
 #else
 #  define LL "%Ld"
 #endif
 
 #include <iostream>
 #include <cstdio>
 #include <cstdlib>
 #include <cmath>
 #include <cstring>
 #include <ctime>
 #include <vector>
 #include <deque>
 #include <set>
 #include <map>
 #include <queue>
 #include <stack>
 #include <bitset>
 #include <string>
 #include <algorithm>
 #include <complex>
 #include <utility>
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
 typedef vector<int> vi;
 typedef pair<int,int> pii;
 typedef long long ll;
 #define IK 302
 char op[510][610][610];
 int sft[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};
 char name[] = {'S' , 'N' , 'W' , 'E'};
 void fill(){
   memset(op , -1 , sizeof op);
   op[0][0+IK][0+IK] = 0;
   for(int step=0;step+1<510;++step){
    int jmp = step + 1;
    for(int i=0;i<610;++i)
     for(int j=0;j<610;++j)
      for(int m=0;m<4;++m){
       if(op[step][i][j] == -1)continue;
       int nx = i + sft[m][0]*jmp,
           ny = j + sft[m][1]*jmp;
       if(nx<0 || nx>=610 || ny<0 || ny>=610)continue;
       op[step+1][nx][ny] = m;
                          }
                                    }
 }
 int least_lev(int x , int y){
   x += IK , y += IK;
   for(int i=0;i<510;++i)
    if(op[i][x][y] != -1)return i;
 }
 string path;
 void find_path(int x , int y , int lev){
   if(lev == 0)return;
   int pop = op[lev][x][y];
   path += name[pop];
   find_path(x - sft[pop][0]*lev , y - sft[pop][1]*lev , lev-1);
 }
 int main(){
   fill();
   int Q; scanf("%d" , &Q);
   for(int CASE=1;CASE<=Q;++CASE){
    int X , Y;
    cin>>X>>Y;
    cout<<"Case #"<<CASE<<": ";
    path.clear();
    find_path(X+IK , Y+IK , least_lev(X , Y));
    reverse(all(path));
    cout<<path<<'\n';
                                 }
   return 0;
 }
