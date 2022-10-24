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

using namespace std;

int main() {
    int T;
    scanf("%d",&T);
    while(T-->0) {
        int S;
        scanf("%d", &S);
        int used = 0;
        int low = 1, high = 1000000;
        int bdist = -1;
        int best = -1;
        int lastmid = (low + high) / 2;
        while (low <= high) {
            int mid = (low + high) / 2;
            lastmid = mid;
            for (int i = 0; i < 500; i++) {
                used++;
                printf("%d\n", mid);
            }
            fflush(stdout);
            int cnt = 0;
            for (int i = 0; i < 500; i++) {
                int v;
                scanf("%d", &v);
                cnt += v;
            }
            if (abs(bdist - 250) > abs(cnt - 250)) {
                bdist = cnt;
                best = mid;
            }
            if (cnt < 250) {
                low = mid + 1; // need higher quality
            } else {
                high = mid - 1;
            }
        }
        if (best < 0) {
            best = lastmid;
        }
        //fprintf(stderr,"finished bsearch %d\n", best);
        //fflush(stderr);
        int baseIndex = used;
        vector<int> responses;
        while (used < S) {
            int await = 0;
            for (int b = 0; b < 500 && used < S; b++) {
                await++;
                printf("%d\n", best);
                used++;
            }
            fflush(stdout);
            while(await-->0) {
                int v;
                scanf("%d",&v);
                responses.push_back(v);
            }
        }
        //fprintf(stderr,"finished response %d\n", used);
        //fflush(stderr);
        int ans = 25;
        for (int test_value = 2; test_value <= 25; test_value++) {
            int rem = baseIndex % test_value;
            int ind = 0;
            while (rem > 0) {
                rem = (rem + 1) % test_value;
                ind++;
            }
            int sum = 0;
            for (int i = ind; i < ind + test_value; i++) {
                sum += responses[i];
            }
            bool failed = false;
            for (int i = ind + test_value; i + (test_value-1) < responses.size(); i += test_value) {
                int tsum = 0;
                for (int j = 0; j < test_value; j++) {
                    tsum += responses[i + j];
                }
                if (tsum != sum) {
                    failed = true;
                    break;
                }
            }
            if (failed) {
                continue;
            }
            ans = test_value;
            break;
        }
        printf("%d\n", -ans);
        fflush(stdout);
        //fprintf(stderr,"finished answer %d\n", ans);
        //fflush(stderr);
    }
    return 0;
}

