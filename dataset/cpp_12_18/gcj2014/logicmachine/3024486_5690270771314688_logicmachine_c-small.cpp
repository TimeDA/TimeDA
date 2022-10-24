#include <iostream>
 #include <string>
 #include <vector>
 #include <algorithm>
 #include <cstring>
 
 using namespace std;
 const int INF = 1000000000;
 int dp[16][1 << 15];
 
 template <typename T>
 class CoordinateCompressor {
 
 private:
 	vector<T> m_table;
 
 public:
 	CoordinateCompressor() : m_table() { }
 	template <typename Iterator>
 	CoordinateCompressor(Iterator first, Iterator last) :
 		m_table(first, last)
 	{
 		sort(m_table.begin(), m_table.end());
 		m_table.erase(unique(m_table.begin(), m_table.end()), m_table.end());
 	}
 	int compress(const T &x) const {
 		return lower_bound(
 			m_table.begin(), m_table.end(), x) - m_table.begin();
 	}
 	T decompress(int y) const { return m_table[y]; }
 	size_t size() const { return m_table.size(); }
 
 };
 
 int main(){
 	ios_base::sync_with_stdio(false);
 	int T;
 	cin >> T;
 	for(int caseNum = 1; caseNum <= T; ++caseNum){
 		int n;
 		cin >> n;
 		vector<int> t(n), id(n);
 		for(int i = 0; i < n; ++i){
 			string s;
 			int k;
 			cin >> s >> id[i];
 			t[i] = (s[0] == 'E' ? 1 : 0);
 		}
 		vector<int> comp_table(id);
 		comp_table.push_back(0);
 		const CoordinateCompressor<int> comp(
 			comp_table.begin(), comp_table.end());
 		for(int i = 0; i < n; ++i){ id[i] = comp.compress(id[i]) - 1; }
 		memset(dp, 0, sizeof(dp));
 		for(int i = 0; i < (1 << n); ++i){ dp[0][i] = 1; }
 		for(int i = 0; i < n; ++i){
 			if(t[i]){
 				for(int j = 0; j < n; ++j){
 					if(id[i] >= 0 && id[i] != j){ continue; }
 					const int mask = (1 << j);
 					for(int k = 0; k < (1 << n); ++k){
 						if(k & mask){ continue; }
 						dp[i + 1][k | mask] |= dp[i][k];
 					}
 				}
 			}else{
 				for(int j = 0; j < n; ++j){
 					if(id[i] >= 0 && id[i] != j){ continue; }
 					const int mask = (1 << j);
 					for(int k = 0; k < (1 << n); ++k){
 						if(!(k & mask)){ continue; }
 						dp[i + 1][k & ~mask] |= dp[i][k];
 					}
 				}
 			}
 		}
 		int answer = INF;
 		for(int i = 0; i < (1 << n); ++i){
 			if(dp[n][i]){ answer = min(answer, __builtin_popcount(i)); }
 		}
 		cout << "Case #" << caseNum << ": ";
 		if(answer >= INF){
 			cout << "CRIME TIME" << endl;
 		}else{
 			cout << answer << endl;
 		}
 	}
 	return 0;
 }
 
