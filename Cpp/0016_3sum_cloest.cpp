// https://leetcode-cn.com/problems/3sum-closest/

class Solution {
public:
    int threeSumCloest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), res = nums[0] + nums[1] + nums[2];
        int diff_abs = abs(res - target);

        for (int i = 0; i < n-2; ++i) {
            int j = i + 1, k = n - 1;

            while (j < k) {
                int res_tmp = nums[i] + nums[j] + nums[k];
                int diff_tmp = res_tmp - target;
                
                if (abs(diff_tmp) < diff_abs) {
                    diff_abs = abs(diff_tmp);
                    res = res_tmp;
                }

                if (diff_tmp < 0)
                    j = j + 1;
                else if (diff_tmp > 0)
                    k = k - 1;
                else
                    return res;
            }
        }

        return res;
    }
};