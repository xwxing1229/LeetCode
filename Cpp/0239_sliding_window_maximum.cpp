// https://leetcode.cn/problems/sliding-window-maximum/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // vector<int> res;
        // priority_queue<pair<int, int>> window;
        // int n = nums.size();
        // for (int i = 0; i < k-1; ++i) {
        //     window.push({nums[i], i});
        // }

        // for (int i = k-1; i < n; ++i) {
        //     window.push({nums[i], i});
        //     pair<int, int> top = window.top();
        //     res.push_back(top.first);
        //     while ((!window.empty()) && (i-k+1 >= window.top().second)) {
        //         window.pop();
        //     }
        // }
        // return res;

        // A better method.
        vector<int> res;
        deque<int> window; // this variable saves indices
        for (int i = 0; i < k; ++i) {
            while ((!window.empty()) && (nums[i] >= nums[window.back()])) {
                window.pop_back();
            }
            window.push_back(i);
        }
        res.push_back(nums[window.front()]);

        for (int i = k; i < nums.size(); ++i) {
            while ((!window.empty()) && (nums[i] >= nums[window.back()])) {
                window.pop_back();
            }
            window.push_back(i);

            while (i-k+1 > window.front()) {
                window.pop_front();
            }

            res.push_back(nums[window.front()]);
        }
        return res;
    }
};
