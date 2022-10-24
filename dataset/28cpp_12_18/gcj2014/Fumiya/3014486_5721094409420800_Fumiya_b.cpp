#include <iostream>
 #include <vector>
 #include <string>
 #include <algorithm>
 #include <cstring>
 #include <cstdio>
 
 using namespace std;
 
 int solveSmall(const vector<int>& vi){
 	vector<int> v = vi;
 	vector<int> a(v.size());
 	sort(v.begin(), v.end());
 	int res = 10000000;
 	do{
 		bool valid = true;
 		int maxPos = 0;
 		for(int i=1;i<v.size();i++){
 			if(v[maxPos] < v[i]) maxPos = i;
 		}
 		for(int i=0;i+1<=maxPos;i++){
 			if(v[i] > v[i+1]) valid = false;
 		}
 		for(int i=maxPos;i+1<v.size();i++){
 			if(v[i] < v[i+1]) valid = false;
 		}
 		if(!valid) continue;
 		for(int i=0;i<v.size();i++){
 			for(int j=0;j<vi.size();j++){
 				if(v[i]==vi[j]) a[j] = i;
 			}
 		}
 		int cnt = 0;
 		for(int i=0;i<v.size();i++){
 			for(int j=i+1;j<v.size();j++)
 				if(a[i] > a[j]) cnt++;
 		}
 		res = min(res, cnt);
 	}while(next_permutation(v.begin(), v.end()));
 	return res;
 }
 
 int main(){
 	int T; cin >> T;
 	for(int test=1;test<=T;test++){
 		int N; cin >> N;
 		vector<int> vi(N);
 		for(int i=0;i<N;i++) cin >> vi[i];
 		printf("Case #%d: %d\n", test, solveSmall(vi));
 	}
 }
