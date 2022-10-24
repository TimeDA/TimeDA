#include <iostream>
 #include <string>
 #include <cstdio>
 #include <vector>
 #include <cmath>
 #include <algorithm>
 #include <cstring>
 
 using namespace std ;
 
 int arr[1100] ;
 
 int main(void)
 {
 	int tc ;
 	cin >> tc ;
 	
 	for(int c=1;c<=tc;c++)
 	{
 		int n ;
 		cin >> n ;
 		for(int i=0;i<n;i++)
 			cin >> arr[i] ;
 		int s = 0, t = n ;
 		int ans = 0 ;
 		for(int iii=0;iii<n;iii++)
 		{
 			int sm = s ;
 			for(int i=s+1;i<t;i++)
 				if(arr[i]<arr[sm])
 					sm = i ;
 			if(sm-s<=t-sm-1)
 			{
 				ans += sm-s ;
 				for(int i=sm;i>0;i--)
 					arr[i] = arr[i-1] ;
 				s++ ;
 			}
 			else
 			{
 				ans += t-sm-1 ;
 				for(int i=sm;i+1<t;i++)
 					arr[i] = arr[i+1] ;
 				t-- ;
 			}
 		}
 		printf("Case #%d: %d\n",c,ans) ;
 	}
 	
 	return 0 ;
 }
