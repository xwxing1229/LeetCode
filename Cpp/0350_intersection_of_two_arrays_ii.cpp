// https://leetcode.cn/problems/intersection-of-two-arrays-ii/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> check;
        vector<int> res;
        for (int num: nums1) {
            check[num] = check[num] + 1;
        }
        for (int num: nums2) {
            if ((check.find(num) != check.end()) && (check[num] > 0)) {
                res.push_back(num);
                check[num] = check[num] - 1;
            }
        }
        return res;
    }
};
