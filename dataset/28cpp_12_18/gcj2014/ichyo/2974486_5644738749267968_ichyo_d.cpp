#include <bits/stdc++.h>
 #define REP(i,n) for(int i=0; i<(int)(n); ++i)
 
 using namespace std;
 
 int calc1(vector<double>& a, vector<double>& b){
     int n = a.size();
     vector<bool> used(n);
     int ans = 0;
     for(int i = 0; i < n; i++){
         int select = -1;
         for(int j = 0; j < n; j++){
             if(!used[j] && a[i] < b[j]){
                 select = j;
                 break;
             }
         }
         if(select == -1) {
             for(int j = 0; j < n; j++){
                 if(!used[j]){
                     select = j;
                     break;
                 }
             }
         }
         used[select] = true;
         if(a[i] > b[select]){
             ans ++;
         }
     }
     return ans;
 }
 int calc2(vector<double>& a, vector<double>& b){
     int n = a.size();
     int ans = 0;
     int j = 0;
     for(int i = 0; i < n; i++){
         if(a[i] > b[j]){
             ans++;
             j++;
         }
     }
     return ans;
 }
 
 int main(){
     int TESTCASE;
     cin >> TESTCASE;
     for(int casenumber = 0; casenumber < TESTCASE; casenumber++){
         printf("Case #%d: ", casenumber + 1);
         int N;
         cin >> N;
         vector<double> a(N), b(N);
         REP(i, N) cin >> a[i];
         REP(i, N) cin >> b[i];
         sort(a.begin(), a.end());
         sort(b.begin(), b.end());
         printf("%d %d\n", calc2(a, b), calc1(a, b));
     }
     return 0;
 }
 
