#include<stdio.h>
 #include<map>
 typedef std::map<long long,long long> S;
 typedef S::reverse_iterator SR;
 S s;
 int main(){
 	int T,TN;
 	scanf("%d",&TN);
 	for(T=1;T<=TN;T++){
 		long long n,m;
 		scanf("%lld%lld",&n,&m);
 		s.clear();
 		s[n]++;
 		m--;
 		while(m){
 			for(SR it=s.rbegin();it!=s.rend();++it){
 				long long u=it->first,v=it->second;
 				if(v){
 					if(v>m) v=m;
 					s[(u-1)/2]+=v;
 					s[u/2]+=v;
 					s[u]-=v;
 					m-=v;
 					break;
 				} // No need to cleanup.
 			}
 		}
 		for(SR it=s.rbegin();it!=s.rend();++it){
 			long long u=it->first,v=it->second;
 			if(v){
 				printf("Case #%d: %lld %lld\n",T,u/2,(u-1)/2);
 				break;
 			}
 		}
 	}
 }
 
 
