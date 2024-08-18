// https://leetcode.cn/problems/find-common-elements-between-two-arrays/
        
class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end()), s2(nums2.begin(), nums2.end());
        int cnt1 = 0, cnt2 = 0;
        for (int num: nums1) {
            if (s2.find(num) != s2.end()) cnt1 += 1;
        }
        for (int num: nums2) {
            if (s1.find(num) != s1.end()) cnt2 += 1;
        }
        return vector<int> {cnt1, cnt2};
    }
};
