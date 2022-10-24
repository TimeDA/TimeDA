#include <cstdio>
 #include <cstring>
 #include <utility>
 #include <vector>
 #include <deque>
 #include <algorithm>
 #define MOD 1000002013
 using namespace std;
 int t;
 int cnt=0;
 typedef pair<long long,long long> ii;
 typedef pair<ii,long long> iii;
 deque <ii> q;
 vector <iii> event;
 ii temp3;
 long long int x,n,m,o[1005],e[1005],p[1005];
 long long int temp,maxtot=0,mintot=0,temp2;
 int main(){
 	scanf("%d",&t);
 	while(t--){
 		maxtot=0;
 		mintot=0;
 		event.clear();
 		q.clear();
 		scanf("%lld %lld",&n,&m);
 		for(x=0;x<m;x++){
 			scanf("%lld %lld %lld",&o[x],&e[x],&p[x]);
 			event.push_back(iii(ii(o[x],0),p[x]));
 			event.push_back(iii(ii(e[x],1),p[x]));
 			temp=e[x]-o[x];
 			maxtot+=((temp*n-temp*(temp-1)/2)%MOD)*p[x];
 			maxtot%=MOD;
 		}
 		sort(event.begin(),event.end());
 		for(x=0;x<int(event.size());x++){
 			if(event[x].first.second==0){
 				q.push_back(ii(event[x].first.first,event[x].second));
 			}
 			else{
 				temp=event[x].second;
 				while(q.back().second<temp){
 					temp-=q.back().second;
 					temp2=event[x].first.first-q.back().first;
 					mintot+=((temp2*n-temp2*(temp2-1)/2)%MOD)*q.back().second;
 					mintot%=MOD;
 					q.pop_back();
 				}
 				temp2=event[x].first.first-q.back().first;
 				mintot+=((temp2*n-temp2*(temp2-1)/2)%MOD)*temp;
 				mintot%=MOD;
 				temp3=q.back();
 				q.pop_back();
 				temp3.second-=temp;
 				q.push_back(temp3);
 			}
 		}
 		cnt++;
 		printf("Case #%d: %lld\n",cnt,(maxtot+MOD-mintot)%MOD);
 	}
 	return 0;
 }
