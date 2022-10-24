//
 //  C.cpp
 //  
 //
 #include <algorithm>
 #include <iostream>
 #include<vector>
 #include<cmath>
 #include <iomanip>
 #include<string>
 #define mod 1000000007
 
 
 
 using namespace std;
 
 int main(){
     int T, n, m;
     cin>>T;
     vector<vector<int > > map;
     for (int i=1; i<=T; i++){
         cin>>n>>m;
         map.clear(); map.resize(n, vector<int > (m));
         vector<int> maxh(n, 0);
         vector<int> maxv(m, 0);
         for(int j=0; j<n; j++)
             for(int k=0; k<m; k++){
                 cin>>map[j][k];
                 if(map[j][k]>maxh[j])maxh[j] = map[j][k];
                 if(map[j][k]>maxv[k])maxv[k] = map[j][k];
             }
         bool res=true;
         for(int j=0; j<n; j++)
             for(int k=0; k<m; k++){
                 if(map[j][k]<maxh[j] && map[j][k]<maxv[k])res=false;
             }
         cout<<"Case #"<<i<<": ";
         if(res)cout<<"YES"; else cout<<"NO";
         
         cout<<"\n";
     }
 }
