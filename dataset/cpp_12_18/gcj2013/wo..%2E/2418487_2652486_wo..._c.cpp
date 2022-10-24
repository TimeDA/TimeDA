#include<cstdio>
 #include<vector>
 #include<algorithm>
 
 using namespace std;
 
 vector<int> nums[64];
 vector<int> prods[64];
 
 vector<int> encode(int N)
 {
 	vector<int> res;
 	for(int i=0;i<3;i++)
 	{
 		int a=((N>>2*i)&1);
 		int b=((N>>(2*i+1))&1);
 		res.push_back(a*2+b+2);
 	}
 	return res;
 }
 
 vector<int> gen(int N)
 {
 	vector<int> nums=encode(N);
 	if(N==-1)
 	{
 		nums.clear();
 		nums.push_back(5);
 		nums.push_back(4);
 		nums.push_back(2);
 	}
 	
 	vector<int> res;
 	for(int i=0;i<8;i++)
 	{
 		int p=1;
 		for(int j=0;j<3;j++) if((i>>j)%2==1) p*=nums[j];
 		res.push_back(p);
 	}
 	sort(res.begin(),res.end());
 	res.erase(unique(res.begin(),res.end()),res.end());
 	if(N==-1)
 	{
 		for(int i=0;i<res.size();i++) printf("%d ",res[i]);
 		printf("\n");
 	}
 	return res;
 }
 
 int a[100];
 
 bool check(int id)
 {
 	vector<int> tmp=prods[id];
 	for(int i=0;i<7;i++)
 	{
 		bool ok=false;
 		for(int j=0;j<tmp.size();j++) if(tmp[j]==a[i]) ok=true;
 		if(ok==false) return false;
 	}
 	return true;
 }
 
 int main()
 {
 	int T;
 	scanf("%d",&T);
 	int R,N,M,K;
 	scanf("%d%d%d%d",&R,&N,&M,&K);
 	for(int i=0;i<64;i++) nums[i]=encode(i);
 	for(int i=0;i<64;i++) prods[i]=gen(i);
 	printf("Case #1:\n");
 	for(int i=0;i<R;i++)
 	{
 		for(int j=0;j<K;j++) scanf("%d",a+j);
 		for(int ans=0;ans<64;ans++)
 		{
 			if(check(ans))
 			{
 				for(int k=0;k<3;k++) printf("%d",nums[ans][k]);
 				printf("\n");
 				goto nxti;
 			}
 		}
 		nxti:;
 	}
 	//gen(-1);
 	return 0;
 }
