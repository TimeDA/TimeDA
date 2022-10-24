#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
#define CLR(a,x) memset(a, x, sizeof(a))
#define EXP(i,l) for (int i=(l); i; i=qn[i])
#define LLD long long
#define RI(x) scanf("%d", &x)
#define PB push_back
using namespace std;

int dp[555][555], n, m;

int buf[555][555];


int main(){
	
	FOE(i,0,32){
	    FOD(nn,501,0) FOD(mm,501,0) buf[nn][mm] = dp[nn][mm];
        FOE(j,0,32) if (i+j > 0){
			int sn = i * (j + 1);
			int sm = j * (j + 1) / 2;

			int add;
			if (i == 0) add = j;
			else add = j + 1;

			FOD(nn,501,sn) FOD(mm,501,sm){
				dp[nn][mm] = max(dp[nn][mm], buf[nn-sn][mm-sm] + add);
			}
		}
	}
	
	
	int tc;scanf("%d", &tc);FOE(TC,1,tc){printf("Case #%d: ", TC);
		RI(n), RI(m);
		printf("%d\n", dp[n][m]);
	}

	return 0;
}