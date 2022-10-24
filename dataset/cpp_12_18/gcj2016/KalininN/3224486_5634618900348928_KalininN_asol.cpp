#include <bits/stdc++.h>
 
 using namespace std;
 
 using ll = long long;
 using ld = long double;
 using D = double;
 using uint = unsigned int;
 
 #ifdef WIN32
     #define LLD "%I64d"
 #else
     #define LLD "%lld"
 #endif
 
 #define pb push_back
 #define mp make_pair
 #define all(x) (x).begin(),(x).end()
 #define fi first
 #define se second
 
 const int maxn = 200005;
 
 vector<int> st;
 char s[maxn];
 
 int main()
 {
     int NT = 0;
     scanf("%d", &NT);
     for (int T = 1; T <= NT; T++)
     {
         printf("Case #%d:", T);
         
 		scanf("%s", s);
 		int n = strlen(s);
 		while (!st.empty()) st.pop_back();
 		int answer = 0;
 		for (int i = 0; i < n; i++)
 		{
 			if (!st.empty() && s[i] == st.back())
 			{
 				answer += 10;
 				st.pop_back();
 			} else if (st.size() == (n - i))
 			{
 				answer += 5;
 				st.pop_back();
 			} else st.push_back(s[i]);
 		}
 		printf(" %d\n", answer);
 		
         fprintf(stderr, "%d/%d cases done!\n", T, NT);
     }
     return 0;
 }
