#include <bits/stdc++.h>
 using namespace std;
 int n,p,r,s,t;
 int cnt[15][5][30];
 vector <string> v[15],v2,v3;
 int main(){
 	v[0].push_back("P");
 	v[0].push_back("R");
 	v[0].push_back("S");
 	for(int x=1;x<=12;x++){
 		for(int y=0;y<3;y++){
 			v2.clear();
 			for(int z=0;z<v[x-1][y].length();z++){
 				if(v[x-1][y][z]=='P'){
 					v2.push_back("PR");
 				}
 				else if(v[x-1][y][z]=='R'){
 					v2.push_back("RS");
 				}
 				else{
 					v2.push_back("PS");
 				}
 			}
 			while(v2.size()>1){
 				v3.clear();
 				for(int x=0;x<v2.size();x+=2){
 					if(v2[x]<v2[x+1]){
 						v3.push_back(v2[x]+v2[x+1]);
 					}
 					else{
 						v3.push_back(v2[x+1]+v2[x]);
 					}
 				}
 				v2.clear();
 				for(int x=0;x<v3.size();x++) v2.push_back(v3[x]);
 			}
 			v[x].push_back(v2[0]);
 		}
 		sort(v[x].begin(),v[x].end());
 		for(int y=0;y<3;y++){
 			for(int z=0;z<v[x][y].length();z++){
 				cnt[x][y][v[x][y][z]]++;
 			}
 		}
 	}
 	scanf("%d",&t);
 	for(int c=1;c<=t;c++){
 		printf("Case #%d: ",c);
 		scanf("%d %d %d %d",&n,&r,&p,&s);
 		for(int x=0;x<3;x++){
 			if(cnt[n][x]['R']==r&&cnt[n][x]['P']==p&&cnt[n][x]['S']==s){
 				printf("%s\n",v[n][x].c_str());
 				break;
 			}
 			if(x==2){
 				printf("IMPOSSIBLE\n");
 			}
 		}
 	}
 	return 0;
 }
