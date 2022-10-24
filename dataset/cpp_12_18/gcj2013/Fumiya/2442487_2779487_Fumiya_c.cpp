#include <iostream>
 #include <vector>
 #include <queue>
 #include <algorithm>
 #include <cstring>
 #include <cstdio>
 
 using namespace std;
 
 int in[2000];
 int road[2000][2000];
 
 int main(){
 	int T; cin >> T;
 	int N;
 	int A[2000], B[2000];
 	int a[2000], b[2000];
 	for(int test=1;test<=T;test++){
 		cin >> N;
 		for(int i=0;i<N;i++) cin >> A[i];
 		for(int i=0;i<N;i++) cin >> B[i];
 		memset(in, 0, sizeof(in));
 		memset(road, 0, sizeof(road));
 		vector< vector<int> > g(N);
 		for(int i=0;i<N;i++){
 			int lastIdx = -1;
 			for(int j=0;j<i;j++){
 				if(A[j] >= A[i]) g[i].push_back(j);
 				if(A[j]+1 == A[i]) lastIdx = j;
 			}
 			if(lastIdx != -1) g[lastIdx].push_back(i);
 		}
 		for(int i=N-1;i>=0;i--){
 			int lastIdx = -1;
 			for(int j=N-1;j>i;j--){
 				if(B[j] >= B[i]) g[i].push_back(j);
 				if(B[j]+1 == B[i]) lastIdx = j;
 			}
 			if(lastIdx != -1) g[lastIdx].push_back(i);
 		}
 
 		for(int i=0;i<N;i++){
 			queue<int> qu; qu.push(i);
 			while(!qu.empty()){
 				int cur = qu.front(); qu.pop();
 				for(int j=0;j<g[cur].size();j++){
 					if(road[i][g[cur][j]]) continue;
 					road[i][g[cur][j]] = 1;
 					qu.push(g[cur][j]);
 				}
 			}
 			for(int j=0;j<N;j++)
 				if(road[i][j]) in[j]++;
 		}
 
 		vector<int> res(N);
 
 		for(int i=0;i<N;i++){
 			for(int j=0;j<N;j++){
 				if(in[j] == 0){
 					res[j] = i+1;
 					for(int k=0;k<N;k++)
 						if(road[j][k]) in[k]--;
 					in[j] = -1;
 					break;
 				}
 			}
 		}
 
 		printf("Case #%d:", test);
 		for(int i=0;i<N;i++) printf(" %d", res[i]);
 
 		a[0] = 1;
 		for(int i=1;i<N;i++){
 			a[i] = 1;
 			for(int j=0;j<i;j++)
 				if(res[j] < res[i]) a[i] = max(a[i], a[j]+1);
 		}
 		b[N-1] = 1;
 		for(int i=N-2;i>=0;i--){
 			b[i] = 1;
 			for(int j=N-1;j>i;j--){
 				if(res[j] < res[i]) b[i] = max(b[i], b[j]+1);
 			}
 		}
 		bool ok = true;
 		for(int i=0;i<N;i++){
 			if(a[i]!=A[i]) ok = false;
 			if(b[i]!=B[i]) ok = false;
 		}
 		if(!ok){
 			cout << "FAILED" << endl;
 			for(int i=0;i<N;i++) cout << A[i] << " "; cout << endl;
 			for(int i=0;i<N;i++) cout << a[i] << " "; cout << endl;
 			for(int i=0;i<N;i++) cout << B[i] << " "; cout << endl;
 			for(int i=0;i<N;i++) cout << b[i] << " "; cout << endl;
 		}
 
 		printf("\n");
 	}
 }
