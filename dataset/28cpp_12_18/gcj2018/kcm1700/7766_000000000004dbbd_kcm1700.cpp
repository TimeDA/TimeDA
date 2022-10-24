#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <numeric>
#include <functional>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <thread>
#include <tuple>
#include <utility>
#include <limits>

using namespace std;

struct MaxFlowDinic {
    typedef long long cap_t;

    struct Edge
    {
        int next;
        int inv; /* inverse edge index */
        cap_t res; /* residual */
        cap_t save; /* save whatever you want. TODO: just remove if you don't need */
    };

    int n;
    vector<vector<Edge>> graph;

    vector<int> q, l, start;

    void init(int _n) {
        n = _n;
        graph.resize(n);
        for(int i = 0; i < n; i++) graph[i].clear();
    }
    void addNodes(int count) {
        n += count;
        graph.resize(n);
    }

    void addEdgeSave(int s, int e, cap_t cap, cap_t save) {
        Edge forward = { e, (int)graph[e].size() + (s == e ? 1 : 0), cap, save};
        Edge reverse = { s, (int)graph[s].size(), 0, -1};
        graph[s].push_back(forward);
        graph[e].push_back(reverse);
    }

    void addEdge(int s, int e, cap_t cap, cap_t caprev = 0) {
        Edge forward = { e, (int)graph[e].size() + (s == e ? 1 : 0), cap, -1};
        Edge reverse = { s, (int)graph[s].size(), caprev, -1};
        graph[s].push_back(forward);
        graph[e].push_back(reverse);
    }

    bool assignLevel(int source, int sink) {
        int t = 0;
        l.assign(n, 0);
        l[source] = 1;
        q[t++] = source;
        for(int h = 0; h < t && !l[sink]; h++) {
            int cur = q[h];
            for (const auto &edge : graph[cur]) {
                int next = edge.next;
                if (l[next]) continue;
                if (edge.res > 0) {
                    l[next] = l[cur] + 1;
                    q[t++] = next;
                }
            }
        }
        return l[sink] != 0;
    }

    cap_t blockFlow(int cur, int sink, cap_t currentFlow) {
        if (cur == sink) return currentFlow;
        for (auto &i = start[cur]; i < (int)graph[cur].size(); i++) {
            int next = graph[cur][i].next;
            if (graph[cur][i].res == 0 || l[next] != l[cur]+1)
                continue;
            if (cap_t res = blockFlow(next, sink, min(graph[cur][i].res, currentFlow))) {
                int inv = graph[cur][i].inv;
                graph[cur][i].res -= res;
                graph[next][inv].res += res;
                return res;
            }
        }
        return 0;
    }

    cap_t solve(int source, int sink)
    {
        if (source == sink) {
            // invalid case
            return -1;
        }
        q.resize(n);
        l.resize(n);
        cap_t ans = 0;
        while (assignLevel(source, sink)) {
            start.assign(n, 0);
            while (cap_t flow = blockFlow(source, sink, numeric_limits<cap_t>::max())) {
                ans += flow;
            }
        }
        return ans;
    }
};

struct MaxFlowEdgeDemand {
    typedef MaxFlowDinic::cap_t cap_t;
    MaxFlowDinic mf;

    vector<cap_t> nodeSum;

    void init(int _n) {
        mf.init(_n + 2);
        nodeSum.resize(_n + 2);
    }

    void addNodes(int count) {
        mf.addNodes(count);
        nodeSum.resize(mf.n + 2);
    }

    void addEdgeSave(int s, int e, cap_t demand, cap_t capacity, cap_t save) {
        mf.addEdgeSave(s + 2, e + 2, capacity - demand, save);
        nodeSum[s + 2] -= demand;
        nodeSum[e + 2] += demand;
    }

    void addEdge(int s, int e, cap_t demand, cap_t capacity) {
        mf.addEdge(s + 2, e + 2, capacity - demand);
        nodeSum[s + 2] -= demand;
        nodeSum[e + 2] += demand;
    }

