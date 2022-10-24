#include<cstdio>
 #include<cstring>
 #include<cmath>
 #include<algorithm>
 using namespace std;
 const double eps=1e-8;
 struct P
 {
 	double x,y;
 	P(double _x=0,double _y=0):x(_x),y(_y){}
 	void get(){scanf("%lf%lf",&x,&y);}
 	P operator + (const P&a) const {return P(x+a.x,y+a.y);}
 	P operator - (const P&a) const {return P(x-a.x,y-a.y);}
 	double operator * (const P&a) const {return x*a.x+y*a.y;}
 	double operator ^ (const P&a) const {return x*a.y-y*a.x;}
 	double abs() const {return sqrt(abs2());}
 	double abs2() const {return x*x+y*y;}
 	bool operator < (const P&a) const {return x<a.x||fabs(x-a.x)<eps&&y<a.y;}
 	bool operator > (const P&a) const {return x>a.x||fabs(x-a.x)<eps&&y>a.y;}
 	bool operator == (const P&a) const {return fabs(x-a.x)<eps&&fabs(y-a.y)<=eps;}
 };
 int n;P A[10];
 bool v[10];int a[10],pa[10];double ws=0.0;
 bool ison(const P&a,const P&b,const P&c)
 {
 	if(fabs((a-b)^(a-c))>eps)return 0;
 	return !(a<b&&a<c||a>b&&a>c);
 }
 bool ints(const P&x0,const P&x1,const P&y0,const P&y1)
 {
 	if(fabs((x1-x0)^(y1-y0))<eps)return 0;
 	double s0=(y0-x0)^(y0-x1),s1=(y1-x0)^(y1-x1);
 	if(!(s0>eps&&s1<-eps||s0<-eps&&s1>eps))return 0;
 	s0=(x0-y0)^(x0-y1),s1=(x1-y0)^(x1-y1);
 	if(!(s0>eps&&s1<-eps||s0<-eps&&s1>eps))return 0;
 	return 1;
 }
 bool FF;
 void gg()
 {
 	for(int i=0;i<n;i++)
 		for(int j=i+2;j<n;j++)
 		{
 			int x0=a[i],x1=a[i+1],y0=a[j],y1=a[(j+1)%n];
 			if(x0==y0||x0==y1||x1==y0||x1==y1)continue;
 			if(ison(A[y0],A[x0],A[x1]))return;
 			if(ison(A[y1],A[x0],A[x1]))return;
 			if(ison(A[x0],A[y0],A[y1]))return;
 			if(ison(A[x1],A[y0],A[y1]))return;
 			if(ints(A[x0],A[x1],A[y0],A[y1]))return;
 		}
 	FF=1;
 	double S=0;
 	for(int i=1;i<n-1;i++)
 		S+=((A[a[i]]-A[a[0]])^(A[a[i+1]]-A[a[0]]));
 	S=fabs(S);
 	if(S>ws)ws=S,memcpy(pa,a,sizeof pa);
 }
 void ff(int x)
 {
 	if(x==n){gg();return;}
 	for(int i=0;i<n;i++)
 		if(!v[i])v[i]=1,a[x]=i,ff(x+1),v[i]=0;
 }
 int main()
 {
 	int _;scanf("%d",&_);
 	for(int __=1;__<=_;__++)
 	{
 		scanf("%d",&n);
 		for(int i=0;i<n;i++)A[i].get();
 		//a[0]=0,a[1]=1,a[2]=4,a[3]=2,a[4]=3;gg();return 0;
 		memset(v,0,sizeof v);
 		a[0]=0,v[0]=1,ws=-1;FF=0;ff(1);
 		printf("Case #%d: ",__);
 		for(int i=0;i<n;i++)printf("%d%c",pa[i],i==n-1?'\n':' ');
 	}
 	return 0;
 }