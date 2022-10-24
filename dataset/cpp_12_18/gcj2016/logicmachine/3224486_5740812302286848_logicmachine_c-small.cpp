#include <iostream>
 #include <iomanip>
 #include <string>
 #include <vector>
 #include <queue>
 #include <array>
 #include <algorithm>
 #include <cmath>
 
 using namespace std;
 
 namespace lc {
 template <class T, class Func>
 T binary_search(T l, T r, Func f, int max_iter = 100){
 	for(int i = 0; i < max_iter; ++i){
 		const T c = l + (r - l) / 2;
 		if(f(c)){
 			r = c;
 		}else{
 			l = c;
 		}
 	}
 	return l;
 }
 }
 
 static double matrix[1000][1000];
 inline double pow2(double x){ return x * x; }
 
 void solve_single_case(){
 	using vec3 = array<double, 3>;
 	int n;
 	double s;
 	cin >> n >> s;
 	vector<vec3> pos(n), mov(n);
 	for(int i = 0; i < n; ++i){
 		for(int j = 0; j < 3; ++j){ cin >> pos[i][j]; }
 		for(int j = 0; j < 3; ++j){ cin >> mov[i][j]; }
 	}
 	auto compute_distance2 = [&](int i, int j, double t) -> double {
 		double d2 = 0.0;
 		for(int k = 0; k < 3; ++k){
 			const double a = pos[i][k] + t * mov[i][k];
 			const double b = pos[j][k] + t * mov[j][k];
 			d2 += pow2(a - b);
 		}
 		return d2;
 	};
 	for(int i = 0; i < n; ++i){
 		for(int j = 0; j < n; ++j){
 			matrix[i][j] = sqrt(compute_distance2(i, j, 0.0));
 		}
 	}
 	const double answer = lc::binary_search(0.0, 1e10, [&](double dlim) -> bool {
 		vector<bool> done(n, false);
 		queue<int> q;
 		done[0] = true;
 		q.push(0);
 		while(!q.empty()){
 			const int u = q.front();
 			q.pop();
 			for(int v = 0; v < n; ++v){
 				if(done[v] || matrix[u][v] > dlim){ continue; }
 				done[v] = true;
 				q.push(v);
 			}
 		}
 		return done[1];
 	});
 	cout << answer << endl;
 }
 
 int main(){
 	ios_base::sync_with_stdio(false);
 	cout << setiosflags(ios::fixed) << setprecision(10);
 	int T;
 	cin >> T;
 	for(int case_num = 1; case_num <= T; ++case_num){
 		cout << "Case #" << case_num << ": ";
 		solve_single_case();
 	}
 	return 0;
 }
 
