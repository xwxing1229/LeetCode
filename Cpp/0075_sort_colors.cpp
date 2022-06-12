// https://leetcode.cn/problems/sort-colors/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt_0 = 0, cnt_1 = 0;
        for (int num: nums) {
            if (num == 0) {
                cnt_0 = cnt_0 + 1;
            }
            else if (num == 1) {
                cnt_1 = cnt_1 + 1;
            }
        }
        for (int i = 0; i < cnt_0; ++i) {
            nums[i] = 0;
        }
        for (int i = cnt_0; i < cnt_0+cnt_1; ++i) {
            nums[i] = 1;
        }
        for (int i = cnt_0+cnt_1; i < nums.size(); ++i) {
            nums[i] = 2;
        }
    }
};
