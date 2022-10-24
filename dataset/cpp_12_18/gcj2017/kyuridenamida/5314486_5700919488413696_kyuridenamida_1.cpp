// this source + manual
 #include <bits/stdc++.h>
 using namespace std;
 
 void cs()
 {
     static int t = 1;
     cout << "Case #" << t++ << ": ";
 }
 
 
 int n,p;
 map<vector<int>,int> memo;
 set< vector<int> > S;
 void build(int t,vector<int> x){
 	sort(x.begin(),x.end());
 	if( t == 0 ){
 		S.insert(x);
 		return;
 	}
 	for(int i = 1 ; i <= min(t,p-1) ; i++){
 		vector<int> y = x;
 		y.push_back(i);
 		build(t-i,y);
 	}
 }
 int dfs(vector<int> c,int r){
 	
 	if( memo.count(c) ) return memo[c];
 	if( count(c.begin(),c.end(),0) == c.size() ){
 		return 0;
 	}
 	int ans = 0;
 	for(int i = 0 ; i < p ; i++){
 		if( c[i] == 0 ) continue;
 		vector<int> d = c;
 		d[i]--;
 		ans = max(ans,dfs(d,(i + r + p) % p));
 	}
 	
 	
 	return memo[c] = ans + (!r);
 
 }
 int main()
 {
     int t;
     cin >> t;
     while (t--)
     {
     	memo.clear();
     	S.clear();
     	cin >> n >> p;
     	int k = 0;
     	vector<int> c(p);
     	for(int i = 0 ; i < n ; i++){
 			int x;
 			cin >> x;
 			x %= p;
 			if( x == 0 ){
 				k++;
 			}else{
 				c[x]++;
 			}
 		}
 		build(p,vector<int>());
 		for( auto i : S ){
 		//	for(auto j : i ) cout << j << " ";
 		//	cout << "<" << endl;
 		}
 		cs();
 		cout << dfs(c,0) + k << endl;
     }
 }
 
 
