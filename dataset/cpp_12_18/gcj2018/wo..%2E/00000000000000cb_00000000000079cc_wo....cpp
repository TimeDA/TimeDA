#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

typedef double Real;

Real A;

const Real C = sqrt(3);
const Real alpha = asin(1.0 / C);
const Real S = sqrt(2);

vector<Real> ans[3];

void solve(){
	Real tmp = A / C;
	if(tmp > 1) tmp = 1;
	Real d = acos(tmp);
	Real theta = d + alpha;
	for(int i = 0; i < 3; ++i) ans[i] = vector<Real>(3);
	ans[0][0] = cos(theta) / (S * 2);
	ans[0][1] = sin(theta) / 2;
	ans[0][2] = -ans[0][0];
	ans[1][0] = (1 + sin(theta)) / 4;
	ans[1][1] = -S * cos(theta) / 4;
	ans[1][2] = (1 - sin(theta)) / 4;
	ans[2][0] = (-1 + sin(theta)) / 4;
	ans[2][1] = -S * cos(theta) / 4;
	ans[2][2] = (-1 - sin(theta)) / 4;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		scanf("%lf", &A);
		solve();
		printf("Case #%d:\n", t + 1);
		for(int i = 0; i < 3; ++i){
			for(int j = 0; j < 3; ++j){
				printf("%.12f%c", ans[i][j], j == 2 ? '\n' : ' ');
			}
		}
	}
	return 0;
}
