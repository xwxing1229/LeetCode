// https://leetcode.cn/problems/check-if-array-is-sorted-and-rotated/

class Solution {
public:
    bool check(vector<int>& nums) {
        int cut = -1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i-1]) {
                if (cut > 0) {
                    return false;
                }
                cut = nums[0];
            }
        }
        if ((cut > 0) && (cut < nums.back())) return false;
        else return true;
    }
};
