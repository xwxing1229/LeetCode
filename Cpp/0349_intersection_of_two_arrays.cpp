// https://leetcode.cn/problems/intersection-of-two-arrays/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> check1, check2;
        vector<int> res;
        for (int num: nums1) {
            check1.insert(num);
        }
        for (int num: nums2) {
            check2.insert(num);
        }
        for (int num: check1) {
            if (check2.find(num) != check2.end()) {
                res.push_back(num);
            }
        }
        return res;
    }
};
