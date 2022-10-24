#include <iostream>
 #include <vector>
 #include <algorithm>
 #include <cmath>
 #include <cstdio>
 
 using namespace std;
 
 double solveSmall(long long x, const vector<long long>& vl){
 	double res = 0.0;
 	long long m = vl[0];
 	for(int i=0;i<vl.size();i++) m = min(m, vl[i]);
 	for(int i=1; ;i++){
 		int use = 0;
 		int target = m+i;
 		int bet = 0;
 		vector<int> add;
 		for(int j=0;j<vl.size();j++){
 			if(vl[j] <= target){
 				add.push_back(target - vl[j]);
 				bet += target-vl[j];
 			}
 		}
 		if(bet > x) break;
 		sort(add.begin(), add.end());
 		for(int j=0;j<add.size();j++){
 			if(bet+j > x) break;
 			double prof = -(bet+j);
 			for(int k=j;k<add.size();k++){
 				prof += 36.0*add[k]/(add.size()-j);
 			}
 			res = max(prof, res);
 		}
 	}
 	return res;
 }
 
 int main(){
 	int TEST; cin >> TEST;
 	for(int test=1;test<=TEST;test++){
 		long long x, n; cin >> x >> n;
 		vector<long long> vl(37, 0);
 		for(int i=0;i<n;i++) cin >> vl[i];
 		printf("Case #%d: %.10lf\n", test, solveSmall(x, vl));
 	}
 }
