#include <iostream>
 #include <iomanip>
 #include <string>
 #include <vector>
 #include <algorithm>
 #include <atomic>
 
 using namespace std;
 
 static double comb[201][201] = { { 0.0 } };
 
 inline unsigned int xorshift128(){
 	static uint32_t x = 192479812;
 	static uint32_t y = 784892731;
 	static uint32_t z = 427398108;
 	static uint32_t w = 48382934; 
 	const uint32_t t = x ^ (x << 11);
 	x = y; y = z; z = w;
 	w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)); 
 	return w;
 }
 
 int count_descendants(
 	vector<int> &result, int u, const vector<vector<int>> &conn)
 {
 	int c = 1;
 	for(const auto v : conn[u]){
 		c += count_descendants(result, v, conn);
 	}
 	result[u] = c;
 	return c;
 }
 
 double count_ways(
 	vector<double> &result,
 	int u,
 	const vector<vector<int>> &conn,
 	const vector<int> &num_descendants)
 {
 	int c = 1;
 	double w = 1.0;
 	for(const auto v : conn[u]){
 		w *= count_ways(result, v, conn, num_descendants);
 		const int x = num_descendants[v];
 		w *= comb[x + c - 1][x];
 		c += x;
 	}
 	result[u] = w;
 	return w;
 }
 
 void solve_single_case(){
 	int n;
 	cin >> n;
 	vector<int> parent(n);
 	for(int i = 0; i < n; ++i){ cin >> parent[i]; --parent[i]; }
 	string heads;
 	cin >> heads;
 	int m;
 	cin >> m;
 	vector<string> words(m);
 	for(int i = 0; i < m; ++i){ cin >> words[i]; }
 
 	vector<vector<int>> conn(n);
 	vector<int> roots;
 	for(int i = 0; i < n; ++i){
 		if(parent[i] >= 0){
 			conn[parent[i]].push_back(i);
 		}else{
 			roots.push_back(i);
 		}
 	}
 
 	vector<int> num_descendants(n);
 	for(const int r : roots){
 		count_descendants(num_descendants, r, conn);
 	}
 	vector<double> ways(n);
 	for(const int r : roots){
 		count_ways(ways, r, conn, num_descendants);
 	}
 
 	const int NUM_ITERATION = 10000;
 	atomic<int> answer[5];
 	for(int i = 0; i < 5; ++i){ answer[i] = 0; }
 #pragma omp parallel for
 	for(int iter = 0; iter < NUM_ITERATION; ++iter){
 		vector<int> next_set = roots;
 		vector<char> str;
 		next_set.reserve(n + 1);
 		str.reserve(n + 1);
 
 		for(int i = 0; i < n; ++i){
 			const int m = next_set.size();
 			vector<double> probs;
 			probs.reserve(m);
 			double psum = 0.0;
 			for(int j = 0; j < m; ++j){
 				int c = 1;
 				double w = 1.0;
 				for(int k = 0; k < m; ++k){
 					if(k == j){ continue; }
 					w *= ways[next_set[k]];
 					const int t = num_descendants[next_set[k]];
 					w *= comb[t + c - 1][t];
 					c += t;
 				}
 				for(const int u : conn[next_set[j]]){
 					w *= ways[u];
 					const int t = num_descendants[u];
 					w *= comb[t + c - 1][t];
 					c += t;
 				}
 				probs.push_back(w);
 				psum += w;
 			}
 
 			const double q =
 				xorshift128() / static_cast<double>(0xffffffffu) * psum;
 			double sum = 0.0;
 			int next = 0;
 			while(next + 1 < m){
 				sum += probs[next];
 				if(q < sum){ break; }
 				++next;
 			}
 
 			const int u = next_set[next];
 			next_set[next] = next_set[m - 1];
 			next_set.pop_back();
 			for(const int v : conn[u]){ next_set.push_back(v); }
 			str.push_back(heads[u]);
 		}
 		str.push_back('\0');
 		string s = str.data();
 		for(int i = 0; i < m; ++i){
 			if(s.find(words[i]) != string::npos){ answer[i]++; }
 		}
 	}
 	for(int i = 0; i < m; ++i){
 		if(i != 0){ cout << " "; }
 		cout << static_cast<double>(answer[i].load()) / NUM_ITERATION;
 	}
 	cout << endl;
 }
 
 int main(){
 	ios_base::sync_with_stdio(false);
 	cout << setiosflags(ios::fixed) << setprecision(10);
 	comb[0][0] = 1.0;
 	for(int i = 1; i < 200; ++i){
 		comb[i][0] = 1.0;
 		for(int j = 1; j <= i; ++j){
 			comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
 		}
 	}
 	int T;
 	cin >> T;
 	for(int case_num = 1; case_num <= T; ++case_num){
 		cout << "Case #" << case_num << ": ";
 		solve_single_case();
 	}
 	return 0;
 }
 
 
