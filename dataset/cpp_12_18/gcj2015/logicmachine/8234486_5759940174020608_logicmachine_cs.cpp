#include <algorithm>
 #include <vector>
 #include <string>
 #include <sstream>
 #include <unordered_map>
 #include <iostream>
 namespace lc {
 class NameTable {
 private:
 	std::unordered_map<std::string, int> m_table;
 	std::vector<std::string> m_inv_table;
 public:
 	NameTable(){ }
 	int operator[](const std::string &s){
 		const auto it = m_table.find(s);
 		if(it != m_table.end()){ return it->second; }
 		const int t = m_inv_table.size();
 		m_table.insert(std::make_pair(s, t));
 		m_inv_table.push_back(s);
 		return t;
 	}
 	size_t size() const { return m_inv_table.size(); }
 };
 }
 using namespace std;
 int main(){
 	ios_base::sync_with_stdio(false);
 	int T;
 	cin >> T;
 	for(int case_num = 1; case_num <= T; ++case_num){
 		int n;
 		cin >> n;
 		string line;
 		getline(cin, line);
 		vector<string> raw_sentences(n);
 		for(int i = 0; i < n; ++i){ getline(cin, raw_sentences[i]); }
 		lc::NameTable word_table;
 		vector<vector<int>> sentences(n);
 		int m = 0;
 		for(int i = 0; i < n; ++i){
 			const int k = (i + 2) % n;
 			if(k == 0){ m = word_table.size(); }
 			istringstream iss(raw_sentences[k]);
 			string word;
 			while(iss >> word){
 				sentences[k].push_back(word_table[word]);
 			}
 		}
 		const int k = word_table.size();
 		vector<int> init(k);
 		for(const int w : sentences[0]){ init[w] |= 1; }
 		for(const int w : sentences[1]){ init[w] |= 2; }
 		int offset = 0;
 		for(int i = m; i < k; ++i){
 			if(init[i] == 3){ ++offset; }
 		}
 		int answer = offset + m;
 		for(int i = 0; i < (1 << (n - 2)); ++i){
 			vector<int> work(init.begin(), init.begin() + m);
 			for(int j = 2; j < n; ++j){
 				const int f = (i & (1 << (j - 2))) ? 2 : 1;
 				for(const int w : sentences[j]){ work[w] |= f; }
 			}
 			int local = offset;
 			for(int j = 0; j < m; ++j){
 				if(work[j] == 3){ ++local; }
 			}
 			answer = min(answer, local);
 		}
 		cout << "Case #" << case_num << ": " << answer << endl;
 	}
 	return 0;
 }
