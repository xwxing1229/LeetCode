// https://leetcode.cn/problems/keep-multiplying-found-values-by-two/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(), nums.end());
        for (int num: nums) {
            if (num == original) {
                original *= 2;
                if (original > nums.back()) break;
            }
        }
        return original;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {5,3,6,1,12};
    int original = 3;
    cout << sol.findFinalValue(nums, original) << '\n';
    return 0;
}