// https://leetcode.cn/problems/majority-element/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Boyer-Moore majority vote algorithm.
        int res = 0, count = 0;
        for (int num: nums) {
            if (count == 0) {
                res = num;
            }

            if (res == num) {
                count = count + 1;
            }
            else {
                count = count - 1;
            }
        }
        return res;
    }
};
