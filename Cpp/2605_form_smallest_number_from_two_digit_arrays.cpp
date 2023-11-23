// https://leetcode.cn/problems/form-smallest-number-from-two-digit-arrays/

class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        int a = nums1[0], b = nums2[0], c = 10;
        vector<int> check(10, 0);
        for (int num: nums1) {
            a = min(a, num);
            check[num] = 1;
        }
        for (int num: nums2) {
            b = min(b, num);
            if (check[num] == 1) {
                c = min(c, num);
            }
        }
        if (c < 10) return c;
        else if (a == b) return a;
        else return (a < b) ? 10*a+b : 10*b+a;
    }
};
