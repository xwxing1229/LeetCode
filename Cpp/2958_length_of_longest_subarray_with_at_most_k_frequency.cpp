// https://leetcode.cn/problems/length-of-longest-subarray-with-at-most-k-frequency/

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int res = 0;
        int left = 0;
        unordered_map<int, int> count;
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            count[num] += 1;
            while (count[num] > k) {
                count[nums[left]] -= 1;
                left += 1;
            }
            res = max(res, i - left + 1);
        }
        return res;
    }
};