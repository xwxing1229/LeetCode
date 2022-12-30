// https://leetcode.cn/problems/two-out-of-three/

class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        set<int> s1(nums1.begin(), nums1.end());
        set<int> s2(nums2.begin(), nums2.end());
        set<int> s3(nums3.begin(), nums3.end());
        set<int> inter1, inter2, inter3;
        set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(),
            inserter(inter1, inter1.begin()));
        set_intersection(s1.begin(), s1.end(), s3.begin(), s3.end(),
            inserter(inter2, inter2.begin()));
        set_intersection(s2.begin(), s2.end(), s3.begin(), s3.end(),
            inserter(inter3, inter3.begin()));
        inter1.insert(inter2.begin(), inter2.end());
        inter1.insert(inter3.begin(), inter3.end());
        vector<int> res(inter1.begin(), inter1.end());
        return res;
    }
};
