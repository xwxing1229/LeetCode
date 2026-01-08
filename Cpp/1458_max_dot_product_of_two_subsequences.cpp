// https://leetcode.cn/problems/max-dot-product-of-two-subsequences/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        // dp[i1+1][i2+1]: max dot product of the subsequences of
        // nums1[0, i1] (included) and nums2[0, i2] (included).
        // Three cases when dealing with nums1[i1] and nums2[i2]:
        //   1. Choose nums1[i1] and nums2[i2].
        //   2. Choose nums1[i1], do not choose nums2[i2].
        //   3. Choose nums2[i2], do not choose nums1[i1].
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1e6));
        for (int i1 = 0; i1 < n1; ++i1) {
            for (int i2 = 0; i2 < n2; ++i2) {
                dp[i1+1][i2+1] = max(max(dp[i1][i2], 0) + nums1[i1] * nums2[i2],
                                     max(dp[i1][i2+1], dp[i1+1][i2]));
            }
        }
        return dp[n1][n2];
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {2, 1, -2, 5};
    vector<int> nums2 = {3, 0, -6};
    cout << sol.maxDotProduct(nums1, nums2) << '\n';
    return 0;
}