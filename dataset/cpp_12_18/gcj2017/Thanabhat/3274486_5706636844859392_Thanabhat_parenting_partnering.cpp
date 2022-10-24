#include<iostream>
 #include<algorithm>
 #include<vector>
 
 using namespace std;
 
 #define pii pair<int,int>
 #define piii pair<pair<int,int>, int>
 
 int solve(int cc) {
     int a[2];
     pii t[2][105];
     piii tt[205];
     int tti=0;
     cin>>a[0]>>a[1];
     int tmp1,tmp2;
     for(int i=0;i<2;i++){
         for(int j=0;j<a[i];j++){
             cin>>tmp1>>tmp2;
             t[i][j]=pii(tmp1,tmp2);
             tt[tti++]=piii(pii(tmp1,tmp2),i);
         }
     }
     sort(t[0],t[0]+a[0]);
     sort(t[1],t[1]+a[1]);
     sort(tt,tt+a[0]+a[1]);
 
     int sol=0;
     for(int i=0;i<a[0]+a[1];i++){
         if(i==0){
             if(!(tt[a[0]+a[1]-1].second==tt[0].second&&tt[0].first.first==0&&tt[a[0]+a[1]-1].first.second==24*60)){
                 if(tt[a[0]+a[1]-1].second==tt[0].second){
                     sol+=2;
                 }else{
                     sol+=1;
                 }
             }
         }
         if(i+1<a[0]+a[1]){
             if(!(tt[i].second==tt[i+1].second&&tt[i].first.second==tt[i+1].first.first)){
                 if(tt[i].second==tt[i+1].second){
                     sol+=2;
                 }else{
                     sol+=1;
                 }
             }
         }
     }
 
 //    for(int i=0;i<a[0]+a[1];i++){
 //        cout<<tt[i].first.first<<" "<<tt[i].first.second<<" "<<tt[i].second<<endl;
 //    }
 //    cout<<sol<<endl;
 
     for(int i=0;i<2;i++){
         int remain=720;
         for(int j=0;j<a[i];j++){
             remain-=(t[i][j].second-t[i][j].first);
         }
         vector<int> vv;
         for(int j=0;j<a[0]+a[1];j++){
             if(tt[j].second==i){
                 if(j==0&&tt[a[0]+a[1]-1].second==tt[j].second){
                     if(tt[a[0]+a[1]-1].first.second!=24*60&&tt[j].first.first!=0){
                         vv.push_back(tt[j].first.first-0+24*60-tt[a[0]+a[1]-1].first.second);
                     }
                 }
                 if(j+1<a[0]+a[1]&&tt[j+1].second==tt[j].second){
                     if(tt[j].first.second!=tt[j+1].first.first){
                         vv.push_back(tt[j+1].first.first-tt[j].first.second);
                     }
                 }
             }
         }
         sort(vv.begin(),vv.end());
 
 //        cout<<"i="<<i<<endl;
 //        for(int i=0;i<vv.size();i++){
 //            cout<<vv[i]<<endl;
 //        }
 //        cout<<"remain="<<remain<<endl;
         for(int i=0;i<vv.size();i++){
             if(vv[i]<=remain){
                 remain-=vv[i];
                 sol-=2;
             }else{
                 break;
             }
         }
     }
 
     cout<<"Case #"<<cc<<": "<<sol<<endl;
     return 1;
 }
 
 int main() {
     int t;
     cin>>t;
     for(int i=1;i<=t;i++){
         solve(i);
     }
     return 0;
 }
 
