// https://leetcode-cn.com/problems/4sum/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        if (n < 4)
            return res;

        sort(nums.begin(), nums.end());

        for (int a = 0; a < n-3; ++a) {
            int num_a = nums[a];
            if ((a > 0) && (num_a == nums[a-1]))
                continue;

            for (int b = a+1; b < n-2; ++b) {
                int num_b = nums[b];
                if ((b > a+1) && (num_b == nums[b-1]))
                    continue;

                int c = b + 1, d = n - 1;
                while (c < d) {
                    int num_c = nums[c], num_d = nums[d];
                    if ((c > b+1) && (num_c == nums[c-1])){
                        c = c + 1;
                        continue;
                    }
                    if ((d < n-1) && (num_d == nums[d+1])) {
                        d = d - 1;
                        continue;
                    }

                    long long sum_tmp = (long long)num_a + (long long)num_b
                        + (long long)num_c + (long long)num_d;
                    if (sum_tmp == target) {
                        vector<int> res_tmp = {num_a, num_b, num_c, num_d};
                        res.push_back(res_tmp);
                        c = c + 1;
                        d = d - 1;
                    }
                    else if(sum_tmp < target)
                        c = c + 1;
                    else
                        d = d - 1;
                }
            }
        }

        return res;
    }
};