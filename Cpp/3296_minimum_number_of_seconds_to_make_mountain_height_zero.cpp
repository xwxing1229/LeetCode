// https://leetcode.cn/problems/minimum-number-of-seconds-to-make-mountain-height-zero/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        auto check = [&](long long t) {
            int s = 0;
            for (const int &w: workerTimes) {
                int remove = sqrt(2 * t / w + 0.25) - 0.5;
                s += remove;
                if (s >= mountainHeight) {
                    return true;
                }
            }
            return false;
        };

        int w_min = workerTimes[0];
        for (const int &w: workerTimes) {
            w_min = min(w_min, w);
        }
        long long left = 0;
        long long right = (long long)w_min * mountainHeight * (1 + mountainHeight) / 2;
        long long res = right;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (check(mid)) {
                res = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    int mountainHeight = 4;
    vector<int> workerTimes = {2, 1, 1};
    cout << sol.minNumberOfSeconds(mountainHeight, workerTimes) << '\n';
    return 0;
}