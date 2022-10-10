// https://leetcode.cn/problems/minimum-swaps-to-make-sequences-increasing/

class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        // dp0: do not swap nums1[i] and nums2[i]
        // dp1: do swap nums1[i] and nums2[i]
        int dp0 = 0, dp1 = 1;
        int dp0_pre = 0, dp1_pre = 1;
        for (int i = 1; i < nums1.size(); ++i) {
            int num1 = nums1[i], num1_pre = nums1[i-1];
            int num2 = nums2[i], num2_pre = nums2[i-1];
            if ((num1 > num1_pre) && (num2 > num2_pre) && (num1 > num2_pre) && (num2 > num1_pre)) {
                dp0 = min(dp0, dp1);
                dp1 = min(dp0, dp1) + 1;
            }
            else if ((num1 > num1_pre) && (num2 > num2_pre)) {
                dp0 = dp0_pre;
                dp1 = dp1_pre + 1;
            }
            else {
                dp0 = dp1_pre;
                dp1 = dp0_pre + 1;
            }
            dp0_pre = dp0;
            dp1_pre = dp1;
        }
        return min(dp0, dp1);
    }
};
