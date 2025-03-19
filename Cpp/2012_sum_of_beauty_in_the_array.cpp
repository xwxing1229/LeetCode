// https://leetcode.cn/problems/sum-of-beauty-in-the-array/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        vector<int> minright(n, nums[n-1]);
        for (int i = n-2; i >= 0; --i) {
            minright[i] = min(minright[i+1], nums[i+1]);
        }
        int res = 0, maxleft = nums[0];
        for (int i = 1; i < n-1; ++i) {
            if (nums[i] > maxleft && nums[i] < minright[i]) {
                res += 2;
            }
            else if (nums[i] > nums[i-1] && nums[i] < nums[i+1]) {
                res += 1;
            }
            if (nums[i] > maxleft) {
                maxleft = nums[i];
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2,4,6,4};
    cout << sol.sumOfBeauties(nums) << '\n';
    return 0;
}
