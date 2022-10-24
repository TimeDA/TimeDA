#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#define ll long long

using namespace std;
    
	int T, r0, b0;
int main(){

	cin>>T; 
	for(int j=0; j<T; j++){
		cin>>r0>>b0;
        if(r0>b0)swap(r0,b0);
        int maxres=0;
        for(int mx1 = 0; mx1<=r0; mx1++){
        int r = r0; int b = b0;
        int res = 0;
        
        for(int sum = 1; sum<=r+b; sum++){
            for(int i=0; i<=min(mx1, sum) ; i++){
                if(i<=r && sum-i<=b){
                    r-=i; b-=sum-i;
//cout<<i<<" "<<sum-i<<"; ";
                    res++;
                }
            }
        }
        if(r>0 && r>mx1){
            res++;
            r-=mx1+1;
        }
        if(res>maxres)maxres=res;
        }
		cout<<"Case #"<<j+1<<": "<<maxres<<"\n" ;

	}
	
}
