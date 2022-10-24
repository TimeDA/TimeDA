#include <bits/stdc++.h>
using namespace std;
unordered_map <int,int> cnt1,cnt2;
unordered_map <int,unordered_map<int,int> >cnt3;
multiset <pair<int,int> >s1,s2;
int t,s,d,a,b,m[100004],n[100004];
int main(){
	scanf("%d",&t);
	for(int tc=1;tc<=t;tc++){
		scanf("%d",&s);
		cnt1.clear();
		cnt2.clear();
		cnt3.clear();
		s1.clear();
		s2.clear();
		int l=0,maxsiz=-1,cnt=0;
		for(int x=0;x<s;x++){
			scanf("%d %d %d",&d,&a,&b);
			m[x]=d+a;
			n[x]=d-b;
			s1.insert(make_pair(m[x],n[x]));
			s2.insert(make_pair(n[x],m[x]));
			cnt1[m[x]]++;
			cnt2[n[x]]++;
			cnt3[m[x]][n[x]]++;
			while(l<x){
				bool done=0;
				for(int y=0;y<2;y++){
					int n1=y?s1.begin()->second:s1.rbegin()->second;
					for(int z=0;z<2;z++){
						int m1=z?s2.begin()->second:s2.rbegin()->second;
						if(cnt1[m1]+cnt2[n1]-cnt3[m1][n1]==(int)s1.size()){
							done=1;
							break;
						}
					}
					if(done) break;
				}
				if(done) break;
				cnt1[m[l]]--;
				cnt2[n[l]]--;
				cnt3[m[l]][n[l]]--;
				s1.erase(s1.find(make_pair(m[l],n[l])));
				s2.erase(s2.find(make_pair(n[l],m[l])));
				l++;
			}
			if((int)s1.size()>maxsiz) maxsiz=(int)s1.size(),cnt=1;
			else if((int)s1.size()==maxsiz) cnt++;
		}
		printf("Case #%d: %d %d\n",tc,maxsiz,cnt);
	}
	return 0;
}		