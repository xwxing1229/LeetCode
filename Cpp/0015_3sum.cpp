// https://leetcode-cn.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;

        int n = nums.size();
        if (n < 3)
            return res;

        std::sort(nums.begin(), nums.end());
        if ((nums[0] > 0) || (nums[n-1] < 0))
            return res;

        for (int i = 0; i < n-2; ++i) {
            int nums_i = nums[i];
            if ((i > 0) && (nums_i == nums[i-1]))
                continue;

            int j = i + 1, k = n - 1;
            while (j < k) {
                int nums_j = nums[j], nums_k = nums[k];

                // Ignore duplicate elements.
                if ((j > i+1) && (nums_j == nums[j-1])) {
                    j = j + 1;
                    continue;
                }
                if ((k < n-1) && (nums_k == nums[k+1])) {
                    k = k - 1;
                    continue;
                }

                int sum_ijk = nums_i + nums_j + nums_k;
                if (sum_ijk == 0) {
                    vector<int> tmp = {nums_i, nums_j, nums_k};
                    res.push_back(tmp);
                    j = j + 1;
                    k = k - 1;
                }
                else if (sum_ijk < 0)
                    j = j + 1;
                else
                    k = k - 1;
            }
        }

        return res;
    }
};