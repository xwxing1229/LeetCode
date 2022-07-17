// https://leetcode.cn/problems/contains-duplicate-iii/

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        /*
        vector<int> window;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > k) {
                auto iter = lower_bound(window.begin(), window.end(), nums[i-k-1]);
                window.erase(iter);
            }
            auto iter = lower_bound(window.begin(), window.end(), nums[i]-t);
            if ((iter != window.end()) &&
                (window[iter-window.begin()] <= (long)nums[i]+t)) {
                return true;
            }
            iter = lower_bound(window.begin(), window.end(), nums[i]);
            window.insert(iter, nums[i]);

        }
        return false;
        */

        // A better data structure.
        set<long> window;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > k) {
                window.erase(nums[i-k-1]);
            }
            auto iter = window.lower_bound((long)nums[i]-t);
            if ((iter != window.end()) && (*iter <= (long)nums[i]+t)) {
                return true;
            }
            window.insert(nums[i]);
        }
        return false;
    }
};
