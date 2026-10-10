// https://leetcode.cn/problems/minimum-sum-of-squared-difference/

#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<long long> diff(n);
        for (int i = 0; i < n; ++i) {
            diff[i] = abs(nums1[i] - nums2[i]);
        }
        sort(diff.rbegin(), diff.rend());
        diff.push_back(0);

        long long res = 0;
        int i = 0;
        long long val = diff[0];
        long long k = k1 + k2;
        while (i < n) {
            long long need = (diff[i] - diff[i+1]) * (i + 1);
            if (need <= k) {
                // (i+1) numbers can be updated to val.
                k -= need;
                val = diff[i+1];
                i += 1;
            }
            else {
                int d = k / (i + 1);
                int r = k % (i + 1);
                // (i+1-r) numbers can be updated to (val-d),
                // and (r) numbers can be updated to (val-d-1).
                res = (val-d) * (val-d) * (i+1-r)
                    + (val-d-1) * (val-d-1) * r;
                break;
            }
        }
        for (int idx = i+1; idx < n; ++idx) {
            res += diff[idx] * diff[idx];
        }
        return res;
    }
};