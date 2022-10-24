#include <bits/stdc++.h>
using namespace std;

int main(){
    int T; cin >> T;
    string input;
    for(int case_nb = 1; case_nb <= T; ++case_nb){
        int A, B; cin >> A >> B;
        int N; cin >> N;
        int nb_interactions = 0;
        getline(cin, input);
        while(A < B && nb_interactions < N){
            ++nb_interactions;
            int Q = (A+B + 1)/2;
            cout << Q << endl;
            getline(cin, input);
            if(input == "WRONG_ANSWER"){
                cerr << "Got wrong answer" << endl;
                return 0;
            }else if(input == "TOO_SMALL"){
                A = Q;
            }else if(input == "TOO_BIG"){
                B = Q - 1;
            }else if(input == "CORRECT"){
                cerr << "Got it correct after " << nb_interactions << " out of " << N << " attempts." << endl;
                break;
            }
        }
    }
    return 0;
}