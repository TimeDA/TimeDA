#include<iostream>
#include<vector>
#include<string>
#define ll long long
using namespace std;
	ll C, n;
	string s;
int main(){
	ios_base::sync_with_stdio(false);
	cin>>C; 
	for(int c=0; c<C; c++){
		cin>>n>>s; int l = s.size();
		vector<int> nums(31, 0);
		ll sum=0; int p2 = 0;
		for(int i=0; i<=l; i++){
		    if(s[i]=='C'){
			p2++;
		    }else if(s[i]=='S'){
			nums[p2]++;
			sum+=(1<<p2);
		    }
		}
		int res=0; bool fail = false;
		while(sum>n){
		    int ind;
		    for(ind=30; ind>0; ind--)if(nums[ind])break;
		    if(!ind){
			fail = true;
			break;
		    }
		    nums[ind]--;
		    nums[ind-1]++;
		    sum -=(1<<ind);
		    sum+=(1<<(ind-1));
		    res++;

		}
		if(fail)
			cout<<"Case #"<<c+1<<": IMPOSSIBLE\n" ;
		else
		    cout<<"Case #"<<c+1<<": "<<res<<"\n" ;
	}
	
}
