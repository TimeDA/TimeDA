#include<cstdio>
 #include<vector>
 #include<algorithm>
 
 using namespace std;
 
 typedef double Real;
 
 const Real eps=1e-7;
 
 int N;
 Real R[110],C[110];
 Real V,X;
 
 typedef pair<Real,Real> P;
 
 vector<P> sm,la;
 Real same;
 
 bool check(Real T){
 	Real m1=0,m2=0;
 	for(int i=0;i<sm.size();i++){
 		Real r=sm[i].first,c=sm[i].second;
 		m1+=(X-c)*r*T;
 	}
 	for(int i=0;i<la.size();i++){
 		Real r=la[i].first,c=la[i].second;
 		m2+=(c-X)*r*T;
 	}
 	Real W=same*T;
 	if(m1<m2){
 		for(int i=0;i<sm.size();i++){
 			Real r=sm[i].first;
 			W+=r*T;
 		}
 		Real m=0;
 		for(int i=0;i<la.size();i++){
 			Real r=la[i].first,c=la[i].second;
 			Real cm=(c-X)*r*T;
 			if(m+cm<=m1){
 				W+=r*T;
 				m+=cm;
 			}else{
 				Real m_=m1-m;
 				Real t=m_/(c-X);
 				W+=t;
 				break;
 			}
 		}
 		return W>=V;
 	}else{
 		for(int i=0;i<la.size();i++){
 			Real r=la[i].first,c=la[i].second;
 			W+=r*T;
 		}
 		Real m=0;
 		for(int i=0;i<sm.size();i++){
 			Real r=sm[i].first,c=sm[i].second;
 			Real cm=(X-c)*r*T;
 			if(m+cm<=m2){
 				W+=r*T;
 				m+=cm;
 			}else{
 				Real m_=m2-m;
 				Real t=m_/(X-c);
 				W+=t;
 				break;
 			}
 		}
 		return W>=V;
 	}
 	return false;
 }
 
 vector<P> sm_,la_;
 
 Real solve(){
 	sort(sm_.begin(),sm_.end());
 	for(int i=(int)sm_.size()-1;i>=0;i--){
 		sm.push_back(P(sm_[i].second,sm_[i].first));
 	}
 	sort(la_.begin(),la_.end());
 	for(int i=0;i<la_.size();i++){
 		la.push_back(P(la_[i].second,la_[i].first));
 	}
 	Real lb=0,ub=1e10;
 	for(int stage=0;stage<100;stage++){
 		Real mid=(ub+lb)/2;
 		bool flg=check(mid);
 		if(flg) ub=mid;
 		else lb=mid;
 	}
 	return ub;
 }
 
 void init(){
 	sm_.clear();
 	sm.clear();
 	la_.clear();
 	la.clear();
 	same=0;
 }
 
 int main(){
 	int T;
 	scanf("%d",&T);
 	for(int datano=1;datano<=T;datano++){
 		int N;
 		init();
 		scanf("%d",&N);
 		scanf("%lf%lf",&V,&X);
 		for(int i=0;i<N;i++){
 			Real r,c;
 			scanf("%lf%lf",&r,&c);
 			if(c+eps<X){
 				sm_.push_back(P(c,r));
 			}else if(X+eps<c){
 				la_.push_back(P(c,r));
 			}else{
 				same+=r;
 			}
 		}
 		if(same<eps&&(sm_.size()==0||la_.size()==0)){
 			printf("Case #%d: IMPOSSIBLE\n",datano);
 			continue;
 		}
 		Real ans=solve();
 		printf("Case #%d: %.9f\n",datano,ans);
 	}
 	return 0;
 }
