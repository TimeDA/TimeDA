#include <iostream>
 #include <vector>
 using namespace std;
 
 string s[1001];
 int serv[100001];
 
 int M,N;
 int bst=-1,ways=0;
 
 void check() {
     vector<string> v[5];
     for (int i=1;i<=M;++i) v[serv[i]].push_back(s[i]);
         int cnt=0;
     for (int i=1;i<=N;++i) {
         if (v[i].size()) ++cnt;
         sort(v[i].begin(),v[i].end());
         for (int j=0;j<v[i].size();++j) {
             if (j==0) cnt+=v[i][0].size();
             else {
             for (int k=0;k<v[i][j].size();++k) {
                 if (k>=v[i][j-1].size() || v[i][j-1][k]!=v[i][j][k]) {
                     cnt+=v[i][j].size()-k;
                     break;
                 }
             }
             }
         }
     }
         if (cnt>bst) bst=cnt,ways=1;
         else if (cnt==bst) ways++;
 }
 
 void search (int i) {
     if (i==M+1) {
         check();
         return;
     }
     for (int j=1;j<=N;++j) {
         serv[i]=j;
         search(i+1);
     }
 }
 
 int main () {
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
     int T;
     cin >> T;
     for (int z=1;z<=T;++z) {
         bst=-1,ways=0;
     cin >> M >> N;
     for (int i=1;i<=M;++i) {
         cin >> s[i];
     }
     search(1);
     cout << "Case #" << z << ": " << bst << " " << ways << "\n";
 }   
     return 0;
 }
