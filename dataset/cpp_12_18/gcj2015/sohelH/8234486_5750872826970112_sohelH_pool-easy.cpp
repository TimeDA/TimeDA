#include<cstdio>
 #include<iostream>
 #include<queue>
 #include<stack>
 #include<vector>
 #include<string>
 #include<algorithm>
 #include<map>
 #include<sstream>
 #include<cmath>
 #include<cctype>
 #include<cassert>
 #include<cstring>
 #include<cstdlib>
 
 using namespace std;
 
 const int debug = 0;
 #define DEBUG(x) cout<<">> "<<#x<<':'<<(x)<<endl
 const int inf = 1000000000;
 
 vector<double> v;
 vector<double> c;
 int n;
 
 int main() {
 	int test, cases = 1;
 	cin >> test;
 	string imp = "IMPOSSIBLE";
 	for (cases = 1; cases <= test; cases++) {
 		v.clear();
 		c.clear();
 		double targetVolume, targetTemp;
 		cin >> n >> targetVolume >> targetTemp;
 		for (int i = 0; i < n; i++) {
 			double a, b;
 			cin >> a >> b;
 			v.push_back(a);
 			c.push_back(b);
 		}
 		printf("Case #%d: ", cases);
 		if (n == 1) {
 			if (fabs(targetTemp - c[0]) > 1e-9) {
 				cout << imp << endl;
 				continue;
 			}
 			double res = targetVolume / v[0];
 			printf("%.8lf\n", res);
 			continue;
 		} else {
 			// if both temp below or above, impossible
 			if ( fabs(targetTemp - c[0]) > 1e-9 && targetTemp > c[0] &&
 			     fabs(targetTemp - c[1]) > 1e-9 && targetTemp > c[1]) {
 					 	cout << imp << endl;
 					 	continue;
 					 }
 			if ( fabs(targetTemp - c[0]) > 1e-9 && targetTemp < c[0] &&
 			     fabs(targetTemp - c[1]) > 1e-9 && targetTemp < c[1]) {
 					 	cout << imp << endl;
 					 	continue;
 					 }
 
 			// if temp is same
 			if (fabs(c[0] - c[1]) < 1e-9) {
 				double res = targetVolume / (v[0] + v[1]);
 				printf("%.8lf\n", res);
 				continue;
 			} else if (fabs(c[0] - targetTemp) < 1e-9) {
 				double res = targetVolume / (v[0]);
 				printf("%.8lf\n", res);
 				continue;
 			} else if (fabs(c[1] - targetTemp) < 1e-9) {
 				double res = targetVolume / (v[1]);
 				printf("%.8lf\n", res);
 				continue;
 			} else {
 				double A = c[0] - targetTemp;
 				double B = c[1] - targetTemp;
 				if (debug) DEBUG(A), DEBUG(B);
 
 				double y = targetVolume * A / (A - B);
 				double x = targetVolume - y;
 
 				if (debug) DEBUG(x), DEBUG(y);
 				double t1 = x / v[0];
 				double t2 = y / v[1];
 
 				if (t1 < t2) t1 = t2;
 				printf("%.8lf\n", t1);
 			}
 		}
 
 
 
 	}
 	return 0;
 }
