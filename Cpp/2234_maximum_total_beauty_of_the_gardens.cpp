// https://leetcode.cn/problems/maximum-total-beauty-of-the-gardens/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
        int n = flowers.size();
        long long need = 0;
        for (auto f: flowers) {
            if (f < target) {
                need += target - f;
            }
        }
        if (need == 0) {
            return (long long)full * n;
        }
        else if (need <= newFlowers) {
            long long tmp1 = (long long)full * n;
            long long tmp2 = (long long)full * (n - 1) + (long long)partial * (target - 1);
            return max(tmp1, tmp2);
        }

        // Try to make flowers[i+1: n-1] complete for i = 0, ..., n-1.
        long long res = 0;
        sort(flowers.begin(), flowers.end());
        int j = 0;
        long long cumsum = 0;
        for (int i = 0; i < n; ++i) {
            if (flowers[i] < target) {
                need -= target - flowers[i];
            }
            long long remain = newFlowers - need;
            if (remain < 0) continue;

            while (j <= i && (long long)flowers[j] * j <= cumsum + remain) {
                cumsum += flowers[j];
                j += 1;
            }
            int num = (cumsum + remain) / j;
            long long tmp = (long long)full * (n - i - 1) + (long long)partial * num;
            res = max(res, tmp);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> flowers = {1, 3, 1, 1};
    long long newFlowers = 7;
    int target = 6;
    int full = 12, partial = 1;
    cout << sol.maximumBeauty(flowers, newFlowers, target, full, partial) << '\n';
    return 0;
}