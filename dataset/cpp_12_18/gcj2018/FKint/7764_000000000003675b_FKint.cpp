#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
#define ENDL "\n"

bool valid_interval_with_both(int left, int right, vector<int> &ms, vector<int> &ns, int m, int n)
{
    for (int i = left; i < right; ++i)
    {
        if (ms[i] != m && ns[i] != n)
            return false;
    }
    return true;
}
bool valid_interval_with_first(int left, int right, vector<int> &ms, vector<int> &ns, int m)
{
    for (int i = left; i < right; ++i)
    {
        if (ms[i] != m)
        {
            return valid_interval_with_both(i + 1, right, ms, ns, m, ns[i]);
        }
    }
    return true;
}
bool valid_interval(int left, int right, vector<int> &ms, vector<int> &ns)
{
    return valid_interval_with_first(left, right, ms, ns, ms[left]) || valid_interval_with_first(left, right, ns, ms, ns[left]);
}

pair<int, int> find_best_intervals(int S, vector<int> &ms, vector<int> &ns)
{
    // map<int, int> m_options;
    // map<int, int> n_options;
    // int left = 0;
    pair<int, int> result(2, S-1);
    for (int interval_length = 3; interval_length <= S; ++interval_length)
    {
        int nb_valid_of_length = 0;
        for (int start = 0; start + interval_length <= S; ++start)
        {
            if (valid_interval(start, start + interval_length, ms, ns))
            {
                // cerr << start << " -> " << start + interval_length << " is valid" << endl;
                ++nb_valid_of_length;
            }else{
                // cerr << start << " -> " << start + interval_length << " is not valid" << endl;
            }
        }
        if (nb_valid_of_length == 0)
        {
            break;
        }
        else
        {
            result = make_pair(interval_length, nb_valid_of_length);
        }
    }
    return result;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    for (int curr_case = 1; curr_case <= T; ++curr_case)
    {
        int S;
        cin >> S;
        vector<int> ns;
        vector<int> ms;

        for (int i = 0; i < S; ++i)
        {
            int D, A, B;
            cin >> D >> A >> B;
            ms.push_back(D + A);
            ns.push_back(D - B);
        }

        cout << "Case #" << curr_case << ": ";
        if (S == 1)
        {
            cout << "1 1";
        }
        else
        {
            // pair<int, int> best(2, S - 1);
            pair<int, int> best = find_best_intervals(S, ns, ms);
            // best = max(best, min3_best);
            cout << best.first << " " << best.second;
        }
        cout << ENDL;
    }
    return 0;
}
