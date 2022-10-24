#include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <string>
 #include <vector>
 #include <cmath>
 #include <algorithm>
 #include <cassert>
 #include <set>
 #include <map>
 #include <queue>
 #include <iostream>
 #include <fstream>
 using namespace std;
 #define pb push_back 
 #define REP(i,n) for(int i=0;i<(n);i++ )
 typedef long long LL;
 typedef pair<int, int> pii;
 
 int mod = 1000002013;
 int N, M;
 
 LL price(int k) {
     LL r = N;
     r += (N - k + 1);
     r *= k;
     r /= 2;
     return r % mod;
 }
 
 vector<pair<pii, int> > V, V2;
 
 int main(){
     int caseNumber;
     //scanf("%d", &caseNumber);
     cin>>caseNumber;
     REP(caseN, caseNumber) {
         cin>>N>>M;
         V.clear();
         LL rst = 0;
         int t1, t2, t3;
         REP(i, M) {
             cin>>t1>>t2>>t3;
             V.pb(make_pair(make_pair(t1, t2), t3));
             rst += price(t2 - t1) * t3;
             rst %= mod;
         }
         // cout<<rst<<endl;
         while (1) {
             if (!V.size()) {
                 break;
             }
             sort(V.begin(), V.end());
             int distance, cnt, point;
             distance = V[0].first.first;
             point = V[0].first.second;
             cnt = V[0].second;
             vector<pii> pass;
             pass.clear();
             pass.pb(make_pair(0, distance));
             int vs = V.size();
             for (int i = 1; i < vs; i++) {
                 if (V[i].first.first <= point && V[i].first.second > point) {
                     pass.pb(make_pair(i, point));
                     cnt = min(cnt, V[i].second);
                     point = V[i].first.second;
                 } 
             }
             // cout<<'x'<<point<<' '<<distance<<endl;
             distance = point - distance;
             // cout<<'d'<<distance<<endl;
             rst -= price(distance) * cnt;
             rst %= mod;
             // cout<<'p'<<pass.size()<<' '<<cnt<<endl;;
             REP(_i, pass.size()) {
                 int i = pass[_i].first;
                 int e2 = V[i].first.second;
                 int b2 = V[i].first.first;
                 int sz = V[i].second;
                 int point = pass[_i].second;
                 V.pb(make_pair(make_pair(point, e2), sz - cnt));
                 V.pb(make_pair(make_pair(b2, point), sz));
                 V[i].second = 0;
             }
             V2.clear();
             REP(i, V.size()) {
                 if (V[i].second == 0) {
                     continue;
                 }
                 if (V[i].first.first == V[i].first.second) {
                     continue;
                 }
                 V2.pb(V[i]);
                 // cout<<i<<' '<<V[i].first.first<<' '<<V[i].first.second<<' '<<V[i].second<<endl;
             }
             V = V2;
             // cout<<rst<<' '<<V2.size()<<endl;
         }
         rst %= mod;
         rst += mod;
         rst %= mod;
     	printf("Case #%d: %d\n", caseN + 1, (int)rst);
     }
     return 0;
 }