#include <cstdio>
 #include <vector>
 
 using namespace std;
 
 int a[5][5];
 
 int main() {
 	int T, v;
 	scanf("%d", &T);
 
 	for (int cn = 1; cn <= T; ++cn) {
 		vector<int> sum(20, 0);
 
 		printf("Case #%d: ", cn);
 		for (int trial = 0; trial < 2; ++trial)
 		{
 			scanf("%d", &v);
 			for (int i = 0; i < 4; ++i)
 				for (int j = 0; j < 4; ++j)
 				{
 					scanf("%d", &a[i][j]);
 					if (i == v - 1) sum[a[i][j]]++;
 				}
 		}
 
 		int numtwo = 0, ret = -1;
 		for (int i = 1; i <= 16; ++i)
 		{
 			if (sum[i] == 2) {
 				numtwo++;
 				ret = i;
 			}
 		}
 		if (numtwo >= 2) 
 		{ 
 			printf("Bad magician!\n"); 
 		}
 		else if (numtwo == 1) 
 		{ 
 			printf("%d\n", ret); 
 		}
 		else 
 		{ 
 			printf("Volunteer cheated!\n"); 
 		}
 	}
 }
 
