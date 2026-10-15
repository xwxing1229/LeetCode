// https://leetcode.cn/problems/subarrays-distinct-element-sum-of-squares-i/

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int res = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            unordered_set<int> s;
            for (int j = i; j < n; ++j) {
                s.insert(nums[j]);
                res += s.size() * s.size();
            }
        }
        return res;
    }
};