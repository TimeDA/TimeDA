#include<cstdio>
 #include<vector>
 #include<utility>
 #include<complex>
 #include<cmath>
 #include<algorithm>
 
 using namespace std;
 
 typedef double Real;
 
 const Real PI=acos(-1.0);
 const Real eps=1e-8;
 long long xs[3030],ys[3030];
 int N;
 
 int ans[3030];
 
 vector<Real> ps;
 
 int main(){
 	int T;
 	scanf("%d",&T);
 	for(int datano=1;datano<=T;datano++){
 		scanf("%d",&N);
 		for(int i=0;i<N;i++) scanf("%lld%lld",xs+i,ys+i);
 		if(N<=3){
 			printf("Case #%d:\n",datano);
 			for(int i=0;i<N;i++) printf("0\n");
 			continue;
 		}
 		for(int i=0;i<N;i++){
 			ps.clear();
 			for(int j=0;j<N;j++){
 				double ang;
 				if(i==j) continue;
 				if(xs[i]==xs[j]){
 					if(ys[i]<ys[j]) ang=PI/2;
 					else ang=-PI/2;
 				}else if(ys[i]==ys[j]){
 					if(xs[i]<xs[j]) ang=0;
 					else ang=PI;
 				}else{
 					ang=atan2(ys[j]-ys[i],xs[j]-xs[i]);
 				}
 				ps.push_back(ang);
 				ps.push_back(ang+PI*2);
 			}
 			sort(ps.begin(),ps.end());
 			int res=3030;
 			for(int j=0;j<ps.size();j++){
 				if(ps[j]>PI+eps) break;
 				int ri=distance(ps.begin(),lower_bound(ps.begin(),ps.end(),ps[j]+PI-eps));
 				int cur=ri-j-1;
 				res=min(res,cur);
 			}
 			ans[i]=res;
 		}
 		printf("Case #%d:\n",datano);
 		for(int i=0;i<N;i++){
 			printf("%d\n",ans[i]);
 		}
 	}
 	return 0;
 }
