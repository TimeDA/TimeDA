#include <iostream>
 #include <string>
 #include <cstdio>
 #include <vector>
 #include <cmath>
 #include <algorithm>
 #include <cstring>
 #include <stack>
 #include <queue>
 
 using namespace std ;
 
 int arr[11000] ;
 
 int main(void)
 {
 	int tc ;
 	cin >> tc ;
 	
 	for(int c=1;c<=tc;c++)
 	{
 		int n ;
 		cin >> n ;
 		int s ;
 		cin >> s ;
 		for(int i=0;i<n;i++)
 			cin >> arr[i] ;
 		sort(arr,arr+n) ;
 		int ans = 0 ;
 		int pos = 0 ;
 		for(int p=n-1;p>=pos;p--)
 		{
 			ans++ ;
 			if(p!=pos)
 			{
 				if(arr[p]+arr[pos]<=s)
 					pos++ ;
 			}
 		}
 		printf("Case #%d: %d\n",c,ans) ;
 	}
 	
 	return 0 ;
 }
