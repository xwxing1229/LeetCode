// https://leetcode.cn/problems/number-of-different-subsequences-gcds/

class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int max_ = *max_element(nums.begin(), nums.end());
        vector<int> occured(max_+1, 0);
        for (int num: nums) {
            occured[num] = 1;
        }
        int res = 0;
        for (int i = 1; i <= max_; ++i) {
            int sub_gcd = 0;
            for (int j = i; j <= max_; j+=i) {
                if (occured[j]) {
                    if (sub_gcd == 0) sub_gcd = j;
                    else sub_gcd = gcd(sub_gcd, j);
                    if (sub_gcd == i) {
                        res += 1;
                        break;
                    }
                }
            }
        }
        return res;
    }
};