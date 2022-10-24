#include <bits/stdc++.h>
 using namespace std;
 
 
 void cs(){
 	static int t = 1;
 	cout << "Case #" << t++ << ": ";
 }
 int main(){
 	int T;
 	cin >> T;
 	while(T--){
 		int N,K;
 		cin >> N >> K;
 		vector<int> w(N+2);
 		w[0] = -1;
 		w.back() = -1;
 
 		for(int i = 0 ; i < K ; i++){
 			int mx = -1;
 			vector<int> dst(N+2,1e9);
 			vector<int> lef(N+2,1e9);
 			vector<int> rig(N+2,1e9);
 			int p = 0;
 			dst[0] = 0;
 			lef[0] = 0;
 			rig[0] = 0;
 
 			dst.back() = 0;
 			lef.back() = 0;
 			rig.back() = 0;
 			for(int j = 1 ; j <= N ; j++){
 				if( w[j] ) p = j;
 				dst[j] = min(dst[j],j-p);
 				lef[j] = j-p;
 			}
 			p = N + 1;
 			for(int j = N ; j >= 1 ; j--){
 				if( w[j] ) p = j;
 				dst[j] = min(dst[j],p-j);
 				rig[j] = p-j;
 			}
 			int ps = 0;
 			
 			for(int j = 1 ; j <= N ; j++){
 				if( dst[ps] < dst[j] || (dst[ps] == dst[j] && max(lef[ps],rig[ps]) < max(lef[j],rig[j])) ){
 					ps = j;
 				}
 			}
 			w[ps] = i+1;
 			if( i == K - 1 ){
 				int mns = 1e9;
 				int mxs = -1e9;
 				for(int j = 0 ; j <= N+1 ; j++){
 					if( w[j] and j != ps ){
 						mns = min(mns,abs(ps-j));
 					}
 				}
 				cs();
 				cout <<  max(lef[ps],rig[ps])-1 << " " << mns-1<< endl;
 			}
 			//for(int j = 0 ; j <= N + 1 ; j++) cout << w[j] << " "; cout << endl;
 			
 		}
 	}
 }