    // -1 if it is impossible to satisfy demand
    // return max flow.
    cap_t solveFeasibility(int source, int sink) {
        mf.addEdge(sink + 2, source + 2, numeric_limits<cap_t>::max());
        cap_t saturation = 0;
        for (int i = 2; i < (int)nodeSum.size(); i++) {
            auto cap = nodeSum[i];
            if (cap == 0) continue;
            if (cap < 0) {
                mf.addEdgeSave(i, 1, -cap, -cap);
            } else if (cap > 0) {
                mf.addEdgeSave(0, i, cap, cap);
                saturation += cap;
            }
        }
        cap_t result = mf.solve(0, 1);
        if (result != saturation) {
            return -1;
        }
        cap_t maxFlow = mf.solve(source + 2, sink + 2);
        return maxFlow;
    }
};

struct Station_t {
    int r, c;
    int d;
};

struct Solver {
    int ans;
    int R,C,n;
    vector<Station_t> stations;
    void input() {
        scanf("%d%d%d",&R,&C,&n);
        stations.clear();
        for (int i = 0; i < n; i++) {
            int r, c, d;
            scanf("%d%d%d", &r, &c, &d);
            Station_t s;
            s.r = r;
            s.c = c;
            s.d = d;
            stations.emplace_back(s);
        }
    }

    void solve() {
        map<vector<int>, int> area_count;
        int all_cells = 0;
        for (int r = 1; r <= R; r++) {
            for (int c = 1; c <= C; c++) {
                bool is_station = false;
                vector<int> found;
                for (int i = 0; i < stations.size(); i++) {
                    const auto &station = stations[i];
                    if (station.r == r && station.c == c) {
                        is_station = true;
                        break;
                    }
                    if (max(abs(station.r - r), abs(station.c - c)) <= station.d) {
                        found.push_back(i);
                    }
                }
                if (is_station) continue;
                if (found.empty()) continue;
                all_cells++;
                ++area_count[found];
            }
        }

        int best_answer = all_cells;
        for (int base_assign = 0; base_assign <= all_cells / n; base_assign++) {
            int low = base_assign, high = low + best_answer - 1;
            while (low <= high) {
                int mid = (low + high) / 2;

                MaxFlowEdgeDemand mf;
                mf.init(area_count.size() + n + 2);
                int source = area_count.size() + n;
                int sink = area_count.size() + n + 1;
                for (int i = 0; i < n; i++) {
                    mf.addEdge(area_count.size() + i, sink, base_assign, mid);
                }
                {
                    int i = 0;
                    for (const auto &kv : area_count) {
                        const auto &ss = kv.first;
                        int cnt = kv.second;
                        mf.addEdge(source, i, cnt, cnt);
                        for (auto dest : ss) {
                            mf.addEdge(i, area_count.size() + dest, 0, cnt);
                        }
                        i++;
                    }
                }

                if (mf.solveFeasibility(source, sink) == -1) {
                    low = mid + 1;
                } else {
                    best_answer = mid - base_assign;
                    high = mid - 1;
                }
            }
        }
        ans = best_answer;
    }

    void output(int testcase) {
        printf("Case #%d: %d\n", testcase, ans);
    }
};

int main() {
    int testCaseCount;
    scanf("%d", &testCaseCount);

    const int batchSize = max(1, (int)(thread::hardware_concurrency() / 2));
    for (int testcase = 1; testcase <= testCaseCount; testcase += batchSize) {
        vector<unique_ptr<Solver>> solvers; solvers.reserve(batchSize);
        vector<unique_ptr<thread>> threads; threads.reserve(batchSize);
        for (int batchInd = 0; batchInd < batchSize && testcase + batchInd <= testCaseCount; batchInd++) {
            solvers.emplace_back(new Solver());
        }
        for (auto &solver : solvers) {
            solver->input();
            threads.emplace_back(new thread(&Solver::solve, solver.get()));
        }
        for (int batchInd = 0; batchInd < (int)solvers.size(); batchInd++) {
            threads[batchInd]->join();
            solvers[batchInd]->output(testcase + batchInd);
        }
    }
    return 0;
}

