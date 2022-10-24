#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
int T,N,P;
int PP;
struct rect{
	int W,H;
	long double mincut,maxcut;
	void read(){
		scanf("%d%d",&W,&H);
		PP+=2*(W+H);
		P-=2*(W+H);
		mincut=2*min(W,H);
		maxcut=2*hypot((long double)W,(long double)H);
	}
}R[101];
struct range{
	long double l,r;
	range(){}
	range(long double l,long double r):l(l),r(r){}
	bool operator <(range const &a)const{
		return l<a.l;
	}
	range operator +(range const &a)const{
		return range(l+a.l,r+a.r);
	}
	void output()const{
		printf("(%.10f, %.10f)\n",(double)l,(double)r);
	}
};
vector<range> V,VV;
int main(){
	scanf("%d",&T);
	for(int tt=1;tt<=T;++tt){
		scanf("%d%d",&N,&P);
		PP=0;
		V.clear();
		V.emplace_back(0,0);
		for(int i=0;i<N;++i){
			R[i].read();
			VV.clear();
			for(auto &&x:V) VV.emplace_back(x),VV.emplace_back(x+range(R[i].mincut,R[i].maxcut));
			sort(VV.begin(),VV.end());
			V.clear();
			long double prev=0,last=0;
			for(auto &&x:VV){
				if(last<x.l){
					V.emplace_back(prev,last);
					prev=x.l,last=x.r;
				}
				else{
					last=max(last,x.r);
				}
			}
			V.emplace_back(prev,last);
		}
//		printf("P = %d\n",P);
//		for(auto &&x:V) x.output();
		long double ans=0;
		for(auto &&x:V){
			if(P<x.l) break;
			if(P>x.r){
				ans=x.r;
			}
			else{
				ans=P;
				break;
			}
		}
		printf("Case #%d: %.10f\n",tt,double(ans+PP));
	}
	return 0;
}
