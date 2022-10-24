#include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <algorithm>
 #include <vector>
 #include <string>
 #include <set>
 #include <map>
 using namespace std;
 int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
 
 void solve(){
 	int n,p;
 	cin >> n >> p;
 	
 	vector<int> cnt(p);
 	
 	for(int i=0;i<n;i++){
 		int x = in() % p;
 		
 		cnt[x]++;
 	}
 	int ans = cnt[0];
 	
 	if(p==2){
 		ans += (cnt[1]+1)/2;
 	}
 	if(p==3){
 		int m = min(cnt[1],cnt[2]);
 		
 		ans+=m;
 		
 		cnt[1]-=m;
 		cnt[2]-=m;
 		
 		if(cnt[1]>0){
 			ans += (cnt[1]+2)/3;
 		}
 		if(cnt[2]>0){
 			ans += (cnt[2]+2)/3;
 		}
 		
 	}
 	
 	
 	
 	cout << ans << endl;
 }
 
 int main(){
   for(int i=0,T=in();i<T;i++){
 	  cout << "Case #"<<i+1 << ": ";
       solve();
   }
 }
