// https://leetcode.cn/problems/find-all-duplicates-in-an-array/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            int k = nums[i];
            if (k < 0) {
                k = -k;
            }

            if (nums[k-1] > 0) {
                nums[k-1] = -nums[k-1];
            }
            else {
                res.push_back(k);
            }
        }
        return res;
    }
};
