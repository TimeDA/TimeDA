#include<cstdio>
 #include<vector>
 #include<algorithm>
 
 using namespace std;
 
 long long tens[16];
 
 vector<int> encode(long long a)
 {
 	vector<int> res;
 	while(a!=0)
 	{
 		res.push_back(a%10);
 		a/=10;
 	}
 //	for(int i=0;i<res.size();i++) printf("%d\n",res[i]);
 	return res;
 }
 
 long long decode(vector<int> vec)
 {
 	long long res=0;
 	for(int i=0;i<vec.size();i++)
 	{
 		int d=vec[i];
 		res+=tens[i]*d;
 	}
 	return res;
 }
 
 long long getpalin(long long s,bool overlap)
 {
 	vector<int> vec=encode(s);
 	int n=vec.size();
 	int st=overlap?n-2:n-1;
 	for(int i=st;i>=0;i--)
 	{
 		vec.push_back(vec[i]);
 	}
 //	for(int i=0;i<vec.size();i++) printf("%d\n",vec[i]);
 	return decode(vec);
 }
 
 bool checkpalin(vector<int> vec)
 {
 	int n=vec.size();
 	for(int i=0;i<n;i++)
 	{
 		if(vec[i]!=vec[n-1-i]) return false;
 	}
 	return true;
 }
 
 bool checkpalin(long long a)
 {
 	vector<int> vec=encode(a);
 	return checkpalin(vec);
 }
 
 long long palin[10100100];
 int c=0;
 
 int getcnt(long long a)
 {
 	//[0,a]
 	return upper_bound(palin,palin+c,a)-palin;
 }
 
 int main()
 {
 	tens[0]=1;
 	for(int i=1;i<16;i++) tens[i]=tens[i-1]*10;
 //	printf("%lld\n",getpalin(12,true));
 	for(int i=1;i<=10000;i++)
 	{
 		if(i%10==0) continue;
 	//	printf("%d\n",i);
 		long long a=getpalin(i,true);
 	//	printf("%lld\n",a);
 		long long b=a*a;
 		if(checkpalin(b))
 		{
 			palin[c]=b;
 			c++;
 		//	printf("%lld %lld\n",a,b);
 		}
 		a=getpalin(i,false);
 	//	printf("%lld\n",a);
 		b=a*a;
 		if(checkpalin(b))
 		{
 			palin[c]=b;
 			c++;
 		//	printf("%lld %lld\n",a,b);
 		}
 	}
 	sort(palin,palin+c);
 //	for(int i=0;i<c;i++) printf("%lld\n",palin[i]);
 	int T;
 	scanf("%d",&T);
 	for(int datano=0;datano<T;datano++)
 	{
 		long long A,B;
 		scanf("%lld%lld",&A,&B);
 		A--;
 		printf("Case #%d: %d\n",datano+1,getcnt(B)-getcnt(A));
 	}
 	return 0;
 }
