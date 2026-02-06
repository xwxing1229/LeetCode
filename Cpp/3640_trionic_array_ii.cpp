// https://leetcode.cn/problems/trionic-array-ii/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        long long res = 0;
        bool init = false;
        int n = nums.size(), l = 0;
        while (l < n) {
            int p = l, q = l, r = l;
            for (int i = l+1; i < n; ++i) {
                if (nums[i] > nums[i-1]) p = i;
                else break;
            }
            if (p == l) {
                l += 1;
                continue;
            }
            for (int i = p+1; i < n; ++i) {
                if (nums[i] < nums[i-1]) q = i;
                else break;
            }
            if (q == l) {
                l = p + 1;
                continue;
            }
            for (int i = q+1; i < n; ++i) {
                if (nums[i] > nums[i-1]) r = i;
                else break;
            }
            if (r == l) {
                l = q + 1;
                continue;
            }

            // dp[i]: maximum sum of subarray that ends with nums[l+i].
            vector<long long> dp(p-l, nums[l]);
            for (int i = 1; i < p-l; ++i) {
                dp[i] = max(dp[i-1]+nums[l+i], (long long)nums[l+i]);
            }
            long long curr = dp.back();
            for (int i = p; i <= q; ++i) {
                curr += nums[i];
            }
            long long cumsum = nums[q+1], tmp = nums[q+1];
            for (int i = q+2; i <= r; ++i) {
                cumsum += nums[i];
                tmp = max(tmp, cumsum);
            }
            curr += tmp;

            if (!init || res < curr) {
                res = curr;
                init = true;
            }

            l = q;
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0,-2,-1,-3,0,2,-1};
    cout << sol.maxSumTrionic(nums) << '\n';
    return 0;
}