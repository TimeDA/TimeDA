#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
#define ENDL "\n"

int get_percentage(int nb_votes, int total_nb_votes)
{
    return ((200 * nb_votes) / total_nb_votes + 1) / 2;
}

bool is_rounded_down(int nb_votes, int total_nb_votes)
{
    return get_percentage(nb_votes, total_nb_votes) * total_nb_votes < 100 * nb_votes;
}

bool is_rounded_up(int nb_votes, int total_nb_votes)
{
    return get_percentage(nb_votes, total_nb_votes) * total_nb_votes > 100 * nb_votes;
}

int get_transition_requirement(int nb_votes, int total_nb_votes, vector<int> &minimal_needed_for_percentage)
{
    if (is_rounded_up(1, total_nb_votes))
    {
        return 0;
    }
    int current_percentage = get_percentage(nb_votes, total_nb_votes);
    for (int i = current_percentage + 1; i <= 100; ++i)
    {
        int minimal_needed = minimal_needed_for_percentage[i] - nb_votes;
        if (is_rounded_up(nb_votes + minimal_needed, total_nb_votes))
        {
            return minimal_needed;
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    for (int curr_case = 1; curr_case <= T; ++curr_case)
    {
        cout << "Case #" << curr_case << ": ";
        int N, L;
        cin >> N >> L;
        vector<int> votes(L);
        int nb_votes_remaining = N;
        map<int, int> transition_requirements;
        int sum_percentages = 0;

        vector<int> minimal_needed_for_percentage(101, N);
        for (int i = 0; i <= N; ++i)
        {
            int p = get_percentage(i, N);
            minimal_needed_for_percentage[p] = min(i, minimal_needed_for_percentage[p]);
        }
        for (int i = 99; i >= 0; --i)
        {
            minimal_needed_for_percentage[i] = min(minimal_needed_for_percentage[i], minimal_needed_for_percentage[i + 1]);
        }

        for (int i = 0; i < L; ++i)
        {
            cin >> votes[i];
            nb_votes_remaining -= votes[i];
            sum_percentages += get_percentage(votes[i], N);
            if (is_rounded_down(votes[i], N))
            {
                int nb_needed = get_transition_requirement(votes[i], N, minimal_needed_for_percentage);
                // cerr << votes[i] << " out of " << N << ": needs " << nb_needed << " more votes to be rounded up" << endl;
                if (nb_needed)
                {
                    transition_requirements[nb_needed]++;
                }
            }
        }
        // cerr << "Current sum of percentages: " << sum_percentages << endl;
        if (is_rounded_up(1, N))
        {
            // cerr << "Groups of single votes are rounded up." << endl;
            sum_percentages += get_percentage(1, N) * nb_votes_remaining;
        }
        else
        {
            // cerr << "Groups of single votes are not rounded up, so try to combine them." << endl;
            int minimal_group_size = get_transition_requirement(1, N, minimal_needed_for_percentage);
            if(minimal_group_size) minimal_group_size ++;
            // cerr << "Minimal group size: " << minimal_group_size << endl;
            for (const auto &x : transition_requirements)
            {
                if (x.first >= minimal_group_size)
                    break;
                int nb_groups = min(nb_votes_remaining / x.first, x.second);
                nb_votes_remaining -= nb_groups * x.first;
                sum_percentages += nb_groups * (get_percentage(x.first, N) + 1);
            }
            if(minimal_group_size){
                int nb_separate_groups = nb_votes_remaining / minimal_group_size;
                sum_percentages += get_percentage(minimal_group_size, N) * nb_separate_groups;
                nb_votes_remaining -= nb_separate_groups * minimal_group_size;
            }
            sum_percentages += get_percentage(1, N) * nb_votes_remaining;
        }
        cout << sum_percentages;
        cout << ENDL;
    }
    return 0;
}
