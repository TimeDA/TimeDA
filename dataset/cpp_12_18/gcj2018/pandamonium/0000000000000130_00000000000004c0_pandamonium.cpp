#include <bits/stdc++.h>
using namespace std;
int t,n,k;
set <pair<int,char> >s;
int main(){
	scanf("%d",&t);
	for(int tc=1;tc<=t;tc++){
		printf("Case #%d:",tc);
		scanf("%d",&n);
		int sum=0;
		s.clear();
		for(int x=0;x<n;x++){
			scanf("%d",&k);
			sum+=k;
			s.insert(make_pair(k,'A'+x));
		}
		while(sum){
			auto i=s.end();
			i--;
			auto p1=(*i);
			i--;
			if((i->first)*2>sum-1){
				auto p2=(*i);
				printf(" %c%c",p1.second,p2.second);
				s.erase(p1);
				s.erase(p2);
				p1.first--;
				p2.first--;
				s.insert(p1);
				s.insert(p2);
				sum-=2;
			} else{
				s.erase(p1);
				printf(" %c",p1.second);
				p1.first--;
				s.insert(p1);
				sum--;
			}
		}
		printf("\n");
	}
	return 0;
}