#include<cstdio>
 #include<vector>
 #include<algorithm>
 
 using namespace std;
 
 long long S[1010];
 int N,K;
 
 long long m[1010],M[1010];
 long long L,R;
 
 long long x[1010];
 
 bool check(int id);
 
 long long solve(){
 	for(int i=0;i<K;i++) x[i]=0;
 	for(int i=K;i<N;i++){
 		int id=i-K;
 		x[i]=x[i-K]+S[id+1]-S[id];
 //		printf("i=%d,x=%lld\n",i,x[i]);
 	}
 	for(int i=0;i<K;i++){
 		m[i]=0,M[i]=0;
 	}
 	for(int i=K;i<N;i++){
 		int id=i%K;
 		m[id]=min(m[id],x[i]);
 		M[id]=max(M[id],x[i]);
 	}
 	L=0,R=0;
 	long long Ma=-1;
 	int id=-1;
 	vector<int> ids;
 	for(int i=0;i<K;i++){
 //		printf("%lld %lld\n",m[i],M[i]);
 		if(Ma<M[i]-m[i]){
 			Ma=M[i]-m[i];
 		}
 	}
 	for(int i=0;i<K;i++) if(M[i]-m[i]==Ma) ids.push_back(i);
 	for(int i=0;i<ids.size();i++){
 		if(check(ids[i])) return Ma;
 	}
 	return Ma+1;
 /*	long long m_=m[id],M_=M[id];
 	for(int i=0;i<K;i++){
 		L+=m[i]-m_;
 		R+=M[i]-M_;
 	}
 	if(R-L>=K-1) return Ma;
 	R%=K;
 	L%=K;
 	if(R<L) R+=K;
 	for(int i=L;i<=R;i++) if((S[0]-i)%K==0) return Ma;
 	return Ma+1;*/
 }
 
 bool check(int id){
 	long long L=0,R=0;
 	long long m_=m[id],M_=M[id];
 	for(int i=0;i<K;i++){
 	//	L+=m[i]-m_;
 	//	R+=M[i]-M_;
 		L+=m_-m[i];
 		R+=M_-M[i];
 	}
 	if(R-L>=K-1) return true;
 	R%=K;
 	L%=K;
 	if(L<0) L+=K;
 	if(R<0) R+=K;
 	if(R<L) R+=K;
 	//for(int i=L;i<=R;i++) if((S[0]-i)%K==0) return true;
 	int s=S[0]%K;
 	while(s<L) s+=K;
 	if(s<=R) return true;
 	return false;
 }
 
 int main(){
 	int T;
 	scanf("%d",&T);
 	for(int datano=1;datano<=T;datano++){
 		scanf("%d%d",&N,&K);
 		for(int i=0;i<=N-K;i++){
 			scanf("%lld",S+i);
 		}
 		long long ans=solve();
 		printf("Case #%d: %lld\n",datano,ans);
 	}
 	return 0;
 }
