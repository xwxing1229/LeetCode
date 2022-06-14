// https://leetcode.cn/problems/merge-sorted-array/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i1 = m - 1, i2 = n - 1;
        for (int idx = m+n-1; idx >= 0; --idx) {
            if (i2 < 0) {
                break;
            }
            else if ((i1 >= 0) && (nums1[i1] > nums2[i2])) {
                nums1[idx] = nums1[i1];
                i1 = i1 - 1;
            }
            else {
                nums1[idx] = nums2[i2];
                i2 = i2 - 1;
            }
        }
    }
};
