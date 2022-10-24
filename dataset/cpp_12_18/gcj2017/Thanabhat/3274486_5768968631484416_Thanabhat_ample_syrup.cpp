#include<iostream>
 #include<cmath>
 #include<algorithm>
 
 using namespace std;
 
 #define pli pair<long long,int>
 
 int n,k;
 long long r[1005],h[1005];
 
 struct my_sort2 {
     bool operator()(const pli &left, const pli &right) {
         if(left.first<right.first){
             return true;
         }else if(left.first>right.first){
             return false;
         }else{
             return left.second<right.second;
         }
     }
 };
 
 int solve(int cc) {
     pli arr2[1005];
     cin>>n>>k;
     for(int i=0;i<n;i++){
         cin>>r[i]>>h[i];
         arr2[i]=pli(r[i]*h[i],i);
     }
     long double sum_all=0;
     for(int i=0;i<n;i++){
         sum_all+=(2.0*M_PI*r[i]*h[i]);
     }
 
     sort(arr2,arr2+n,my_sort2());
 
 //    for(int i=0;i<n;i++){
 //        cout<<arr2[i].first<<" "<<arr2[i].second<<endl;
 //    }
 
     long double sol=0;
     for(int i=0;i<n;i++){
 //        cout<<"i="<<i<<endl;
         long double tmp=0;
         tmp=(1.0L*M_PI*r[i]*r[i]);
         tmp+=(2.0L*M_PI*r[i]*h[i]);
 //        cout<<"tmp="<<tmp<<endl;
         long long sum=0;
         int count=0;
         for(int j=n-1;j>=0;j--){
             if(count==k-1){
                 break;
             }
             if(arr2[j].second!=i&&r[arr2[j].second]<=r[i]){
                 sum+=arr2[j].first;
                 count++;
             }
 //            cout<<"sum="<<sum<<endl;
             if(count==k-1){
                 break;
             }
         }
         if(count!=k-1){
             continue;
         }
 //        cout<<"sum="<<sum<<endl;
         tmp+=(2.0L*M_PI*sum);
         sol=max(sol,tmp);
 //        cout<<"tmp="<<tmp<<endl;
     }
     cout<<"Case #"<<cc<<": "<<fixed<<sol<<endl;
     return 1;
 }
 
 int main() {
     cout.precision(10);
     int t;
     cin>>t;
     for(int i=1;i<=t;i++){
         solve(i);
     }
     return 0;
 }
