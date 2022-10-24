#include <bits/stdc++.h>
using namespace std;
int t,n,a[104],cur[104][104];
string s[104];
int main(){
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++){
        printf("Case #%d: ",tc);
        memset(cur,0,sizeof(cur));
        scanf("%d",&n);
        for(int x=0;x<n;x++){
            scanf("%d",&a[x]);
            cur[0][x]=1;
        }
        if(!a[0]||!a[n-1]){
            printf("IMPOSSIBLE\n");
            continue;
        }
        for(int r=0;;r++){
            bool done=1;
            s[r]="";
            int pos=0;
            for(int x=0;x<n;x++){
                int temp=a[x];
                while(temp){
                    if(!cur[r][pos]){
                        s[r]+='.';
                        pos++;
                        continue;
                    }
                    if(pos<x) s[r]+='\\',cur[r+1][pos+1]+=cur[r][pos];
                    else if(pos>x) s[r]+='/',cur[r+1][pos-1]+=cur[r][pos];
                    else s[r]+='.',cur[r+1][pos]+=cur[r][pos];
                    temp-=cur[r][pos];
                    pos++;
                }
            }
            while(pos<n){
				s[r]+='.';
				pos++;
			}
			for(int x=0;x<n;x++){
				if(cur[r][x]!=a[x]){
					done=0;
					break;
				}
			}
            if(done){
                printf("%d\n",r+1);
                for(int x=0;x<=r;x++) printf("%s\n",s[x].c_str());
                break;
            }
        }
    }
    return 0;
}