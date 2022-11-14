// https://leetcode.cn/problems/split-array-with-same-average/

class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return false;

        // nums[i] = nums[i] - avg: sum(nums) = 0.
        // nums[i] = (nums[i] - avg) * n: sum(nums) = 0.
        int s = 0;
        for (int i = 0; i < n; ++i) {
            s += nums[i];
        }
        for (int i = 0; i < n; ++i) {
            nums[i] = nums[i] * n - s;
        }
        // Check if there is a subset sub1 of the first half of nums and
        // a subset sub2 of the second half of nums s.t.
        // sum(sub1) + sum(sub2) = 0.
        int n1 = n / 2;
        unordered_set<int> s1_set;
        for (int i = 1; i < (1 << n1); ++i) {
            int s1 = 0;
            for (int k = 0; k < n1; ++k) {
                if (((i >> k) & 1) == 1) {
                    s1 += nums[k];
                }
            }
            if (s1 == 0) return true;
            s1_set.emplace(s1);
        }
        for (int i = 1; i < (1 << (n-n1)); ++i) {
            int s2 = 0;
            for (int k = n1; k < n; ++k) {
                if (((i >> (k-n1)) & 1) == 1) {
                    s2 += nums[k];
                }
            }
            if ((s2 == 0) || ((s1_set.find(-s2) != s1_set.end()) && (i+1 != (1<<(n-n1))))) {
                return true;
            }
        }
        return false;
    }
};
