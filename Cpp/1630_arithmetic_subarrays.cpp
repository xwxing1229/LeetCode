// https://leetcode.cn/problems/arithmetic-subarrays/

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size(), m = l.size();
        vector<int> idxs(n);
        for (int i = 0; i < n; ++i) {
            idxs[i] = i;
        }
        sort(idxs.begin(), idxs.end(), [&](int i, int j) {
            return nums[i] < nums[j];
        });

        vector<bool> res(m, true);
        for (int i = 0; i < m; ++i) {
            int left = l[i], right = r[i];
            int pre = 0, diff = 0;
            bool first = false, second = false;
            for (int j = 0; j < n; ++j) {
                int idx = idxs[j];
                if (idx < left || idx > right) {
                    continue;
                }

                if (!first) {
                    pre = nums[idx];
                    first = true;
                }
                else if (!second) {
                    diff = nums[idx] - pre;
                    pre = nums[idx];
                    second = true;
                    
                }
                else {
                    if (nums[idx] - pre != diff) {
                        res[i] = false;
                        break;
                    }
                    else {
                        pre = nums[idx];
                    }
                }
            }
        }
        return res;
    }
};