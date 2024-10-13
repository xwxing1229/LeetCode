// https://leetcode.cn/problems/find-the-number-of-good-pairs-i/

class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int res = 0;
        for (int i = 0; i < nums1.size(); ++i) {
            int num1 = nums1[i];
            if (num1 % k != 0) {
                continue;
            }
            num1 = num1 / k;
            for (int num2: nums2) {
                if (num1 % num2 == 0) {
                    res += 1;
                }
            }
        }
        return res;
    }
};
