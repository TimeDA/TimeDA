#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
#define ENDL "\n"
int sum_up_to(int nb_other_color, int n){ 
    if(nb_other_color > 0)
        n--;
    return n*(n+1)/2; 
}
int get_best_allocation(int R, int B, int curr_nb_of_red_per_juggler, vector<vector<vector<int>>>& dp){
    if(dp[R][B][curr_nb_of_red_per_juggler] < 0){
        int best = 0;
        if(curr_nb_of_red_per_juggler == 0 && B == 0){
            return get_best_allocation(R,B,1,dp);
        }
        for(int i = 1; sum_up_to(curr_nb_of_red_per_juggler, i) <= B && i * curr_nb_of_red_per_juggler <= R; ++i){
            int result = i + get_best_allocation(R - i*curr_nb_of_red_per_juggler, B - sum_up_to(curr_nb_of_red_per_juggler, i), curr_nb_of_red_per_juggler + 1, dp);
            best = max(best, result);
        }
        dp[R][B][curr_nb_of_red_per_juggler] = best;
    }
    return dp[R][B][curr_nb_of_red_per_juggler];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    vector<vector<vector<int>>> dp(501, vector<vector<int>>(501, vector<int>(501, -1)));
    for (int curr_case = 1; curr_case <= T; ++curr_case)
    {
        int R, B; cin >> R >> B;
        cout << "Case #" << curr_case << ": ";
        int best = get_best_allocation(R,B,0,dp);
        cout << best;
        cout << ENDL;
    }
    return 0;
}
