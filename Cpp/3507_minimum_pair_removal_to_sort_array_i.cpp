// https://leetcode.cn/problems/minimum-pair-removal-to-sort-array-i/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int res = 0;
        bool valid = false;
        while (!valid) {
            int n = nums.size();
            if (n <= 1) {
                break;
            }

            valid = true;
            int s_min = nums[0] + nums[1], idx = 0;
            for (int i = 0; i < n-1; ++i) {
                if (nums[i] > nums[i+1]) {
                    valid = false;
                }
                if (s_min > nums[i] + nums[i+1]) {
                    s_min = nums[i] + nums[i+1];
                    idx = i;
                }
            }
            if (!valid) {
                nums[idx] = s_min;
                nums.erase(nums.begin() + idx + 1);
                res += 1;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {5,2,3,1};
    cout << sol.minimumPairRemoval(nums) << '\n';
    return 0;
}