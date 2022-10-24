#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
#define CLR(a,x) memset(a, x, sizeof(a))
#define EXP(i,l) for (int i=(l); i; i=qn[i])
#define LLD long long
#define RI(x) scanf("%d", &x)
#define PB push_back
using namespace std;

double A, t;
const double PI = acos(-1);

int main(){int tc;scanf("%d", &tc);FOE(TC,1,tc){printf("Case #%d:\n", TC);
	scanf("%lf", &A);
	t = asin(A / sqrt(2.0)) - PI / 4.0;
	if (t < 0) t = 0;
	if (t > PI/2) t = PI/2;
	printf("%.18f %.18f %.18f\n", 0, 0, 0.5);
	printf("%.18f %.18f %.18f\n", sin(t)/2, cos(t)/2, 0);
	printf("%.18f %.18f %.18f\n", cos(t)/2, -sin(t)/2, 0);
}return 0;}