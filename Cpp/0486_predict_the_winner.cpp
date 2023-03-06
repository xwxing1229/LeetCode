// https://leetcode.cn/problems/predict-the-winner/

/* Check solution for a DP-based method. */

// class Solution {
// public:
//     bool PredictTheWinner(vector<int>& nums) {
//         nums_ = nums;
//         if (dfs(0, nums.size()-1, 0, 0) >= 0) {
//             return true;
//         }
//         else {
//             return false;
//         }
//     }

//     int dfs(int left, int right, int total1, int total2) {
//         if (left + 1 >= right) {
//             total1 += max(nums_[left], nums_[right]);
//             total2 += min(nums_[left], nums_[right]);
//             return total1 - total2;
//         }

//         int diff1 = -dfs(left + 1, right, total2, total1 + nums_[left]);
//         int diff2 = -dfs(left, right - 1, total2, total1 + nums_[right]);
//         return max(diff1, diff2);
//     }

//     vector<int> nums_;
// };


// This is an improved version based on the idea above with repeated operations avoided.
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        nums_ = nums;
        n_ = nums.size();
        if (dfs(0, n_-1) >= 0) {
            return true;
        }
        else {
            return false;
        }
    }

    int dfs(int left, int right) {
        int key = left * n_ + right;
        if (records_.find(key) != records_.end()) {
            return records_[key];
        }
        if (left + 1 >= right) {
            int diff = abs(nums_[left] - nums_[right]);
            records_[key] = diff;
            return diff;
        }

        int diff1 = nums_[left] - dfs(left + 1, right);
        int diff2 = nums_[right] - dfs(left, right - 1);
        int diff = max(diff1, diff2);
        records_[key] = diff;
        return diff;
    }

    vector<int> nums_;
    int n_;
    unordered_map<int, int> records_;
};