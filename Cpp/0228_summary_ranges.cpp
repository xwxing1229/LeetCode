// https://leetcode.cn/problems/summary-ranges/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n = nums.size();
        if (n == 0) {
            return res;
        }
        int left = nums[0], pre = nums[0];
        nums.push_back(0);
        for (int i = 1; i <= n; ++i) {
            pre = nums[i-1];
            if ((nums[i] - 1 > pre) || (i == n)) {
                string tmp = to_string(left);
                if (left < pre) {
                    tmp = tmp + "->" + to_string(pre);
                }
                res.push_back(tmp);
                left = nums[i];
            }
        }
        return res;
    }
};
