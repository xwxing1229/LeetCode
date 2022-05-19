// https://leetcode.cn/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 1, tmp;
        int n = nums.size();

        while (j < n) {
            while ((nums[i] == nums[j]) && (j+1 < n)) {
                j = j + 1;
            }
            if (nums[i] == nums[j]) break;

            tmp = nums[i+1];
            nums[i+1] = nums[j];
            nums[j] = tmp;

            i = i + 1;
            j = j + 1;
        }

        return i+1;
    }
};