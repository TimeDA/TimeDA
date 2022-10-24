#include <iostream>
 #include <stdio.h>
 using namespace std;
 
 int T,ts;
 double c,f,x,t,tt,v,ans;
 
 int main()
 {
 	freopen("b.in","r",stdin);
 	freopen("b.out","w",stdout);
 	cout.precision(15);
 	cin>>T;
 	while(T--)
 	{
 		cin>>c>>f>>x;
 		v=2;
 		ans=0;
 		while(1)
 		{
 			t=x/v;
 			tt=c/v+c/f;
 			if(t<tt)
 			{
 				ans+=t;
 				break;
 			}
 			ans+=c/v;
 			v+=f;
 		}
 		cout<<"Case #"<<++ts<<": "<<ans<<'\n';
 	}
 	return 0;
 }
