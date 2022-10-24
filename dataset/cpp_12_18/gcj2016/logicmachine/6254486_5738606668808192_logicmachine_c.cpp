#include <utility>
 #include <algorithm>
 #include <vector>
 #include <string>
 #include <iostream>
 namespace lc {
 template <typename T>
 std::vector<int> eratosthenes(T &sieve){
 	const int n = sieve.size();
 	for(int i = 0; i < n; ++i){ sieve[i] = 1; }
 	sieve[0] = sieve[1] = 0;
 	std::vector<int> primes;
 	for(int i = 2; i < n; ++i){
 		if(!sieve[i]){ continue; }
 		primes.push_back(i);
 		for(int j = i + i; j < n; j += i){ sieve[j] = 0; }
 	}
 	return primes;
 }
 std::vector<int> eratosthenes(int n){
 	std::vector<bool> sieve(n);
 	return eratosthenes(sieve);
 }
 }
 using namespace std;
 int main(){
 	ios_base::sync_with_stdio(false);
 	const auto primes = lc::eratosthenes(10000);
 	const int np = primes.size();
 	int T, n, m;
 	cin >> T >> n >> m;
 	vector<vector<int>> offsets(np, vector<int>(11));
 	for(int i = 0; i < np; ++i){
 		const int p = primes[i];
 		for(int j = 2; j <= 10; ++j){
 			int x = 1;
 			for(int k = 1; k < n; ++k){
 				x = (x * j) % p;
 			}
 			offsets[i][j] = x;
 		}
 	}
 	cout << "Case #1:" << endl;
 	for(int i = 1, j = 0; j < m; i += 2){
 		int proof[11];
 		uint32_t x = (1u << (n - 1)) | i;
 		bool accept = true;
 		for(int b = 2; accept && b <= 10; ++b){
 			uint64_t y = 0;
 			for(int k = n - 2; k >= 0; --k){
 				y = (y * b) + ((x >> k) & 1);
 			}
 			proof[b] = 0;
 			for(int k = 0; k < np; ++k){
 				const int p = primes[k];
 				if((y + offsets[k][b]) % p == 0){
 					proof[b] = p;
 					break;
 				}
 			}
 			if(proof[b] == 0){
 				accept = false;
 			}
 		}
 		if(accept){
 			for(int k = n - 1; k >= 0; --k){ cout << ((x >> k) & 1); }
 			for(int k = 2; k <= 10; ++k){ cout << " " << proof[k]; }
 			cout << endl;
 			bool valid = true;
 			for(int k = 2; k <= 10; ++k){
 				const int p = proof[k];
 				int sum = 0;
 				for(int s = n - 1; s >= 0; --s){
 					sum = (sum * k + ((x >> s) & 1)) % p;
 				}
 				if(sum != 0){
 					cout << "FAIL on " << k << endl;
 				}
 			}
 			if(!valid){ cout << "ERROR" << endl; return 0; }
 			++j;
 		}
 	}
 	return 0;
 }
