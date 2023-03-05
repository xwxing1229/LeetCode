// https://leetcode.cn/problems/predict-the-winner/

/* Check solution for a DP-based method which is time-efficient. */

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        nums_ = nums;
        if (dfs(0, nums.size()-1, 0, 0) >= 0) {
            return true;
        }
        else {
            return false;
        }
    }

    int dfs(int left, int right, int total1, int total2) {
        if (left + 1 >= right) {
            total1 += max(nums_[left], nums_[right]);
            total2 += min(nums_[left], nums_[right]);
            return total1 - total2;
        }

        int diff1 = -dfs(left + 1, right, total2, total1 + nums_[left]);
        int diff2 = -dfs(left, right - 1, total2, total1 + nums_[right]);
        return max(diff1, diff2);
    }

    vector<int> nums_;
};
