// https://leetcode.cn/problems/find-missing-elements/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int mn = nums[0], mx = nums.back();
        int n = mx - mn + 1 - nums.size();
        vector<int> res;
        if (n == 0) {
            return res;
        }
        res.reserve(n);
        int i = 0;
        for (int num = mn; num <= mx; ++num) {
            if (num == nums[i]) {
                i += 1;
            }
            else {
                res.push_back(num);
            }
        }
        return res;
    }
};