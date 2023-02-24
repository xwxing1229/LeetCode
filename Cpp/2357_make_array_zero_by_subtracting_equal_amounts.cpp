// https://leetcode.cn/problems/make-array-zero-by-subtracting-equal-amounts/

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> s;
        for (int num: nums) {
            if (num > 0) {
                s.insert(num);
            }
        }
        return s.size();
    }
};
