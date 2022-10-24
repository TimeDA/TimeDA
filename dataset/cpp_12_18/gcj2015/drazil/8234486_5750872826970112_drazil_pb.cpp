#include <stdio.h>
 #include <algorithm>
 #include <iostream>
 
 using namespace std ;
 
 int n ;
 long long V, X, totalRate ;
 struct src
 {
 	long long R, C ;
 } S[110] ;
 
 long long getnum()
 {
 	int a, b ;
 	scanf("%d.%d", &a, &b) ;
 	return a*10000+b ;
 }
 
 bool isOK(long double t)
 {
 	long double maxV[110] ;
 	for(int i=0;i<n;i++)
 		maxV[i] = S[i].R*t ;
 		
 	long double MaxX = 0 ;
 	long double usableV = V ;
 	for(int i=n-1;i>=0;i--)
 	{
 		long double v = min(usableV, maxV[i]) ;
 		MaxX += S[i].C * v ;
 		usableV -= v ;
 	}
 	
 	long double MinX = 0 ;
 	usableV = V ;
 	for(int i=0;i<n;i++)
 	{
 		long double v = min(usableV, maxV[i]) ;
 		MinX += S[i].C * v ;
 		usableV -= v ;
 	}
 	
 	return (MaxX>=V*X && MinX<=V*X && totalRate*t>=V) ;
 }
 
 int main(void)
 {
 	int tc ;
 	scanf("%d", &tc) ;
 	
 	for(int c=1;c<=tc;c++)
 	{
 		long double maxTime = 0 ;
 		scanf("%d", &n) ;
 		V = getnum() ;
 		X = getnum() ;
 		totalRate = 0 ;
 		for(int i=0;i<n;i++)
 		{
 			S[i].R = getnum() ;
 			S[i].C = getnum() ;
 			totalRate += S[i].R ;
 			maxTime = max(maxTime, ((long double)V)/S[i].R) ;
 		}
 		
 		sort(S, S+n, [](const src &a, const src &b) { return (a.C<b.C) ; } ) ;
 		
 		printf("Case #%d: ", c) ;
 		if(S[n-1].C<X || S[0].C>X || !isOK(maxTime*1e+12))
 			puts("IMPOSSIBLE") ;
 		else
 		{
 			long double a = 0, b = maxTime*1e+12 ;
 			while(b-a>1e-11)
 			{
 				long double m = a+(b-a)/2 ;
 				if(isOK(m))
 					b = m ;
 				else
 					a = m ;
 			}
 			printf("%.13Lf\n", a+(b-a)/2) ;
 		}
 	}
 	
 	return 0 ;
 }
 
