// https://leetcode.cn/problems/advantage-shuffle/submissions/

class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> idx1(n), idx2(n);
        for (int i = 0; i < n; ++i) {
            idx1[i] = i;
            idx2[i] = i;
        }
        sort(idx1.begin(), idx1.end(), [&](int i, int j) {
            return nums1[i] < nums1[j];
        });
        sort(idx2.begin(), idx2.end(), [&](int i, int j) {
            return nums2[i] < nums2[j];
        });

        vector<int> res(n);
        int left = 0, right = n-1;
        for (int i: idx1) {
            if (nums1[i] > nums2[idx2[left]]) {
                res[idx2[left]] = nums1[i];
                left = left + 1;
            }
            else {
                res[idx2[right]] = nums1[i];
                right = right - 1;
            }
        }
        return res;
    }
};
