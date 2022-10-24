#include <bits/stdc++.h>
 #include <cstdio>
 using namespace std;
 
 #define MAXVAL 1000000
 #define MAXN 10000
 
 set<int> get_words(string line, map<string, int> &dictionary){
 	set<int> result;
 	stringstream ss;
 	ss << line;
 	while(!ss.eof()){
 		string s;
 		ss >> s;
 		if(dictionary.count(s) == 0)
 			dictionary[s] = dictionary.size();
 		result.insert(dictionary[s]);
 	}
 	return result;
 }
 
 void add_all(set<int> &s, set<int> &new_strings){
 	for(set<int>::iterator it = new_strings.begin(); it != new_strings.end(); ++it){
 		s.insert(*it);
 	}
 }
 
 int is_french[MAXN];
 int is_english[MAXN];
 
 int calculate(set<int> &french_sure, set<int> &english_sure, vector<set<int> > &sentences, int mask, int best_so_far){
 	for(set<int>::iterator it = french_sure.begin(); it != french_sure.end(); ++it){
 		is_french[*it] = mask;
 	}
 	for(set<int>::iterator it = english_sure.begin(); it != english_sure.end(); ++it){
 		is_english[*it] = mask;
 	}
 	int result = 0;
 	for(int i = 0; i < sentences.size(); ++i){
 		for(set<int>::iterator it = sentences[i].begin(); it != sentences[i].end(); ++it){
 			if(mask & (1<<i)){
 				if(is_english[*it] != mask  && is_french[*it] == mask){
 					result ++;
 					if(best_so_far <= result)
 						return best_so_far;
 				}
 				is_english[*it] = mask;
 			}else{
 				if(is_french[*it] != mask && is_english[*it] == mask){
 					result++;
 					if(best_so_far <= result)
 						return best_so_far;
 				}
 				is_french[*it] = mask;
 			}
 		}
 	}
 	return result;
 }
 
 int intersection_size(set<int> &a, set<int> &b){
 	int amount = 0;
 	for(set<int>::iterator it = a.begin(); it != a.end(); ++it){
 		if(b.count(*it) > 0)
 			++amount;
 	}
 	return amount;
 }
 
 int main(){
 	std::ios::sync_with_stdio(false);
 	int nb_test_cases;
 	cin >> nb_test_cases;
 	for(int current_test_case = 1; current_test_case <= nb_test_cases; ++ current_test_case){
 		int N;
 		cin >> N;
 		string line1;
 		getline(cin, line1);
 		getline(cin, line1);
 		string line2;
 		getline(cin, line2);
 
 		map<string, int> dictionary;
 		set<int> french_sure = get_words(line2, dictionary);
 		set<int> english_sure = get_words(line1, dictionary);
 		vector<set<int> > sentences;
 		for(int i = 2; i < N; ++i){
 			string line;
 			getline(cin, line);
 			sentences.push_back(get_words(line, dictionary));
 		}
 		int default_overlap = intersection_size(french_sure, english_sure);
 		for(int i = 0; i < dictionary.size(); ++i){
 			is_french[i] = -1;
 			is_english[i] = -1;
 		}
 		cout << "Case #" << current_test_case << ": ";
 		if(N == 2){
 			cout << default_overlap;
 		}else{
 			int result = MAXVAL;
 			for(int i = 0; i < (1<<(N-2)); ++i){
 				result = min(result, calculate(french_sure, english_sure, sentences, i, result - default_overlap) + default_overlap);
 			}
 			cout << result;
 		}
 		cout << endl;
 	}
     return 0;
 }
