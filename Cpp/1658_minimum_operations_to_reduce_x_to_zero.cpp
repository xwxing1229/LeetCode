// https://leetcode.cn/problems/minimum-operations-to-reduce-x-to-zero/

#include <vector>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int res = n + 1;
        vector<int> presum(n+1, 0);
        for (int i = 0; i < n; ++i) {
            presum[i+1] = presum[i] + nums[i];
            if (presum[i+1] == x) {
                res = min(res, i+1);
            }
        }
        int sufsum = 0;
        int left = n;
        for (int right = n-1; right >= 0; --right) {
            sufsum += nums[right];
            while (left >= 0 && presum[left] + sufsum > x) {
                left -= 1;
            }
            if (left >= 0 && presum[left] + sufsum == x) {
                res = min(res, left + n - right);
            }
        }
        return res <= n ? res : -1;
    }
};