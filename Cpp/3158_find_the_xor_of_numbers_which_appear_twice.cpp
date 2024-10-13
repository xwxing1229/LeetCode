// https://leetcode.cn/problems/find-the-xor-of-numbers-which-appear-twice/

class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_set<int> s;
        int res = 0;
        for (int num: nums) {
            if (s.find(num) != s.end()) {
                res ^= num;
            }
            else {
                s.insert(num);
            }
        }
        return res;
    }
};
