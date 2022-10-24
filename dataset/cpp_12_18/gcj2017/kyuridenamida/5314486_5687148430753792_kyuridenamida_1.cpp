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
 
 
 int main()
 {
     int t;
     cin >> t;
     while (t--)
     {
     	int N,C,M;
     	cin >> N >> C >> M;
     	vector< vector<int> > backet(N);
     	for(int i = 0 ; i < M ; i++){
     		int x,y;
     		cin >> x >> y;
     		--x,--y;
     		assert(y <= 1 );
     		backet[x].push_back(y);
     	}
     	vector<int> pos[2];
     	int t = 0, l = 0;
     	for(int i = 0 ; i < N ; i++){
     		
     		for( auto j : backet[i] ){
     			int ok = 0;
     			
     			//　もし埋めれるところがあれば
     			for(int k = 0 ; k < pos[!j].size() ; k++){
     				if( pos[!j][k] < i ){
     					pos[!j].erase(pos[!j].begin()+k);
     					ok = 1;
     					break;
 					}
     			}
 				if(ok) continue;
 				// もしなければ妥協して動かす
 				for(int k = 0 ; k < pos[!j].size() ; k++){
 					if( 0 < pos[!j][k] ){
 						pos[!j].erase(pos[!j].begin()+k);
 						ok = 1;
 						t++;
 						break;
 					}
 				}
 
 				if(ok) continue;
 				// どうしようもなければ追加
 				pos[j].push_back(i);
 
 								
 				l++;
 			}
 		}
 		cs();
 		cout << l << " " << t << endl;
 		
     }
 }
 
 
