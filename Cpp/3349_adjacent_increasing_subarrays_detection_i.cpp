// https://leetcode.cn/problems/adjacent-increasing-subarrays-detection-i/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> incr(n, 1);
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i-1]) incr[i] = incr[i-1] + 1;
        }
        for (int i = k-1; i < n-k; ++i) {
            if (incr[i] >= k && incr[i+k] >= k) return true;
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2,5,7,8,9,2,3,4,3,1};
    int k = 3;
    cout << sol.hasIncreasingSubarrays(nums, k) << '\n';
    return true;
}