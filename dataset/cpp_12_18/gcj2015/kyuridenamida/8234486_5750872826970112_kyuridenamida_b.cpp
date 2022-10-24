#include <bits/stdc++.h>
 using namespace std;
 #define double long double
 int putCase(){
 	static int n = 1;
 	cout << "Case #" << n++ << ": ";
 }
 double R[222];
 double T[222];
 double EPS = 1e-10;
 double V,X;
 
 double calc(double R1,double T1,double R2,double T2,double t1,double t2){
 	return (R1*t1*T1+T2*t2*R2) / (R1*t1+R2*t2);
 }
 int can(double R1,double T1,double R2,double T2,double t1){
 	double V2 = V - R1*t1;
 	double t2 = V2 / t2;
 	
 }
 double solve(double R1,double T1,double R2,double T2){
 	double a = R1;
 	double b = R2;
 	double c = T1;
 	double d = T2;
 	if( c == d ){
 		return V/(a+b);
 	}
 	double y = V*(c - X) / (b*c-b*d);
 	double x = (V - b * y) / a;
 	
 	if( x < -EPS || y < -EPS ) return 1e100;
 	return max(x,y);
 }
 int main(){
 	int TT;
 	cin >> TT;
 	while(TT--){
 		putCase();
 		int N;
 		cin >> N;
 		cin >> V >> X;
 		for(int i = 0 ; i < N ; i++){
 			cin >> R[i];
 			cin >> T[i];
 		}
 		double ans = 1e18;
 		
 		if( N == 1 ){
 			if( fabs(X - T[0]) > 1e-9 ){
 				puts("IMPOSSIBLE");
 			}else{
 				printf("%.10Lf\n",V / R[0]);
 			}
 		}else{		
 			if( T[0] > T[1] ){
 				swap(R[0],R[1]);
 				swap(T[0],T[1]);
 			}
 			if( T[0] - EPS < X && X < T[1] + EPS ){
 				double ans = 1e100;
 				ans = min(ans,solve(R[0],T[0],R[1],T[1]));
 				if( ans > 1e50 ){
 					puts("IMPOSSIBLE");
 				}else printf("%.10Lf\n",ans);
 			}else{
 				puts("IMPOSSIBLE");
 			}
 		}
 	}
 }