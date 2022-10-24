// https://leetcode.cn/problems/partition-array-into-disjoint-intervals/

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        vector<int> mins(n, nums[n-1]);
        for (int i = n-2; i >= 0; --i) {
            if (nums[i] < mins[i+1]) {
                mins[i] = nums[i];
            }
            else {
                mins[i] = mins[i+1];
            }
        }

        int cur_max = nums[0];
        for (int i = 1; i < n; ++i) {
            if (cur_max <= mins[i]) {
                return i;
            }

            if (nums[i] > cur_max) {
                cur_max = nums[i];
            }
        }
        return 0;
    }
};
