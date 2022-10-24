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
 vector<int> digs;
 bool palindrome(long long num){
     int c=0; 
     while(num>0){
         digs[c]=num%10;
         num/=10;
         c++;
     }
     for(int i=0; i<=c/2; i++){
         if(digs[i]!=digs[c-1-i])return false;
     }
     return true;
 }
 int main(){
     int T;
     long long a, b;
     cin>>T;
     digs.clear(); digs.resize(20);
     for (int i=1; i<=T; i++){
         cin>>a>>b;
         int res=0;
         for(long long j=sqrt(a); j<=sqrt(b); j++){
             if(j*j<a)continue;
             if(palindrome(j) && palindrome(j*j)){
              res++;
                 //cout<<j<<" "<<j*j<<" ";
             }
         }
         cout<<"Case #"<<i<<": "<<res<<"\n";
     }
 }
