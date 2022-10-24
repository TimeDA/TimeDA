#include<stdio.h>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long double DB;
DB const pi=acosl(-1.);
DB const Bound1=pi/4;
DB const Bound2=atanl(1./sqrt(2.));
inline DB Sqrt(DB const &x){
	return x<0?0:sqrt(x);
}
inline int Sign(DB const &x){
	return x<-1e-10?-1:x>1e-10;
}
inline bool equal(DB const &x,DB const &y){
	return x+1e-10>=y&&y+1e-10>=x;
}
struct point{
	DB x,y,z;
	point(){}
	point(DB x,DB y,DB z):x(x),y(y),z(z){}
	point rotateYZ(DB const &theta)const{
		DB cosT=cosl(theta),sinT=sinl(theta);
		return point(x,y*cosT-z*sinT,y*sinT+z*cosT);
	}
	point rotateXZ(DB const &theta)const{
		DB cosT=cosl(theta),sinT=sinl(theta);
		return point(x*cosT-z*sinT,y,x*sinT+z*cosT);
	}
	bool operator <(point const &a)const{
		if(!equal(x,a.x)) return x<a.x;
		if(!equal(y,a.y)) return y<a.y;
		if(!equal(z,a.z)) return z<a.z;
		return false;
	}
	void output(){
		printf("%.10f %.10f %.10f\n",(double)x,(double)z,(double)y);
	}
	point operator +(point const &a)const{
		return point(x+a.x,y+a.y,z+a.z);
	}
	point operator -(point const &a)const{
		return point(x-a.x,y-a.y,z-a.z);
	}
	point operator *(DB const &a)const{
		return point(x*a,y*a,z*a);
	}
	point operator /(DB const &a)const{
		return point(x/a,y/a,z/a);
	}
};
inline DB detXY(point const &a,point const &b){
	return a.x*b.y-a.y*b.x;
}
point ori[2][2][2];
point rot[2][2][2];
int T;
DB const Thres=sqrt(2.);
DB S;
DB calcArea(){
	vector<point> V;
	vector<point> convex;
	for(int i=0;i<2;++i) for(int j=0;j<2;++j) for(int k=0;k<2;++k) V.push_back(rot[i][j][k]);
	sort(V.begin(),V.end());
	int limit=1;
	int n=0;
	for(int i=0;i<8;++i){
		while(n>limit&&Sign(detXY(convex[n-1]-convex[n-2],V[i]-convex[n-2]))==-1){
			--n,convex.pop_back();
		}
		convex.push_back(V[i]);
		++n;
	}
	limit=n;
	for(int i=6;i>=0;--i){
		while(n>limit&&Sign(detXY(convex[n-1]-convex[n-2],V[i]-convex[n-2]))==-1){
			--n,convex.pop_back();
		}
		convex.push_back(V[i]);
		++n;
	}
	DB ret=0;
	for(int i=1;i<n;++i) ret+=detXY(convex[i-1],convex[i]);
	return ret/2;
}
int main(){
	scanf("%d",&T);
	for(int tt=1;tt<=T;++tt){
		double SS;
		scanf("%lf",&SS);
		S=SS;
		if(S>Thres){
			for(int i=0;i<2;++i) for(int j=0;j<2;++j) for(int k=0;k<2;++k) ori[i][j][k]=point(i,j,k).rotateYZ(Bound1);
			DB l=0,r=Bound2;
			for(int rr=1;rr<=100;++rr){
				DB mid=(l+r)/2;
				for(int i=0;i<2;++i) for(int j=0;j<2;++j) for(int k=0;k<2;++k) rot[i][j][k]=ori[i][j][k].rotateXZ(mid);
				if(calcArea()<=S) l=mid;
				else r=mid;
			}
			for(int i=0;i<2;++i) for(int j=0;j<2;++j) for(int k=0;k<2;++k) rot[i][j][k]=ori[i][j][k].rotateXZ((l+r)/2);
		}
		else{
			for(int i=0;i<2;++i) for(int j=0;j<2;++j) for(int k=0;k<2;++k) ori[i][j][k]=point(i,j,k);
			DB l=0,r=Bound1;
			for(int rr=1;rr<=100;++rr){
				DB mid=(l+r)/2;
				for(int i=0;i<2;++i) for(int j=0;j<2;++j) for(int k=0;k<2;++k) rot[i][j][k]=ori[i][j][k].rotateYZ(mid);
				if(calcArea()<=S) l=mid;
				else r=mid;
			}
			for(int i=0;i<2;++i) for(int j=0;j<2;++j) for(int k=0;k<2;++k) rot[i][j][k]=ori[i][j][k].rotateYZ((l+r)/2);
		}
		point O(0,0,0);
		point F(O),G(O),H(O);
		for(int i=0;i<2;++i) for(int j=0;j<2;++j) for(int k=0;k<2;++k){
			O=O+rot[i][j][k];
			if(i) F=F+rot[i][j][k];
			if(j) G=G+rot[i][j][k];
			if(k) H=H+rot[i][j][k];
		}
		O=O/8;
		F=F/4;
		G=G/4;
		H=H/4;
		printf("Case #%d:\n",tt);
		(F-O).output();
		(G-O).output();
		(H-O).output();
	}
	return 0;
}
