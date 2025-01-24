// https://leetcode.cn/problems/find-the-array-concatenation-value/

class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        int n = nums.size(), j = n/2;
        for (int i = 0; i < n/2; ++i) {
            int val = 2 * nums[i];
            while (j < n && val > nums[j]) {
                j += 1;
            }
            if (j < n) {
                res += 2;
                j += 1;
            }
            else {
                break;
            }
        }
        return res;
    }
};
