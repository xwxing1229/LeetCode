// https://leetcode.cn/problems/remove-duplicates-from-sorted-array-ii/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = 1, idx = 1, val = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == val) {
                cnt = cnt + 1;
                if (cnt < 3) {
                    nums[idx] = nums[i];
                    idx = idx + 1;
                }
            }
            else {
                cnt = 1;
                nums[idx] = nums[i];
                idx = idx + 1;
                val = nums[i];
            }
        }
        return idx;
    }
};
