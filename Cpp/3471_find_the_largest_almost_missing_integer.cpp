// https://leetcode.cn/problems/find-the-largest-almost-missing-integer/

#include <vector>

using namespace std;

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int res = -1, mx = nums[0];
        vector<int> count(51, 0);
        for (int num: nums) {
            mx = max(mx, num);
            count[num] += 1;
        }
        if (k == 1) {
            for (int num = 0; num < count.size(); ++num) {
                if (count[num] == 1 && num > res) {
                    res = num;
                }
            }
            return res;
        }
        else if (k == nums.size()) {
            return mx;
        }

        int left = nums[0], right = nums.back();
        if (count[left] == 1 && count[right] == 1) return max(left, right);
        else if (count[left] == 1) return left;
        else if (count[right] == 1) return right;
        return -1;
    }
};