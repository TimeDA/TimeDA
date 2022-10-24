#include <bits/stdc++.h>
using namespace std;

int main(){
    int T; cin >> T;
    string input;
    for(int case_nb = 1; case_nb <= T; ++case_nb){
        double D; cin >> D;
        int N; cin >> N;
        double earliest_arrival = 0;
        for(int i = 0; i < N; ++i){
            double K, S; cin >> K >> S;
            double arrival = (D - K) / S;
            earliest_arrival = max(earliest_arrival, arrival);
        }
        cout << "Case #" << case_nb << ": ";
        cout << fixed << setprecision(10) << (D / earliest_arrival);
        cout << endl;
    }
    return 0;
}