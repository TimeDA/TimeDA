#include<cstdio>
 #include<stack>
 #include<algorithm>
 
 using namespace std;
 
 const long long mod=1000002013;
 
 int N;
 
 long long get(int dis)
 {
 	return (long long)dis*N-(long long)dis*(dis-1)/2;
 }
 
 struct stat{
 	int place,num;
 	bool isin;
 	stat(){}
 	stat(int a,int b,bool c):place(a),num(b),isin(c){}
 };
 
 stack<stat> st;
 stat stats[3030];
 int M;
 
 bool cmp(const stat &s1,const stat &s2)
 {
 	if(s1.place!=s2.place) return s1.place<s2.place;
 	if(s1.isin==true) return true;
 	return false;
 }
 
 long long get_minimum()
 {
 	sort(stats,stats+M*2,cmp);
 	long long res=0;
 	for(int i=0;i<M*2;i++)
 	{
 		stat s=stats[i];
 		if(s.isin==true)
 		{
 			st.push(s);
 			continue;
 		}
 		else
 		{
 			int n=s.num;
 			int c_pl=s.place;
 			while(n>0)
 			{
 				stat tmp=st.top();
 				st.pop();
 				if(tmp.num>n)
 				{
 					long long pr=get(c_pl-tmp.place);
 					pr*=n;
 					pr%=mod;
 					res+=pr;
 					res%=mod;
 					tmp.num-=n;
 					st.push(tmp);
 					n=0;
 				}
 				else
 				{
 					n-=tmp.num;
 					long long pr=get(c_pl-tmp.place);
 					pr*=tmp.num;
 					pr%=mod;
 					res+=pr;
 					res%=mod;
 				}
 			}
 		}
 	}
 	return res;
 }
 
 int main()
 {
 	int T;
 	scanf("%d",&T);
 	for(int datano=0;datano<T;datano++)
 	{
 		long long actual=0;
 		scanf("%d%d",&N,&M);
 		for(int i=0;i<M;i++)
 		{
 			int l,r,p;
 			scanf("%d%d%d",&l,&r,&p);
 			actual+=get(r-l)*p;
 			actual%=mod;
 			stats[i*2]=stat(l,p,true);
 			stats[i*2+1]=stat(r,p,false);
 		}
 		long long cheap=get_minimum();
 		long long ans=actual-cheap;
 		ans%=mod;
 		ans+=mod;
 		ans%=mod;
 		printf("Case #%d: %lld\n",datano+1,ans);
 	}
 	return 0;
 }
