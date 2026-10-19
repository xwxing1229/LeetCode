// https://leetcode.cn/problems/find-target-indices-after-sorting-array/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> res;
        res.reserve(nums.size());
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                res.push_back(i);
            }
        }
        return res;
    }
};