// https://leetcode.cn/problems/maximum-value-of-an-ordered-triplet-ii/

#include <iostream>
#include <vector>

using namespace std;
        
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> right_max(n, 0);
        for (int i = n-2; i >= 0; --i) {
            right_max[i] = max(right_max[i+1], nums[i+1]);
        }
        long long res = 0, left_max = nums[0];
        for (int i = 1; i < n-1; ++i) {
            res = max(res, (left_max - nums[i]) * right_max[i]);
            left_max = max(left_max, (long long)nums[i]);
        }
        return res > 0 ? res : 0;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {12,6,1,2,7};
    cout << sol.maximumTripletValue(nums) << '\n';
    return 0;
}