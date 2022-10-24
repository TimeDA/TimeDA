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

struct interval_t {
    long double s, e;
    int is_internal;

    bool operator < (const interval_t &other) const {
        if (is_internal != other.is_internal) return is_internal < other.is_internal;
        if (is_internal) {
            return s < other.s;
        } else {
            return e < other.e;
        }
    }
};

struct iint_t {
    int s1, e1; // normal form
    int s2, e2; // reversed
};

const long double PI = atanl((long double)1.0) * 4;
const long double eps = 1e-15;
const long double eps2 = 1e-17;

long double normalizeAngleToUnit(long double v) {
    v /= PI * 2;
    while (v > 1) {
        v -= 1;
    }
    while (v < 0) {
        v += 1;
    }
    if (eps >= 1 - v) return 0;
    return v;
}

long double normalize(long double v) {
    while (v > 1) {
        v -= 1;
    }
    while (v < 0) {
        v += 1;
    }
    if (eps >= 1 - v) return 0;
    return v;
}

struct Solver {
    int n;
    double ans;
    vector<interval_t> intervals;
    void input() {
        intervals.clear();
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            int x, y, xp, yp;
            scanf("%d%d%d%d",&x,&y,&xp,&yp);
            // atan2 -> -pi to pi
            long double curangle = atan2l(yp - y, xp - x);
            long double a1 = normalizeAngleToUnit(atan2l(0 - y, 0 - x) - curangle);
            long double a2 = normalizeAngleToUnit(atan2l(1000 - y, 0 - x) - curangle);
            auto t2 = max(a1, a2);
            auto t1 = min(a1, a2);
            if (t2 - t1 < 0.5) {
                /* internal */
                interval_t interval;
                interval.is_internal = 1;
                if (t1 <= 1 - t2) {
                    interval.s = (t1)-eps;
                    interval.e = (t2)+eps;
                } else {
                    interval.s = (1 - t2)-eps;
                    interval.e = (1 - t1)+eps;
                }
                intervals.emplace_back(interval);
            } else {
                /* wrap around */
                interval_t interval;
                interval.is_internal = 0;
                if (t1 <= 1 - t2) {
                    interval.s = (-t1)-eps;
                    interval.e = (1 - t2)+eps;
                } else {
                    interval.s = (-(1 - t2))-eps;
                    interval.e = (t1)+eps;
                }
                intervals.emplace_back(interval);
            }
        }
    }

    vector<long double> coords;
    vector<iint_t> ints;

    int findClosestCoord(long double v) const {
        v = normalize(v);
        auto I = upper_bound(coords.begin(), coords.end(), v);
        if (I == coords.begin()) {
            return 0;
        }
        if (I == coords.end()) {
            return coords.size() - 1;
        }
        auto v1 = *I; int i1 = I - coords.begin();
        --I;
        auto v2 = *I; int i2 = I - coords.begin();
        if (fabsl(v - v1) <= fabsl(v - v2)) return i1;
        return i2;
    }

    int make_right(int v) const {
        if (v == 0) {
            return coords.size() - 1;
        }
        return v;
    }

    void solve() {
        sort(intervals.begin(), intervals.end());
        for (const auto &interval : intervals) {
            coords.push_back(normalize(interval.s));
            coords.push_back(normalize(-interval.s));
            coords.push_back(normalize(interval.e));
            coords.push_back(normalize(-interval.e));
        }
        coords.push_back(0.0);
        coords.push_back(1.0); // for hypothetical reach
        sort(coords.begin(), coords.end());
        {
            int i = 0;
            for (int j = 0; j < (int)coords.size(); j++) {
                if (i == 0 || fabsl(coords[j] - coords[i - 1]) > eps) {
                    coords[i] = coords[j];
                    i++;
                }
            }
            coords.resize(i);
        }
        ints.clear();
        const int coordCnt = (int)coords.size();
        for (const auto &interval : intervals) {
            if (interval.is_internal) {
                iint_t new_interval;
                new_interval.s1 = findClosestCoord(interval.s);
                new_interval.e1 = findClosestCoord(interval.e);
                if (new_interval.s1 == new_interval.e1) continue; // point interval, unnecessary
                new_interval.s2 = make_right(findClosestCoord(-interval.s));
                new_interval.e2 = make_right(findClosestCoord(-interval.e));
                ints.emplace_back(new_interval);
            } else {
                iint_t new_interval;
                new_interval.s1 = findClosestCoord(interval.s);
                new_interval.e1 = findClosestCoord(interval.e);
                if (new_interval.s1 == new_interval.e1) continue; // point interval, unnecessary
                new_interval.s1 = make_right(new_interval.s1);

                new_interval.s2 = findClosestCoord(-interval.s);
                new_interval.e2 = make_right(findClosestCoord(-interval.e));
                ints.emplace_back(new_interval);
            }
        }
        // dpL means, reach was used for L, and index means R
        vector<double> dpL(coords.size()), dpR(coords.size());
        vector<double> ndpL(coords.size()), ndpR(coords.size());
        int reachL = 0, reachR = coordCnt - 1;
        dpR[0] = 1.0;
        ans = 0;
        for (int i = 0; i < (int)ints.size(); i++) {
            fill(ndpL.begin(), ndpL.end(), 0.0);
            fill(ndpR.begin(), ndpR.end(), 0.0);
            int nextReachL, nextReachR;
            const auto &interval = ints[i];
            nextReachL = max(interval.e1, reachL);
            nextReachR = min(interval.e2, reachR);

            if (interval.s1 > interval.e1) {
                // wrap around
                for (int j = 0; j < coordCnt; j++) {
                    double pval = dpL[j];
                    if (pval < eps2) continue;
                    // reachL] [j
                    // 1) nextReachL] [min(j, s1)
                    if (nextReachL >= min(j, interval.s1)) {
                        ans += pval * 0.5;
                    } else {
                        ndpL[min(j, interval.s1)] += pval * 0.5;
                    }
                    // 2) max(reachL, s2)] [nextReachR
                    if (max(reachL, interval.s2) >= nextReachR) {
                        ans += pval * 0.5;
                    } else {
                        ndpR[max(reachL, interval.s2)] += pval * 0.5;
                    }
                }
                for (int j = 0; j < coordCnt; j++) {
                    double pval = dpR[j];
                    if (pval < eps2) continue;
                    // j] [reachR
                    // 1) nextReachL] [min(reachR, s1)
                    if (nextReachL >= min(reachR, interval.s1)) {
                        ans += pval * 0.5;
                    } else {
                        ndpL[min(reachR, interval.s1)] += pval * 0.5;
                    }
                    // 2) max(j, s2)] [nextReachR
                    if (max(j, interval.s2) >= nextReachR) {
                        ans += pval * 0.5;
                    } else {
                        ndpR[max(j, interval.s2)] += pval * 0.5;
                    }
                }
            } else {
                // internal
                for (int j = 0; j < coordCnt; j++) {
                    double pval = dpL[j];
                    if (pval < eps2) continue;
                    // reachL] [j
                    // 1) nextReachL] [j
                    if (interval.s1 <= reachL) {
                        if (nextReachL >= j) {
                            ans += pval * 0.5;
                        } else {
                            ndpL[j] += pval * 0.5;
                        }
                    }
                    // 2) reachL] [nextReachR
                    if (interval.e2 > reachR) {
                        // failed to reduce, which means reachL = nextReachL
                        // reachL] [min(j, interval.e2)
                        if (interval.s2 >= j) {
                            if (reachL >= min(j, interval.e2)) {
                                ans += pval * 0.5;
                            } else {
                                ndpL[min(j, interval.e2)] += pval * 0.5;
                            }
                        }
                    } else {
                        // reduced
                        if (interval.s2 >= j) {
                            if (reachL >= nextReachR) {
                                ans += pval * 0.5;
                            } else {
                                ndpR[reachL] += pval * 0.5;
                            }
                        }
                    }
                }
                for (int j = 0; j < coordCnt; j++) {
                    double pval = dpR[j];
                    if (pval < eps2) continue;
                    // j] [reachR
                    // 1) nextReachL] [reachR
                    if (interval.e1 < reachL) {
                        // failed to reduce, which means reachR = nextReachR
                        // max(j, interval.e1)] [reachR
                        if (interval.s1 <= j) {
                            if (max(j, interval.e1) >= reachR) {
                                ans += pval * 0.5;
                            } else {
                                ndpR[max(j, interval.e1)] += pval * 0.5;
                            }
                        }
                    } else {
                        // reduced
                        if (interval.s1 <= j) {
                            if (nextReachL >= reachR) {
                                ans += pval * 0.5;
                            } else {
                                ndpL[reachR] += pval * 0.5;
                            }
                        }
                    }
                    // 2) j] [nextReachR
                    if (interval.s2 >= reachR) {
                        if (j >= nextReachR) {
                            ans += pval * 0.5;
                        } else {
                            ndpR[j] += pval * 0.5;
                        }
                    }
                }
            }
            ndpL.swap(dpL);
            ndpR.swap(dpR);
            reachL = nextReachL;
            reachR = nextReachR;
        }
    }

    void output(int testcase) {
        printf("Case #%d: %.6f\n", testcase, (double)(1 - ans));
    }
};

int main() {
    int testCaseCount;
    scanf("%d", &testCaseCount);

    //const int batchSize = max(1, (int)(thread::hardware_concurrency() / 2));
    const int batchSize = 1;
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

