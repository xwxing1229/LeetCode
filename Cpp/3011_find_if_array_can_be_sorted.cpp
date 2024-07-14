// https://leetcode.cn/problems/find-if-array-can-be-sorted/
        
class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int pre_group_max = 0;
        int cur_group_max = 0, cur_group_1cnt = 0;
        for (int num: nums) {
            int n = __builtin_popcount(num);
            if (n == cur_group_1cnt) {
                cur_group_max = max(cur_group_max, num);
            }
            else {
                pre_group_max = cur_group_max;
                cur_group_max = num;
                cur_group_1cnt = n;
            }
            if (num < pre_group_max) {
                return false;
            }
        }
        return true;
    }
};
