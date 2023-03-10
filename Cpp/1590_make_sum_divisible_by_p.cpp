// https://leetcode.cn/problems/make-sum-divisible-by-p/

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int target = 0;
        for (int num: nums) {
            target = (target + num) % p;
        }
        if (target == 0) {
            return 0;
        }
        // Given
        //     sum_cur % p = s,
        // we would like to find a sum_pre that
        //     (sum_cur - sum_pre) % p = target.
        int s = 0, n = nums.size(), res = n;
        unordered_map<int, int> record{ {0, -1} };
        for (int i = 0; i < n; ++i) {
            s = (s + nums[i]) % p;
            record[s] = i;
            // +p to avoid problems caused by the condition s < target.
            int target_subarr = (s - target + p) % p;
            if (record.find(target_subarr) != record.end()) {
                res = min(res, i - record[target_subarr]);
            }
        }
        if (res == n) {
            res = -1;
        }
        return res;
    }
};
