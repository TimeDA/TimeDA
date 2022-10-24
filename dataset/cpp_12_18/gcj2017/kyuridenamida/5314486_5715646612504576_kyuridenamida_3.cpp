// this source + manual
 #include <bits/stdc++.h>
 using namespace std;
 typedef long long ll;
 typedef unsigned long long ull;
 typedef pair<int,int> Pii;
 typedef pair<ll,ll> Pll;
 #define FOR(i,n) for(int i = 0; i < (n); i++)
 #define sz(c) ((int)(c).size())
 #define ten(x) ((int)1e##x)
 template<class T> void chmax(T& l, const T r){ l = max(l, r); }
 template<class T> void chmin(T& l, const T r){ l = min(l, r); }
 
 void cs()
 {
     static int t = 1;
     cout << "Case #" << t++ << ": ";
 }
 
 
 struct NODE{
 	int x;
 	int vbeam;
 	int vexist;
 	int vuncovered;
 };
 
 int R,C;
 
 char c[55][55];
 char r[55][55];
 int dp[128][1<<5][1<<5][1<<5];
 int dfs(const NODE s){	
 	if( dp[s.x][s.vbeam][s.vexist][s.vuncovered] != -1 )
 		return dp[s.x][s.vbeam][s.vexist][s.vuncovered];
 		
 	if( s.x == C ){
 		//cout << vexist << " " << vbeam << endl;
 		return s.vuncovered == 0;
 	}
 	int ans = 0;
 	
 	for(int i = 0 ; i < (1<<R) ; i++){
 		int hbeam = 0;
 		int hexist = 0;
 		int det = 0;
 		vector<int> hex;
 		NODE ns = s;
 		int f = 1;
 		
 		for(int j = 0 ; j < R ; j++){
 			char x;
 			if( c[j][s.x] == '#' )
 				x = '#';
 			else if( c[j][s.x] == '.' )
 				x = '.';
 			else
 				x = (i >> j & 1 ? '-' : '|' );
 			
 			if( x == '|' or x == '-' ){
 				if( ns.vbeam >> j & 1 ) f = 0;	// 横から衝突
 				if( hbeam ) f = 0; // 上から衝突
 			}
 			//cout << x << " " << s.x << ">" << s.vbeam << "|" << s.vexist << "(" << x << ")" << endl;
 			if( x == '|' ){
 
 				if( hexist ) f = 0; // 上に当たる
 				hbeam = 1;
 				hexist = 1;
 				hex.clear();
 				ns.vexist |= (1<<j);
 			}else if( x == '-'){
 				if( s.vexist >> j & 1 ) f = 0; // ←に当たる
 				hexist = 1;
 				ns.vbeam |= (1<<j);
 				ns.vexist |= (1<<j);
 			}else if( x == '#' ){
 				if( s.vuncovered >> j & 1 ) f = 0;
 				for(int h : hex ) det |= (1<<h);
 				hex.clear();
 				
 				hbeam = 0;
 				hexist = 0;
 				ns.vbeam &= ~(1<<j);
 				ns.vexist &= ~(1<<j);
 			}else if( x == '.' ){
 				if( !hbeam ) hex.push_back(j);
 			}
 		}
 		for(int h : hex ) det |= (1<<h);
 		hex.clear();
 		//cout << det << endl;
 		det &= ~(s.vbeam);
 		if(f){
 			ns.vuncovered = s.vuncovered | det;
 			ns.x = s.x + 1;
 			if( dfs(ns) ){
 				for(int j = 0 ; j < R ; j++){
 					char x;
 					if( c[j][s.x] == '#' )
 						x = '#';
 					else if( c[j][s.x] == '.' )
 						x = '.';
 					else
 						x = (i >> j & 1 ? '-' : '|' );
 					r[j][s.x] = x;
 				}
 				return dp[s.x][s.vbeam][s.vexist][s.vuncovered] = true;
 			}
 		}
 	}
 	return dp[s.x][s.vbeam][s.vexist][s.vuncovered] = false;
 	
 }
 
 int main()
 {
 	
     int t;
     cin >> t;
     while (t--)
     {
     	memset(dp,-1,sizeof(dp));
     	cin >> R >> C;
     	for(int i = 0 ; i < R ; i++)
 			for(int j = 0 ; j < C ; j++)
 				cin >> c[i][j];
 		cs();
 		int w = dfs({0,0,0,0});
 		if( w ){
 			cout << "POSSIBLE" << endl; 
 			for(int i = 0 ; i < R ; i++){
 				for(int j = 0 ; j < C ; j++)
 					cout << r[i][j];
 				cout << endl;
 			}
 		}else{
 			cout << "IMPOSSIBLE" << endl;
 		}
 		
     }
 }
 
 
