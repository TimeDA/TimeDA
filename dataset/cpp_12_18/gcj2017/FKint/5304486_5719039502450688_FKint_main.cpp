#include <vector>
 #include <map>
 #include <set>
 #include <iostream>
 #include <iomanip>
 #include <queue>
 #include <string>
 #include <stack>
 #include <list>
 #include <algorithm>
 #include <functional>
 #include <utility>
 #include <random>
 #include <cmath>
 #include <cstdio>
 #include <numeric>
 #include <iterator>
 using namespace std;
 
 #define MAXV 1000000000
 
 long long get_turns_after_debuffs(long long start_health, long long Hd, long long Ad, long long Hk, long long Ak, long long B){
 	return 0;
 }
 
 long long get_min_turns(long long Hd, long long Ad, long long Hk, long long Ak, long long B, long long D){
 	// one blow and the knight is dead
 	if(Hk<=Ad) 
 		return 1;
 	// can't kill the knight in one blow and even when making the knight weaker, it still kills the poor dragon immediately :(
 	if(Hd<=Ak-D) 
 		return 0;
 	// debuff once, cure next, debuff again -> knight has attacked twice (once with Ak-D and once with Ak-2D) after the cure
 	if(Hd<=Ak-D + Ak - D - D)
 		return 0;
 	
 	long long max_debuffs = 0;
 	if(D > 0){
 		max_debuffs = (Ak + D - 1) / D;
 	}
 	long long nb_cures_before_buffs = 0;
 	// without debuffs
 	long long best = get_turns_after_debuffs(Hd, Hd, Ad, Hk, Ak, B);
 
 	long long current_health = Hd;
 	for(long long nb_debuffs = 1; nb_debuffs <= max_debuffs; ++nb_debuffs){
 		long long before_remaining_knight_attack = Ak - (nb_debuffs - 1) * D;
 		long long after_remaining_knight_attack = Ak - nb_debuffs * D;
 		if(current_health <= after_remaining_knight_attack){
 			++nb_cures_before_buffs;
 			current_health = Hd - before_remaining_knight_attack;
 		}
 		current_health -= after_remaining_knight_attack;
 		long long nb_extra_turns = get_turns_after_debuffs(current_health, Hd, Ad, Hk, after_remaining_knight_attack, B);
 
 		best = min(best, nb_extra_turns + nb_debuffs + nb_cures_before_buffs);
 	}
 	return best;
 }
 
 
 long long simulate(long long nb_debuffs, long long nb_buffs, long long Hd, long long Ad, long long Hk, long long Ak, long long B, long long D){
 	long long total_turns = 0;
 	long long current_dragon_health = Hd;
 	long long current_dragon_attack = Ad;
 	long long current_knight_health = Hk;
 	long long current_knight_attack = Ak;
 	for(long long i = 0; i < nb_debuffs; ++i){
 		if(current_dragon_health <= current_knight_attack - D){
 			++total_turns; // cure
 			current_dragon_health = Hd - current_knight_attack;
 		}
 		++total_turns; // debuff
 		current_knight_attack = max(0ll, current_knight_attack - D);
 		current_dragon_health -= current_knight_attack;
 		if(current_dragon_health <= 0)
 			return 0;
 	}
 
 	for(long long i = 0; i < nb_buffs; ++i){
 		if(current_dragon_health <= current_knight_attack){
 			++total_turns; // cure
 			current_dragon_health = Hd - current_knight_attack;
 		}
 		++total_turns; // buff
 		current_dragon_attack += B;
 		current_dragon_health -= current_knight_attack;
 		if(current_dragon_health <= 0)
 			return 0;
 	}
 	while(true){
 		if(current_dragon_health <= current_knight_attack && current_knight_health > current_dragon_attack){
 			++total_turns; // cure
 			current_dragon_health = Hd - current_knight_attack;
 		}
 		++total_turns; // attack
 		current_knight_health -= current_dragon_attack;
 		if(current_knight_health <= 0)
 			return total_turns;
 		current_dragon_health -= current_knight_attack;
 		if(current_dragon_health <= 0)
 			return 0;
 	}
 }
 
 int main(){
 	std::ios::sync_with_stdio(false);
 	int nb_test_cases; cin >> nb_test_cases;
 	for(int test_case_id = 1; test_case_id <= nb_test_cases; ++test_case_id){
 		long long Hd, Ad, Hk, Ak, B, D;
 		cin >> Hd >> Ad >> Hk >> Ak >> B >> D;
 
 		long long best = 4ll*MAXV;
 		for(int i = 0; i <= 100; ++i){
 			for(int j = 0; j <= 100; ++j){
 				long long v = simulate(i, j, Hd, Ad, Hk, Ak, B, D);
 				if(v > 0){
 					best = min(best, v);
 				}
 			}
 		}
 		cout << "Case #" << test_case_id << ": ";
 		if(best == 4ll * MAXV){
 			cout << "IMPOSSIBLE";
 		}else{
 			cout << best;
 		}
 		cout << endl;
 		
 	}
     return 0;
 }
