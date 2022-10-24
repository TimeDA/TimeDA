#include <bits/stdc++.h>
 #include <stdio.h>
 #include <unistd.h>
 #include <sys/types.h>
 #include <sys/wait.h>
 using namespace std;
 #define rep(i,n) for(int i = 0 ; i < (int)(n) ; i++)
 
 
 int caseNum;
 int solve(int N,set<string> p[200]){
 	/*ここから処理*/
 	int res = 1e9;
 	map<string,pair<int,int> > o;
 	for( auto x : p[0] ) o[x].first++;
 	for( auto x : p[1] ) o[x].second++;
 	
 	for(int i = 0 ; i < (1<<(N-2)) ; i++){	
 		int bit = (i << 2) | 2;
 		for(int j = 2 ; j < N ; j++){
 			for( auto x : p[j] ){
 				if( bit >> j & 1 ) o[x].second++;
 				else o[x].first++;
 			}
 		}
 		int ans = 0;
 		for( auto w : o ){
 			if( w.second.first > 0 && w.second.second > 0 ) ans++;
 		}
 		for(int j = 2 ; j < N ; j++){
 			for( auto x : p[j] ){
 				if( bit >> j & 1 ) o[x].second--;
 				else o[x].first--;
 			}
 		}
 		res = min(res,ans);
 	}
 	/*ここまで処理*/
 	
 	char name[256];
 	sprintf(name,"./out_%s/%04d.txt",__FILE__,caseNum);
 	ofstream ofs(name);
 	ofs << "Case #" << caseNum << ": ";
 	/*ここに出力*/
 	ofs << res << endl;
 	/*ここまで出力*/
 }
 
 int main(){
 	
 	int T;
 	cin >> T;
 	
 	int status;
 	int p_id;
 	int current = 0;
 	string cmd = "mkdir out_"+string(__FILE__);
 	system(cmd.c_str());
 
 	map<int,int> Q_ids;
 	set<int> Q;
 	for(caseNum=1;caseNum<=T;caseNum++){
 		/*入力ここから*/
 		int N;
 		cin >> N;
 		string t;
 		set<string> p[200];
 		getline(cin,t);
 		for(int i = 0 ; i < N ; i++){
 			getline(cin,t);
 			stringstream ss(t);
 			while( ss >> t ) p[i].insert(t);
 		}
 
 		/*入力ここまで*/
 		if ((p_id = fork()) == 0) { // child
 			/*入力*/
 			solve(N,p);
 			/*いれろ*/
 			exit(0);
 		}else if( p_id != -1 ){
 			current++;
 			Q.insert(caseNum);
 			Q_ids[p_id] = caseNum;
 			if( current > 6 ){
 				int k = wait(&status);
 				current--;
 				Q.erase(Q_ids[k]);
 			}
 			cerr << setw(8) << caseNum << " / " << T << "[";
 			for( auto q : Q ) cerr << " " << q;
 			
 			cerr << "]" << '\r' << flush;
 		}
 	}
 	while( current > 0 ){
 		int k = wait(&status);
 		current--;
 		Q.erase(Q_ids[k]);
 	}
 	cerr << "DONE" << endl;
 	return 0;
 }