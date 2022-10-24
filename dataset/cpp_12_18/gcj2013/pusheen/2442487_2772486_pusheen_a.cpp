#include<stdio.h>
 #include<algorithm>
 #include<vector>
 #include<queue>
 int s[10001];
 struct E {
 	long long st,ed,cnt;
 }e[10001];
 int f(int x){
 	return s[x]==x?x:s[x]=f(s[x]);
 }
 struct QMIN {
 	long long p,cnt;
 	bool operator<(QMIN x)const {
 		return p>x.p;
 	}
 } ;
 struct QMAX {
 	long long p,cnt;
 	bool operator<(QMAX x)const {
 		return p<x.p;
 	}
 } ;
 std::priority_queue<QMIN> Qmin;
 std::priority_queue<QMAX> Qmax;
 long long cost(long long n,long long ln){
 	return (n+(n-ln+1))*ln/2;
 }
 int main(){
 	int i,j,k;
 	int m;
 	long long n;
 	int T,TN;
 	scanf("%d",&TN);
 	long long sum1,sum2;
 	for(T=1;T<=TN;T++){
 		sum1=sum2=0;
 		scanf("%I64d%d",&n,&m);
 		for(i=0;i<m;i++){
 			scanf("%I64d%I64d%I64d",&e[i].st,&e[i].ed,&e[i].cnt);
 			sum1+=(cost(n,e[i].ed-e[i].st)%1000002013)*e[i].cnt;
 			sum1%=1000002013;
 			s[i]=i;
 		}
 		for(i=0;i<m;i++){
 			for(j=i+1;j<m;j++){
 				if(f(i)==f(j))continue;
 				if(
 					(e[i].st>=e[j].st&&e[i].st<=e[j].ed)||
 					(e[i].ed>=e[j].st&&e[i].st<=e[j].ed)||
 					(e[i].st<e[j].st&&e[i].ed>e[j].ed)
 				){
 					s[f(i)]=f(j);
 				}
 			}
 		}
 		for(i=0;i<m;i++){
 			while(!Qmin.empty())Qmin.pop();
 			while(!Qmax.empty())Qmax.pop();
 			for(j=0;j<m;j++){
 				if(f(j)!=i)continue;
 				//printf("[%d]",j+1);
 				Qmin.push((QMIN){e[j].st,e[j].cnt});
 				Qmax.push((QMAX){e[j].ed,e[j].cnt});
 			}
 			while(!Qmin.empty()||!Qmax.empty()){
 				long long x=Qmin.top().p;
 				long long y=Qmax.top().p;
 				long long z=std::min(Qmin.top().cnt,Qmax.top().cnt);
 				if(z==Qmin.top().cnt&&z==Qmax.top().cnt){
 					Qmin.pop();
 					Qmax.pop();
 				} else if(z==Qmin.top().cnt){
 					Qmin.pop();
 					int zz=Qmax.top().cnt-z;
 					Qmax.pop();
 					Qmax.push((QMAX){y,zz});
 				} else if(z==Qmax.top().cnt){
 					Qmax.pop();
 					int zz=Qmin.top().cnt-z;
 					Qmin.pop();
 					Qmin.push((QMIN){x,zz});
 				}
 				if(x>y)std::swap(x,y);
 				//printf("[%I64d %I64d %I64d]",x,y,z);
 				sum2+=(cost(n,y-x)%1000002013)*z;
 				sum2%=1000002013;
 			}
 			//puts("");
 		}
 		//printf("%I64d %I64d\n",sum1,sum2);
 		printf("Case #%d: ",T);
 		printf("%I64d",(sum1-sum2+1000002013)%1000002013);
 		puts("");
 	}
 	
 }
