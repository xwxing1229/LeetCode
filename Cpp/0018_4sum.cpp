// https://leetcode-cn.com/problems/4sum/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int a = 0; a < n-3; ++a) {
            if (a > 0 && nums[a] == nums[a-1]) continue;
            if ((long)nums[a] + nums[a+1] + nums[a+2] + nums[a+3] > target) break;
            if ((long)nums[a] + nums[n-3] + nums[n-2] + nums[n-1] < target) continue;
            for (int b = a+1; b < n-2; ++b) {
                if (b > a+1 && nums[b] == nums[b-1]) continue;
                if ((long)nums[a] + nums[b] + nums[b+1] + nums[b+2] > target) break;
                if ((long)nums[a] + nums[b] + nums[n-2] + nums[n-1] < target) continue;
                long cur = (long)target - nums[a] - nums[b];
                int c = b+1, d = n-1;
                while (c < d) {
                    long diff = cur - nums[c] - nums[d];
                    if (diff == 0) {
                        res.push_back((vector<int>{nums[a], nums[b], nums[c], nums[d]}));
                        while (c+1 < d && nums[c+1] == nums[c]) {
                            c += 1;
                        }
                        while (d-1 > c && nums[d-1] == nums[d]) {
                            d -= 1;
                        }
                        c += 1;
                        d -= 1;
                    }
                    else if (diff > 0) {
                        c += 1;
                    }
                    else {
                        d -= 1;
                    }
                }
            }
        }
        return res;
    }
};
